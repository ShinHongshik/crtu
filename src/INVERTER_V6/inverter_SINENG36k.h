//32000독립형, 32002작동 상태 
//32016(V1) ~ 32027(A6)
//32064(DCKW) ~ 32089(기계)
//32106(total) ~ 32114(day) 
//01 03 75 77 00 01 2E 1C -> dc 갯수 확인

void sendInverterRead_SINENG36k(void) {  
    unsigned int retVal;
    char sendBuff[10];   
    
    switch(inverter_seq) {
		
        case 0:
            inverter_seq++;
			if (sendInverterCount[0] < 100) {
            	sendInverterCount[0]++;
            }
            break;
			
        case 1:  //01 03 7D 00 00 01 9C 66 //01 03 7D 00 00 1C 5C 6F

            inverter_address = 1;     
			rx_seq0 = 0; 
            
			sendBuff[0] = inverter_address;	//Slave Number
			sendBuff[1] = 0x03;	//Function Code
            sendBuff[2] = 0x04; //Modbus Address High
            sendBuff[3] = 0x1A; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x18; //Data Count Low
    		retVal = calcCRC(sendBuff,6);         
                        
            putchar0(sendBuff[1]); 
            putchar0(sendBuff[2]); //Modbus Address High
            putchar0(sendBuff[3]); //Modbus Address Low
            putchar0(sendBuff[4]); //Data Count High
            putchar0(sendBuff[5]); //Data Count Low           
		    putchar0(retVal % 0x100);   //2a.73
    		putchar0(retVal / 0x100);
       
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
	
        case 2:  //check //01 03 7D 40 00 1A DD B9
		
			rx_seq0 = 0; 
            
			sendBuff[0] = inverter_address;	//Slave Number
			sendBuff[1] = 0x03;	//Function Code
            sendBuff[2] = 0x04; //Modbus Address High
            sendBuff[3] = 0x4C; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x04; //Data Count Low
    		retVal = calcCRC(sendBuff,6);         
                        
            putchar0(sendBuff[1]); 
            putchar0(sendBuff[2]); //Modbus Address High
            putchar0(sendBuff[3]); //Modbus Address Low
            putchar0(sendBuff[4]); //Data Count High
            putchar0(sendBuff[5]); //Data Count Low           
		    putchar0(retVal % 0x100);   //2a.73
    		putchar0(retVal / 0x100);
       
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
		
        case 3: //01 03 7D 6A 00 0A FD BD
		
			rx_seq0 = 0; 
            
			sendBuff[0] = inverter_address;	//Slave Number
			sendBuff[1] = 0x03;	//Function Code
            sendBuff[2] = 0x07; //Modbus Address High
            sendBuff[3] = 0xEE; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x03; //Data Count Low
    		retVal = calcCRC(sendBuff,6);         
                        
            putchar0(sendBuff[1]); 
            putchar0(sendBuff[2]); //Modbus Address High
            putchar0(sendBuff[3]); //Modbus Address Low
            putchar0(sendBuff[4]); //Data Count High
            putchar0(sendBuff[5]); //Data Count Low           
		    putchar0(retVal % 0x100);   //2a.73
    		putchar0(retVal / 0x100);
       
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
            sendBuff[2] = 0x04; //Modbus Address High
            sendBuff[3] = 0x1A; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x18; //Data Count Low
    		retVal = calcCRC(sendBuff,6);         
                        
            putchar0(sendBuff[1]); 
            putchar0(sendBuff[2]); //Modbus Address High
            putchar0(sendBuff[3]); //Modbus Address Low
            putchar0(sendBuff[4]); //Data Count High
            putchar0(sendBuff[5]); //Data Count Low           
		    putchar0(retVal % 0x100);   //2a.73
    		putchar0(retVal / 0x100);
       
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

        case 7:  //check
			rx_seq0 = 0; 
            
			sendBuff[0] = inverter_address;	//Slave Number
			sendBuff[1] = 0x03;	//Function Code
            sendBuff[2] = 0x04; //Modbus Address High
            sendBuff[3] = 0x4C; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x04; //Data Count Low
    		retVal = calcCRC(sendBuff,6);         
                        
            putchar0(sendBuff[1]); 
            putchar0(sendBuff[2]); //Modbus Address High
            putchar0(sendBuff[3]); //Modbus Address Low
            putchar0(sendBuff[4]); //Data Count High
            putchar0(sendBuff[5]); //Data Count Low           
		    putchar0(retVal % 0x100);   //2a.73
    		putchar0(retVal / 0x100);
       
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
			
        case 8: 

            rx_seq0 = 0; 
            
			sendBuff[0] = inverter_address;	//Slave Number
			sendBuff[1] = 0x03;	//Function Code
            sendBuff[2] = 0x07; //Modbus Address High
            sendBuff[3] = 0xEE; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x03; //Data Count Low
    		retVal = calcCRC(sendBuff,6);         
                        
            putchar0(sendBuff[1]); 
            putchar0(sendBuff[2]); //Modbus Address High
            putchar0(sendBuff[3]); //Modbus Address Low
            putchar0(sendBuff[4]); //Data Count High
            putchar0(sendBuff[5]); //Data Count Low           
		    putchar0(retVal % 0x100);   //2a.73
    		putchar0(retVal / 0x100);
       
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
		
		case 9: 
        	inverter_seq = 5; 
            break;

        default:  
            inverter_seq = 0;
            break;
    }
}



