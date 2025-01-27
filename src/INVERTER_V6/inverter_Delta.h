void sendInverterRead_Delta(void) {  
    unsigned int retVal;
    char sendBuff[10];   
    
    switch(inverter_seq) {
        case 0:
            inverter_seq++;
			if (sendInverterCount[0] < 100) {
            	sendInverterCount[0]++;
            }
            break;     
        case 1:     //Inv-1
			rx_seq0 = 0; 
			//INVERTER-STATUS
            invCommand = 0x0417;
			
			sendBuff[0] = 0x01;	//Slave Number
			sendBuff[1] = 0x04;	//Function Code
            sendBuff[2] = 0x04; //Modbus Address High
            sendBuff[3] = 0x17; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x01; //Data Count Low (29)
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
			write_dudr ( 0, 0x01);  
#else  
			UDR0 = 0x01 ;  
#endif        
            sprintf(str,"TX-1");     
            put_str(4,16,str,1);   
            rx_led_delay = 2500;
            inverter_seq++;             
            break;         
        case 2:
			rx_seq0 = 0; 
			//AC-INFO (ACV,ACA,ACKW,FREQ)
            invCommand = 0xBFFF;
			
			sendBuff[0] = 0x01;	//Slave Number
			sendBuff[1] = 0x04;	//Function Code
            sendBuff[2] = 0xBF; //Modbus Address High
            sendBuff[3] = 0xFF; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x0D; //Data Count Low (29)
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
			write_dudr ( 0, 0x01);  
#else  
			UDR0 = 0x01 ;  
#endif        
            inverter_seq++;             
            break;         
        case 3:
			rx_seq0 = 0; 
			//DC-INFO (DCV,DCA,DCKW)
            invCommand = 0xAFFF;
			
			sendBuff[0] = 0x01;	//Slave Number
			sendBuff[1] = 0x04;	//Function Code
            sendBuff[2] = 0xAF; //Modbus Address High
            sendBuff[3] = 0xFF; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x13; //Data Count Low (29)
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
			write_dudr ( 0, 0x01);  
#else  
			UDR0 = 0x01 ;  
#endif        
            inverter_seq++;             
            break;         
        case 4:
			rx_seq0 = 0; 
			// Current even - Fault 0-2
            invCommand = 0x0C1F;
			
			sendBuff[0] = 0x01;	//Slave Number
			sendBuff[1] = 0x04;	//Function Code
            sendBuff[2] = 0x0C; //Modbus Address High
            sendBuff[3] = 0x1F; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x03; //Data Count Low (29)
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
			write_dudr ( 0, 0x01);  
#else  
			UDR0 = 0x01 ;  
#endif        
            inverter_seq++;             
            break;         
        case 5:
			rx_seq0 = 0; 
			// Current even - Fault 0-2
            invCommand = 0x0437;
			
			sendBuff[0] = 0x01;	//Slave Number
			sendBuff[1] = 0x04;	//Function Code
            sendBuff[2] = 0x04; //Modbus Address High
            sendBuff[3] = 0x37; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x01; //Data Count Low (29)
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
			write_dudr ( 0, 0x01);  
#else  
			UDR0 = 0x01 ;  
#endif        
            inverter_seq++;             
            break;         
        case 6:
			rx_seq0 = 0; 
			// Current even - Fault 0-2
            invCommand = 0xCFFF;
			
			sendBuff[0] = 0x01;	//Slave Number
			sendBuff[1] = 0x04;	//Function Code
            sendBuff[2] = 0xCF; //Modbus Address High
            sendBuff[3] = 0xFF; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x06; //Data Count Low (29)
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
			write_dudr ( 0, 0x01);  
#else  
			UDR0 = 0x01 ;  
#endif        
            inverter_seq++;             
            break;         
        case 7:
        case 8:
        case 9:
        	inverter_seq++;
            break;

        case 10:           
        	if (eeInverterCount > 1) { 
                if (sendInverterCount[1] < 100) {
                    sendInverterCount[1]++;
                }            
            	inverter_seq++;
        	} else {
				inverter_seq = 0;            	
            }
            break;    
        case 11:     //Inv-2
			rx_seq0 = 0; 
			//INVERTER-STATUS
            invCommand = 0x0417;
			
			sendBuff[0] = 0x02;	//Slave Number
			sendBuff[1] = 0x04;	//Function Code
            sendBuff[2] = 0x04; //Modbus Address High
            sendBuff[3] = 0x17; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x01; //Data Count Low (29)
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
			write_dudr ( 0, 0x02);  
#else  
			UDR0 = 0x02 ;  
#endif        
            sprintf(str,"TX-2");     
            put_str(4,16,str,1);   
            rx_led_delay = 2500;
            inverter_seq++;             
            break;         
        case 12:
			rx_seq0 = 0; 
			//AC-INFO (ACV,ACA,ACKW,FREQ)
            invCommand = 0xBFFF;
			
			sendBuff[0] = 0x02;	//Slave Number
			sendBuff[1] = 0x04;	//Function Code
            sendBuff[2] = 0xBF; //Modbus Address High
            sendBuff[3] = 0xFF; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x0D; //Data Count Low (29)
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
			write_dudr ( 0, 0x02);  
#else  
			UDR0 = 0x02 ;  
#endif        
            inverter_seq++;             
            break;         
        case 13:
			rx_seq0 = 0; 
			//DC-INFO (DCV,DCA,DCKW)
            invCommand = 0xAFFF;
			
			sendBuff[0] = 0x02;	//Slave Number
			sendBuff[1] = 0x04;	//Function Code
            sendBuff[2] = 0xAF; //Modbus Address High
            sendBuff[3] = 0xFF; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x13; //Data Count Low (29)
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
			write_dudr ( 0, 0x02);  
#else  
			UDR0 = 0x02 ;  
#endif        
            inverter_seq++;             
            break;         
        case 14:
			rx_seq0 = 0; 
			// Current even - Fault 0-2
            invCommand = 0x0C1F;
			
			sendBuff[0] = 0x02;	//Slave Number
			sendBuff[1] = 0x04;	//Function Code
            sendBuff[2] = 0x0C; //Modbus Address High
            sendBuff[3] = 0x1F; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x03; //Data Count Low (29)
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
			write_dudr ( 0, 0x02);  
#else  
			UDR0 = 0x02 ;  
#endif        
            inverter_seq++;             
            break;         
        case 15:
			rx_seq0 = 0; 
			// Current even - Fault 0-2
            invCommand = 0x0437;
			
			sendBuff[0] = 0x02;	//Slave Number
			sendBuff[1] = 0x04;	//Function Code
            sendBuff[2] = 0x04; //Modbus Address High
            sendBuff[3] = 0x37; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x01; //Data Count Low (29)
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
			write_dudr ( 0, 0x02);  
#else  
			UDR0 = 0x02 ;  
#endif        
            inverter_seq++;             
            break;         
        case 16:
			rx_seq0 = 0; 
			// Current even - Fault 0-2
            invCommand = 0xCFFF;
			
			sendBuff[0] = 0x02;	//Slave Number
			sendBuff[1] = 0x04;	//Function Code
            sendBuff[2] = 0xCF; //Modbus Address High
            sendBuff[3] = 0xFF; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x06; //Data Count Low (29)
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
			write_dudr ( 0, 0x02);  
#else  
			UDR0 = 0x02 ;  
#endif        
            inverter_seq++;             
            break;         
        case 17:
        case 18:
        case 19:
            inverter_seq++;
            break;     

        case 20:           
        	if (eeInverterCount > 2) { 
                if (sendInverterCount[2] < 100) {
                    sendInverterCount[2]++;
                }            
            	inverter_seq++;
        	} else {
				inverter_seq = 0;            	
            }
            break; 
        case 21:     //Inv-3
			rx_seq0 = 0; 
			//INVERTER-STATUS
            invCommand = 0x0417;
			
			sendBuff[0] = 0x03;	//Slave Number
			sendBuff[1] = 0x04;	//Function Code
            sendBuff[2] = 0x04; //Modbus Address High
            sendBuff[3] = 0x17; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x01; //Data Count Low (29)
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
			write_dudr ( 0, 0x03);  
#else  
			UDR0 = 0x03 ;  
#endif        
            sprintf(str,"TX-3");     
            put_str(4,16,str,1);   
            rx_led_delay = 2500;
            inverter_seq++;             
            break;         
        case 22:
			rx_seq0 = 0; 
			//AC-INFO (ACV,ACA,ACKW,FREQ)
            invCommand = 0xBFFF;
			
			sendBuff[0] = 0x03;	//Slave Number
			sendBuff[1] = 0x04;	//Function Code
            sendBuff[2] = 0xBF; //Modbus Address High
            sendBuff[3] = 0xFF; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x0D; //Data Count Low (29)
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
			write_dudr ( 0, 0x03);  
#else  
			UDR0 = 0x03 ;  
#endif        
            inverter_seq++;             
            break;         
        case 23:
			rx_seq0 = 0; 
			//DC-INFO (DCV,DCA,DCKW)
            invCommand = 0xAFFF;
			
			sendBuff[0] = 0x03;	//Slave Number
			sendBuff[1] = 0x04;	//Function Code
            sendBuff[2] = 0xAF; //Modbus Address High
            sendBuff[3] = 0xFF; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x13; //Data Count Low (29)
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
			write_dudr ( 0, 0x03);  
#else  
			UDR0 = 0x03 ;  
#endif        
            inverter_seq++;             
            break;         
        case 24:
			rx_seq0 = 0; 
			// Current even - Fault 0-2
            invCommand = 0x0C1F;
			
			sendBuff[0] = 0x03;	//Slave Number
			sendBuff[1] = 0x04;	//Function Code
            sendBuff[2] = 0x0C; //Modbus Address High
            sendBuff[3] = 0x1F; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x03; //Data Count Low (29)
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
			write_dudr ( 0, 0x03);  
#else  
			UDR0 = 0x03 ;  
#endif        
            inverter_seq++;             
            break;         
        case 25:
			rx_seq0 = 0; 
			// Current even - Fault 0-2
            invCommand = 0x0437;
			
			sendBuff[0] = 0x03;	//Slave Number
			sendBuff[1] = 0x04;	//Function Code
            sendBuff[2] = 0x04; //Modbus Address High
            sendBuff[3] = 0x37; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x01; //Data Count Low (29)
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
			write_dudr ( 0, 0x03);  
#else  
			UDR0 = 0x03 ;  
#endif        
            inverter_seq++;             
            break;         
        case 26:
			rx_seq0 = 0; 
			// Current even - Fault 0-2
            invCommand = 0xCFFF;
			
			sendBuff[0] = 0x03;	//Slave Number
			sendBuff[1] = 0x04;	//Function Code
            sendBuff[2] = 0xCF; //Modbus Address High
            sendBuff[3] = 0xFF; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x06; //Data Count Low (29)
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
			write_dudr ( 0, 0x03);  
#else  
			UDR0 = 0x03 ;  
#endif        
            inverter_seq++;             
            break;         
        case 27:
        case 28:
        case 29:
            inverter_seq++;
            break;     

        case 30:           
        	if (eeInverterCount > 3) { 
                if (sendInverterCount[3] < 100) {
                    sendInverterCount[3]++;
                }            
            	inverter_seq++;
        	} else {
				inverter_seq = 0;            	
            }
            break;    
        case 31:     //Inv-4
			rx_seq0 = 0; 
			//INVERTER-STATUS
            invCommand = 0x0417;
			
			sendBuff[0] = 0x04;	//Slave Number
			sendBuff[1] = 0x04;	//Function Code
            sendBuff[2] = 0x04; //Modbus Address High
            sendBuff[3] = 0x17; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x01; //Data Count Low (29)
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
			write_dudr ( 0, 0x04);  
#else  
			UDR0 = 0x04 ;  
#endif        
            sprintf(str,"TX-4");     
            put_str(4,16,str,1);   
            rx_led_delay = 2500;
            inverter_seq++;             
            break;         
        case 32:
			rx_seq0 = 0; 
			//AC-INFO (ACV,ACA,ACKW,FREQ)
            invCommand = 0xBFFF;
			
			sendBuff[0] = 0x04;	//Slave Number
			sendBuff[1] = 0x04;	//Function Code
            sendBuff[2] = 0xBF; //Modbus Address High
            sendBuff[3] = 0xFF; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x0D; //Data Count Low (29)
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
			write_dudr ( 0, 0x04);  
#else  
			UDR0 = 0x04 ;  
#endif        
            inverter_seq++;             
            break;         
        case 33:
			rx_seq0 = 0; 
			//DC-INFO (DCV,DCA,DCKW)
            invCommand = 0xAFFF;
			
			sendBuff[0] = 0x04;	//Slave Number
			sendBuff[1] = 0x04;	//Function Code
            sendBuff[2] = 0xAF; //Modbus Address High
            sendBuff[3] = 0xFF; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x13; //Data Count Low (29)
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
			write_dudr ( 0, 0x04);  
#else  
			UDR0 = 0x04 ;  
#endif        
            inverter_seq++;             
            break;         
        case 34:
			rx_seq0 = 0; 
			// Current even - Fault 0-2
            invCommand = 0x0C1F;
			
			sendBuff[0] = 0x04;	//Slave Number
			sendBuff[1] = 0x04;	//Function Code
            sendBuff[2] = 0x0C; //Modbus Address High
            sendBuff[3] = 0x1F; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x03; //Data Count Low (29)
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
			write_dudr ( 0, 0x04);  
#else  
			UDR0 = 0x04 ;  
#endif        
            inverter_seq++;             
            break;         
        case 35:
			rx_seq0 = 0; 
			// Current even - Fault 0-2
            invCommand = 0x0437;
			
			sendBuff[0] = 0x04;	//Slave Number
			sendBuff[1] = 0x04;	//Function Code
            sendBuff[2] = 0x04; //Modbus Address High
            sendBuff[3] = 0x37; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x01; //Data Count Low (29)
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
			write_dudr ( 0, 0x04);  
#else  
			UDR0 = 0x04 ;  
#endif        
            inverter_seq++;             
            break;         
        case 36:
			rx_seq0 = 0; 
			// Current even - Fault 0-2
            invCommand = 0xCFFF;
			
			sendBuff[0] = 0x04;	//Slave Number
			sendBuff[1] = 0x04;	//Function Code
            sendBuff[2] = 0xCF; //Modbus Address High
            sendBuff[3] = 0xFF; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x06; //Data Count Low (29)
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
			write_dudr ( 0, 0x04);  
#else  
			UDR0 = 0x04 ;  
#endif        
            inverter_seq++;             
            break;         
        case 37:
        case 38:
        case 39:
            inverter_seq++;
            break;
                 
        case 40:           
        	if (eeInverterCount > 4) { 
                if (sendInverterCount[4] < 100) {
                    sendInverterCount[4]++;
                }            
            	inverter_seq++;
        	} else {
				inverter_seq = 0;            	
            }
            break;  
        case 41:     //Inv-5
			rx_seq0 = 0; 
			//INVERTER-STATUS
            invCommand = 0x0417;
			
			sendBuff[0] = 0x05;	//Slave Number
			sendBuff[1] = 0x04;	//Function Code
            sendBuff[2] = 0x04; //Modbus Address High
            sendBuff[3] = 0x17; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x01; //Data Count Low (29)
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
			write_dudr ( 0, 0x05);  
#else  
			UDR0 = 0x05 ;  
#endif        
            sprintf(str,"TX-5");     
            put_str(4,16,str,1);   
            rx_led_delay = 2500;
            inverter_seq++;             
            break;         
        case 42:
			rx_seq0 = 0; 
			//AC-INFO (ACV,ACA,ACKW,FREQ)
            invCommand = 0xBFFF;
			
			sendBuff[0] = 0x05;	//Slave Number
			sendBuff[1] = 0x04;	//Function Code
            sendBuff[2] = 0xBF; //Modbus Address High
            sendBuff[3] = 0xFF; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x0D; //Data Count Low (29)
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
			write_dudr ( 0, 0x05);  
#else  
			UDR0 = 0x05 ;  
#endif        
            inverter_seq++;             
            break;         
        case 43:
			rx_seq0 = 0; 
			//DC-INFO (DCV,DCA,DCKW)
            invCommand = 0xAFFF;
			
			sendBuff[0] = 0x05;	//Slave Number
			sendBuff[1] = 0x04;	//Function Code
            sendBuff[2] = 0xAF; //Modbus Address High
            sendBuff[3] = 0xFF; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x13; //Data Count Low (29)
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
			write_dudr ( 0, 0x05);  
#else  
			UDR0 = 0x05 ;  
#endif        
            inverter_seq++;             
            break;         
        case 44:
			rx_seq0 = 0; 
			// Current even - Fault 0-2
            invCommand = 0x0C1F;
			
			sendBuff[0] = 0x05;	//Slave Number
			sendBuff[1] = 0x04;	//Function Code
            sendBuff[2] = 0x0C; //Modbus Address High
            sendBuff[3] = 0x1F; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x03; //Data Count Low (29)
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
			write_dudr ( 0, 0x05);  
#else  
			UDR0 = 0x05 ;  
#endif        
            inverter_seq++;             
            break;         
        case 45:
			rx_seq0 = 0; 
			// Current even - Fault 0-2
            invCommand = 0x0437;
			
			sendBuff[0] = 0x05;	//Slave Number
			sendBuff[1] = 0x04;	//Function Code
            sendBuff[2] = 0x04; //Modbus Address High
            sendBuff[3] = 0x37; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x01; //Data Count Low (29)
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
			write_dudr ( 0, 0x05);  
#else  
			UDR0 = 0x05 ;  
#endif        
            inverter_seq++;             
            break;         
        case 46:
			rx_seq0 = 0; 
			// Current even - Fault 0-2
            invCommand = 0xCFFF;
			
			sendBuff[0] = 0x05;	//Slave Number
			sendBuff[1] = 0x04;	//Function Code
            sendBuff[2] = 0xCF; //Modbus Address High
            sendBuff[3] = 0xFF; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x06; //Data Count Low (29)
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
			write_dudr ( 0, 0x05);  
#else  
			UDR0 = 0x05 ;  
#endif        
            inverter_seq++;             
            break;         
        case 47:
        case 48:
        case 49:
            inverter_seq++;
            break;     

        case 50:           
        	if (eeInverterCount > 5) { 
                if (sendInverterCount[5] < 100) {
                    sendInverterCount[5]++;
                }            
            	inverter_seq++;
        	} else {
				inverter_seq = 0;            	
            }
            break;  
        case 51:     //Inv-6
			rx_seq0 = 0; 
			//INVERTER-STATUS
            invCommand = 0x0417;
			
			sendBuff[0] = 0x06;	//Slave Number
			sendBuff[1] = 0x04;	//Function Code
            sendBuff[2] = 0x04; //Modbus Address High
            sendBuff[3] = 0x17; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x01; //Data Count Low (29)
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
			write_dudr ( 0, 0x06);  
#else  
			UDR0 = 0x06 ;  
#endif        
            sprintf(str,"TX-6");     
            put_str(4,16,str,1);   
            rx_led_delay = 2500;
            inverter_seq++;             
            break;         
        case 52:
			rx_seq0 = 0; 
			//AC-INFO (ACV,ACA,ACKW,FREQ)
            invCommand = 0xBFFF;
			
			sendBuff[0] = 0x06;	//Slave Number
			sendBuff[1] = 0x04;	//Function Code
            sendBuff[2] = 0xBF; //Modbus Address High
            sendBuff[3] = 0xFF; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x0D; //Data Count Low (29)
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
			write_dudr ( 0, 0x06);  
#else  
			UDR0 = 0x06 ;  
#endif        
            inverter_seq++;             
            break;         
        case 53:
			rx_seq0 = 0; 
			//DC-INFO (DCV,DCA,DCKW)
            invCommand = 0xAFFF;
			
			sendBuff[0] = 0x06;	//Slave Number
			sendBuff[1] = 0x04;	//Function Code
            sendBuff[2] = 0xAF; //Modbus Address High
            sendBuff[3] = 0xFF; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x13; //Data Count Low (29)
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
			write_dudr ( 0, 0x06);  
#else  
			UDR0 = 0x06 ;  
#endif        
            inverter_seq++;             
            break;         
        case 54:
			rx_seq0 = 0; 
			// Current even - Fault 0-2
            invCommand = 0x0C1F;
			
			sendBuff[0] = 0x06;	//Slave Number
			sendBuff[1] = 0x04;	//Function Code
            sendBuff[2] = 0x0C; //Modbus Address High
            sendBuff[3] = 0x1F; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x03; //Data Count Low (29)
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
			write_dudr ( 0, 0x06);  
#else  
			UDR0 = 0x06 ;  
#endif        
            inverter_seq++;             
            break;         
        case 55:
			rx_seq0 = 0; 
			// Current even - Fault 0-2
            invCommand = 0x0437;
			
			sendBuff[0] = 0x06;	//Slave Number
			sendBuff[1] = 0x04;	//Function Code
            sendBuff[2] = 0x04; //Modbus Address High
            sendBuff[3] = 0x37; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x01; //Data Count Low (29)
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
			write_dudr ( 0, 0x06);  
#else  
			UDR0 = 0x06 ;  
#endif        
            inverter_seq++;             
            break;         
        case 56:
			rx_seq0 = 0; 
			// Current even - Fault 0-2
            invCommand = 0xCFFF;
			
			sendBuff[0] = 0x06;	//Slave Number
			sendBuff[1] = 0x04;	//Function Code
            sendBuff[2] = 0xCF; //Modbus Address High
            sendBuff[3] = 0xFF; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x06; //Data Count Low (29)
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
			write_dudr ( 0, 0x06);  
#else  
			UDR0 = 0x06 ;  
#endif        
            inverter_seq++;             
            break;         
        case 57:
        case 58:
        case 59:
            inverter_seq++;
            break;     

        case 60:           
        	if (eeInverterCount > 6) { 
                if (sendInverterCount[6] < 100) {
                    sendInverterCount[6]++;
                }            
            	inverter_seq++;
        	} else {
				inverter_seq = 0;            	
            }
            break;     
        case 61:     //Inv-7
			rx_seq0 = 0; 
			//INVERTER-STATUS
            invCommand = 0x0417;
			
			sendBuff[0] = 0x07;	//Slave Number
			sendBuff[1] = 0x04;	//Function Code
            sendBuff[2] = 0x04; //Modbus Address High
            sendBuff[3] = 0x17; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x01; //Data Count Low (29)
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
			write_dudr ( 0, 0x07);  
#else  
			UDR0 = 0x07 ;  
#endif        
            sprintf(str,"TX-7");     
            put_str(4,16,str,1);   
            rx_led_delay = 2500;
            inverter_seq++;             
            break;         
        case 62:
			rx_seq0 = 0; 
			//AC-INFO (ACV,ACA,ACKW,FREQ)
            invCommand = 0xBFFF;
			
			sendBuff[0] = 0x07;	//Slave Number
			sendBuff[1] = 0x04;	//Function Code
            sendBuff[2] = 0xBF; //Modbus Address High
            sendBuff[3] = 0xFF; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x0D; //Data Count Low (29)
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
			write_dudr ( 0, 0x07);  
#else  
			UDR0 = 0x07 ;  
#endif        
            inverter_seq++;             
            break;         
        case 63:
			rx_seq0 = 0; 
			//DC-INFO (DCV,DCA,DCKW)
            invCommand = 0xAFFF;
			
			sendBuff[0] = 0x07;	//Slave Number
			sendBuff[1] = 0x04;	//Function Code
            sendBuff[2] = 0xAF; //Modbus Address High
            sendBuff[3] = 0xFF; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x13; //Data Count Low (29)
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
			write_dudr ( 0, 0x07);  
#else  
			UDR0 = 0x07 ;  
#endif        
            inverter_seq++;             
            break;         
        case 64:
			rx_seq0 = 0; 
			// Current even - Fault 0-2
            invCommand = 0x0C1F;
			
			sendBuff[0] = 0x07;	//Slave Number
			sendBuff[1] = 0x04;	//Function Code
            sendBuff[2] = 0x0C; //Modbus Address High
            sendBuff[3] = 0x1F; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x03; //Data Count Low (29)
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
			write_dudr ( 0, 0x07);  
#else  
			UDR0 = 0x07 ;  
#endif        
            inverter_seq++;             
            break;         
        case 65:
			rx_seq0 = 0; 
			// Current even - Fault 0-2
            invCommand = 0x0437;
			
			sendBuff[0] = 0x07;	//Slave Number
			sendBuff[1] = 0x04;	//Function Code
            sendBuff[2] = 0x04; //Modbus Address High
            sendBuff[3] = 0x37; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x01; //Data Count Low (29)
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
			write_dudr ( 0, 0x07);  
#else  
			UDR0 = 0x07 ;  
#endif        
            inverter_seq++;             
            break;         
        case 66:
			rx_seq0 = 0; 
			// Current even - Fault 0-2
            invCommand = 0xCFFF;
			
			sendBuff[0] = 0x07;	//Slave Number
			sendBuff[1] = 0x04;	//Function Code
            sendBuff[2] = 0xCF; //Modbus Address High
            sendBuff[3] = 0xFF; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x06; //Data Count Low (29)
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
			write_dudr ( 0, 0x07);  
#else  
			UDR0 = 0x07 ;  
#endif        
            inverter_seq++;             
            break;         
        case 67:
        case 68:
        case 69:
            inverter_seq++;
            break;     

        case 70:           
        	if (eeInverterCount > 7) { 
                if (sendInverterCount[7] < 100) {
                    sendInverterCount[7]++;
                }            
            	inverter_seq++;
        	} else {
				inverter_seq = 0;            	
            }
            break;   
        case 71:     //Inv-8
			rx_seq0 = 0; 
			//INVERTER-STATUS
            invCommand = 0x0417;
			
			sendBuff[0] = 0x08;	//Slave Number
			sendBuff[1] = 0x04;	//Function Code
            sendBuff[2] = 0x04; //Modbus Address High
            sendBuff[3] = 0x17; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x01; //Data Count Low (29)
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
			write_dudr ( 0, 0x08);  
#else  
			UDR0 = 0x08 ;  
#endif        
            sprintf(str,"TX-8");     
            put_str(4,16,str,1);   
            rx_led_delay = 2500;
            inverter_seq++;             
            break;         
        case 72:
			rx_seq0 = 0; 
			//AC-INFO (ACV,ACA,ACKW,FREQ)
            invCommand = 0xBFFF;
			
			sendBuff[0] = 0x08;	//Slave Number
			sendBuff[1] = 0x04;	//Function Code
            sendBuff[2] = 0xBF; //Modbus Address High
            sendBuff[3] = 0xFF; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x0D; //Data Count Low (29)
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
			write_dudr ( 0, 0x08);  
#else  
			UDR0 = 0x08 ;  
#endif        
            inverter_seq++;             
            break;         
        case 73:
			rx_seq0 = 0; 
			//DC-INFO (DCV,DCA,DCKW)
            invCommand = 0xAFFF;
			
			sendBuff[0] = 0x08;	//Slave Number
			sendBuff[1] = 0x04;	//Function Code
            sendBuff[2] = 0xAF; //Modbus Address High
            sendBuff[3] = 0xFF; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x13; //Data Count Low (29)
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
			write_dudr ( 0, 0x08);  
#else  
			UDR0 = 0x08 ;  
#endif        
            inverter_seq++;             
            break;         
        case 74:
			rx_seq0 = 0; 
			// Current even - Fault 0-2
            invCommand = 0x0C1F;
			
			sendBuff[0] = 0x08;	//Slave Number
			sendBuff[1] = 0x04;	//Function Code
            sendBuff[2] = 0x0C; //Modbus Address High
            sendBuff[3] = 0x1F; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x03; //Data Count Low (29)
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
			write_dudr ( 0, 0x08);  
#else  
			UDR0 = 0x08 ;  
#endif        
            inverter_seq++;             
            break;         
        case 75:
			rx_seq0 = 0; 
			// Current even - Fault 0-2
            invCommand = 0x0437;
			
			sendBuff[0] = 0x08;	//Slave Number
			sendBuff[1] = 0x04;	//Function Code
            sendBuff[2] = 0x04; //Modbus Address High
            sendBuff[3] = 0x37; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x01; //Data Count Low (29)
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
			write_dudr ( 0, 0x08);  
#else  
			UDR0 = 0x08 ;  
#endif        
            inverter_seq++;             
            break;         
        case 76:
			rx_seq0 = 0; 
			// Current even - Fault 0-2
            invCommand = 0xCFFF;
			
			sendBuff[0] = 0x08;	//Slave Number
			sendBuff[1] = 0x04;	//Function Code
            sendBuff[2] = 0xCF; //Modbus Address High
            sendBuff[3] = 0xFF; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x06; //Data Count Low (29)
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
			write_dudr ( 0, 0x08);  
#else  
			UDR0 = 0x08 ;  
#endif        
            inverter_seq++;             
            break;         
        case 77:
        case 78:
        case 79:
            inverter_seq++;
            break;     

        case 80:           
        	if (eeInverterCount > 8) { 
                if (sendInverterCount[8] < 100) {
                    sendInverterCount[8]++;
                }            
            	inverter_seq++;
        	} else {
				inverter_seq = 0;            	
            }
            break;  
        case 81:     //Inv-9
			rx_seq0 = 0; 
			//INVERTER-STATUS
            invCommand = 0x0417;
			
			sendBuff[0] = 0x09;	//Slave Number
			sendBuff[1] = 0x04;	//Function Code
            sendBuff[2] = 0x04; //Modbus Address High
            sendBuff[3] = 0x17; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x01; //Data Count Low (29)
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
			write_dudr ( 0, 0x09);  
#else  
			UDR0 = 0x09 ;  
#endif        
            sprintf(str,"TX-9");     
            put_str(4,16,str,1);   
            rx_led_delay = 2500;
            inverter_seq++;             
            break;         
        case 82:
			rx_seq0 = 0; 
			//AC-INFO (ACV,ACA,ACKW,FREQ)
            invCommand = 0xBFFF;
			
			sendBuff[0] = 0x09;	//Slave Number
			sendBuff[1] = 0x04;	//Function Code
            sendBuff[2] = 0xBF; //Modbus Address High
            sendBuff[3] = 0xFF; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x0D; //Data Count Low (29)
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
			write_dudr ( 0, 0x09);  
#else  
			UDR0 = 0x09 ;  
#endif        
            inverter_seq++;             
            break;         
        case 83:
			rx_seq0 = 0; 
			//DC-INFO (DCV,DCA,DCKW)
            invCommand = 0xAFFF;
			
			sendBuff[0] = 0x09;	//Slave Number
			sendBuff[1] = 0x04;	//Function Code
            sendBuff[2] = 0xAF; //Modbus Address High
            sendBuff[3] = 0xFF; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x13; //Data Count Low (29)
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
			write_dudr ( 0, 0x09);  
#else  
			UDR0 = 0x09 ;  
#endif        
            inverter_seq++;             
            break;         
        case 84:
			rx_seq0 = 0; 
			// Current even - Fault 0-2
            invCommand = 0x0C1F;
			
			sendBuff[0] = 0x09;	//Slave Number
			sendBuff[1] = 0x04;	//Function Code
            sendBuff[2] = 0x0C; //Modbus Address High
            sendBuff[3] = 0x1F; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x03; //Data Count Low (29)
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
			write_dudr ( 0, 0x09);  
#else  
			UDR0 = 0x09 ;  
#endif        
            inverter_seq++;             
            break;         
        case 85:
			rx_seq0 = 0; 
			// Current even - Fault 0-2
            invCommand = 0x0437;
			
			sendBuff[0] = 0x09;	//Slave Number
			sendBuff[1] = 0x04;	//Function Code
            sendBuff[2] = 0x04; //Modbus Address High
            sendBuff[3] = 0x37; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x01; //Data Count Low (29)
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
			write_dudr ( 0, 0x09);  
#else  
			UDR0 = 0x09 ;  
#endif        
            inverter_seq++;             
            break;         
        case 86:
			rx_seq0 = 0; 
			// Current even - Fault 0-2
            invCommand = 0xCFFF;
			
			sendBuff[0] = 0x09;	//Slave Number
			sendBuff[1] = 0x04;	//Function Code
            sendBuff[2] = 0xCF; //Modbus Address High
            sendBuff[3] = 0xFF; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x06; //Data Count Low (29)
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
			write_dudr ( 0, 0x09);  
#else  
			UDR0 = 0x09 ;  
#endif        
            inverter_seq++;             
            break;         
        case 87:
        case 88:
        case 89:
            inverter_seq++;
            break;     

        case 90:           
        	if (eeInverterCount > 9) { 
                if (sendInverterCount[9] < 100) {
                    sendInverterCount[9]++;
                }            
            	inverter_seq++;
        	} else {
				inverter_seq = 0;            	
            }
            break;   
        case 91:     //Inv-10
			rx_seq0 = 0; 
			//INVERTER-STATUS
            invCommand = 0x0417;
			
			sendBuff[0] = 0x0A;	//Slave Number
			sendBuff[1] = 0x04;	//Function Code
            sendBuff[2] = 0x04; //Modbus Address High
            sendBuff[3] = 0x17; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x01; //Data Count Low (29)
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
			write_dudr ( 0, 0x0A);  
#else  
			UDR0 = 0x0A ;  
#endif        
            sprintf(str,"TX-A");     
            put_str(4,16,str,1);   
            rx_led_delay = 2500;
            inverter_seq++;             
            break;         
        case 92:
			rx_seq0 = 0; 
			//AC-INFO (ACV,ACA,ACKW,FREQ)
            invCommand = 0xBFFF;
			
			sendBuff[0] = 0x0A;	//Slave Number
			sendBuff[1] = 0x04;	//Function Code
            sendBuff[2] = 0xBF; //Modbus Address High
            sendBuff[3] = 0xFF; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x0D; //Data Count Low (29)
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
			write_dudr ( 0, 0x0A);  
#else  
			UDR0 = 0x0A ;  
#endif        
            inverter_seq++;             
            break;         
        case 93:
			rx_seq0 = 0; 
			//DC-INFO (DCV,DCA,DCKW)
            invCommand = 0xAFFF;
			
			sendBuff[0] = 0x0A;	//Slave Number
			sendBuff[1] = 0x04;	//Function Code
            sendBuff[2] = 0xAF; //Modbus Address High
            sendBuff[3] = 0xFF; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x13; //Data Count Low (29)
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
			write_dudr ( 0, 0x0A);  
#else  
			UDR0 = 0x0A ;  
#endif        
            inverter_seq++;             
            break;         
        case 94:
			rx_seq0 = 0; 
			// Current even - Fault 0-2
            invCommand = 0x0C1F;
			
			sendBuff[0] = 0x0A;	//Slave Number
			sendBuff[1] = 0x04;	//Function Code
            sendBuff[2] = 0x0C; //Modbus Address High
            sendBuff[3] = 0x1F; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x03; //Data Count Low (29)
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
			write_dudr ( 0, 0x0A);  
#else  
			UDR0 = 0x0A ;  
#endif        
            inverter_seq++;             
            break;         
        case 95:
			rx_seq0 = 0; 
			// Current even - Fault 0-2
            invCommand = 0x0437;
			
			sendBuff[0] = 0x0A;	//Slave Number
			sendBuff[1] = 0x04;	//Function Code
            sendBuff[2] = 0x04; //Modbus Address High
            sendBuff[3] = 0x37; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x01; //Data Count Low (29)
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
			write_dudr ( 0, 0x0A);  
#else  
			UDR0 = 0x0A ;  
#endif        
            inverter_seq++;             
            break;         
        case 96:
			rx_seq0 = 0; 
			// Current even - Fault 0-2
            invCommand = 0xCFFF;
			
			sendBuff[0] = 0x0A;	//Slave Number
			sendBuff[1] = 0x04;	//Function Code
            sendBuff[2] = 0xCF; //Modbus Address High
            sendBuff[3] = 0xFF; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x06; //Data Count Low (29)
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
			write_dudr ( 0, 0x0A);  
#else  
			UDR0 = 0x0A ;  
#endif        
            inverter_seq++;             
            break;         
        case 97:
        case 98:
        case 99:
            inverter_seq++;
            break;     

        case 100:
            inverter_seq = 0;
            break;
        default:  
            inverter_seq = 0;
            break;
    }
}


