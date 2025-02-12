//DongYang ENP INVERTER, 485 ID는 인버터 일련번호 끝 2자리입니다........
//발전소마다 인버터 개별 설정해야합니다.
#define DYENP_START_ID	0x3A

void sendInverterRead_DYENP(void) {  
    unsigned int retVal;
    char sendBuff[10];   
    
    switch(inverter_seq) {
        case 0:
            inverter_seq++;
			if (sendInverterCount[0] < 100) {
            	sendInverterCount[0]++;
            }
            break;     
        case 1:     //Inv-1: 
			rx_seq0 = 0; 
			sendBuff[0] = 0x0A;	//Header-1
			sendBuff[1] = 0x96;	//Header-2
            sendBuff[2] = eeDYENPaddress[inverter_address-1]; //Station ID
            sendBuff[3] = 0x54; //COMMAND
            sendBuff[4] = 0x18; //Don't Care
            sendBuff[5] = 0x05; //Fixed Data
    		retVal = sendBuff[2] + sendBuff[3] + sendBuff[4];         
                        
            putchar0(sendBuff[1]); 
            putchar0(sendBuff[2]); //Modbus Address High
            putchar0(sendBuff[3]); //Modbus Address Low
            putchar0(sendBuff[4]); //Data Count High
            putchar0(sendBuff[5]); //Data Count Low           
		    putchar0(retVal % 0x100);   //2a.73
            
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_udr0 (sendBuff[0]);  
#else  
			UDR0 = sendBuff[0] ;  
#endif        
            sprintf(str,"TX-1");     
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
        case 6:     //Inv-2  
			rx_seq0 = 0; 
			sendBuff[0] = 0x0A;	//Header-1
			sendBuff[1] = 0x96;	//Header-2
            sendBuff[2] = eeDYENPaddress[inverter_address-1];; //Station ID
            sendBuff[3] = 0x54; //COMMAND
            sendBuff[4] = 0x18; //Don't Care
            sendBuff[5] = 0x05; //Fixed Data
    		retVal = sendBuff[2] + sendBuff[3] + sendBuff[4];         
                        
            putchar0(sendBuff[1]); 
            putchar0(sendBuff[2]); //Modbus Address High
            putchar0(sendBuff[3]); //Modbus Address Low
            putchar0(sendBuff[4]); //Data Count High
            putchar0(sendBuff[5]); //Data Count Low           
		    putchar0(retVal % 0x100);   //2a.73
            
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_udr0 (sendBuff[0]);  
#else  
			UDR0 = sendBuff[0] ;  
#endif        
            sprintf(str,"TX-2");     
            put_str(4,16,str,1);   
            rx_led_delay = 2500;
            inverter_seq++;             
            break;         
        case 7:
        case 8:
        case 9:
            inverter_seq++;
            break;     

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
        case 11:     //Inv-3:  
			rx_seq0 = 0; 
			sendBuff[0] = 0x0A;	//Header-1
			sendBuff[1] = 0x96;	//Header-2
            sendBuff[2] = eeDYENPaddress[inverter_address-1];; //Station ID
            sendBuff[3] = 0x54; //COMMAND
            sendBuff[4] = 0x18; //Don't Care
            sendBuff[5] = 0x05; //Fixed Data
    		retVal = sendBuff[2] + sendBuff[3] + sendBuff[4];         
                        
            putchar0(sendBuff[1]); 
            putchar0(sendBuff[2]); //Modbus Address High
            putchar0(sendBuff[3]); //Modbus Address Low
            putchar0(sendBuff[4]); //Data Count High
            putchar0(sendBuff[5]); //Data Count Low           
		    putchar0(retVal % 0x100);   //2a.73
            
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_udr0 (sendBuff[0]);  
#else  
			UDR0 = sendBuff[0] ;  
#endif        
            sprintf(str,"TX-3");     
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
        case 16:     //Inv-4  
			rx_seq0 = 0; 
			sendBuff[0] = 0x0A;	//Header-1
			sendBuff[1] = 0x96;	//Header-2
            sendBuff[2] = eeDYENPaddress[inverter_address-1]; //Station ID
            sendBuff[3] = 0x54; //COMMAND
            sendBuff[4] = 0x18; //Don't Care
            sendBuff[5] = 0x05; //Fixed Data
    		retVal = sendBuff[2] + sendBuff[3] + sendBuff[4];         
                        
            putchar0(sendBuff[1]); 
            putchar0(sendBuff[2]); //Modbus Address High
            putchar0(sendBuff[3]); //Modbus Address Low
            putchar0(sendBuff[4]); //Data Count High
            putchar0(sendBuff[5]); //Data Count Low           
		    putchar0(retVal % 0x100);   //2a.73
            
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_udr0 (sendBuff[0]);  
#else  
			UDR0 = sendBuff[0] ;  
#endif        
            sprintf(str,"TX-4");     
            put_str(4,16,str,1);   
            rx_led_delay = 2500;
            inverter_seq++;             
            break;         
        case 17:
        case 18:
        case 19:
            inverter_seq++;
            break;
                 
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
        case 21:     //Inv-5  
			rx_seq0 = 0; 
			sendBuff[0] = 0x0A;	//Header-1
			sendBuff[1] = 0x96;	//Header-2
            sendBuff[2] = eeDYENPaddress[inverter_address-1]; //Station ID
            sendBuff[3] = 0x54; //COMMAND
            sendBuff[4] = 0x18; //Don't Care
            sendBuff[5] = 0x05; //Fixed Data
    		retVal = sendBuff[2] + sendBuff[3] + sendBuff[4];         
                        
            putchar0(sendBuff[1]); 
            putchar0(sendBuff[2]); //Modbus Address High
            putchar0(sendBuff[3]); //Modbus Address Low
            putchar0(sendBuff[4]); //Data Count High
            putchar0(sendBuff[5]); //Data Count Low           
		    putchar0(retVal % 0x100);   //2a.73
            
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_udr0 (sendBuff[0]);  
#else  
			UDR0 = sendBuff[0] ;  
#endif        
            sprintf(str,"TX-5");     
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
        case 26:     //Inv-6  
			rx_seq0 = 0; 
			sendBuff[0] = 0x0A;	//Header-1
			sendBuff[1] = 0x96;	//Header-2
            sendBuff[2] = eeDYENPaddress[inverter_address-1]; //Station ID
            sendBuff[3] = 0x54; //COMMAND
            sendBuff[4] = 0x18; //Don't Care
            sendBuff[5] = 0x05; //Fixed Data
    		retVal = sendBuff[2] + sendBuff[3] + sendBuff[4];         
                        
            putchar0(sendBuff[1]); 
            putchar0(sendBuff[2]); //Modbus Address High
            putchar0(sendBuff[3]); //Modbus Address Low
            putchar0(sendBuff[4]); //Data Count High
            putchar0(sendBuff[5]); //Data Count Low           
		    putchar0(retVal % 0x100);   //2a.73
            
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_udr0 (sendBuff[0]);  
#else  
			UDR0 = sendBuff[0] ;  
#endif        
            sprintf(str,"TX-6");     
            put_str(4,16,str,1);   
            rx_led_delay = 2500;
            inverter_seq++;             
            break;         
        case 27:
        case 28:
        case 29:
            inverter_seq++;
            break;     

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
        case 31:     //Inv-7  
			rx_seq0 = 0; 
			sendBuff[0] = 0x0A;	//Header-1
			sendBuff[1] = 0x96;	//Header-2
            sendBuff[2] = eeDYENPaddress[inverter_address-1]; //Station ID
            sendBuff[3] = 0x54; //COMMAND
            sendBuff[4] = 0x18; //Don't Care
            sendBuff[5] = 0x05; //Fixed Data
    		retVal = sendBuff[2] + sendBuff[3] + sendBuff[4];         
                        
            putchar0(sendBuff[1]); 
            putchar0(sendBuff[2]); //Modbus Address High
            putchar0(sendBuff[3]); //Modbus Address Low
            putchar0(sendBuff[4]); //Data Count High
            putchar0(sendBuff[5]); //Data Count Low           
		    putchar0(retVal % 0x100);   //2a.73
            
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_udr0 (sendBuff[0]);  
#else  
			UDR0 = sendBuff[0] ;  
#endif        
            sprintf(str,"TX-7");     
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
        case 36:     //Inv-8  
			rx_seq0 = 0; 
			sendBuff[0] = 0x0A;	//Header-1
			sendBuff[1] = 0x96;	//Header-2
            sendBuff[2] = eeDYENPaddress[inverter_address-1]; //Station ID
            sendBuff[3] = 0x54; //COMMAND
            sendBuff[4] = 0x18; //Don't Care
            sendBuff[5] = 0x05; //Fixed Data
    		retVal = sendBuff[2] + sendBuff[3] + sendBuff[4];         
                        
            putchar0(sendBuff[1]); 
            putchar0(sendBuff[2]); //Modbus Address High
            putchar0(sendBuff[3]); //Modbus Address Low
            putchar0(sendBuff[4]); //Data Count High
            putchar0(sendBuff[5]); //Data Count Low           
		    putchar0(retVal % 0x100);   //2a.73
            
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_udr0 (sendBuff[0]);  
#else  
			UDR0 = sendBuff[0] ;  
#endif        
            sprintf(str,"TX-8");     
            put_str(4,16,str,1);   
            rx_led_delay = 2500;
            inverter_seq++;             
            break;         
        case 37:
        case 38:
        case 39:
            inverter_seq++;
            break;     

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
        case 41:     //Inv-9  
			rx_seq0 = 0; 
			sendBuff[0] = 0x0A;	//Header-1
			sendBuff[1] = 0x96;	//Header-2
            sendBuff[2] = eeDYENPaddress[inverter_address-1]; //Station ID
            sendBuff[3] = 0x54; //COMMAND
            sendBuff[4] = 0x18; //Don't Care
            sendBuff[5] = 0x05; //Fixed Data
    		retVal = sendBuff[2] + sendBuff[3] + sendBuff[4];         
                        
            putchar0(sendBuff[1]); 
            putchar0(sendBuff[2]); //Modbus Address High
            putchar0(sendBuff[3]); //Modbus Address Low
            putchar0(sendBuff[4]); //Data Count High
            putchar0(sendBuff[5]); //Data Count Low           
		    putchar0(retVal % 0x100);   //2a.73
            
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_udr0 (sendBuff[0]);  
#else  
			UDR0 = sendBuff[0] ;  
#endif        
            sprintf(str,"TX-9");     
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
        case 46:     //Inv-10  
			rx_seq0 = 0; 
			sendBuff[0] = 0x0A;	//Header-1
			sendBuff[1] = 0x96;	//Header-2
            sendBuff[2] = eeDYENPaddress[inverter_address-1]; //Station ID  10번 인버터가 ID오류로 인하여 변경됨...
            sendBuff[3] = 0x54; //COMMAND
            sendBuff[4] = 0x18; //Don't Care
            sendBuff[5] = 0x05; //Fixed Data
    		retVal = sendBuff[2] + sendBuff[3] + sendBuff[4];         
                        
            putchar0(sendBuff[1]); 
            putchar0(sendBuff[2]); //Modbus Address High
            putchar0(sendBuff[3]); //Modbus Address Low
            putchar0(sendBuff[4]); //Data Count High
            putchar0(sendBuff[5]); //Data Count Low           
		    putchar0(retVal % 0x100);   //2a.73
            
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_udr0 (sendBuff[0]);  
#else  
			UDR0 = sendBuff[0] ;  
#endif        
            sprintf(str,"TX-A");     
            put_str(4,16,str,1);   
            rx_led_delay = 2500;
            inverter_seq++;             
            break;         
        case 47:
        case 48:
        case 49:
            inverter_seq++;
            break;
                 
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
        case 51:     //Inv-11(B)  
			rx_seq0 = 0; 
			sendBuff[0] = 0x0A;	//Header-1
			sendBuff[1] = 0x96;	//Header-2
            sendBuff[2] = eeDYENPaddress[inverter_address-1]; //Station ID
            sendBuff[3] = 0x54; //COMMAND
            sendBuff[4] = 0x18; //Don't Care
            sendBuff[5] = 0x05; //Fixed Data
    		retVal = sendBuff[2] + sendBuff[3] + sendBuff[4];         
                        
            putchar0(sendBuff[1]); 
            putchar0(sendBuff[2]); //Modbus Address High
            putchar0(sendBuff[3]); //Modbus Address Low
            putchar0(sendBuff[4]); //Data Count High
            putchar0(sendBuff[5]); //Data Count Low           
		    putchar0(retVal % 0x100);   //2a.73
            
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_udr0 (sendBuff[0]);  
#else  
			UDR0 = sendBuff[0] ;  
#endif        
            sprintf(str,"TX-B");     
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
        case 56:     //Inv-12(C)  
			rx_seq0 = 0; 
			sendBuff[0] = 0x0A;	//Header-1
			sendBuff[1] = 0x96;	//Header-2
            sendBuff[2] = eeDYENPaddress[inverter_address-1]; //Station ID
            sendBuff[3] = 0x54; //COMMAND
            sendBuff[4] = 0x18; //Don't Care
            sendBuff[5] = 0x05; //Fixed Data
    		retVal = sendBuff[2] + sendBuff[3] + sendBuff[4];         
                        
            putchar0(sendBuff[1]); 
            putchar0(sendBuff[2]); //Modbus Address High
            putchar0(sendBuff[3]); //Modbus Address Low
            putchar0(sendBuff[4]); //Data Count High
            putchar0(sendBuff[5]); //Data Count Low           
		    putchar0(retVal % 0x100);   //2a.73
            
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_udr0 (sendBuff[0]);  
#else  
			UDR0 = sendBuff[0] ;  
#endif        
            sprintf(str,"TX-9");     
            put_str(4,16,str,1);   
            rx_led_delay = 2500;
            inverter_seq++;             
            break;         
        case 57:
        case 58:
        case 59:
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



void rx0Control_DYENP(void) {   
	char rxdata;   
    unsigned int curr1,curr2;
	rxdata = getchar0();
	
	switch(rx_seq0) {
		case 0: //Header-1        
        	if (rxdata == 0xB1) {
				rcnt = 0;     
                chksum0 = rxdata;      
                memset(rxbuff,0,sizeof(rxbuff));
                rxbuff[rcnt++] = rxdata;
                timeout0 = 250;
            	rx_seq0++;
            }
			break;        
        case 1: //Header-2       
        	chksum0 ^= rxdata;
            rxbuff[rcnt++] = rxdata;
            if (rxdata == 0xB5) {
                rx_seq0++;
            } else {
                rx_seq0 = 0;
            }                     
            break;
        case 2: 
        	chksum0 ^= rxdata;
            rxbuff[rcnt++] = rxdata;

            if (rcnt == 39) {
                rx_seq0++;
            }
            break;
        case 3:
        	rchksum0 = rxdata;

//sprintf(str,"RCHK:%02X,%02X  ",rchksum0, chksum0);
//put_str(0,0,str,1);   

            if (rchksum0 == chksum0) {
                //invNo = 0;
        		if (rxbuff[2] < 100) {
                    invNo = inverter_address - 1;   
                    //if (invNo == 11) invNo = 9;
                        
                    inverter[invNo].solar_cell_voltage  = Bytes_to_Uint(rxbuff[4],rxbuff[3]) / 10;
					curr1 = Bytes_to_Uint(rxbuff[6],rxbuff[5]);
					curr2 = Bytes_to_Uint(rxbuff[12],rxbuff[11]);

//sprintf(str,"RCHK:%03d,%03d  ",curr1, curr2);
//put_str(0,0,str,1);   

                    inverter[invNo].solar_cell_current  = (curr1 + curr2) / 100;            
                    inverter[invNo].power_solar         = Bytes_to_Uint(rxbuff[8],rxbuff[7]) / 100; 
                    inverter[invNo].inv_u_voltage     	= Bytes_to_Uint(rxbuff[16],rxbuff[15]) / 10; 
                    inverter[invNo].inv_v_voltage     	= Bytes_to_Uint(rxbuff[16],rxbuff[15]) / 10; 
                    inverter[invNo].inv_w_voltage     	= Bytes_to_Uint(rxbuff[16],rxbuff[15]) / 10; 
                    inverter[invNo].inv_u_current      	= Bytes_to_Uint(rxbuff[18],rxbuff[17]) / 100;
                    inverter[invNo].inv_v_current      	= Bytes_to_Uint(rxbuff[18],rxbuff[17]) / 100;
                    inverter[invNo].inv_w_current      	= Bytes_to_Uint(rxbuff[18],rxbuff[17]) / 100;
                    inverter[invNo].power_inv_now       = Bytes_to_Uint(rxbuff[20],rxbuff[19]) / 10;  
                    inverter[invNo].inv_frequency       = Bytes_to_Uint(rxbuff[22],rxbuff[21]);
                    inverter[invNo].power_inv_day_total = Bytes_to_Uint(rxbuff[27],rxbuff[26]) / 100;
                    inverter[invNo].power_inv_total     = Bytes_to_Uint(0,rxbuff[25]);
                    inverter[invNo].power_inv_total   <<= 16; 
                    inverter[invNo].power_inv_total    += Bytes_to_Uint(rxbuff[24],rxbuff[23]); 
                        
                    inverter[invNo].inverter_status[0] = Bytes_to_Uint(0,rxbuff[34]);            
                    inverter[invNo].inverter_status[1] = Bytes_to_Uint(0,rxbuff[35]);              
                    inverter[invNo].inverter_status[2] = Bytes_to_Uint(rxbuff[36],rxbuff[37]);             
                    inverter[invNo].inverter_status[3] = Bytes_to_Uint(0,rxbuff[38]);             
                    
//                    inverter[invNo].solar_cell_voltage  /= 10;
//                    inverter[invNo].solar_cell_current  /= 10;            
//                    inverter[invNo].inv_u_voltage     /= 10; 
//                    inverter[invNo].inv_v_voltage     /= 10; 
//                    inverter[invNo].inv_w_voltage     /= 10;
//                    inverter[invNo].inv_u_current      /= 10;
//                    inverter[invNo].inv_v_current      /= 10;
//                    inverter[invNo].inv_w_current      /= 10;
//                    inverter[invNo].power_inv_day_total /= 10;

                    sendInverterCount[invNo] = 0;
                    //buzzer_flag |= BUZZER_TIC;
                    sprintf(str,"RX%02d",invNo+1);
                    put_str(4,16,str,1);   
                    rx_led_delay = 2500;
				}
            }
            rx_seq0 = 0;
            break;

		default:
			rx_seq0 = 0;
			break;
	}
}
