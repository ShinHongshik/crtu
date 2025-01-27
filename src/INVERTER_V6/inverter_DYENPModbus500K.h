#define true 1
#define false 0

	typedef union{
	    float f;
	    unsigned char buf[4];
	} uni1;

uni1 data = {0};

unsigned long int Hex_to_Ulongint(char buf1, char buf2, char buf3, char buf4)
{
   unsigned long int result=0;
  
   data.buf[3] = (unsigned char)buf1;
   data.buf[2] = (unsigned char)buf2;
   data.buf[1] = (unsigned char)buf3;
   data.buf[0] = (unsigned char)buf4;
   
   data.f /= 1000;

   result = (unsigned long int)data.f;

    sprintf(str,"%d", result);
    put_str(0,0,str,1);

   return result;
}

unsigned long int Hex_to_Uint(char buf1, char buf2, char buf3, char buf4, char flag)
{
   unsigned int result=0;
  
   data.buf[3] = (unsigned char)buf1;
   data.buf[2] = (unsigned char)buf2;
   data.buf[1] = (unsigned char)buf3;
   data.buf[0] = (unsigned char)buf4;
   
   if(flag == true)
   {
        data.f /= 100;
   }
   
   result = (unsigned int)data.f;

   return result;
}


void sendInverterRead_DYENPModbus500K(void) {  
    unsigned int retVal;
    char sendBuff[10];   
    
    switch(inverter_seq) {
        case 0:
            inverter_seq++;
         if (sendInverterCount[0] < 100) {
               sendInverterCount[0]++;
            }
            break;     
        case 1:     //Inv-1: RTU Master request frame  

            inverter_address = 1;     
         rx_seq0 = 0; 
            
         sendBuff[0] = 0x01;   //Slave Number
         sendBuff[1] = 0x04;   //Function Code
         sendBuff[2] = 0x00; //Modbus Address High
         sendBuff[3] = 0x22; //Modbus Address Low
         sendBuff[4] = 0x00; //Data Count High
         sendBuff[5] = 0x46; //Data Count Low (26)
         retVal = calcCRC(sendBuff,6);         
                        
          putchar0(sendBuff[1]); 
          putchar0(sendBuff[2]); //Modbus Address High
          putchar0(sendBuff[3]); //Modbus Address Low
          putchar0(sendBuff[4]); //Data Count High
          putchar0(sendBuff[5]); //Data Count Low           
          putchar0(retVal % 0x100);   //2a.73
          putchar0(retVal / 0x100);

//            sprintf(str,"%02X %02X ", retVal % 0x100, retVal / 0x100);
//            put_str(0,0,str,1);
            
            TXEN=1;TXEN=1; //RS485 Tx Enable Pin is ON, two delay
            
#if (UDR_CLONE_MODE == 1)
			write_udr0 (sendBuff[0]);  
#else  
			UDR0 = sendBuff[0] ;  
#endif        
            sprintf(str,"TX%02d",inverter_address);     
            put_str(4,16,str,1);   
            rx_led_delay = 2500;
            inverter_seq++;             
            break;         
        case 2:
        case 3:
        case 4:
           inverter_seq++;
            break;  
            
        case 5:         
           inverter_address++;
           if (eeInverterCount >= inverter_address) { 
                if (sendInverterCount[inverter_address-1] < 100) {
                    sendInverterCount[inverter_address-1]++;
                }            
               inverter_seq++;
           } else {
            inverter_seq = 0;               
            }
            break;    
        case 6:     //Inv-??: RTU Master request frame  

            //putchar0(0x01); //Slave Address
         rx_seq0 = 0; 
            
         sendBuff[0] = inverter_address;   //Slave Number??
         sendBuff[1] = 0x04;   //Function Code
         sendBuff[2] = 0x00; //Modbus Address High
         sendBuff[3] = 0x22; //Modbus Address Low
         sendBuff[4] = 0x00; //Data Count High
         sendBuff[5] = 0x46; //Data Count Low (26)
         retVal = calcCRC(sendBuff,6);        
                        
            putchar0(sendBuff[1]); 
            putchar0(sendBuff[2]); //Modbus Address High
            putchar0(sendBuff[3]); //Modbus Address Low
            putchar0(sendBuff[4]); //Data Count High
            putchar0(sendBuff[5]); //Data Count Low           
          putchar0(retVal % 0x100);   //2a.73
          putchar0(retVal / 0x100);

//            sprintf(str,"%02X %02X ", retVal % 0x100, retVal / 0x100);
//            put_str(0,0,str,1);
            
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_udr0 (sendBuff[0]);  
#else  
			UDR0 = sendBuff[0] ;  
#endif        
            sprintf(str,"TX%02d",inverter_address);     
            put_str(4,16,str,1);   
            rx_led_delay = 2500;
            inverter_seq++;             
            break;         
        case 7:
        case 8:  
           inverter_seq++;
            break;  
        case 9: 
           inverter_seq = 5;
            break;



        default:  
            inverter_seq = 0;
            break;
    }
}



