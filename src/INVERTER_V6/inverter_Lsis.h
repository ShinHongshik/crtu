void sendInverterRead_Lsis50K(void) {
    switch(inverter_seq) {
        case 0:
			if (sendInverterCount[0] < 100) {
            	sendInverterCount[0]++;
            }       
            timeout0 = 250;
            inverter_seq++;
            break;     
        case 1:     //Inverter Status 0x0031~33
            inv_command = 0x31;		//01 03 00 31 00 03 54 04 =>01 03 06 00 01 00 03 00 01 2d 75
            putchar0(0x03);
            putchar0(0x00);
            putchar0(inv_command);
            putchar0(0x00);
            putchar0(0x03);
            putchar0(0x54);
            putchar0(0x04);
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
        case 2:		//Inv-1:Fault Infomation
            inv_command = 0x0C;		//01 03 00 0C 00 02 04 08 =>01 03 04 00 00 00 00 fa 33 ff 
            putchar0(0x03);
            putchar0(0x00);
            putchar0(inv_command);
            putchar0(0x00);
            putchar0(0x02);
            putchar0(0x04);
            putchar0(0x08);
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x01);  
#else  
			UDR0 = 0x01 ;  
#endif  
            inverter_seq++;
            break;                       
        case 3:     //Inv-1:Inverter voltage / current / frequency
            inv_command = 0x10;		//01 03 00 10 00 08 45 C9 =>01 03 10 0f 83 0f 92 0f 86 01 72 01 67 01 6a 00 00 02 58 eb a1 
            putchar0(0x03);
            putchar0(0x00);
            putchar0(inv_command);
            putchar0(0x00);
            putchar0(0x08);
            putchar0(0x45);
            putchar0(0xC9);
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x01);  
#else  
			UDR0 = 0x01 ;  
#endif  
            inverter_seq++;
            break;                       
        case 4:     //Inv-1:Solar voltage / current
            inv_command = 0x29;		//01 03 00 29 00 02 15 C3 =>01 03 04 15 1c 00 dd ff a0   
        														
            putchar0(0x03);
            putchar0(0x00);
            putchar0(inv_command);
            putchar0(0x00);
            putchar0(0x02);
            putchar0(0x15);
            putchar0(0xC3);
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x01);  
#else  
			UDR0 = 0x01 ;  
#endif  
            inverter_seq++;
            break;                       
        case 5:     //Inv-1:Solar and INV power
            inv_command = 0x19;		//01 03 00 19 00 06 14 0F =>01 03 0c 00 54 00 51 01 24 03 6a 00 16 0e 30 2e 96  
            putchar0(0x03);
            putchar0(0x00);
            putchar0(inv_command);
            putchar0(0x00);
            putchar0(0x06);
            putchar0(0x14);
            putchar0(0x0f);
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x01);  
#else  
			UDR0 = 0x01 ;  
#endif  
            inverter_seq++;
            break;                       
        case 6:
        case 7:
        case 8:
        case 9:
            inverter_seq++;
            break;      
        
        //// Inv-2 ////////////////////////////////////////////////////       
        case 10:  
        	if (eeInverterCount > 1) {  
                if (sendInverterCount[1] < 100) {
                    sendInverterCount[1]++;
                }
            timeout0 = 250;
            	inverter_seq++;
        	} else {
				inverter_seq = 0;            	
            }
            break;                 
        case 11:     //Inverter2 Status 0x0031~33
            inv_command = 0x31;		//02 03 00 31 00 03 54 37 =>01 03 06 00 01 00 03 00 01 2d 75
            putchar0(0x03);
            putchar0(0x00);
            putchar0(inv_command);
            putchar0(0x00);
            putchar0(0x03);
            putchar0(0x54);
            putchar0(0x37);
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
        case 12:		//Inv-2:Fault Infomation
            inv_command = 0x0C;		//02 03 00 0C 00 02 04 3B =>01 03 04 00 00 00 00 fa 33 ff 
            putchar0(0x03);
            putchar0(0x00);
            putchar0(inv_command);
            putchar0(0x00);
            putchar0(0x02);
            putchar0(0x04);
            putchar0(0x3b);
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x02);  
#else  
			UDR0 = 0x02 ;  
#endif  
            inverter_seq++;
            break;                       
        case 13:     //Inv-2:Inverter voltage / current / frequency
            inv_command = 0x10;		//02 03 00 10 00 08 45 FA =>01 03 10 0f 83 0f 92 0f 86 01 72 01 67 01 6a 00 00 02 58 eb a1 
            putchar0(0x03);
            putchar0(0x00);
            putchar0(inv_command);
            putchar0(0x00);
            putchar0(0x08);
            putchar0(0x45);
            putchar0(0xfa);
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x02);  
#else  
			UDR0 = 0x02 ;  