void rx0Control_Delta(void) {   
	char rxdata;   
    unsigned int calCrc,rxCrc;
	rxdata = getchar0();
	
	switch(rx_seq0) {
		case 0: //STX        
        	if ( (rxdata > 0x00) && (rxdata < 0x0b)) {
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
				
				switch(invCommand) {
					//1.INVERTER-STATUS
					case 0x0417:
						rx_seq0 = 10;
						break;
					//2.AC-INFO
					case 0xBFFF:
						rx_seq0 = 20;
						break;
					//3.DC-INFO
					case 0xAFFF:
						rx_seq0 = 30;
						break;
					//4.Current even - FAULT0~2
					case 0x0C1F:
						rx_seq0 = 40;
						break;
					//5.Temperature-1 
					case 0x0437:
						rx_seq0 = 50;
						break;
					//6.TOTAL-Energy (today, total)
					case 0xCFFF:
						rx_seq0 = 60;
						break;
					default:
						rx_seq0 = 0;
						break;
				}

			} else {
                rx_seq0 = 0;
            }                     
            break;
			
        case 10: //INVERTER-STATUS
            if (rxdata == 0x02) {   
            	dcnt = 0;
                rxbuff[rcnt++] = rxdata;
                rx_seq0++;
            } else {
                rx_seq0 = 0;
            }                     
            break;   
        case 11:
            rxbuff[rcnt++] = rxdata;
            dcnt++;
            if (dcnt == 4) {
            	calCrc = calcCRC(rxbuff,2+3);   
                rxCrc = rxbuff[6];
                rxCrc <<= 8;
                rxCrc += rxbuff[5];  
//sprintf(str,"%04X %04X ", calCrc, rxCrc);
//put_str(0,0,str,1);

                if (rxCrc == calCrc) {
                    //invNo = 0;
                    invNo = rxbuff[0] - 1;
                    inverter[invNo].inverter_status[0] = Bytes_to_Uint(rxbuff[4],0);            
                }
            	rx_seq0 = 0;  
			}
			break;
				
        case 20: //2.AC-INFO
            if (rxdata == 0x1A) {   
            	dcnt = 0;
                rxbuff[rcnt++] = rxdata;
                rx_seq0++;
            } else {
                rx_seq0 = 0;
            }                     
            break;   
        case 21:
            rxbuff[rcnt++] = rxdata;
            dcnt++;
            if (dcnt == 28) {
            	calCrc = calcCRC(rxbuff,26+3);   
                rxCrc = rxbuff[30];
                rxCrc <<= 8;
                rxCrc += rxbuff[29];  
//sprintf(str,"%04X %04X ", calCrc, rxCrc);
//put_str(0,0,str,1);

                if (rxCrc == calCrc) {
                    //invNo = 0;
                    invNo = rxbuff[0] - 1;
                	inverter[invNo].inv_u_voltage     = Bytes_to_Uint(rxbuff[5],rxbuff[6]); 
                	inverter[invNo].inv_v_voltage     = Bytes_to_Uint(rxbuff[13],rxbuff[14]); 
                	inverter[invNo].inv_w_voltage     = Bytes_to_Uint(rxbuff[21],rxbuff[22]);
                    inverter[invNo].inv_u_current     = Bytes_to_Uint(rxbuff[7],rxbuff[8]);
                	inverter[invNo].inv_v_current     = Bytes_to_Uint(rxbuff[15],rxbuff[16]);
                	inverter[invNo].inv_w_current     = Bytes_to_Uint(rxbuff[23],rxbuff[24]);
//                	inverter[invNo].power_inv_now     = Bytes_to_Uint(rxbuff[9],rxbuff[10]);  
//                	inverter[invNo].power_inv_now    += Bytes_to_Uint(rxbuff[17],rxbuff[18]);  
//                	inverter[invNo].power_inv_now    += Bytes_to_Uint(rxbuff[25],rxbuff[26]);  
                	inverter[invNo].power_inv_now     = Bytes_to_Uint(rxbuff[3],rxbuff[4]);  
                    inverter[invNo].inv_frequency     = Bytes_to_Uint(rxbuff[11],rxbuff[12]);
                    inverter[invNo].power_inv_pf      = 950;

                	inverter[invNo].inv_u_voltage     	/= 10; 
                	inverter[invNo].inv_v_voltage     	/= 10; 
                	inverter[invNo].inv_w_voltage     	/= 10;
                    inverter[invNo].inv_u_current      	/= 100;
                	inverter[invNo].inv_v_current      	/= 100;
                	inverter[invNo].inv_w_current      	/= 100;   
                         
                	inverter[invNo].power_inv_now    	/= 100;         

                }
            	rx_seq0 = 0;     
			}
			break;

        case 30: //3.DC-INFO
            if (rxdata == 0x26) {   
            	dcnt = 0;
                rxbuff[rcnt++] = rxdata;
                rx_seq0++;
            } else {
                rx_seq0 = 0;
            }                     
            break;   
        case 31:
            rxbuff[rcnt++] = rxdata;
            dcnt++;
            if (dcnt == 40) {
            	calCrc = calcCRC(rxbuff,38+3);   
                rxCrc = rxbuff[42];
                rxCrc <<= 8;
                rxCrc += rxbuff[41];  
//sprintf(str,"%04X %04X ", calCrc, rxCrc);
//put_str(0,0,str,1);

                if (rxCrc == calCrc) {
                    //invNo = 0;
                    invNo = rxbuff[0] - 1;
                	inverter[invNo].solar_cell_voltage  = Bytes_to_Uint(rxbuff[5],rxbuff[6]);
					inverter[invNo].solar_cell_current  = Bytes_to_Uint(rxbuff[7],rxbuff[8]);            
					inverter[invNo].solar_cell_current += Bytes_to_Uint(rxbuff[13],rxbuff[14]);            
					inverter[invNo].solar_cell_current += Bytes_to_Uint(rxbuff[19],rxbuff[20]);            
					inverter[invNo].solar_cell_current += Bytes_to_Uint(rxbuff[25],rxbuff[26]);            
					inverter[invNo].solar_cell_current += Bytes_to_Uint(rxbuff[31],rxbuff[32]);            
					inverter[invNo].solar_cell_current += Bytes_to_Uint(rxbuff[37],rxbuff[38]);            
//                	inverter[invNo].power_solar         = Bytes_to_Uint(rxbuff[7],rxbuff[8]);              
//                	inverter[invNo].power_solar        += Bytes_to_Uint(rxbuff[13],rxbuff[14]);              
//                	inverter[invNo].power_solar        += Bytes_to_Uint(rxbuff[19],rxbuff[20]);              
//                	inverter[invNo].power_solar        += Bytes_to_Uint(rxbuff[25],rxbuff[26]);              
//                	inverter[invNo].power_solar        += Bytes_to_Uint(rxbuff[31],rxbuff[32]);              
//                	inverter[invNo].power_solar        += Bytes_to_Uint(rxbuff[37],rxbuff[38]);            
                	inverter[invNo].power_solar         = Bytes_to_Uint(rxbuff[3],rxbuff[4]);            

                	inverter[invNo].solar_cell_voltage  /= 10;
					inverter[invNo].solar_cell_current  /= 100;            
                	inverter[invNo].power_solar         /= 100; 
                }
            	rx_seq0 = 0;
			}
			break;

        case 40: //4.Current even - FAULT0~2
            if (rxdata == 0x06) {   
            	dcnt = 0;
                rxbuff[rcnt++] = rxdata;
                rx_seq0++;
            } else {
                rx_seq0 = 0;
            }                     
            break;   
        case 41:
            rxbuff[rcnt++] = rxdata;
            dcnt++;
            if (dcnt == 8) {
            	calCrc = calcCRC(rxbuff,6+3);   
                rxCrc = rxbuff[10];
                rxCrc <<= 8;
                rxCrc += rxbuff[9];  
//sprintf(str,"%04X %04X ", calCrc, rxCrc);
//put_str(0,0,str,1);

                if (rxCrc == calCrc) {
                    //invNo = 0;
                    invNo = rxbuff[0] - 1;
                    inverter[invNo].inverter_status[1] = Bytes_to_Uint(rxbuff[3],rxbuff[4]);              
                    inverter[invNo].inverter_status[2] = Bytes_to_Uint(rxbuff[5],rxbuff[6]);             
                    inverter[invNo].inverter_status[3] = Bytes_to_Uint(rxbuff[7],rxbuff[8]);           
                }
            	rx_seq0 = 0;
			}
			break;

        case 50: //5.Temperature-1 
            if (rxdata == 0x02) {   
            	dcnt = 0;
                rxbuff[rcnt++] = rxdata;
                rx_seq0++;
            } else {
                rx_seq0 = 0;
            }                     
            break;   
        case 51:
            rxbuff[rcnt++] = rxdata;
            dcnt++;
            if (dcnt == 4) {
            	calCrc = calcCRC(rxbuff,2+3);   
                rxCrc = rxbuff[6];
                rxCrc <<= 8;
                rxCrc += rxbuff[5];  
//sprintf(str,"%04X %04X ", calCrc, rxCrc);
//put_str(0,0,str,1);

                if (rxCrc == calCrc) {
                    //invNo = 0;
                    invNo = rxbuff[0] - 1;
                    inverter[invNo].inverter_status[0] += Bytes_to_Uint(0,rxbuff[4]);              
                }
            	rx_seq0 = 0;
			}
			break;
				
        case 60: //6.TOTAL-Energy (today, total)
            if (rxdata == 0x0C) {   
            	dcnt = 0;
                rxbuff[rcnt++] = rxdata;
                rx_seq0++;
            } else {
                rx_seq0 = 0;
            }                     
            break;   
        case 61:
            rxbuff[rcnt++] = rxdata;
            dcnt++;
            if (dcnt == 14) {
            	calCrc = calcCRC(rxbuff,12+3);   
                rxCrc = rxbuff[16];
                rxCrc <<= 8;
                rxCrc += rxbuff[15];  
//sprintf(str,"%04X %04X ", calCrc, rxCrc);
//put_str(0,0,str,1);

                if (rxCrc == calCrc) {
                    //invNo = 0;
                    invNo = rxbuff[0] - 1;
                	inverter[invNo].power_inv_day_total     = Bytes_to_Uint(rxbuff[5],rxbuff[6]);
                    inverter[invNo].power_inv_day_total   <<= 16; 
                	inverter[invNo].power_inv_day_total    += Bytes_to_Uint(rxbuff[3],rxbuff[4]);  
                	inverter[invNo].power_inv_total     = Bytes_to_Uint(rxbuff[13],rxbuff[14]);
                    inverter[invNo].power_inv_total   <<= 16; 
                	inverter[invNo].power_inv_total    += Bytes_to_Uint(rxbuff[11],rxbuff[12]);       
//sprintf(str,"DTOT:%02X%02X%02X%02X ", rxbuff[3],rxbuff[4],rxbuff[5],rxbuff[6]);
//put_str(0,0,str,1);                          
//sprintf(str,"TTOT:%02X%02X%02X%02X ", rxbuff[11],rxbuff[12],rxbuff[13],rxbuff[14]);
//put_str(1,0,str,1);                          

                    
                	inverter[invNo].power_inv_day_total /= 1000;
                	inverter[invNo].power_inv_total 	/= 100;

	                sendInverterCount[invNo] = 0;
					buzzer_flag |= BUZZER_TIC;
	                sprintf(str,"RX-%01X",invNo+1);
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
