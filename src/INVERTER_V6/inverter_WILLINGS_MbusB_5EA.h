
void sendInverterRead_WillingsMbusB(void) {
    unsigned int retVal;
    char sendBuff[10];   
    
    switch(inverter_seq) {
        case 0:
            inverter_seq++;
			if (sendInverterCount[0] < 100) {
            	sendInverterCount[0]++;
            }
            break;         
        case 1:     //Inv-1: RTU Master request frame (from WILLINGS_MBUS)  
            sendBuff[0] = 11; //0x11;
            sendBuff[1] = 0x04;
            sendBuff[2] = 0x00;
            sendBuff[3] = 0x18;
            sendBuff[4] = 0x00;
            sendBuff[5] = 0x4B;		//cnt:75 
            retVal = calcCRC(sendBuff,6);     
                                          
            TXEN = 1;
            TXEN = 1;
            putchar0(sendBuff[1]); //Function Code
            putchar0(sendBuff[2]); //Modbus Address High
            putchar0(sendBuff[3]); //Modbus Address Low
            putchar0(sendBuff[4]); //Data Count High
            putchar0(sendBuff[5]); //Data Count Low  
            putchar0(retVal % 0x100); //CRC_L
            putchar0(retVal / 0x100); //CRC_H
                            
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_udr0 (sendBuff[0]);  
#else  
			UDR0 = sendBuff[0] ;  
#endif	//485 Address     

            sprintf(str,"TX01");     
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
        	if (eeInverterCount > 1) { 
                if (sendInverterCount[1] < 100) {
                    sendInverterCount[1]++;
                }            
            	inverter_seq++;
        	} else {
				inverter_seq = 0;            	
            }
            break;        
        case 6:     //Inv-2: RTU Master request frame (from WILLINGS_MBUS)  
            sendBuff[0] = 12; //0x12;
            sendBuff[1] = 0x04;
            sendBuff[2] = 0x00;
            sendBuff[3] = 0x18;
            sendBuff[4] = 0x00;
            sendBuff[5] = 0x4B;		//cnt:75 
            retVal = calcCRC(sendBuff,6);     
                                          
            TXEN = 1;
            TXEN = 1;
            putchar0(sendBuff[1]); //Function Code
            putchar0(sendBuff[2]); //Modbus Address High
            putchar0(sendBuff[3]); //Modbus Address Low
            putchar0(sendBuff[4]); //Data Count High
            putchar0(sendBuff[5]); //Data Count Low  
            putchar0(retVal % 0x100); //CRC_L
            putchar0(retVal / 0x100); //CRC_H
                            
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_udr0 (sendBuff[0]);  
#else  
			UDR0 = sendBuff[0] ;  
#endif	//485 Address     

            sprintf(str,"TX02");     
            put_str(4,16,str,1);   
            rx_led_delay = 2500;
                        
            inverter_seq++;             
            break;         
        case 7:
        case 8:
        case 9:
        	inverter_seq++;
            break;                    
            
//-----------------------------------------------------
        case 10:    
        	if (eeInverterCount > 2) { 
                if (sendInverterCount[2] < 100) {
                    sendInverterCount[2]++;
                }            
            	inverter_seq++;
        	} else {
				inverter_seq = 0;            	
            }
            break;             
        case 11:     //Inv-3: RTU Master request frame (from WILLINGS_MBUS)  
            sendBuff[0] = 13; //0x13;
            sendBuff[1] = 0x04;
            sendBuff[2] = 0x00;
            sendBuff[3] = 0x18;
            sendBuff[4] = 0x00;
            sendBuff[5] = 0x4B;		//cnt:75 
            retVal = calcCRC(sendBuff,6);     
                                          
            TXEN = 1;
            TXEN = 1;
            putchar0(sendBuff[1]); //Function Code
            putchar0(sendBuff[2]); //Modbus Address High
            putchar0(sendBuff[3]); //Modbus Address Low
            putchar0(sendBuff[4]); //Data Count High
            putchar0(sendBuff[5]); //Data Count Low  
            putchar0(retVal % 0x100); //CRC_L
            putchar0(retVal / 0x100); //CRC_H
                            
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_udr0 (sendBuff[0]);  
#else  
			UDR0 = sendBuff[0] ;  
#endif	//485 Address     

            sprintf(str,"TX03");     
            put_str(4,16,str,1);   
            rx_led_delay = 2500;
                        
            inverter_seq++;             
            break;         
        case 12:
        case 13:
        case 14:
            inverter_seq++;             
            break;
            
        case 15:    
        	if (eeInverterCount > 3) { 
                if (sendInverterCount[3] < 100) {
                    sendInverterCount[3]++;
                }            
            	inverter_seq++;
        	} else {
				inverter_seq = 0;            	
            }
            break;        
        case 16:     //Inv-4: RTU Master request frame (from WILLINGS_MBUS)  
            sendBuff[0] = 14; //0x14;
            sendBuff[1] = 0x04;
            sendBuff[2] = 0x00;
            sendBuff[3] = 0x18;
            sendBuff[4] = 0x00;
            sendBuff[5] = 0x4B;		//cnt:75 
            retVal = calcCRC(sendBuff,6);     
                                          
            TXEN = 1;
            TXEN = 1;
            putchar0(sendBuff[1]); //Function Code
            putchar0(sendBuff[2]); //Modbus Address High
            putchar0(sendBuff[3]); //Modbus Address Low
            putchar0(sendBuff[4]); //Data Count High
            putchar0(sendBuff[5]); //Data Count Low  
            putchar0(retVal % 0x100); //CRC_L
            putchar0(retVal / 0x100); //CRC_H
                            
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_udr0 (sendBuff[0]);  
#else  
			UDR0 = sendBuff[0] ;  
#endif	//485 Address     

            sprintf(str,"TX04");     
            put_str(4,16,str,1);   
            rx_led_delay = 2500;
                        
            inverter_seq++;             
            break;         
        case 17:
        case 18:
        case 19:
        	inverter_seq++;
            break; 
            //-------------------
//-----------------------------------------------------
        case 20:    
        	if (eeInverterCount > 4) { 
                if (sendInverterCount[4] < 100) {
                    sendInverterCount[4]++;
                }            
            	inverter_seq++;
        	} else {
				inverter_seq = 0;            	
            }
            break;             
        case 21:     //Inv2-1: RTU Master request frame (from WILLINGS_MBUS)  
            sendBuff[0] = 15;//21; //0x15;
            sendBuff[1] = 0x04;
            sendBuff[2] = 0x00;
            sendBuff[3] = 0x18;
            sendBuff[4] = 0x00;
            sendBuff[5] = 0x4B;		//cnt:75 
            retVal = calcCRC(sendBuff,6);     
                                          
            TXEN = 1;
            TXEN = 1;
            putchar0(sendBuff[1]); //Function Code
            putchar0(sendBuff[2]); //Modbus Address High
            putchar0(sendBuff[3]); //Modbus Address Low
            putchar0(sendBuff[4]); //Data Count High
            putchar0(sendBuff[5]); //Data Count Low  
            putchar0(retVal % 0x100); //CRC_L
            putchar0(retVal / 0x100); //CRC_H
                            
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_udr0 (sendBuff[0]);  
#else  
			UDR0 = sendBuff[0] ;  
#endif	//485 Address     

            sprintf(str,"TX05");     
            put_str(4,16,str,1);   
            rx_led_delay = 2500;
                        
            inverter_seq++;             
            break;         
        case 22:
        case 23:
        case 24:
            inverter_seq++;             
            break;
            
        case 25:    
        	if (eeInverterCount > 5) { 
                if (sendInverterCount[5] < 100) {
                    sendInverterCount[5]++;
                }            
            	inverter_seq++;
        	} else {
				inverter_seq = 0;            	
            }
            break;        
        case 26:     //Inv2-2: RTU Master request frame (from WILLINGS_MBUS)  
            sendBuff[0] = 22; //0x16;
            sendBuff[1] = 0x04;
            sendBuff[2] = 0x00;
            sendBuff[3] = 0x18;
            sendBuff[4] = 0x00;
            sendBuff[5] = 0x4B;		//cnt:75 
            retVal = calcCRC(sendBuff,6);     
                                          
            TXEN = 1;
            TXEN = 1;
            putchar0(sendBuff[1]); //Function Code
            putchar0(sendBuff[2]); //Modbus Address High
            putchar0(sendBuff[3]); //Modbus Address Low
            putchar0(sendBuff[4]); //Data Count High
            putchar0(sendBuff[5]); //Data Count Low  
            putchar0(retVal % 0x100); //CRC_L
            putchar0(retVal / 0x100); //CRC_H
                            
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_udr0 (sendBuff[0]);  
#else  
			UDR0 = sendBuff[0] ;  
#endif	//485 Address     

            sprintf(str,"TX06");     
            put_str(4,16,str,1);   
            rx_led_delay = 2500;
                        
            inverter_seq++;             
            break;         
        case 27:
        case 28:
        case 29:
        	inverter_seq++;
            break; 
            //-------------------
//-----------------------------------------------------
        case 30:    
        	if (eeInverterCount > 6) { 
                if (sendInverterCount[6] < 100) {
                    sendInverterCount[6]++;
                }            
            	inverter_seq++;
        	} else {
				inverter_seq = 0;            	
            }
            break;             
        case 31:     //Inv2-3 : RTU Master request frame (from WILLINGS_MBUS)  
            sendBuff[0] = 23; //0x21;
            sendBuff[1] = 0x04;
            sendBuff[2] = 0x00;
            sendBuff[3] = 0x18;
            sendBuff[4] = 0x00;
            sendBuff[5] = 0x4B;		//cnt:75 
            retVal = calcCRC(sendBuff,6);     
                                          
            TXEN = 1;
            TXEN = 1;
            putchar0(sendBuff[1]); //Function Code
            putchar0(sendBuff[2]); //Modbus Address High
            putchar0(sendBuff[3]); //Modbus Address Low
            putchar0(sendBuff[4]); //Data Count High
            putchar0(sendBuff[5]); //Data Count Low  
            putchar0(retVal % 0x100); //CRC_L
            putchar0(retVal / 0x100); //CRC_H
                            
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_udr0 (sendBuff[0]);  
#else  
			UDR0 = sendBuff[0] ;  
#endif	//485 Address     

            sprintf(str,"TX07");     
            put_str(4,16,str,1);   
            rx_led_delay = 2500;
                        
            inverter_seq++;             
            break;         
        case 32:
        case 33:
        case 34:
            inverter_seq++;             
            break;
            
        case 35:    
        	if (eeInverterCount > 7) { 
                if (sendInverterCount[7] < 100) {
                    sendInverterCount[7]++;
                }            
            	inverter_seq++;
        	} else {
				inverter_seq = 0;            	
            }
            break;        
        case 36:     //Inv2-4 : RTU Master request frame (from WILLINGS_MBUS)  
            sendBuff[0] = 24; //0x22;
            sendBuff[1] = 0x04;
            sendBuff[2] = 0x00;
            sendBuff[3] = 0x18;
            sendBuff[4] = 0x00;
            sendBuff[5] = 0x4B;		//cnt:75 
            retVal = calcCRC(sendBuff,6);     
                                          
            TXEN = 1;
            TXEN = 1;
            putchar0(sendBuff[1]); //Function Code
            putchar0(sendBuff[2]); //Modbus Address High
            putchar0(sendBuff[3]); //Modbus Address Low
            putchar0(sendBuff[4]); //Data Count High
            putchar0(sendBuff[5]); //Data Count Low  
            putchar0(retVal % 0x100); //CRC_L
            putchar0(retVal / 0x100); //CRC_H
                            
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_udr0 (sendBuff[0]);  
#else  
			UDR0 = sendBuff[0] ;  
#endif	//485 Address     

            sprintf(str,"TX08");     
            put_str(4,16,str,1);   
            rx_led_delay = 2500;
                        
            inverter_seq++;             
            break;         
        case 37:
        case 38:
        case 39:
        	inverter_seq++;
            break;           
            
//-----------------------------------------------------
        case 40:    
        	if (eeInverterCount > 8) { 
                if (sendInverterCount[8] < 100) {
                    sendInverterCount[8]++;
                }            
            	inverter_seq++;
        	} else {
				inverter_seq = 0;            	
            }
            break;             
        case 41:     //Inv3-1 : RTU Master request frame (from WILLINGS_MBUS)  
            sendBuff[0] = 31; //0x23;
            sendBuff[1] = 0x04;
            sendBuff[2] = 0x00;
            sendBuff[3] = 0x18;
            sendBuff[4] = 0x00;
            sendBuff[5] = 0x4B;		//cnt:75 
            retVal = calcCRC(sendBuff,6);     
                                          
            TXEN = 1;
            TXEN = 1;
            putchar0(sendBuff[1]); //Function Code
            putchar0(sendBuff[2]); //Modbus Address High
            putchar0(sendBuff[3]); //Modbus Address Low
            putchar0(sendBuff[4]); //Data Count High
            putchar0(sendBuff[5]); //Data Count Low  
            putchar0(retVal % 0x100); //CRC_L
            putchar0(retVal / 0x100); //CRC_H
                            
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_udr0 (sendBuff[0]);  
#else  
			UDR0 = sendBuff[0] ;  
#endif	//485 Address     

            sprintf(str,"TX09");     
            put_str(4,16,str,1);   
            rx_led_delay = 2500;
                        
            inverter_seq++;             
            break;         
        case 42:
        case 43:
        case 44:
            inverter_seq++;             
            break;
            
        case 45:    
        	if (eeInverterCount > 9) { 
                if (sendInverterCount[9] < 100) {
                    sendInverterCount[9]++;
                }            
            	inverter_seq++;
        	} else {
				inverter_seq = 0;            	
            }
            break;        
        case 46:     //Inv3-2: RTU Master request frame (from WILLINGS_MBUS)  
            sendBuff[0] = 32; //0x24;
            sendBuff[1] = 0x04;
            sendBuff[2] = 0x00;
            sendBuff[3] = 0x18;
            sendBuff[4] = 0x00;
            sendBuff[5] = 0x4B;		//cnt:75 
            retVal = calcCRC(sendBuff,6);     
                                          
            TXEN = 1;
            TXEN = 1;
            putchar0(sendBuff[1]); //Function Code
            putchar0(sendBuff[2]); //Modbus Address High
            putchar0(sendBuff[3]); //Modbus Address Low
            putchar0(sendBuff[4]); //Data Count High
            putchar0(sendBuff[5]); //Data Count Low  
            putchar0(retVal % 0x100); //CRC_L
            putchar0(retVal / 0x100); //CRC_H
                            
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_udr0 (sendBuff[0]);  
#else  
			UDR0 = sendBuff[0] ;  
#endif	//485 Address     

            sprintf(str,"TX10");     
            put_str(4,16,str,1);   
            rx_led_delay = 2500;
                        
            inverter_seq++;             
            break;         
        case 47:
        case 48:
        case 49:
        	inverter_seq++;
            break;           
            
//-----------------------------------------------------
        case 50:    
        	if (eeInverterCount > 10) { 
                if (sendInverterCount[10] < 100) {
                    sendInverterCount[10]++;
                }            
            	inverter_seq++;
        	} else {
				inverter_seq = 0;            	
            }
            break;             
        case 51:     //Inv3-3 : RTU Master request frame (from WILLINGS_MBUS)  
            sendBuff[0] = 33; //0x31;
            sendBuff[1] = 0x04;
            sendBuff[2] = 0x00;
            sendBuff[3] = 0x18;
            sendBuff[4] = 0x00;
            sendBuff[5] = 0x4B;		//cnt:75 
            retVal = calcCRC(sendBuff,6);     
                                          
            TXEN = 1;
            TXEN = 1;
            putchar0(sendBuff[1]); //Function Code
            putchar0(sendBuff[2]); //Modbus Address High
            putchar0(sendBuff[3]); //Modbus Address Low
            putchar0(sendBuff[4]); //Data Count High
            putchar0(sendBuff[5]); //Data Count Low  
            putchar0(retVal % 0x100); //CRC_L
            putchar0(retVal / 0x100); //CRC_H
                            
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_udr0 (sendBuff[0]);  
#else  
			UDR0 = sendBuff[0] ;  
#endif	//485 Address     

            sprintf(str,"TX11");     
            put_str(4,16,str,1);   
            rx_led_delay = 2500;
                        
            inverter_seq++;             
            break;         
        case 52:
        case 53:
        case 54:
            inverter_seq++;             
            break;
            
        case 55:    
        	if (eeInverterCount > 11) { 
                if (sendInverterCount[11] < 100) {
                    sendInverterCount[11]++;
                }            
            	inverter_seq++;
        	} else {
				inverter_seq = 0;            	
            }
            break;        
        case 56:     //Inv3-4 : RTU Master request frame (from WILLINGS_MBUS)  
            sendBuff[0] = 34; //0x32;
            sendBuff[1] = 0x04;
            sendBuff[2] = 0x00;
            sendBuff[3] = 0x18;
            sendBuff[4] = 0x00;
            sendBuff[5] = 0x4B;		//cnt:75 
            retVal = calcCRC(sendBuff,6);     
                                          
            TXEN = 1;
            TXEN = 1;
            putchar0(sendBuff[1]); //Function Code
            putchar0(sendBuff[2]); //Modbus Address High
            putchar0(sendBuff[3]); //Modbus Address Low
            putchar0(sendBuff[4]); //Data Count High
            putchar0(sendBuff[5]); //Data Count Low  
            putchar0(retVal % 0x100); //CRC_L
            putchar0(retVal / 0x100); //CRC_H
                            
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_udr0 (sendBuff[0]);  
#else  
			UDR0 = sendBuff[0] ;  
#endif	//485 Address     

            sprintf(str,"TX12");     
            put_str(4,16,str,1);   
            rx_led_delay = 2500;
                        
            inverter_seq++;             
            break;         
        case 57:
        case 58:
        case 59:
        	inverter_seq++;
            break;   
                    
//-----------------------------------------------------
        case 60:    
        	if (eeInverterCount > 12) { 
                if (sendInverterCount[12] < 100) {
                    sendInverterCount[12]++;
                }            
            	inverter_seq++;
        	} else {
				inverter_seq = 0;            	
            }
            break;             
        case 61:     //Inv4-1 : RTU Master request frame (from WILLINGS_MBUS)  
            sendBuff[0] = 41; //0x33;
            sendBuff[1] = 0x04;
            sendBuff[2] = 0x00;
            sendBuff[3] = 0x18;
            sendBuff[4] = 0x00;
            sendBuff[5] = 0x4B;		//cnt:75 
            retVal = calcCRC(sendBuff,6);     
                                          
            TXEN = 1;
            TXEN = 1;
            putchar0(sendBuff[1]); //Function Code
            putchar0(sendBuff[2]); //Modbus Address High
            putchar0(sendBuff[3]); //Modbus Address Low
            putchar0(sendBuff[4]); //Data Count High
            putchar0(sendBuff[5]); //Data Count Low  
            putchar0(retVal % 0x100); //CRC_L
            putchar0(retVal / 0x100); //CRC_H
                            
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_udr0 (sendBuff[0]);  
#else  
			UDR0 = sendBuff[0] ;  
#endif	//485 Address     

            sprintf(str,"TX13");     
            put_str(4,16,str,1);   
            rx_led_delay = 2500;
                        
            inverter_seq++;             
            break;         
        case 62:
        case 63:
        case 64:
            inverter_seq++;             
            break;
            
        case 65:    
        	if (eeInverterCount > 13) { 
                if (sendInverterCount[13] < 100) {
                    sendInverterCount[13]++;
                }            
            	inverter_seq++;
        	} else {
				inverter_seq = 0;            	
            }
            break;        
        case 66:     //Inv4-2 : RTU Master request frame (from WILLINGS_MBUS)  
            sendBuff[0] = 42; //0x34;
            sendBuff[1] = 0x04;
            sendBuff[2] = 0x00;
            sendBuff[3] = 0x18;
            sendBuff[4] = 0x00;
            sendBuff[5] = 0x4B;		//cnt:75 
            retVal = calcCRC(sendBuff,6);     
                                          
            TXEN = 1;
            TXEN = 1;
            putchar0(sendBuff[1]); //Function Code
            putchar0(sendBuff[2]); //Modbus Address High
            putchar0(sendBuff[3]); //Modbus Address Low
            putchar0(sendBuff[4]); //Data Count High
            putchar0(sendBuff[5]); //Data Count Low  
            putchar0(retVal % 0x100); //CRC_L
            putchar0(retVal / 0x100); //CRC_H
                            
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_udr0 (sendBuff[0]);  
#else  
			UDR0 = sendBuff[0] ;  
#endif	//485 Address     

            sprintf(str,"TX14");     
            put_str(4,16,str,1);   
            rx_led_delay = 2500;
                        
            inverter_seq++;             
            break;         
        case 67:
        case 68:
        case 69:
        	inverter_seq++;
            break;           
            
            
            
            
            
            //-------------------
		case 70:
        	inverter_seq = 0;
            break;            
            
            
            
                  
        default:  
            inverter_seq = 0;
            break;
    }
}