#endif  
            inverter_seq++;
            break;                       
        case 14:     //Inv-2:Solar voltage / current
            inv_command = 0x29;		//02 03 00 29 00 02 15 F0 =>01 03 04 15 1c 00 dd ff a0   
        														
            putchar0(0x03);
            putchar0(0x00);
            putchar0(inv_command);
            putchar0(0x00);
            putchar0(0x02);
            putchar0(0x15);
            putchar0(0xf0);
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x02);  
#else  
			UDR0 = 0x02 ;  
#endif  
            inverter_seq++;
            break;                       
        case 15:     //Inv-2:Solar and INV power
            inv_command = 0x19;		//02 03 00 19 00 06 14 3C =>01 03 0c 00 54 00 51 01 24 03 6a 00 16 0e 30 2e 96  
            putchar0(0x03);
            putchar0(0x00);
            putchar0(inv_command);
            putchar0(0x00);
            putchar0(0x06);
            putchar0(0x14);
            putchar0(0x3c);
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x02);  
#else  
			UDR0 = 0x02 ;  
#endif  
            inverter_seq++;
            break;                       
        case 16:
        case 17:
        case 18:
        case 19:
            inverter_seq++;
            break;     
                   
        //// Inv-3 ////////////////////////////////////////////////////      
        case 20:  
        	if (eeInverterCount > 2) {  
                if (sendInverterCount[2] < 100) {
                    sendInverterCount[2]++;
                }
            timeout0 = 250;
            	inverter_seq++;
        	} else {
				inverter_seq = 0;            	
            }
            break;                 
        case 21:     //Inverter3 Status 0x0031~33
            inv_command = 0x31;		//03 03 00 31 00 03 55 E6 =>01 03 06 00 01 00 03 00 01 2d 75
            putchar0(0x03);
            putchar0(0x00);
            putchar0(inv_command);
            putchar0(0x00);
            putchar0(0x03);
            putchar0(0x55);
            putchar0(0xE6);
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
                                               
        case 22:		//Inv-3:Fault Infomation
            inv_command = 0x0C;		//03 03 00 0C 00 02 05 EA =>01 03 04 00 00 00 00 fa 33 ff 
            putchar0(0x03);
            putchar0(0x00);
            putchar0(inv_command);
            putchar0(0x00);
            putchar0(0x02);
            putchar0(0x05);
            putchar0(0xEA);
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x03);  
#else  
			UDR0 = 0x03 ;  
#endif  
            inverter_seq++;
            break;                       
            
            
        case 23:     //Inv-3:Inverter voltage / current / frequency
            inv_command = 0x10;		//03 03 00 10 00 08 44 2B =>01 03 10 0f 83 0f 92 0f 86 01 72 01 67 01 6a 00 00 02 58 eb a1 
            putchar0(0x03);
            putchar0(0x00);
            putchar0(inv_command);
            putchar0(0x00);
            putchar0(0x08);
            putchar0(0x44);
            putchar0(0x2B);
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x03);  
#else  
			UDR0 = 0x03 ;  
#endif  
            inverter_seq++;
            break;                       

        case 24:     //Inv-3:Solar voltage / current
            inv_command = 0x29;		//03 03 00 29 00 02 14 21 =>01 03 04 15 1c 00 dd ff a0   
        														
            putchar0(0x03);
            putchar0(0x00);
            putchar0(inv_command);
            putchar0(0x00);
            putchar0(0x02);
            putchar0(0x14);
            putchar0(0x21);
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x03);  
#else  
			UDR0 = 0x03 ;  
#endif  
            inverter_seq++;
            break;                       

        case 25:     //Inv-3:Solar and INV power
            inv_command = 0x19;		//03 03 00 19 00 06 15 ED =>01 03 0c 00 54 00 51 01 24 03 6a 00 16 0e 30 2e 96  
            putchar0(0x03);
            putchar0(0x00);
            putchar0(inv_command);
            putchar0(0x00);
            putchar0(0x06);
            putchar0(0x15);
            putchar0(0xED);
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x03);  
#else  
			UDR0 = 0x03 ;  
