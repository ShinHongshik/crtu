void sendInverterRead_KSTAR50K(void) {  
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
            sendBuff[2] = 0x0b; //Modbus Address High (dec:3000, hex:bb8)
            sendBuff[3] = 0xb8; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x30; //Data Count Low (48)
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
        	//ADDR 04 13 87 00 55 CC CC => 01 04 aa ff ff ff ff .......
            //putchar0(0x01); //Slave Address
			rx_seq0 = 0; 
            
			sendBuff[0] = inverter_address;	//Slave Number
			sendBuff[1] = 0x04;	//Function Code
            sendBuff[2] = 0x0b; //Modbus Address High
            sendBuff[3] = 0xb8; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x30; //Data Count Low (29)
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



void rx0Control_KSTAR50K(void) {   
	char rxdata;   
    unsigned int calCrc,rxCrc;
    //sLong slong1,slong2,slong3;
    //uLong ulong;          

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
            if (rxdata == 0x60) {   
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
            if (dcnt == (0x60+2)) {
            //if (1) {	//CRC-16 Check
            //if (rxCount1 == (rx1RetCount[rxbuff1[0]]*2+5)) {   
            	calCrc = calcCRC(rxbuff,(0x60+3));   
                rxCrc = rxbuff[0x60+4];
                rxCrc <<= 8;
                rxCrc += rxbuff[0x60+3];  
//sprintf(str,"%04X %04X ", calCrc, rxCrc);
//put_str(0,0,str,1);

                if (rxCrc == calCrc) {
                    //invNo = 0;
                    invNo = rxbuff[0] - 1;
                                                          
                                    
                    //ADDR:3030, Operating mode of the inverter
                    inverter[invNo].inverter_status[0] = Bytes_to_Uint(rxbuff[63],rxbuff[64]);            
                    //ADDR:3028 (HIGH; 17~32) DSP error code
                    inverter[invNo].inverter_status[1] = Bytes_to_Uint(rxbuff[59],rxbuff[60]);              
                    //ADDR:3029 (LOW; 1~16) DSP error code
                    inverter[invNo].inverter_status[2] = Bytes_to_Uint(rxbuff[61],rxbuff[62]);             
                    //ADDR:3027, DSP alarm code 
                    inverter[invNo].inverter_status[3] = Bytes_to_Uint(rxbuff[57],rxbuff[58]);                      
                    
                    inverter[invNo].solar_cell_voltage = Bytes_to_Uint(rxbuff[3],rxbuff[4]);
                	//inverter[invNo].solar_cell_voltage  = Bytes_to_Uint(rxbuff[25],rxbuff[26]);
					inverter[invNo].solar_cell_current  = Bytes_to_Uint(rxbuff[9],rxbuff[10]) + Bytes_to_Uint(rxbuff[11],rxbuff[12]) + Bytes_to_Uint(rxbuff[13],rxbuff[14]);            
                	//inverter[invNo].power_solar         = Bytes_to_Uint(rxbuff[37],rxbuff[38]);
                    slong1.cc[3] = rxbuff[15];  
                    slong1.cc[2] = rxbuff[16];  
                    slong1.cc[1] = rxbuff[17];  
                    slong1.cc[0] = rxbuff[18];
                    if (slong1.ff < 0) slong1.ff = 0;  
                    slong2.cc[3] = rxbuff[19];  
                    slong2.cc[2] = rxbuff[20];  
                    slong2.cc[1] = rxbuff[21];  
                    slong2.cc[0] = rxbuff[22];
                    if (slong2.ff < 0) slong2.ff = 0;  
                    slong3.cc[3] = rxbuff[23];  
                    slong3.cc[2] = rxbuff[24];  
                    slong3.cc[1] = rxbuff[25];  
                    slong3.cc[0] = rxbuff[26];
                    if (slong3.ff < 0) slong3.ff = 0;  
                    inverter[invNo].power_solar = (slong1.ff + slong2.ff + slong3.ff) / 100;
                    
                	inverter[invNo].inv_u_voltage		= Bytes_to_Uint(rxbuff[31],rxbuff[32]); 
                	inverter[invNo].inv_v_voltage		= Bytes_to_Uint(rxbuff[33],rxbuff[34]); 
                	inverter[invNo].inv_w_voltage		= Bytes_to_Uint(rxbuff[35],rxbuff[36]); 
                    inverter[invNo].inv_frequency       = Bytes_to_Uint(rxbuff[37],rxbuff[38]);
                    inverter[invNo].inv_u_current		= Bytes_to_Uint(rxbuff[43],rxbuff[44]);
                	inverter[invNo].inv_v_current		= Bytes_to_Uint(rxbuff[45],rxbuff[46]);
                	inverter[invNo].inv_w_current		= Bytes_to_Uint(rxbuff[47],rxbuff[48]);
                    slong1.cc[3] = rxbuff[49]; 
                    slong1.cc[2] = rxbuff[50]; 
                    slong1.cc[1] = rxbuff[51]; 
                    slong1.cc[0] = rxbuff[52];
                    if (slong1.ff < 0) slong1.ff = 0; 
                	inverter[invNo].power_inv_now		= slong1.ff / 100;  
                    inverter[invNo].power_inv_pf        = 95;//Bytes_to_Uint(rxbuff[73],rxbuff[74]);
                	//inverter[invNo].power_inv_max       = Bytes_to_Uint(rxbuff[27],rxbuff[28]);
                	inverter[invNo].power_inv_day_total = Bytes_to_Uint(rxbuff[87],rxbuff[88]);  
                    
                    uLong.cc[3] = rxbuff[79];
                    uLong.cc[2] = rxbuff[80];
                    uLong.cc[1] = rxbuff[81];
                    uLong.cc[0] = rxbuff[82];
                    if ( (uLong.ff > 100) && (inverter[invNo].inverter_status[0] > 0) )  {         
                		inverter[invNo].power_inv_total     = uLong.ff;
	                    inverter[invNo].power_inv_total /= 10;
                    }
                                                                     
                	inverter[invNo].solar_cell_voltage  /= 10;
					inverter[invNo].solar_cell_current  /= 100;            
                	inverter[invNo].inv_u_voltage     /= 10; 
                	inverter[invNo].inv_v_voltage     /= 10; 
                	inverter[invNo].inv_w_voltage     /= 10;
                    inverter[invNo].inv_u_current      /= 100;
                	inverter[invNo].inv_v_current      /= 100;
                	inverter[invNo].inv_w_current      /= 100;
                	//inverter[invNo].power_inv_day_total /= 10;
					inverter[invNo].inv_frequency      /= 10; 
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