void rx0Control_WillingsMbusB(void) {
    //char imc;        
	char rxdata = getchar0();; 
    unsigned int calCrc,rxCrc;  
    unsigned long int lim1, lim2;

//buzzer_flag |= BUZZER_TIC; 
//sprintf(str,"SEQ:%02d, %02X ", rx_seq0, rxdata );
//put_str(0,0,str,1);
             	
	switch(rx_seq0) {
		case 0:
			if ((rxdata > 10) || (rxdata < 39)) {   
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
//        	if (rxdata == (0x2E * 2)) {	//92 (5CH)  
        	if (rxdata == (0x4B * 2)) {	//92 (5CH)  
            	rx_seq0++;
            } else {      
            	rx_seq0 = 0;
            }  
            break;
    	case 3:   
            rxbuff[rcnt++] = rxdata;  
                
            if (rcnt == (0x4B * 2 + 5)) {   
            	calCrc = calcCRC(rxbuff, 0x4B * 2 + 3);
                rxCrc = rxbuff[0x4B * 2 + 4];
                rxCrc <<= 8;
                rxCrc += rxbuff[0x4B * 2 + 3];  
                
                          
                       
//				sprintf(str,"CR:%02X%02X,%02X%02X ",calCrc%0x100,calCrc/0x100,rxCrc%0x100,rxCrc/0x100  );
//                put_str(0,0,str,1);         
                buzzer_flag |= BUZZER_TIC;
                
                if (rxCrc != calCrc) {
                	return;
                }
                       
                if( (rxbuff[0] > 10) && (rxbuff[0] < 16)) { 
                	invNo = rxbuff[0] - 11;
                } else if( (rxbuff[0] > 20) && (rxbuff[0] < 25)) {  
                	invNo = rxbuff[0] - 17;
                } else if( (rxbuff[0] > 30) && (rxbuff[0] < 35)) {  
                	invNo = rxbuff[0] - 23;
                }            
                inverter[invNo].inverter_status[0] = Bytes_to_Uint(rxbuff[4],rxbuff[6]);
                inverter[invNo].inverter_status[1] = Bytes_to_Uint(rxbuff[7],rxbuff[8]);
                inverter[invNo].inverter_status[2] = Bytes_to_Uint(rxbuff[9],rxbuff[10]);
                inverter[invNo].inverter_status[3] = Bytes_to_Uint(rxbuff[11],rxbuff[12]);
                
                
                //DC-V
                fdata.chars[3] = rxbuff[23];
                fdata.chars[2] = rxbuff[24];
                fdata.chars[1] = rxbuff[25];
                fdata.chars[0] = rxbuff[26];
                inverter[invNo].solar_cell_voltage	= (unsigned int)(fdata.value);                                                           
                //DC-A
                fdata.chars[3] = rxbuff[31];
                fdata.chars[2] = rxbuff[32];
                fdata.chars[1] = rxbuff[33];
                fdata.chars[0] = rxbuff[34];
                inverter[invNo].solar_cell_current	= (unsigned int)(fdata.value*10) / 10;
                //DC-KW
                fdata.chars[3] = rxbuff[35];
                fdata.chars[2] = rxbuff[36];
                fdata.chars[1] = rxbuff[37];
                fdata.chars[0] = rxbuff[38];                                     
                inverter[invNo].power_solar			= (unsigned int)(fdata.value/100);// / 10;   
                                                                                                      
                //선간전압 RS상
                fdata.chars[3] = rxbuff[71];
                fdata.chars[2] = rxbuff[72];
                fdata.chars[1] = rxbuff[73];
                fdata.chars[0] = rxbuff[74];
                inverter[invNo].inv_u_voltage		= (unsigned int)(fdata.value);// / 10;  
                //선간전압 ST상
                fdata.chars[3] = rxbuff[75];
                fdata.chars[2] = rxbuff[76];
                fdata.chars[1] = rxbuff[77];
                fdata.chars[0] = rxbuff[78];
                inverter[invNo].inv_v_voltage     	= (unsigned int)(fdata.value);// / 10;  
                //선간전압 TR상
                fdata.chars[3] = rxbuff[79];
                fdata.chars[2] = rxbuff[80];
                fdata.chars[1] = rxbuff[81];
                fdata.chars[0] = rxbuff[82];
                inverter[invNo].inv_w_voltage     	= (unsigned int)(fdata.value);// / 10;
                                                                                                                                             
                //전류 R상
                fdata.chars[3] = rxbuff[83];
                fdata.chars[2] = rxbuff[84];
                fdata.chars[1] = rxbuff[85];
                fdata.chars[0] = rxbuff[86];
                inverter[invNo].inv_u_current      = (unsigned int)(fdata.value*10) / 10;
                //전류 S상
                fdata.chars[3] = rxbuff[87];
                fdata.chars[2] = rxbuff[88];
                fdata.chars[1] = rxbuff[89];
                fdata.chars[0] = rxbuff[90];
                inverter[invNo].inv_v_current      = (unsigned int)(fdata.value*10) / 10; 
                //전류 T상
                fdata.chars[3] = rxbuff[91];
                fdata.chars[2] = rxbuff[92];
                fdata.chars[1] = rxbuff[93];
                fdata.chars[0] = rxbuff[94];
                inverter[invNo].inv_w_current      = (unsigned int)(fdata.value*10) / 10;  
                //주파수
                fdata.chars[3] = rxbuff[59];
                fdata.chars[2] = rxbuff[60];
                fdata.chars[1] = rxbuff[61];
                fdata.chars[0] = rxbuff[62];
                inverter[invNo].inv_frequency		= (unsigned int)(fdata.value*10); 
                //총 역률
                fdata.chars[3] = rxbuff[55];
                fdata.chars[2] = rxbuff[56];
                fdata.chars[1] = rxbuff[57];
                fdata.chars[0] = rxbuff[58];                                     
                //gipam.powerFactor = (signed int)(abs)(fdata.value*10);       
                inverter[invNo].power_inv_pf		= (signed int)(abs)(fdata.value*10);

                //AC-KW (현재 출력)
                fdata.chars[3] = rxbuff[47];
                fdata.chars[2] = rxbuff[48];
                fdata.chars[1] = rxbuff[49];
                fdata.chars[0] = rxbuff[50];
                inverter[invNo].power_inv_now 		= (unsigned int)(fdata.value/100);// / 10;          

                //DAY-TOTAL
                fdata.chars[3] = rxbuff[63];
                fdata.chars[2] = rxbuff[64];
                fdata.chars[1] = rxbuff[65];
                fdata.chars[0] = rxbuff[66];
                inverter[invNo].power_inv_day_total =  (unsigned int)(fdata.value/1000);// / 10;
                      
//                //전체 유효전력량
//                fdata.chars[3] = rxbuff[67];
//                fdata.chars[2] = rxbuff[68];
//                fdata.chars[1] = rxbuff[69];
//                fdata.chars[0] = rxbuff[70];                                     
//                //gipam.longData[0] = (unsigned long int)(fdata.value);
//                inverter[invNo].power_inv_total     = (unsigned long int)(fdata.value) / 1000;         

                lim1 = Bytes_to_Uint(rxbuff[143],rxbuff[144]);
                lim1 <<= 16; 
                lim1  += Bytes_to_Uint(rxbuff[145],rxbuff[146]);
                lim1 *= 1000; 

                lim2 = Bytes_to_Uint(rxbuff[147],rxbuff[148]);
                lim2 <<= 16; 
                lim2  += Bytes_to_Uint(rxbuff[149],rxbuff[150]);
                lim2 /= 1000; 
                         
                inverter[invNo].power_inv_total     = lim1 + lim2;

                                            
                sendInverterCount[invNo] = 0;
                buzzer_flag |= BUZZER_TIC;
                sprintf(str,"RX%02d",invNo+1);
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