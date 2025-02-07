
void sendInverterRead_GIPAM115(void) {
    unsigned int retVal;
    char sendBuff[10];   
    
    switch(inverter_seq) {
        case 0:
            inverter_seq++;
			if (sendInverterCount[0] < 100) {
            	sendInverterCount[0]++;
            }
            break;         
        case 1:     //Inv-1: RTU Master request frame (from GIPAM115FI)  
        	//01 03 02 BB 00 1D F4 5E => 01 03 10 0f 83 0f 92 0f 86 01 72 01 67 01 6a 00 00 02 58 eb a1
            sendBuff[0] = 0x01;
            sendBuff[1] = 0x04;
            sendBuff[2] = 0x00;
            sendBuff[3] = 0x00;
            sendBuff[4] = 0x00;
            sendBuff[5] = 0x26;
            retVal = calcCRC(sendBuff,6);     
                                               //010.4650.2238
            TXEN = 1;
            TXEN = 1;
            putchar0(0x04); //Function Code
            putchar0(0x00); //Modbus Address High
            putchar0(0x00); //Modbus Address Low
            putchar0(0x00); //Data Count High
            putchar0(0x26); //Data Count Low  
            putchar0(retVal % 0x100); //CRC_L
            putchar0(retVal / 0x100); //CRC_H
                            
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x01);  
#else  
			UDR0 = 0x01 ;  
#endif	//485 Address 
            inverter_seq++;             
            break;         
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        	inverter_seq++;
            break;
        case 10:           
            inverter_seq = 0;            	
            break;         
        default:  
            inverter_seq = 0;
            break;
    }
}