#endif  
            inverter_seq++;
            break;                       
        case 26:
        case 27:
        case 28:
        case 29:
            inverter_seq++;
            break;     


        //// Inv-4 ////////////////////////////////////////////////////      
        case 30:  
        	if (eeInverterCount > 3) {  
                if (sendInverterCount[3] < 100) {
                    sendInverterCount[3]++;
                }
            timeout0 = 250;
            	inverter_seq++;
        	} else {
				inverter_seq = 0;            	
            }
            break;                 
        case 31:     //Inverter4 Status 0x0031~33
            inv_command = 0x31;		//04 03 00 31 00 03 54 51 =>01 03 06 00 01 00 03 00 01 2d 75
            putchar0(0x03);
            putchar0(0x00);
            putchar0(inv_command);
            putchar0(0x00);
            putchar0(0x03);
            putchar0(0x54);
            putchar0(0x51);
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
                                               
        case 32:		//Inv-4:Fault Infomation
            inv_command = 0x0C;		//04 03 00 0C 00 02 04 5D =>01 03 04 00 00 00 00 fa 33 ff 
            putchar0(0x03);
            putchar0(0x00);
            putchar0(inv_command);
            putchar0(0x00);
            putchar0(0x02);
            putchar0(0x04);
            putchar0(0x5D);
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x04);  
#else  
			UDR0 = 0x04 ;  
#endif  
            inverter_seq++;
            break;                       
            
            
        case 33:     //Inv-4:Inverter voltage / current / frequency
            inv_command = 0x10;		//04 03 00 10 00 08 45 9C =>01 03 10 0f 83 0f 92 0f 86 01 72 01 67 01 6a 00 00 02 58 eb a1 
            putchar0(0x03);
            putchar0(0x00);
            putchar0(inv_command);
            putchar0(0x00);
            putchar0(0x08);
            putchar0(0x45);
            putchar0(0x9C);
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x04);  
#else  
			UDR0 = 0x04 ;  
#endif  
            inverter_seq++;
            break;                       

        case 34:     //Inv-4:Solar voltage / current
            inv_command = 0x29;		//04 03 00 29 00 02 15 96 =>01 03 04 15 1c 00 dd ff a0   
        														
            putchar0(0x03);
            putchar0(0x00);
            putchar0(inv_command);
            putchar0(0x00);
            putchar0(0x02);
            putchar0(0x15);
            putchar0(0x96);
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x04);  
#else  
			UDR0 = 0x04 ;  
#endif  
            inverter_seq++;
            break;                       

        case 35:     //Inv-4:Solar and INV power
            inv_command = 0x19;		//04 03 00 19 00 06 14 5A =>01 03 0c 00 54 00 51 01 24 03 6a 00 16 0e 30 2e 96  
            putchar0(0x03);
            putchar0(0x00);
            putchar0(inv_command);
            putchar0(0x00);
            putchar0(0x06);
            putchar0(0x14);
            putchar0(0x5A);
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x04);  
#else  
			UDR0 = 0x04 ;  
#endif  
            inverter_seq++;
            break;                       
        case 36:
        case 37:
        case 38:
        case 39:
            inverter_seq++;
            break;     



        //// Inv-5 ////////////////////////////////////////////////////      
        case 40:  
        	if (eeInverterCount > 4) {  
                if (sendInverterCount[4] < 100) {
                    sendInverterCount[4]++;
                }
            timeout0 = 250;
            	inverter_seq++;
        	} else {
				inverter_seq = 0;            	
            }
            break;                 
        case 41:     //Inverter5 Status 0x0031~33
            inv_command = 0x31;		//05 03 00 31 00 03 55 80 =>01 03 06 00 01 00 03 00 01 2d 75
            putchar0(0x03);
            putchar0(0x00);
            putchar0(inv_command);
            putchar0(0x00);
            putchar0(0x03);
            putchar0(0x55);
            putchar0(0x80);
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
                                               
        case 42:		//Inv-5:Fault Infomation
            inv_command = 0x0C;		//05 03 00 0C 00 02 05 8C =>01 03 04 00 00 00 00 fa 33 ff 
            putchar0(0x03);
            putchar0(0x00);
            putchar0(inv_command);
            putchar0(0x00);
            putchar0(0x02);
            putchar0(0x05);
            putchar0(0x8c);
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x05);  
#else  
			UDR0 = 0x05 ;  
