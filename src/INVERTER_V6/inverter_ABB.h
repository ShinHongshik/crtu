void sendInverterRead_AbbModbus(void) {
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
        	//01 03 02 BB 00 1D F4 5E => 01 03 10 0f 83 0f 92 0f 86 01 72 01 67 01 6a 00 00 02 58 eb a1
            //putchar0(0x01); //Slave Address     
			rx_seq0 = 0;                           
            
			sendBuff[0] = 0x01;	//Slave Number
			sendBuff[1] = 0x03;	//Function Code
            // Parameter Groups 01..09 (104;0068H)
            sendBuff[2] = 0x00; //Modbus Address High
            sendBuff[3] = 0x67; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x1F; //Data Count Low (29)
    		retVal = calcCRC(sendBuff,6);         
                        
            putchar0(sendBuff[1]); 
            putchar0(sendBuff[2]); //Modbus Address High
            putchar0(sendBuff[3]); //Modbus Address Low
            putchar0(sendBuff[4]); //Data Count High
            putchar0(sendBuff[5]); //Data Count Low           
		    putchar0(retVal % 0x100);   //2a.73
    		putchar0(retVal / 0x100);
	
//    		sprintf(str,"CRC:%04X ",retVal);
//            put_str(0,0,str,2);

            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x01);  
#else  
			UDR0 = 0x01 ;  
#endif        
            sprintf(str,"TX-%d",1);
            put_str(4,16,str,1);   
            rx_led_delay = 2500;
            inverter_seq++;             
            
//            //01 03 10 0f 83 0f 92 0f 86 01 72 01 67 01 6a 00 00 02 58 eb a1
//            memset(str,0,sizeof(str));
//            str[0] = 0x01;
//            str[1] = 0x03;
//            str[2] = 0x10;
//            str[3] = 0x0f;
//            str[4] = 0x83;
//            str[5] = 0x0f;
//            str[6] = 0x92;
//            str[7] = 0x0f;
//            str[8] = 0x86;
//            str[9] = 0x01;
//            str[10] = 0x72;
//            str[11] = 0x01;
//            str[12] = 0x67;
//            str[13] = 0x01;
//            str[14] = 0x6a;
//            str[15] = 0x00;
//            str[16] = 0x00;
//            str[17] = 0x02;
//            str[18] = 0x58;
//            im = CRC16(str,19);
//            
//            sprintf(str,"%04X",im);
//            put_str(0,0,str,1);
            
            break;         
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
        case 14: 
        	inverter_seq++;
            break;
        case 15:           
        	if (eeInverterCount > 1) { 
                if (sendInverterCount[1] < 100) {
                    sendInverterCount[1]++;
                }            
            	inverter_seq++;
        	} else {
				inverter_seq = 0;            	
            }
            break;         
        case 16:     //Inv-2: RTU Master request frame  
        	//02 03 02 BB 00 1D F4 6D => 01 03 10 0f 83 0f 92 0f 86 01 72 01 67 01 6a 00 00 02 58 eb a1
            //putchar0(0x01); //Slave Address     
			rx_seq0 = 0;       
            
			sendBuff[0] = 0x02;	//Slave Number
			sendBuff[1] = 0x03;	//Function Code
            // Parameter Groups 01..09 (104;0068H)
            sendBuff[2] = 0x00; //Modbus Address High
            sendBuff[3] = 0x67; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x1F; //Data Count Low (29)
    		retVal = calcCRC(sendBuff,6);         
                        
            putchar0(sendBuff[1]); 
            putchar0(sendBuff[2]); //Modbus Address High
            putchar0(sendBuff[3]); //Modbus Address Low
            putchar0(sendBuff[4]); //Data Count High
            putchar0(sendBuff[5]); //Data Count Low          
		    putchar0(retVal % 0x100);
    		putchar0(retVal / 0x100);
            
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x02);  
#else  
			UDR0 = 0x02 ;  
#endif  
            sprintf(str,"TX-%d",2);
            put_str(4,16,str,1);   
            rx_led_delay = 2500;
            inverter_seq++;
            break;         
        case 17:
        case 18:
        case 19:
        case 20:
        case 21:
        case 22:
        case 23:
        case 24:
        case 25:
        case 26:
        case 27:
        case 28:
        case 29:
            inverter_seq++;
            break;     
        case 30:
            inverter_seq = 0;
            break;
        default:  
            inverter_seq = 0;
            break;
    }
}