void rx0Control_SINENG36k(void) {   
	char rxdata;   
    unsigned int calCrc,rxCrc,offset;
	unsigned long int tempValue;

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
            if (rxdata == 0x30) {   
            	dcnt = 0;
                rxbuff[rcnt++] = rxdata;
				offset=0x2E;
                rx_seq0++;
            } 
			else if (rxdata == 0x08) {   
            	dcnt = 0;
                rxbuff[rcnt++] = rxdata;
				offset=0x08;
                rx_seq0=13;
            } 
			else if (rxdata == 0x06) {   
            	dcnt = 0;
                rxbuff[rcnt++] = rxdata;
				offset=0x06;
                rx_seq0=23;
            } 
			else {
                rx_seq0 = 0;
            }                     
            break;
			
		case 3:
            rxbuff[rcnt++] = rxdata;
            dcnt++;
            if (dcnt == (0x30+2)) {
  
            	calCrc = calcCRC(rxbuff,(0x30+3));   
                rxCrc = rxbuff[0x30+4];
                rxCrc <<= 8;
                rxCrc += rxbuff[0x30+3];  

                if (rxCrc == calCrc) {
                    //invNo = 0;
                    invNo = rxbuff[0] - 1;
                    
                    
					inverter[invNo].power_inv_now       = Bytes_to_Uint(rxbuff[3],rxbuff[4])/10;
					
					inverter[invNo].power_inv_pf        = 950;//Bytes_to_Uint(rxbuff[7],rxbuff[9]);
					
					inverter[invNo].inv_u_voltage     = Bytes_to_Uint(rxbuff[9],rxbuff[10])/10; 
                	inverter[invNo].inv_v_voltage     = Bytes_to_Uint(rxbuff[11],rxbuff[12])/10; 
                	inverter[invNo].inv_w_voltage     = Bytes_to_Uint(rxbuff[13],rxbuff[14])/10;
					
					inverter[invNo].inv_frequency       = Bytes_to_Uint(rxbuff[15],rxbuff[16])/100;
					
					inverter[invNo].inv_u_current      = Bytes_to_Uint(rxbuff[17],rxbuff[18])/100;
                	inverter[invNo].inv_v_current      = Bytes_to_Uint(rxbuff[19],rxbuff[20])/100;
                	inverter[invNo].inv_w_current      = Bytes_to_Uint(rxbuff[21],rxbuff[22])/100;
                	
                    
                    if(modelInverter == MODEL_INVERTER_SINENG36K){
                        tempValue =	Bytes_to_Uint(rxbuff[23],rxbuff[24]) + Bytes_to_Uint(rxbuff[25],rxbuff[26]) + Bytes_to_Uint(rxbuff[27],rxbuff[28]) + Bytes_to_Uint(rxbuff[29],rxbuff[30]) + Bytes_to_Uint(rxbuff[31],rxbuff[32]) + Bytes_to_Uint(rxbuff[33],rxbuff[34]) + Bytes_to_Uint(rxbuff[35],rxbuff[36]) + Bytes_to_Uint(rxbuff[37],rxbuff[38]);				
    					
                        inverter[invNo].solar_cell_current = tempValue/10;
    					
                        inverter[invNo].power_solar         = Bytes_to_Uint(rxbuff[39],rxbuff[40])/10;
    					
                        inverter[invNo].solar_cell_voltage  = Bytes_to_Uint(rxbuff[41],rxbuff[42]);
					}
                    
                    
                               
                	else if(modelInverter == MODEL_INVERTER_SINENG50K){
                        tempValue =	Bytes_to_Uint(rxbuff[23],rxbuff[24]) + Bytes_to_Uint(rxbuff[25],rxbuff[26]) + Bytes_to_Uint(rxbuff[27],rxbuff[28]) + Bytes_to_Uint(rxbuff[29],rxbuff[30]) + Bytes_to_Uint(rxbuff[31],rxbuff[32]) + Bytes_to_Uint(rxbuff[33],rxbuff[34]) + Bytes_to_Uint(rxbuff[35],rxbuff[36]) + Bytes_to_Uint(rxbuff[37],rxbuff[38]) + Bytes_to_Uint(rxbuff[39],rxbuff[40]) + Bytes_to_Uint(rxbuff[41],rxbuff[42]) + Bytes_to_Uint(rxbuff[43],rxbuff[44]) + Bytes_to_Uint(rxbuff[45],rxbuff[46]);				
					
					    inverter[invNo].solar_cell_current = tempValue/10;
					
					    inverter[invNo].power_solar         = Bytes_to_Uint(rxbuff[47],rxbuff[48])/10;
					
                	    inverter[invNo].solar_cell_voltage  = Bytes_to_Uint(rxbuff[49],rxbuff[50]); 
                    }
                     
                	
                    
                    
                    
                    
	                sendInverterCount[invNo] = 0;
					buzzer_flag |= BUZZER_TIC;
	                sprintf(str,"RX%02d",invNo+1);
    	            put_str(4,16,str,1);   
        	        rx_led_delay = 2500;
                }
            	rx_seq0 = 0;
            }
            break;
			
		case 13:
            rxbuff[rcnt++] = rxdata;
            dcnt++;
            if (dcnt == (0x08+2)) {
 
            	calCrc = calcCRC(rxbuff,(0x08+3));   
                rxCrc = rxbuff[0x08+4];
                rxCrc <<= 8;
                rxCrc += rxbuff[0x08+3];  

                if (rxCrc == calCrc) {
                    //invNo = 0;

                    invNo = rxbuff[0] - 1;
					
					inverter[invNo].power_inv_day_total = Bytes_to_Uint(rxbuff[3],rxbuff[4])/10;
					
					tempValue = Bytes_to_Uint(rxbuff[5],rxbuff[6]);
					tempValue <<= 16;
					tempValue += Bytes_to_Uint(rxbuff[7],rxbuff[8]);
					
                    inverter[invNo].power_inv_total = tempValue; 

	                sendInverterCount[invNo] = 0;
					buzzer_flag |= BUZZER_TIC;
	                sprintf(str,"RX%02d",invNo+1);
    	            put_str(4,16,str,1);   
        	        rx_led_delay = 2500;
                }
            	rx_seq0 = 0;
            }
            break;
			
		case 23:
            rxbuff[rcnt++] = rxdata;
            dcnt++;
            if (dcnt == (0x06+2)) {
 
            	calCrc = calcCRC(rxbuff,(0x06+3));   
                rxCrc = rxbuff[0x06+4];
                rxCrc <<= 8;
                rxCrc += rxbuff[0x06+3];  

                if (rxCrc == calCrc) {
                    //invNo = 0;

                    invNo = rxbuff[0] - 1;
					
					inverter[invNo].inverter_status[0] = Bytes_to_Uint(rxbuff[3],rxbuff[4]); 
					inverter[invNo].inverter_status[1] = Bytes_to_Uint(rxbuff[5],rxbuff[6]);
					inverter[invNo].inverter_status[2] = Bytes_to_Uint(rxbuff[7],rxbuff[8]);
                    inverter[invNo].inverter_status[2] = 0;
                    
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