#endif  
            inverter_seq++;
            break;                       
            
            
        case 43:     //Inv-5:Inverter voltage / current / frequency
            inv_command = 0x10;		//05 03 00 10 00 08 44 4D =>01 03 10 0f 83 0f 92 0f 86 01 72 01 67 01 6a 00 00 02 58 eb a1 
            putchar0(0x03);
            putchar0(0x00);
            putchar0(inv_command);
            putchar0(0x00);
            putchar0(0x08);
            putchar0(0x44);
            putchar0(0x4D);
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x05);  
#else  
			UDR0 = 0x05 ;  
#endif  
            inverter_seq++;
            break;                       

        case 44:     //Inv-5:Solar voltage / current
            inv_command = 0x29;		//05 03 00 29 00 02 14 47 =>01 03 04 15 1c 00 dd ff a0   
        														
            putchar0(0x03);
            putchar0(0x00);
            putchar0(inv_command);
            putchar0(0x00);
            putchar0(0x02);
            putchar0(0x14);
            putchar0(0x47);
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x05);  
#else  
			UDR0 = 0x05 ;  
#endif  
            inverter_seq++;
            break;                       

        case 45:     //Inv-5:Solar and INV power
            inv_command = 0x19;		//05 03 00 19 00 06 15 8B =>01 03 0c 00 54 00 51 01 24 03 6a 00 16 0e 30 2e 96  
            putchar0(0x03);
            putchar0(0x00);
            putchar0(inv_command);
            putchar0(0x00);
            putchar0(0x06);
            putchar0(0x15);
            putchar0(0x8b);
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x05);  
#else  
			UDR0 = 0x05 ;  
#endif  
            inverter_seq++;
            break;                       
        case 46:
        case 47:
        case 48:
        case 49:
            inverter_seq++;
            break;     



        //// Inv-6 ////////////////////////////////////////////////////      
        case 50:  
        	if (eeInverterCount > 5) {  
                if (sendInverterCount[5] < 100) {
                    sendInverterCount[5]++;
                }
            timeout0 = 250;
            	inverter_seq++;
        	} else {
				inverter_seq = 0;            	
            }
            break;                 
        case 51:     //Inverter6 Status 0x0031~33
            inv_command = 0x31;		//06 03 00 31 00 03 55 B3 =>01 03 06 00 01 00 03 00 01 2d 75
            putchar0(0x03);
            putchar0(0x00);
            putchar0(inv_command);
            putchar0(0x00);
            putchar0(0x03);
            putchar0(0x55);
            putchar0(0xb3);
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
                                               
        case 52:		//Inv-6:Fault Infomation
            inv_command = 0x0C;		//06 03 00 0C 00 02 05 BF =>01 03 04 00 00 00 00 fa 33 ff 
            putchar0(0x03);
            putchar0(0x00);
            putchar0(inv_command);
            putchar0(0x00);
            putchar0(0x02);
            putchar0(0x05);
            putchar0(0xbf);
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x06);  
#else  
			UDR0 = 0x06 ;  
#endif  
            inverter_seq++;
            break;                       
            
            
        case 53:     //Inv-6:Inverter voltage / current / frequency
            inv_command = 0x10;		//06 03 00 10 00 08 44 7E =>01 03 10 0f 83 0f 92 0f 86 01 72 01 67 01 6a 00 00 02 58 eb a1 
            putchar0(0x03);
            putchar0(0x00);
            putchar0(inv_command);
            putchar0(0x00);
            putchar0(0x08);
            putchar0(0x44);
            putchar0(0x7e);
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x06);  
#else  
			UDR0 = 0x06 ;  
#endif  
            inverter_seq++;
            break;                       

        case 54:     //Inv-6:Solar voltage / current
            inv_command = 0x29;		//06 03 00 29 00 02 14 74 =>01 03 04 15 1c 00 dd ff a0   
        														
            putchar0(0x03);
            putchar0(0x00);
            putchar0(inv_command);
            putchar0(0x00);
            putchar0(0x02);
            putchar0(0x14);
            putchar0(0x74);
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x06);  
#else  
			UDR0 = 0x06 ;  
#endif  
            inverter_seq++;
            break;                       

        case 55:     //Inv-6:Solar and INV power
            inv_command = 0x19;		//06 03 00 19 00 06 15 B8 =>01 03 0c 00 54 00 51 01 24 03 6a 00 16 0e 30 2e 96  
            putchar0(0x03);
            putchar0(0x00);
            putchar0(inv_command);
            putchar0(0x00);
            putchar0(0x06);
            putchar0(0x15);
            putchar0(0xb8);
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x06);  
#else  
			UDR0 = 0x06 ;  