void rx0Control_AbbModbus(void) {   
	char rxdata;   
    //unsigned int rcrc;
	rxdata = getchar0();
	
	switch(rx_seq0) {
		case 0: //STX        
        	if ( (rxdata == 0x01) || (rxdata == 0x02) || (rxdata == 0x03) ){
				rcnt = 0;           
                memset(rxbuff,0,sizeof(rxbuff));
                rxbuff[rcnt++] = rxdata;
                timeout0 = 250;
            	rx_seq0++;
            } 
			break;        
        case 1: //Device (Slave) 
            if (rxdata == 0x03) {
                rxbuff[rcnt++] = rxdata;
                rx_seq0++;
            } else {
                rx_seq0 = 0;
            }                     
            break;
        case 2: //Data Count
//            if (rxdata == 0x3a) {   
            if (rxdata == 0x3e) {   
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
//            if (dcnt == 58) {
            if (dcnt == 62) {
					buzzer_flag |= BUZZER_TIC;
//                    put_str(4,16,C_RXOK,1);   
                    put_strf(4,16,C_RXOK,1);   			
					rx_led_delay = 2500;

                	//if (1) {	//CRC-16 Check
                    //invNo = 0;
                    invNo = rxbuff[0] - 1;
                    
                	inverter[invNo].solar_cell_voltage  = Bytes_to_Uint(rxbuff[63],rxbuff[64]);
					inverter[invNo].solar_cell_current  = Bytes_to_Uint(rxbuff[31],rxbuff[32]);            
                	inverter[invNo].power_solar         = Bytes_to_Uint(rxbuff[33],rxbuff[34]); 
                	inverter[invNo].inv_u_voltage     = Bytes_to_Uint(rxbuff[3],rxbuff[4]); 
                	inverter[invNo].inv_v_voltage     = Bytes_to_Uint(rxbuff[5],rxbuff[6]); 
                	inverter[invNo].inv_w_voltage     = Bytes_to_Uint(rxbuff[7],rxbuff[8]);
                    inverter[invNo].inv_u_current      = Bytes_to_Uint(rxbuff[ 9],rxbuff[10]);
                	inverter[invNo].inv_v_current      = Bytes_to_Uint(rxbuff[11],rxbuff[12]);
                	inverter[invNo].inv_w_current      = Bytes_to_Uint(rxbuff[13],rxbuff[14]);
                	inverter[invNo].power_inv_now       = Bytes_to_Uint(rxbuff[15],rxbuff[16]);  
                    inverter[invNo].power_inv_pf        = 950;// Bytes_to_Uint(rxbuff[23],rxbuff[24]);
                    inverter[invNo].inv_frequency       = Bytes_to_Uint(rxbuff[19],rxbuff[20]);
                	//inverter[invNo].power_inv_max       = inverter[invNo].power_inv_now;
                	inverter[invNo].power_inv_day_total = Bytes_to_Uint(rxbuff[15],rxbuff[16]);
                	inverter[invNo].power_inv_total     = Bytes_to_Uint(rxbuff[53],rxbuff[54]);
                    inverter[invNo].power_inv_total    *= 1000000; 
                	inverter[invNo].power_inv_total    += (unsigned long int)Bytes_to_Uint(rxbuff[51],rxbuff[52]) * 1000; 
                	inverter[invNo].power_inv_total    += Bytes_to_Uint(rxbuff[49],rxbuff[50]); 
                    
                    inverter[invNo].inverter_status[0] = Bytes_to_Uint(rxbuff[37],rxbuff[38]);            
                    inverter[invNo].inverter_status[1] = Bytes_to_Uint(rxbuff[39],rxbuff[40]);              
                    inverter[invNo].inverter_status[2] = Bytes_to_Uint(rxbuff[41],rxbuff[42]);             
                    inverter[invNo].inverter_status[3] = Bytes_to_Uint(rxbuff[43],rxbuff[44]);             
                
//                	inverter[invNo].solar_cell_voltage  /= 10;
//					inverter[invNo].solar_cell_current  /= 10;            
                	inverter[invNo].power_solar         *= 10; 
//                	inverter[invNo].util_rs_voltage     /= 10; 
//                	inverter[invNo].util_st_voltage     /= 10; 
//                	inverter[invNo].util_tr_voltage     /= 10;
//                	inverter[invNo].inv_u_voltage = inverter[invNo].util_rs_voltage;
//                	inverter[invNo].inv_v_voltage = inverter[invNo].util_st_voltage; 
//                	inverter[invNo].inv_w_voltage = inverter[invNo].util_tr_voltage;
//                    inverter[invNo].util_r_current      /= 10;
//                	inverter[invNo].util_s_current      /= 10;
//                	inverter[invNo].util_t_current      /= 10;
//                	inverter[invNo].inv_u_current = inverter[invNo].util_r_current; 
//                	inverter[invNo].inv_v_current = inverter[invNo].util_s_current;
//                	inverter[invNo].inv_w_current = inverter[invNo].util_t_current; 
//                	inverter[invNo].power_solar;//         = 10;  
//               	    inverter[invNo].power_inv_now = inverter[invNo].power_solar;
//                 	inverter[invNo].power_inv_max;//       = 10;
                	inverter[invNo].power_inv_day_total /= 10;
//                	inverter[invNo].power_inv_total     = 10;

	                sendInverterCount[invNo] = 0;
					buzzer_flag |= BUZZER_TIC;
                sprintf(str,"RX-%01d",invNo+1);
                put_str(4,16,str,1);   
                rx_led_delay = 2500;
//                    put_str(4,16,C_RXOK,1);   
//					rx_led_delay = 2500;
                
                //}    
                rx_seq0 = 0;
            }
            break;

		default:
			rx_seq0 = 0;
			break;
	}
}