void rx0Control_GIPAM115(void) {
    //char imc;        
	char rxdata = getchar0();; 
    unsigned int calCrc,rxCrc;  

//buzzer_flag |= BUZZER_TIC; 
//sprintf(str,"SEQ:%02d, %02X ", rx_seq0, rxdata );
//put_str(0,0,str,1);
             	
	switch(rx_seq0) {
		case 0:
			if (rxdata == 0x01) {   
                rcnt = 0;
                rxbuff[rcnt++] = rxdata;   
                timeout0 = 250;
				rx_seq0++;
			}   
			break;   
		case 1:     
        	rxbuff[rcnt++] = rxdata;   
			if (rxdata == 0x04) {   
            	rx_seq0++;   
            } else {      
            	rx_seq0=0;  
            }  
            break;
        case 2:      
        	rxbuff[rcnt++] = rxdata;
        	if (rxdata == (0x26 * 2)) {  
            	rx_seq0++;
            } else {      
            	rx_seq0 = 0;
            }  
            break;
    	case 3:   
            rxbuff[rcnt++] = rxdata;  
                
            if (rcnt == (0x26 * 2 + 5)) {   
            	calCrc = calcCRC(rxbuff, 0x26 * 2 + 3);
                rxCrc = rxbuff[0x26 * 2 + 4];
                rxCrc <<= 8;
                rxCrc += rxbuff[0x26 * 2 + 3];  
                
                          
                       
				sprintf(str,"CR:%02X%02X,%02X%02X ",calCrc%0x100,calCrc/0x100,rxCrc%0x100,rxCrc/0x100  );
                put_str(0,0,str,1);         
                buzzer_flag |= BUZZER_TIC;
                
                if (rxCrc != calCrc) {
                	return;
                }

                invNo = 0;            
                inverter[0].inverter_status[0] = Bytes_to_Uint(rxbuff[3],rxbuff[4]);
                inverter[0].inverter_status[1] = Bytes_to_Uint(rxbuff[5],rxbuff[6]);
                inverter[0].inverter_status[2] = Bytes_to_Uint(rxbuff[7],rxbuff[8]);
                inverter[0].inverter_status[3] = Bytes_to_Uint(rxbuff[9],rxbuff[10]);
                
                
                //선간전압 RS상
                fdata.chars[3] = rxbuff[23];
                fdata.chars[2] = rxbuff[24];
                fdata.chars[1] = rxbuff[25];
                fdata.chars[0] = rxbuff[26];
                //gipam.powerData[3] = (unsigned int)(fdata.value);  
                inverter[invNo].solar_cell_voltage	= (unsigned int)(fdata.value);// / 10;	//RS상 전압                                                               
                //전류 R상
                fdata.chars[3] = rxbuff[39];
                fdata.chars[2] = rxbuff[40];
                fdata.chars[1] = rxbuff[41];
                fdata.chars[0] = rxbuff[42];
                //gipam.powerData[7] = (unsigned int)(fdata.value*10);
                inverter[invNo].solar_cell_current	= (unsigned int)(fdata.value*10) / 10;// + gipam.powerData[8] + gipam.powerData[9]) / 10;    
                //총 유효전력
                fdata.chars[3] = rxbuff[59];
                fdata.chars[2] = rxbuff[60];
                fdata.chars[1] = rxbuff[61];
                fdata.chars[0] = rxbuff[62];                                     
                //gipam.powerData[12] = (unsigned int)(fdata.value/100);          
                inverter[invNo].power_solar			= (unsigned int)(fdata.value/100);// / 10;   
                                                                                                      
                //선간전압 RS상
                fdata.chars[3] = rxbuff[23];
                fdata.chars[2] = rxbuff[24];
                fdata.chars[1] = rxbuff[25];
                fdata.chars[0] = rxbuff[26];
                //gipam.powerData[3] = (unsigned int)(fdata.value);  
                inverter[invNo].inv_u_voltage		= (unsigned int)(fdata.value);// / 10;  
                //선간전압 ST상
                fdata.chars[3] = rxbuff[27];
                fdata.chars[2] = rxbuff[28];
                fdata.chars[1] = rxbuff[29];
                fdata.chars[0] = rxbuff[30];
                //gipam.powerData[4] = (unsigned int)(fdata.value);  
                inverter[invNo].inv_v_voltage     	= (unsigned int)(fdata.value);// / 10;  
                //선간전압 TR상
                fdata.chars[3] = rxbuff[31];
                fdata.chars[2] = rxbuff[32];
                fdata.chars[1] = rxbuff[33];
                fdata.chars[0] = rxbuff[34];
                //gipam.powerData[5] = (unsigned int)(fdata.value);        
                inverter[invNo].inv_w_voltage     	= (unsigned int)(fdata.value);// / 10;
                                                                                                                                             
                //전류 R상
                fdata.chars[3] = rxbuff[39];
                fdata.chars[2] = rxbuff[40];
                fdata.chars[1] = rxbuff[41];
                fdata.chars[0] = rxbuff[42];
                //gipam.powerData[7] = (unsigned int)(fdata.value*10);
                inverter[invNo].inv_u_current      = (unsigned int)(fdata.value*10) / 10;
                //전류 S상
                fdata.chars[3] = rxbuff[43];
                fdata.chars[2] = rxbuff[44];
                fdata.chars[1] = rxbuff[45];
                fdata.chars[0] = rxbuff[46];
                //gipam.powerData[8] = (unsigned int)(fdata.value*10);
                inverter[invNo].inv_v_current      = (unsigned int)(fdata.value*10) / 10; 
                //전류 T상
                fdata.chars[3] = rxbuff[47];
                fdata.chars[2] = rxbuff[48];
                fdata.chars[1] = rxbuff[49];
                fdata.chars[0] = rxbuff[50];
                //gipam.powerData[9] = (unsigned int)(fdata.value*10); 
                inverter[invNo].inv_w_current      = (unsigned int)(fdata.value*10) / 10;  
                //주파수
                fdata.chars[3] = rxbuff[51];
                fdata.chars[2] = rxbuff[52];
                fdata.chars[1] = rxbuff[53];
                fdata.chars[0] = rxbuff[54];
                //gipam.powerData[10] = (unsigned int)(fdata.value*10);
                inverter[invNo].inv_frequency		= (unsigned int)(fdata.value*10);
                //inverter[invNo].util_frequency = inverter[invNo].inv_frequency;

           	    inverter[invNo].power_inv_now = inverter[invNo].power_solar;       
                //inverter[invNo].power_inv_max = inverter[invNo].power_inv_now;   
                inverter[invNo].power_inv_day_total = inverter[invNo].power_inv_now;
               	
                      
                //전체 유효전력량
                fdata.chars[3] = rxbuff[71];
                fdata.chars[2] = rxbuff[72];
                fdata.chars[1] = rxbuff[73];
                fdata.chars[0] = rxbuff[74];                                     
                //gipam.longData[0] = (unsigned long int)(fdata.value);
                inverter[invNo].power_inv_total     = (unsigned long int)(fdata.value) / 1000;         
                
                //총 역률
                fdata.chars[3] = rxbuff[67];
                fdata.chars[2] = rxbuff[68];
                fdata.chars[1] = rxbuff[69];
                fdata.chars[0] = rxbuff[70];                                     
                //gipam.powerFactor = (signed int)(abs)(fdata.value*10);       
                inverter[invNo].power_inv_pf		= (signed int)(abs)(fdata.value*10);
                                            
                sendInverterCount[invNo] = 0;
                buzzer_flag |= BUZZER_TIC;
                sprintf(str,"RX-%01d",invNo+1);
                put_str(4,16,str,1);   
                rx_led_delay = 2500; 

                rx_seq0 = 0;    
            }                                              
			break;    
			
		default:
			rx_seq0 = 0;
			break;
	}
}