#endif  
            inverter_seq++;
            break;                       
        case 56:
        case 57:
        case 58:
        case 59:
            inverter_seq++;
            break;     



        //// Inv-7 ////////////////////////////////////////////////////      
        case 60:  
        	if (eeInverterCount > 6) {  
                if (sendInverterCount[6] < 100) {
                    sendInverterCount[6]++;
                }
            timeout0 = 250;
            	inverter_seq++;
        	} else {
				inverter_seq = 0;            	
            }
            break;                 
        case 61:     //Inverter7 Status 0x0031~33
            inv_command = 0x31;		//07 03 00 31 00 03 54 62 =>01 03 06 00 01 00 03 00 01 2d 75
            putchar0(0x03);
            putchar0(0x00);
            putchar0(inv_command);
            putchar0(0x00);
            putchar0(0x03);
            putchar0(0x54);
            putchar0(0x62);
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
                                               
        case 62:		//Inv-7:Fault Infomation
            inv_command = 0x0C;		//07 03 00 0C 00 02 04 6E =>01 03 04 00 00 00 00 fa 33 ff 
            putchar0(0x03);
            putchar0(0x00);
            putchar0(inv_command);
            putchar0(0x00);
            putchar0(0x02);
            putchar0(0x04);
            putchar0(0x6e);
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x07);  
#else  
			UDR0 = 0x07 ;  
#endif  
            inverter_seq++;
            break;                       
            
            
        case 63:     //Inv-7:Inverter voltage / current / frequency
            inv_command = 0x10;		//07 03 00 10 00 08 45 AF =>01 03 10 0f 83 0f 92 0f 86 01 72 01 67 01 6a 00 00 02 58 eb a1 
            putchar0(0x03);
            putchar0(0x00);
            putchar0(inv_command);
            putchar0(0x00);
            putchar0(0x08);
            putchar0(0x45);
            putchar0(0xaf);
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x07);  
#else  
			UDR0 = 0x07 ;  
#endif  
            inverter_seq++;
            break;                       

        case 64:     //Inv-7:Solar voltage / current
            inv_command = 0x29;		//07 03 00 29 00 02 15 A5 =>01 03 04 15 1c 00 dd ff a0   
        														
            putchar0(0x03);
            putchar0(0x00);
            putchar0(inv_command);
            putchar0(0x00);
            putchar0(0x02);
            putchar0(0x15);
            putchar0(0xa5);
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x07);  
#else  
			UDR0 = 0x07 ;  
#endif  
            inverter_seq++;
            break;                       

        case 65:     //Inv-7:Solar and INV power
            inv_command = 0x19;		//07 03 00 19 00 06 14 69 =>01 03 0c 00 54 00 51 01 24 03 6a 00 16 0e 30 2e 96  
            putchar0(0x03);
            putchar0(0x00);
            putchar0(inv_command);
            putchar0(0x00);
            putchar0(0x06);
            putchar0(0x14);
            putchar0(0x69);
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x07);  
#else  
			UDR0 = 0x07 ;  
#endif  
            inverter_seq++;
            break;                       
        case 66:
        case 67:
        case 68:
        case 69:
            inverter_seq++;
            break;     



        //// Inv-8 ////////////////////////////////////////////////////      
        case 70:  
        	if (eeInverterCount > 7) {  
                if (sendInverterCount[7] < 100) {
                    sendInverterCount[7]++;
                }
            timeout0 = 250;
            	inverter_seq++;
        	} else {
				inverter_seq = 0;            	
            }
            break;                 
        case 71:     //Inverter8 Status 0x0031~33
            inv_command = 0x31;		//08 03 00 31 00 03 54 9D =>01 03 06 00 01 00 03 00 01 2d 75
            putchar0(0x03);
            putchar0(0x00);
            putchar0(inv_command);
            putchar0(0x00);
            putchar0(0x03);
            putchar0(0x54);
            putchar0(0x9d);
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
                                               
        case 72:		//Inv-8:Fault Infomation
            inv_command = 0x0C;		//08 03 00 0C 00 02 04 91 =>01 03 04 00 00 00 00 fa 33 ff 
            putchar0(0x03);
            putchar0(0x00);
            putchar0(inv_command);
            putchar0(0x00);
            putchar0(0x02);
            putchar0(0x04);
            putchar0(0x91);
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x08);  
#else  
			UDR0 = 0x08 ;  