void rx0Control_DYENPModbus500K(void) {   
   char rxdata;   
    unsigned int calCrc,rxCrc;
    unsigned long int imlong;
    

   rxdata = getchar0();
   
   switch(rx_seq0) {
      case 0: //STX        
           if (rxdata < 100) {
            rcnt = 0;           
                memset(rxbuff,0,sizeof(rxbuff));
                rxbuff[rcnt++] = rxdata;
                timeout0 = 250;
                rx_seq0++;
            }
         break; 
       
        case 1: //Device (Slave) 
            if (rxdata == 0x04) {
                rxbuff[rcnt++] = rxdata;
                rx_seq0++;
            } else {
                rx_seq0 = 0;
            }                     
            break;
        case 2: //Data Count
            if (rxdata == 0x8C) {   
               dcnt = 0;
                rxbuff[rcnt++] = rxdata;
                rx_seq0++;
            } else {
                rx_seq0 = 0;
            }                     
            break;   
        case 3:
            rxbuff[rcnt++] = rxdata;
            dcnt++;
            if (dcnt == 142) {
            calCrc = calcCRC(rxbuff,144+3);   
               rxCrc = rxbuff[148];
               rxCrc <<= 8;
               rxCrc += rxbuff[147];  


                if (rxCrc == calCrc) {

                   invNo = rxbuff[0] - 1;
                    
                   inverter[invNo].solar_cell_voltage  = Hex_to_Uint(rxbuff[3],rxbuff[4],rxbuff[5],rxbuff[6],false);    /*clr*/ 
                   inverter[invNo].solar_cell_current = Hex_to_Uint(rxbuff[11],rxbuff[12],rxbuff[13],rxbuff[14],false);  
                   inverter[invNo].power_solar = Hex_to_Uint(rxbuff[15],rxbuff[16],rxbuff[17],rxbuff[18],true); 
                   
                                                        
                   inverter[invNo].inv_u_voltage     = Hex_to_Uint(rxbuff[51],rxbuff[52],rxbuff[53],rxbuff[54],false);        
                   inverter[invNo].inv_v_voltage     = Hex_to_Uint(rxbuff[55],rxbuff[56],rxbuff[57],rxbuff[58],false);      
                   inverter[invNo].inv_w_voltage     = Hex_to_Uint(rxbuff[59],rxbuff[60],rxbuff[61],rxbuff[62],false);       
                    
                   inverter[invNo].inv_u_current      = Hex_to_Uint(rxbuff[63],rxbuff[64],rxbuff[65],rxbuff[66],false);       
                   inverter[invNo].inv_v_current      = Hex_to_Uint(rxbuff[67],rxbuff[68],rxbuff[69],rxbuff[70],false);      
                   inverter[invNo].inv_w_current      = Hex_to_Uint(rxbuff[71],rxbuff[72],rxbuff[73],rxbuff[74],false);        

                    
                   inverter[invNo].power_inv_now       = Hex_to_Uint(rxbuff[27],rxbuff[28],rxbuff[29],rxbuff[30],true);                                  
                   inverter[invNo].power_inv_pf        = Hex_to_Uint(rxbuff[35],rxbuff[36],rxbuff[37],rxbuff[38],false);
                   inverter[invNo].inv_frequency       = Hex_to_Uint(rxbuff[39],rxbuff[40],rxbuff[41],rxbuff[42],false);   

                    
                   

                    inverter[invNo].power_inv_day_total = Hex_to_Ulongint(rxbuff[43],rxbuff[44],rxbuff[45],rxbuff[46]);     
                    
                    
                    
                    inverter[invNo].inverter_status[0] = Bytes_to_Uint(rxbuff[137],rxbuff[138]);    //????         
                    inverter[invNo].inverter_status[1] = Bytes_to_Uint(rxbuff[139],rxbuff[140]);                   
                    inverter[invNo].inverter_status[2] = Bytes_to_Uint(rxbuff[141],rxbuff[142]);                  
                    inverter[invNo].inverter_status[3] = 0;                                                             
                    


                    inverter[invNo].power_inv_total    = Bytes_to_Uint(rxbuff[123],rxbuff[124]);
                    inverter[invNo].power_inv_total  <<= 16;
                    inverter[invNo].power_inv_total   += Bytes_to_Uint(rxbuff[125],rxbuff[126]);
                    inverter[invNo].power_inv_total   *= 1000000;
                                                   
                    imlong   = Bytes_to_Uint(rxbuff[127],rxbuff[128]);
                    imlong <<= 16;
                    imlong   += Bytes_to_Uint(rxbuff[129],rxbuff[130]);
                    
                    inverter[invNo].power_inv_total += imlong;
                    inverter[invNo].power_inv_total /= 1000;
                    
                    inverter[invNo].power_inv_pf *= 10;
                    //inverter[invNo].power_solar /= 1000;
                    //inverter[invNo].power_inv_now /= 1000;
                    //inverter[invNo].power_inv_day_total /= 1000;
                     
                    
                    
                   sendInverterCount[invNo] = 0;
                   buzzer_flag |= BUZZER_TIC;
                   sprintf(str,"RX%02d",invNo+1);
                   put_str(4,16,str,1);   
                   rx_led_delay = 2500;
                }
               rx_seq0 = 0;
            }
            break;

      default:
         rx_seq0 = 0;
         break;
   }
}