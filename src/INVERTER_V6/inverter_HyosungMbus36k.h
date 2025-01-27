void sendInverterRead_HyosungMbus36k(void) {  
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
        	//01 03 7e 06 00 3c bd f2 => 01 03 78 ff ff ff ff .......
            //putchar0(0x01); //Slave Address
            inverter_address = 1;     
			rx_seq0 = 0; 
            
			sendBuff[0] = inverter_address;	//Slave Number
			sendBuff[1] = 0x03;	//Function Code
            sendBuff[2] = 0x7e; //Modbus Address High (dec:3000, hex:bb8)
            sendBuff[3] = 0x06; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x3c; //Data Count Low (48)
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
        	//02 03 7e 06 00 3c bd f2 => 01 04 aa ff ff ff ff .......
            //putchar0(0x01); //Slave Address
			rx_seq0 = 0; 
            
			sendBuff[0] = inverter_address;	//Slave Number
			sendBuff[1] = 0x03;	//Function Code
            sendBuff[2] = 0x7e; //Modbus Address High (dec:3000, hex:bb8)
            sendBuff[3] = 0x06; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x3c; //Data Count Low (48)
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



void rx0Control_HyosungMbus36k(void) {   
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
            if (rxdata == 0x03) {
                rxbuff[rcnt++] = rxdata;
                rx_seq0++;
            } else {
                rx_seq0 = 0;
            }                     
            break;
        case 2: //Data Count
            if (rxdata == 0x78) {   
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
            if (dcnt == (0x78+2)) {
            //if (1) {	//CRC-16 Check
            //if (rxCount1 == (rx1RetCount[rxbuff1[0]]*2+5)) {   
            	calCrc = calcCRC(rxbuff,(0x78+3));   
                rxCrc = rxbuff[0x78+4];
                rxCrc <<= 8;
                rxCrc += rxbuff[0x78+3];  
//sprintf(str,"%04X %04X ", calCrc, rxCrc);
//put_str(0,0,str,1);

                if (rxCrc == calCrc) {
                    //invNo = 0;
                    invNo = rxbuff[0] - 1;
                    
                    inverter[invNo].solar_cell_voltage = Bytes_to_Uint(rxbuff[3],rxbuff[4]);
                	//inverter[invNo].solar_cell_voltage  = Bytes_to_Uint(rxbuff[25],rxbuff[26]);
					inverter[invNo].solar_cell_current  = Bytes_to_Uint(rxbuff[5],rxbuff[6]);
					inverter[invNo].solar_cell_current += Bytes_to_Uint(rxbuff[9],rxbuff[10]);
					inverter[invNo].solar_cell_current += Bytes_to_Uint(rxbuff[13],rxbuff[14]);
					inverter[invNo].solar_cell_current += Bytes_to_Uint(rxbuff[17],rxbuff[18]);
					inverter[invNo].solar_cell_current += Bytes_to_Uint(rxbuff[21],rxbuff[22]);
					inverter[invNo].solar_cell_current += Bytes_to_Uint(rxbuff[25],rxbuff[26]);
					inverter[invNo].solar_cell_current += Bytes_to_Uint(rxbuff[109],rxbuff[110]);
					inverter[invNo].solar_cell_current += Bytes_to_Uint(rxbuff[113],rxbuff[114]);

                    inverter[invNo].power_solar = Bytes_to_Uint(rxbuff[69],rxbuff[70]);
                    
                	inverter[invNo].inv_u_voltage		= Bytes_to_Uint(rxbuff[27],rxbuff[28]); 
                	inverter[invNo].inv_v_voltage		= Bytes_to_Uint(rxbuff[29],rxbuff[30]); 
                	inverter[invNo].inv_w_voltage		= Bytes_to_Uint(rxbuff[31],rxbuff[32]); 
                    inverter[invNo].inv_frequency       = Bytes_to_Uint(rxbuff[45],rxbuff[46]);
                    inverter[invNo].inv_u_current		= Bytes_to_Uint(rxbuff[39],rxbuff[40]);
                	inverter[invNo].inv_v_current		= Bytes_to_Uint(rxbuff[41],rxbuff[42]);
                	inverter[invNo].inv_w_current		= Bytes_to_Uint(rxbuff[43],rxbuff[44]);

                    slong1.cc[3] = rxbuff[59]; 
                    slong1.cc[2] = rxbuff[60]; 
                    slong1.cc[1] = rxbuff[61]; 
                    slong1.cc[0] = rxbuff[22];
                    if (slong1.ff < 0) slong1.ff = 0; 
                	inverter[invNo].power_inv_now		= slong1.ff;  
                    inverter[invNo].power_inv_pf        = Bytes_to_Uint(rxbuff[49],rxbuff[50]);
                	//inverter[invNo].power_inv_max       = Bytes_to_Uint(rxbuff[27],rxbuff[28]); 
                    uLong.cc[3] = rxbuff[79];
                    uLong.cc[2] = rxbuff[80];
                    uLong.cc[1] = rxbuff[81];
                    uLong.cc[0] = rxbuff[82];
                	inverter[invNo].power_inv_day_total = uLong.ff;    
                    
                    uLong.cc[3] = rxbuff[91];
                    uLong.cc[2] = rxbuff[92];
                    uLong.cc[1] = rxbuff[93];
                    uLong.cc[0] = rxbuff[94];
                    if (uLong.ff > 100) {
                		inverter[invNo].power_inv_total     = uLong.ff;
                    }
                                                                                              
                    //ADDR:3030, Operating mode of the inverter
                    inverter[invNo].inverter_status[0] = Bytes_to_Uint(rxbuff[53],rxbuff[54]);            
                    
                    //ADDR:3028 (HIGH; 17~32) DSP error code
                    inverter[invNo].inverter_status[1] = 0;              
                    //ADDR:3029 (LOW; 1~16) DSP error code
                    inverter[invNo].inverter_status[2] = 0;             
                    //ADDR:3027, DSP alarm code 
                    inverter[invNo].inverter_status[3] = 0;             
                
                	inverter[invNo].solar_cell_voltage  /= 10;
					inverter[invNo].solar_cell_current  /= 10;            
                	inverter[invNo].inv_u_voltage     /= 10; 
                	inverter[invNo].inv_v_voltage     /= 10; 
                	inverter[invNo].inv_w_voltage     /= 10;
                    inverter[invNo].inv_u_current      /= 10;
                	inverter[invNo].inv_v_current      /= 10;
                	inverter[invNo].inv_w_current      /= 10;
                	//inverter[invNo].power_inv_day_total /= 10;
					inverter[invNo].inv_frequency      /= 10;   
                    inverter[invNo].power_inv_pf		/= 10;
                	inverter[invNo].power_solar         /= 100;
                	inverter[invNo].power_inv_now		/= 100;  
                    inverter[invNo].power_inv_day_total /= 100;
                    inverter[invNo].power_inv_total     /= 100;
                    
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