#endif  
            inverter_seq++;
            break;                       
            
            
        case 73:     //Inv-8:Inverter voltage / current / frequency
            inv_command = 0x10;		//08 03 00 10 00 08 45 50 =>01 03 10 0f 83 0f 92 0f 86 01 72 01 67 01 6a 00 00 02 58 eb a1 
            putchar0(0x03);
            putchar0(0x00);
            putchar0(inv_command);
            putchar0(0x00);
            putchar0(0x08);
            putchar0(0x45);
            putchar0(0x50);
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x08);  
#else  
			UDR0 = 0x08 ;  
#endif  
            inverter_seq++;
            break;                       

        case 74:     //Inv-8:Solar voltage / current
            inv_command = 0x29;		//08 03 00 29 00 02 15 5A =>01 03 04 15 1c 00 dd ff a0   
        														
            putchar0(0x03);
            putchar0(0x00);
            putchar0(inv_command);
            putchar0(0x00);
            putchar0(0x02);
            putchar0(0x15);
            putchar0(0x5a);
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x08);  
#else  
			UDR0 = 0x08 ;  
#endif  
            inverter_seq++;
            break;                       

        case 75:     //Inv-8:Solar and INV power
            inv_command = 0x19;		//08 03 00 19 00 06 14 96 =>01 03 0c 00 54 00 51 01 24 03 6a 00 16 0e 30 2e 96  
            putchar0(0x03);
            putchar0(0x00);
            putchar0(inv_command);
            putchar0(0x00);
            putchar0(0x06);
            putchar0(0x14);
            putchar0(0x96);
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x08);  
#else  
			UDR0 = 0x08 ;  
#endif  
            inverter_seq++;
            break;                       
        case 76:
        case 77:
        case 78:
        case 79:
            inverter_seq++;
            break;     



        //// Inv-9 ////////////////////////////////////////////////////      
        case 80:  
        	if (eeInverterCount > 8) {  
                if (sendInverterCount[8] < 100) {
                    sendInverterCount[8]++;
                }
            timeout0 = 250;
            	inverter_seq++;
        	} else {
				inverter_seq = 0;            	
            }
            break;                 
        case 81:     //Inverter9 Status 0x0031~33
            inv_command = 0x31;		//09 03 00 31 00 03 55 4C =>01 03 06 00 01 00 03 00 01 2d 75
            putchar0(0x03);
            putchar0(0x00);
            putchar0(inv_command);
            putchar0(0x00);
            putchar0(0x03);
            putchar0(0x55);
            putchar0(0x4c);
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
                                               
        case 82:		//Inv-9:Fault Infomation
            inv_command = 0x0C;		//09 03 00 0C 00 02 05 40 =>01 03 04 00 00 00 00 fa 33 ff 
            putchar0(0x03);
            putchar0(0x00);
            putchar0(inv_command);
            putchar0(0x00);
            putchar0(0x02);
            putchar0(0x05);
            putchar0(0x40);
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x09);  
#else  
			UDR0 = 0x09 ;  
#endif  
            inverter_seq++;
            break;                       
            
            
        case 83:     //Inv-9:Inverter voltage / current / frequency
            inv_command = 0x10;		//09 03 00 10 00 08 44 81 =>01 03 10 0f 83 0f 92 0f 86 01 72 01 67 01 6a 00 00 02 58 eb a1 
            putchar0(0x03);
            putchar0(0x00);
            putchar0(inv_command);
            putchar0(0x00);
            putchar0(0x08);
            putchar0(0x44);
            putchar0(0x81);
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x09);  
#else  
			UDR0 = 0x09 ;  
#endif  
            inverter_seq++;
            break;                       

        case 84:     //Inv-9:Solar voltage / current
            inv_command = 0x29;		//09 03 00 29 00 02 14 8B =>01 03 04 15 1c 00 dd ff a0   
        														
            putchar0(0x03);
            putchar0(0x00);
            putchar0(inv_command);
            putchar0(0x00);
            putchar0(0x02);
            putchar0(0x14);
            putchar0(0x8b);
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x09);  
#else  
			UDR0 = 0x09 ;  
#endif  
            inverter_seq++;
            break;                       

        case 85:     //Inv-9:Solar and INV power
            inv_command = 0x19;		//09 03 00 19 00 06 15 47 =>01 03 0c 00 54 00 51 01 24 03 6a 00 16 0e 30 2e 96  
            putchar0(0x03);
            putchar0(0x00);
            putchar0(inv_command);
            putchar0(0x00);
            putchar0(0x06);
            putchar0(0x15);
            putchar0(0x47);
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x09);  
#else  
			UDR0 = 0x09 ;  
