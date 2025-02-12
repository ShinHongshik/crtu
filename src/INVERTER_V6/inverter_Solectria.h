void sendInverterRead_Solectria(void) {  
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
			//INVERTER DATA
            invCommand = 0x9C41;
			
			sendBuff[0] = 0x01;	//Slave Number
			sendBuff[1] = 0x04;	//Function Code
            sendBuff[2] = 0x9C; //Modbus Address High
            sendBuff[3] = 0x41; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x1D; //Data Count Low (29)
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
			//INVERTER DATA
            invCommand = 0x9C95;
			
			sendBuff[0] = 0x01;	//Slave Number
			sendBuff[1] = 0x04;	//Function Code
            sendBuff[2] = 0x9C; //Modbus Address High
            sendBuff[3] = 0x95; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x0A; //Data Count Low (10)
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
        case 4:
        case 5:
        case 6:
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
            invCommand = 0x9C41;
			
			sendBuff[0] = 0x02;	//Slave Number
			sendBuff[1] = 0x04;	//Function Code
            sendBuff[2] = 0x9C; //Modbus Address High
            sendBuff[3] = 0x41; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x1D; //Data Count Low (29)
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
			//INVERTER DATA
            invCommand = 0x9C95;
			
			sendBuff[0] = 0x02;	//Slave Number
			sendBuff[1] = 0x04;	//Function Code
            sendBuff[2] = 0x9C; //Modbus Address High
            sendBuff[3] = 0x95; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x0A; //Data Count Low (10)
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
        case 14:
        case 15:
        case 16:
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
            invCommand = 0x9C41;
			
			sendBuff[0] = 0x03;	//Slave Number
			sendBuff[1] = 0x04;	//Function Code
            sendBuff[2] = 0x9C; //Modbus Address High
            sendBuff[3] = 0x41; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x1D; //Data Count Low (29)
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
			//INVERTER DATA
            invCommand = 0x9C95;
			
			sendBuff[0] = 0x03;	//Slave Number
			sendBuff[1] = 0x04;	//Function Code
            sendBuff[2] = 0x9C; //Modbus Address High
            sendBuff[3] = 0x95; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x0A; //Data Count Low (10)
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
        case 24:
        case 25:
        case 26:
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
            invCommand = 0x9C41;
			
			sendBuff[0] = 0x04;	//Slave Number
			sendBuff[1] = 0x04;	//Function Code
            sendBuff[2] = 0x9C; //Modbus Address High
            sendBuff[3] = 0x41; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x1D; //Data Count Low (29)
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
			//INVERTER DATA
            invCommand = 0x9C95;
			
			sendBuff[0] = 0x04;	//Slave Number
			sendBuff[1] = 0x04;	//Function Code
            sendBuff[2] = 0x9C; //Modbus Address High
            sendBuff[3] = 0x95; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x0A; //Data Count Low (10)
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
        case 34:
        case 35:
        case 36:
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
            invCommand = 0x9C41;
			
			sendBuff[0] = 0x05;	//Slave Number
			sendBuff[1] = 0x04;	//Function Code
            sendBuff[2] = 0x9C; //Modbus Address High
            sendBuff[3] = 0x41; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x1D; //Data Count Low (29)
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
			//INVERTER DATA
            invCommand = 0x9C95;
			
			sendBuff[0] = 0x05;	//Slave Number
			sendBuff[1] = 0x04;	//Function Code
            sendBuff[2] = 0x9C; //Modbus Address High
            sendBuff[3] = 0x95; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x0A; //Data Count Low (10)
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
        case 44:
        case 45:
        case 46:
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
            invCommand = 0x9C41;
			
			sendBuff[0] = 0x06;	//Slave Number
			sendBuff[1] = 0x04;	//Function Code
            sendBuff[2] = 0x9C; //Modbus Address High
            sendBuff[3] = 0x41; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x1D; //Data Count Low (29)
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
			//INVERTER DATA
            invCommand = 0x9C95;
			
			sendBuff[0] = 0x06;	//Slave Number
			sendBuff[1] = 0x04;	//Function Code
            sendBuff[2] = 0x9C; //Modbus Address High
            sendBuff[3] = 0x95; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x0A; //Data Count Low (10)
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
        case 54:
        case 55:
        case 56:
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
			
			sendBuff[0] = 0x9C41;	//Slave Number
			sendBuff[1] = 0x04;	//Function Code
            sendBuff[2] = 0x9C; //Modbus Address High
            sendBuff[3] = 0x41; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x1D; //Data Count Low (29)
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
			//INVERTER DATA
            invCommand = 0x9C95;
			
			sendBuff[0] = 0x07;	//Slave Number
			sendBuff[1] = 0x04;	//Function Code
            sendBuff[2] = 0x9C; //Modbus Address High
            sendBuff[3] = 0x95; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x0A; //Data Count Low (10)
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
        case 64:
        case 65:
        case 66:
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
            invCommand = 0x9C41;
			
			sendBuff[0] = 0x08;	//Slave Number
			sendBuff[1] = 0x04;	//Function Code
            sendBuff[2] = 0x9C; //Modbus Address High
            sendBuff[3] = 0x41; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x1D; //Data Count Low (29)
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
			//INVERTER DATA
            invCommand = 0x9C95;
			
			sendBuff[0] = 0x08;	//Slave Number
			sendBuff[1] = 0x04;	//Function Code
            sendBuff[2] = 0x9C; //Modbus Address High
            sendBuff[3] = 0x95; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x0A; //Data Count Low (10)
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
        case 74:
        case 75:
        case 76:
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
            invCommand = 0x9C41;
			
			sendBuff[0] = 0x09;	//Slave Number
			sendBuff[1] = 0x04;	//Function Code
            sendBuff[2] = 0x9C; //Modbus Address High
            sendBuff[3] = 0x41; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x1D; //Data Count Low (29)
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
			//INVERTER DATA
            invCommand = 0x9C95;
			
			sendBuff[0] = 0x09;	//Slave Number
			sendBuff[1] = 0x04;	//Function Code
            sendBuff[2] = 0x9C; //Modbus Address High
            sendBuff[3] = 0x95; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x0A; //Data Count Low (10)
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
        case 84:
        case 85:
        case 86:
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
            invCommand = 0x9C41;
			
			sendBuff[0] = 0x0A;	//Slave Number
			sendBuff[1] = 0x04;	//Function Code
            sendBuff[2] = 0x9C; //Modbus Address High
            sendBuff[3] = 0x41; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x1D; //Data Count Low (29)
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
			//INVERTER DATA
            invCommand = 0x9C95;
			
			sendBuff[0] = 0x0A;	//Slave Number
			sendBuff[1] = 0x04;	//Function Code
            sendBuff[2] = 0x9C; //Modbus Address High
            sendBuff[3] = 0x95; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x0A; //Data Count Low (10)
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
        case 94:
        case 95:
        case 96:
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


void rx0Control_Solectria(void) {  
	float fim;
	unsigned int iim;
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
					//1.INVERTER-DATA
					case 0x9C41:
						rx_seq0 = 10;
						break;
					//2.INVERTER-DATA
					case 0x9C95:
						rx_seq0 = 20;
						break;
					default:
						rx_seq0 = 0;
						break;
				}

			} else {
                rx_seq0 = 0;
            }                     
            break;
			
        case 10: //1.INVERTER-DATA
            if (rxdata == 0x3A) {	//(58D)   
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
            if (dcnt == 60) {
            	calCrc = calcCRC(rxbuff,58+3);   
                rxCrc = rxbuff[62];
                rxCrc <<= 8;
                rxCrc += rxbuff[61];  
//sprintf(str,"%04X %04X ", calCrc, rxCrc);
//put_str(0,0,str,1);

                if (rxCrc == calCrc) {
                    //invNo = 0;
                    invNo = rxbuff[0] - 1;
					                	
					iim = Bytes_to_Uint(rxbuff[3],rxbuff[4]);
					fim = (float)iim * 0.1953125;
					inverter[invNo].solar_cell_voltage  = (unsigned int)fim;
					inverter[invNo].solar_cell_current  = Bytes_to_Uint(rxbuff[59],rxbuff[60]);            
                	inverter[invNo].power_solar         = inverter[invNo].solar_cell_voltage * inverter[invNo].solar_cell_current; 
					
					iim = Bytes_to_Uint(rxbuff[11],rxbuff[12]); 
					fim = (float)iim * 0.1953125;
					inverter[invNo].inv_u_voltage  = (unsigned int)fim;
					iim = Bytes_to_Uint(rxbuff[13],rxbuff[14]);
					fim = (float)iim * 0.1953125;
					inverter[invNo].inv_v_voltage  = (unsigned int)fim;
					iim = Bytes_to_Uint(rxbuff[15],rxbuff[16]);
					fim = (float)iim * 0.1953125;
					inverter[invNo].inv_w_voltage  = (unsigned int)fim;
					
					iim = Bytes_to_Uint(rxbuff[7],rxbuff[8]);
					fim = (float)iim * 0.0048828;
					inverter[invNo].inv_frequency  = (unsigned int)fim;

                    inverter[invNo].power_inv_pf      = 950;

                    inverter[invNo].inverter_status[0] = Bytes_to_Uint(rxbuff[39],rxbuff[40]);              
                    inverter[invNo].inverter_status[1] = Bytes_to_Uint(rxbuff[35],rxbuff[36]);             
                    inverter[invNo].inverter_status[2] = Bytes_to_Uint(rxbuff[33],rxbuff[34]);  
					inverter[invNo].inverter_status[3] = rssiLevel;
					
					iim = Bytes_to_Uint(rxbuff[5],rxbuff[6]);
					fim = (float)iim * 0.1953125;
					inverter[invNo].power_inv_now  = (unsigned int)fim;
					
					
                    inverter[invNo].power_inv_day_total  = 0;
                	inverter[invNo].power_inv_total     = Bytes_to_Uint(rxbuff[19],rxbuff[20]);
                    inverter[invNo].power_inv_total   <<= 16; 
                	inverter[invNo].power_inv_total    += Bytes_to_Uint(rxbuff[21],rxbuff[22]);       
//sprintf(str,"DTOT:%02X%02X%02X%02X ", rxbuff[3],rxbuff[4],rxbuff[5],rxbuff[6]);
//put_str(0,0,str,1);                          
//sprintf(str,"TTOT:%02X%02X%02X%02X ", rxbuff[11],rxbuff[12],rxbuff[13],rxbuff[14]);
//put_str(1,0,str,1);                          
                	//inverter[invNo].solar_cell_voltage  /= 10;
					//inverter[invNo].solar_cell_current  /= 100;            
                	//inverter[invNo].power_solar         /= 100; 

                	//inverter[invNo].inv_u_voltage     	/= 10; 
                	//inverter[invNo].inv_v_voltage     	/= 10; 
                	//inverter[invNo].inv_w_voltage     	/= 10;
                	inverter[invNo].power_inv_now    	/= 100; 

                	inverter[invNo].power_inv_total 	/= 10;
	                
					sendInverterCount[invNo] = 0;
					buzzer_flag |= BUZZER_TIC;
	                sprintf(str,"RX-%01X",invNo+1);
    	            put_str(4,16,str,1);   
        	        rx_led_delay = 2500;
					
					
                }
            	rx_seq0 = 0;     
			}
			break;

        case 20: //2.TEMP, AC-CURRENT
            if (rxdata == 0x14) {   
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
            if (dcnt == 16) {
            	calCrc = calcCRC(rxbuff,14+3);   
                rxCrc = rxbuff[18];
                rxCrc <<= 8;
                rxCrc += rxbuff[17];  
//sprintf(str,"%04X %04X ", calCrc, rxCrc);
//put_str(0,0,str,1);

                if (rxCrc == calCrc) {
                    //invNo = 0;
                    invNo = rxbuff[0] - 1;

					iim = Bytes_to_Uint(rxbuff[21],rxbuff[22]);
					fim = (float)iim * 0.976563;
					inverter[invNo].inv_u_current  = (unsigned int)fim;
                    inverter[invNo].inv_u_current  /= 10;
                	inverter[invNo].inv_v_current   = inverter[invNo].inv_u_current;
                	inverter[invNo].inv_w_current   = inverter[invNo].inv_u_current;   
                }
            	rx_seq0 = 0;
            }
            break;

		default:
			rx_seq0 = 0;
			break;
	}
}
