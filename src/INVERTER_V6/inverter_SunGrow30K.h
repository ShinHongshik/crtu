void sendInverterRead_SunGrow3K(void) {  
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
        	//01 04 13 87 00 55 CC CC => 01 04 aa ff ff ff ff .......
            //putchar0(0x01); //Slave Address
            inverter_address = 1;     
			rx_seq0 = 0; 
            
			sendBuff[0] = inverter_address;	//Slave Number
			sendBuff[1] = 0x04;	//Function Code
            sendBuff[2] = 0x13; //Modbus Address High
            sendBuff[3] = 0x87; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x55; //Data Count Low (29)
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
			write_udr0 (inverter_address);  
#else  
			UDR0 = inverter_address ;  
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
        	if (eeInverterCount > inverter_address) { 
                if (sendInverterCount[inverter_address-1] < 100) {
                    sendInverterCount[inverter_address-1]++;
                }            
            	inverter_seq++;
        	} else {
				inverter_seq = 0;            	
            }
            break;    
        case 6:     //Inv-??: RTU Master request frame  
        	//ADDR 04 13 87 00 55 CC CC => 01 04 aa ff ff ff ff .......
            //putchar0(0x01); //Slave Address
			rx_seq0 = 0; 
            
			sendBuff[0] = inverter_address;	//Slave Number
			sendBuff[1] = 0x04;	//Function Code
            sendBuff[2] = 0x13; //Modbus Address High
            sendBuff[3] = 0x87; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x55; //Data Count Low (29)
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
			write_udr0 (inverter_address);  
#else  
			UDR0 = inverter_address ;  
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



void rx0Control_SunGrow3K(void) {   
	char rxdata;   
    unsigned int calCrc,rxCrc;
	rxdata = getchar0();
	
	switch(rx_seq0) {
		case 0: //STX        
        	if ( (rxdata > 0x00) && (rxdata < 0x23)) {
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
            if (rxdata == 0xaa) {   
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
            if (dcnt == 172) {
            //if (1) {	//CRC-16 Check
            //if (rxCount1 == (rx1RetCount[rxbuff1[0]]*2+5)) {   
            	calCrc = calcCRC(rxbuff,170+3);   
                rxCrc = rxbuff[174];
                rxCrc <<= 8;
                rxCrc += rxbuff[173];  
sprintf(str,"%04X %04X ", calCrc, rxCrc);
put_str(0,0,str,1);

                if (rxCrc == calCrc) {
                    //invNo = 0;
                    invNo = rxbuff[0] - 1;
                    
					calCrc = Bytes_to_Uint(rxbuff[25],rxbuff[26]);
					rxCrc = Bytes_to_Uint(rxbuff[29],rxbuff[30]);
					if (rxCrc > calCrc) {
						inverter[invNo].solar_cell_voltage = rxCrc;
					} else {
						inverter[invNo].solar_cell_voltage = calCrc;
					}
                	//inverter[invNo].solar_cell_voltage  = Bytes_to_Uint(rxbuff[25],rxbuff[26]);
					inverter[invNo].solar_cell_current  = Bytes_to_Uint(rxbuff[27],rxbuff[28]) + Bytes_to_Uint(rxbuff[31],rxbuff[32]) + Bytes_to_Uint(rxbuff[35],rxbuff[36]);            
                	inverter[invNo].power_solar         = Bytes_to_Uint(rxbuff[37],rxbuff[38]);  
                    
                	inverter[invNo].inv_u_voltage		= Bytes_to_Uint(rxbuff[41],rxbuff[42]); 
                	inverter[invNo].inv_v_voltage		= Bytes_to_Uint(rxbuff[43],rxbuff[44]); 
                	inverter[invNo].inv_w_voltage		= Bytes_to_Uint(rxbuff[45],rxbuff[46]); 
                    inverter[invNo].inv_u_current		= Bytes_to_Uint(rxbuff[47],rxbuff[48]);
                	inverter[invNo].inv_v_current		= Bytes_to_Uint(rxbuff[49],rxbuff[50]);
                	inverter[invNo].inv_w_current		= Bytes_to_Uint(rxbuff[51],rxbuff[52]);
                	inverter[invNo].power_inv_now		= Bytes_to_Uint(rxbuff[65],rxbuff[66]);  
                    inverter[invNo].power_inv_pf        = Bytes_to_Uint(rxbuff[73],rxbuff[74]);
                    inverter[invNo].inv_frequency       = Bytes_to_Uint(rxbuff[75],rxbuff[76]);
                	//inverter[invNo].power_inv_max       = Bytes_to_Uint(rxbuff[27],rxbuff[28]);
                	inverter[invNo].power_inv_day_total = Bytes_to_Uint(rxbuff[9],rxbuff[10]);
                	inverter[invNo].power_inv_total     = Bytes_to_Uint(rxbuff[13],rxbuff[14]);
                    inverter[invNo].power_inv_total   <<= 16; 
                	inverter[invNo].power_inv_total    += Bytes_to_Uint(rxbuff[11],rxbuff[12]); 
                    
                    inverter[invNo].inverter_status[0] = Bytes_to_Uint(rxbuff[79],rxbuff[80]);            
                    inverter[invNo].inverter_status[1] = Bytes_to_Uint(rxbuff[93],rxbuff[94]);              
                    inverter[invNo].inverter_status[2] = Bytes_to_Uint(rxbuff[103],rxbuff[104]);             
                    inverter[invNo].inverter_status[3] = Bytes_to_Uint(rxbuff[105],rxbuff[106]);             
                
                	inverter[invNo].solar_cell_voltage  /= 10;
					inverter[invNo].solar_cell_current  /= 10;            
                	inverter[invNo].inv_u_voltage     /= 10; 
                	inverter[invNo].inv_v_voltage     /= 10; 
                	inverter[invNo].inv_w_voltage     /= 10;
                    inverter[invNo].inv_u_current      /= 10;
                	inverter[invNo].inv_v_current      /= 10;
                	inverter[invNo].inv_w_current      /= 10;
                	inverter[invNo].power_inv_day_total /= 10;
                	//inverter[invNo].power_solar         /= 10;
                	//inverter[invNo].power_inv_now		/= 10;  

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