#endif  
            inverter_seq++;
            break;                       
        case 86:
        case 87:
        case 88:
        case 89:
            inverter_seq++;
            break;     



        //// Inv-10 ////////////////////////////////////////////////////      
        case 90:  
        	if (eeInverterCount > 9) {  
                if (sendInverterCount[9] < 100) {
                    sendInverterCount[9]++;
                }
            timeout0 = 250;
            	inverter_seq++;
        	} else {
				inverter_seq = 0;            	
            }
            break;                 
        case 91:     //Inverter10 Status 0x0031~33
            inv_command = 0x31;		//0A 03 00 31 00 03 55 7F =>01 03 06 00 01 00 03 00 01 2d 75
            putchar0(0x03);
            putchar0(0x00);
            putchar0(inv_command);
            putchar0(0x00);
            putchar0(0x03);
            putchar0(0x55);
            putchar0(0x7f);
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x0a);  
#else  
			UDR0 = 0x0a ;  
#endif  
            sprintf(str,"TX-A");
            put_str(4,16,str,1);   
            rx_led_delay = 2500;
            inverter_seq++;
            break;                       
                                               
        case 92:		//Inv-10:Fault Infomation
            inv_command = 0x0C;		//0A 03 00 0C 00 02 05 73 =>01 03 04 00 00 00 00 fa 33 ff 
            putchar0(0x03);
            putchar0(0x00);
            putchar0(inv_command);
            putchar0(0x00);
            putchar0(0x02);
            putchar0(0x05);
            putchar0(0x73);
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x0a);  
#else  
			UDR0 = 0x0a ;  
#endif  
            inverter_seq++;
            break;                       
            
            
        case 93:     //Inv-10:Inverter voltage / current / frequency
            inv_command = 0x10;		//0A 03 00 10 00 08 44 B2 =>01 03 10 0f 83 0f 92 0f 86 01 72 01 67 01 6a 00 00 02 58 eb a1 
            putchar0(0x03);
            putchar0(0x00);
            putchar0(inv_command);
            putchar0(0x00);
            putchar0(0x08);
            putchar0(0x44);
            putchar0(0xb2);
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x0a);  
#else  
			UDR0 = 0x0a ;  
#endif  
            inverter_seq++;
            break;                       

        case 94:     //Inv-10:Solar voltage / current
            inv_command = 0x29;		//0A 03 00 29 00 02 14 B8 =>01 03 04 15 1c 00 dd ff a0   
        														
            putchar0(0x03);
            putchar0(0x00);
            putchar0(inv_command);
            putchar0(0x00);
            putchar0(0x02);
            putchar0(0x14);
            putchar0(0xb8);
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x0a);  
#else  
			UDR0 = 0x0a ;  
#endif  
            inverter_seq++;
            break;                       

        case 95:     //Inv-10:Solar and INV power
            inv_command = 0x19;		//0A 03 00 19 00 06 15 74 =>01 03 0c 00 54 00 51 01 24 03 6a 00 16 0e 30 2e 96  
            putchar0(0x03);
            putchar0(0x00);
            putchar0(inv_command);
            putchar0(0x00);
            putchar0(0x06);
            putchar0(0x15);
            putchar0(0x74);
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x0a);  
#else  
			UDR0 = 0x0a ;  
#endif  
            inverter_seq++;
            break;                       
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


void rx0Control_Lsis50K(void) {   
	char rxdata;
	rxdata = getchar0();
	
	switch(rx_seq0) {
		case 0:       
        	if ((rxdata > 0x00) && (rxdata < 11) ) {
				imInvNo = rxdata - 1;
				rcnt = 0;           
                memset(rxbuff,0,sizeof(rxbuff));
                timeout0 = 250;
            	rx_seq0++;
            }
			break;        
        case 1:    
        	if (rxdata == 0x03) {
            	rcnt = 0;
                memset(rxbuff,0,sizeof(rxbuff));
				switch(inv_command) {
            		case 0x31:	//inv_command = 0x31
                    	rx_seq0 = 10;
                        break;            
            		case 0x0C:	//inv_command = 0x31
                    	rx_seq0 = 20;
                        break;            
            		case 0x10:	//inv_command = 0x31
                    	rx_seq0 = 30;
                        break;            
            		case 0x29:	//inv_command = 0x31
                    	rx_seq0 = 40;
                        break;            
            		case 0x19:	//inv_command = 0x31
                    	rx_seq0 = 50;
                        break;      
                    case 0x00:
		            	rx_seq0 = 0;
                        break;               
                }
                
            } else {
            	rx_seq0 = 0;
            }               
            break;
        
        case 10:	//01 03 06 00 01 00 03 00 01 2d 75
        	rxbuff[rcnt++] = rxdata;       
            if (rcnt == 9) {
        		inverter[imInvNo].inverter_status[0] = (unsigned int)rxbuff[2] * 0x100 + rxbuff[4];
        		inverter[imInvNo].inverter_status[1] = (unsigned int)rxbuff[6] * 0x100;    
                inv_command = 0;
                rx_seq0 = 0;
            }               
            break;
                  
        case 20:	//01 03 00 0C 00 02 04 08 =>01 03 04 00 00 00 00 fa 33 ff
        	rxbuff[rcnt++] = rxdata;       
            if (rcnt == 7) {
        		inverter[imInvNo].inverter_status[2] = (unsigned int)rxbuff[1] * 0x100 + rxbuff[2];
        		inverter[imInvNo].inverter_status[3] = (unsigned int)rxbuff[3] * 0x100 + rxbuff[4];
                inv_command = 0;
                rx_seq0 = 0;
            }               
            break;
                    
        case 30:	//01 03 00 10 00 08 45 C9 =>01 03 10 0f 83 0f 92 0f 86 01 72 01 67 01 6a 00 00 02 58 eb a1
        	rxbuff[rcnt++] = rxdata;       
            if (rcnt == 19) {
                inverter[imInvNo].inv_u_voltage = ((unsigned int)rxbuff[1] * 0x100 + rxbuff[2]) / 10; 
                inverter[imInvNo].inv_v_voltage = ((unsigned int)rxbuff[3] * 0x100 + rxbuff[4]) / 10;
                inverter[imInvNo].inv_w_voltage = ((unsigned int)rxbuff[5] * 0x100 + rxbuff[6]) / 10;
                inverter[imInvNo].inv_u_current  = ((unsigned int)rxbuff[7] * 0x100 + rxbuff[8]) / 10;
                inverter[imInvNo].inv_v_current  = ((unsigned int)rxbuff[9] * 0x100 + rxbuff[10]) / 10;
                inverter[imInvNo].inv_w_current  = ((unsigned int)rxbuff[11] * 0x100 + rxbuff[12]) / 10;
                inverter[imInvNo].inv_frequency  = (unsigned int)rxbuff[15] * 0x100 + rxbuff[16];  
                inv_command = 0;
                rx_seq0 = 0;
            }               
            break;
                          
        case 40:	//01 03 00 29 00 02 15 C3 =>01 03 04 15 1c 00 dd ff a0
        	rxbuff[rcnt++] = rxdata;       
            if (rcnt == 7) {
                inverter[imInvNo].solar_cell_voltage = (rxbuff[1] * 0x100 + rxbuff[2]) / 10;            
                inverter[imInvNo].solar_cell_current = (rxbuff[3] * 0x100 + rxbuff[4]) / 10;            
                inv_command = 0;
                rx_seq0 = 0;
            }               
            break;
                                                                                    
        case 50:	////01 03 00 19 00 06 14 0F =>01 03 0c 00 54 00 51 01 24 03 6a 00 16 0e 30 2e 96
        	rxbuff[rcnt++] = rxdata;       
            if (rcnt == 15) {

                inverter[imInvNo].power_solar         = (unsigned int)rxbuff[1] * 0x100 + rxbuff[2]; 
                inverter[imInvNo].power_inv_now       = (unsigned int)rxbuff[3] * 0x100 + rxbuff[4];
                //inverter[0].power_inv_max       = (unsigned int)rxbuff[5] * 0x100 + rxbuff[6];
                inverter[imInvNo].power_inv_day_total = ((unsigned int)rxbuff[7] * 0x100 + rxbuff[8])/10;
                inverter[imInvNo].power_inv_total     = (unsigned long int)rxbuff[9] * 0x100 + (unsigned long int)rxbuff[10];
                inverter[imInvNo].power_inv_total    *= 100; 
                inverter[imInvNo].power_inv_total    += ((unsigned long int)rxbuff[11] * 0x100 + (unsigned long int)rxbuff[12])/100;

                inverter[imInvNo].power_inv_pf        = 995;

                sendInverterCount[imInvNo] = 0;
	            buzzer_flag |= BUZZER_TIC;
                sprintf(str,"RX-%X", imInvNo+1);
            	put_str(4,16,str,1);   
        	    rx_led_delay = 2500;
                inv_command = 0;
                rx_seq0 = 0;
            }               
            break;
            
		default:
			rx_seq0 = 0;
			break;
	}
}

