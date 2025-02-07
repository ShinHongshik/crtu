
void sendInverterRead_Kaco39(void) {
    switch(inverter_seq) {
        case 0:
            inverter_seq++;
         if (sendInverterCount[0] < 100) {
               sendInverterCount[0]++;
            }                                                                                                     
            break;     
        case 1:     //Inv-1: //23 30 31 30 0d
            //putchar0(0x23); //
            putchar0(0x30); //0
            putchar0(0x31); //1
            putchar0(0x30); //0
            putchar0(0x0d); //cr
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x23);  
#else  
			UDR0 = 0x23 ;  
#endif       

            sprintf(str,"TX01");
            put_str(4,16,str,1);   
            rx_led_delay = 2500;  
                        
            inverter_seq++;
            break;         
        case 2:
            putchar0(0x30); //0
            putchar0(0x31); //1
            putchar0(0x33); //3
            putchar0(0x0d); //cr
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x23);  
#else  
			UDR0 = 0x23 ;  
#endif       
            inverter_seq++;
            break;         
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
        case 6:     //Inv-2: //23 30 32 30 0d
            //putchar0(0x23); //
            putchar0(0x30); //0
            putchar0(0x32); //2
            putchar0(0x30); //0
            putchar0(0x0d); //cr
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x23);  
#else  
			UDR0 = 0x23 ;  
#endif  

            sprintf(str,"TX02");
            put_str(4,16,str,1);   
            rx_led_delay = 2500;  

            inverter_seq++;
            break;         
        case 7:
            putchar0(0x30); //0
            putchar0(0x32); //2
            putchar0(0x33); //3
            putchar0(0x0d); //cr
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x23);  
#else  
			UDR0 = 0x23 ;  
#endif       
            inverter_seq++;
            break;         
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
        case 11:     //Inv-3: //23 30 33 30 0d
            //putchar0(0x23); //
            putchar0(0x30); //0
            putchar0(0x33); //3
            putchar0(0x30); //0
            putchar0(0x0d); //cr
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x23);  
#else  
			UDR0 = 0x23 ;  
#endif  

            sprintf(str,"TX03");
            put_str(4,16,str,1);   
            rx_led_delay = 2500;  

            inverter_seq++;
            break;         
        case 12:
            putchar0(0x30); //0
            putchar0(0x33); //3
            putchar0(0x33); //3
            putchar0(0x0d); //cr
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x23);  
#else  
			UDR0 = 0x23 ;  
#endif       
            inverter_seq++;
            break;         
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
        case 16:     //Inv-4: //23 30 34 30 0d
            //putchar0(0x23); //
            putchar0(0x30); //0
            putchar0(0x34); //4
            putchar0(0x30); //0
            putchar0(0x0d); //cr
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x23);  
#else  
			UDR0 = 0x23 ;  
#endif  

            sprintf(str,"TX04");
            put_str(4,16,str,1);   
            rx_led_delay = 2500;  

            inverter_seq++;
            break;         
        case 17:
            putchar0(0x30); //0
            putchar0(0x34); //4
            putchar0(0x33); //3
            putchar0(0x0d); //cr
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x23);  
#else  
			UDR0 = 0x23 ;  
#endif       
            inverter_seq++;
            break;         
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
        case 21:     //Inv-5: //23 30 35 30 0d
            //putchar0(0x23); //
            putchar0(0x30); //0
            putchar0(0x35); //5
            putchar0(0x30); //0
            putchar0(0x0d); //cr
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x23);  
#else  
			UDR0 = 0x23 ;  
#endif  

            sprintf(str,"TX05");
            put_str(4,16,str,1);   
            rx_led_delay = 2500;  

            inverter_seq++;
            break;         
        case 22:
            putchar0(0x30); //0
            putchar0(0x35); //5
            putchar0(0x33); //3
            putchar0(0x0d); //cr
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x23);  
#else  
			UDR0 = 0x23 ;  
#endif       
            inverter_seq++;
            break;         
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
        case 26:     //Inv-6: //23 30 36 30 0d
            //putchar0(0x23); //
            putchar0(0x30); //0
            putchar0(0x36); //6
            putchar0(0x30); //0
            putchar0(0x0d); //cr
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x23);  
#else  
			UDR0 = 0x23 ;  
#endif  

            sprintf(str,"TX06");
            put_str(4,16,str,1);   
            rx_led_delay = 2500;  

            inverter_seq++;
            break;         
        case 27:
            putchar0(0x30); //0
            putchar0(0x36); //6
            putchar0(0x33); //3
            putchar0(0x0d); //cr
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x23);  
#else  
			UDR0 = 0x23 ;  
#endif       
            inverter_seq++;
            break;         
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
        case 31:     //Inv-7: //23 30 37 30 0d
            //putchar0(0x23); //
            putchar0(0x30); //0
            putchar0(0x37); //7
            putchar0(0x30); //0
            putchar0(0x0d); //cr
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x23);  
#else  
			UDR0 = 0x23 ;  
#endif  

            sprintf(str,"TX07");
            put_str(4,16,str,1);   
            rx_led_delay = 2500;  

            inverter_seq++;
            break;         
        case 32:
            putchar0(0x30); //0
            putchar0(0x37); //7
            putchar0(0x33); //3
            putchar0(0x0d); //cr
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x23);  
#else  
			UDR0 = 0x23 ;  
#endif       
            inverter_seq++;
            break;         
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
        case 36:     //Inv-8: //23 30 38 30 0d
            //putchar0(0x23); //
            putchar0(0x30); //0
            putchar0(0x38); //8
            putchar0(0x30); //0
            putchar0(0x0d); //cr
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x23);  
#else  
			UDR0 = 0x23 ;  
#endif  

            sprintf(str,"TX08");
            put_str(4,16,str,1);   
            rx_led_delay = 2500;  

            inverter_seq++;
            break;         
        case 37:
            putchar0(0x30); //0
            putchar0(0x38); //8
            putchar0(0x33); //3
            putchar0(0x0d); //cr
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x23);  
#else  
			UDR0 = 0x23 ;  
#endif       
            inverter_seq++;
            break;         
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
        case 41:     //Inv-9: //23 30 39 30 0d
            //putchar0(0x23); //
            putchar0(0x30); //0
            putchar0(0x39); //9
            putchar0(0x30); //0
            putchar0(0x0d); //cr
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x23);  
#else  
			UDR0 = 0x23 ;  
#endif  

            sprintf(str,"TX09");
            put_str(4,16,str,1);   
            rx_led_delay = 2500;  

            inverter_seq++;
            break;         
        case 42:
            putchar0(0x30); //0
            putchar0(0x39); //9
            putchar0(0x33); //3
            putchar0(0x0d); //cr
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x23);  
#else  
			UDR0 = 0x23 ;  
#endif       
            inverter_seq++;
            break;         
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
        case 46:     //Inv-10: //23 31 30 30 0d
            //putchar0(0x23); //
            putchar0(0x31); //1
            putchar0(0x30); //0
            putchar0(0x30); //0
            putchar0(0x0d); //cr
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x23);  
#else  
			UDR0 = 0x23 ;  
#endif  

            sprintf(str,"TX10");
            put_str(4,16,str,1);   
            rx_led_delay = 2500;  

            inverter_seq++;
            break;         
        case 47:
            putchar0(0x31); //1
            putchar0(0x30); //0
            putchar0(0x33); //3
            putchar0(0x0d); //cr
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x23);  
#else  
			UDR0 = 0x23 ;  
#endif       
            inverter_seq++;
            break;         
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
        case 51:     //Inv-11: //23 31 31 30 0d
            //putchar0(0x23); //
            putchar0(0x31); //1
            putchar0(0x31); //1
            putchar0(0x30); //0
            putchar0(0x0d); //cr
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x23);  
#else  
			UDR0 = 0x23 ;  
#endif  

            sprintf(str,"TX11");
            put_str(4,16,str,1);   
            rx_led_delay = 2500;  

            inverter_seq++;
            break;         
        case 52:
            putchar0(0x31); //1
            putchar0(0x31); //1
            putchar0(0x33); //3
            putchar0(0x0d); //cr
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x23);  
#else  
			UDR0 = 0x23 ;  
#endif       
            inverter_seq++;
            break;         
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
        case 56:     //Inv-12: //23 31 32 30 0d
            //putchar0(0x23); //
            putchar0(0x31); //1
            putchar0(0x32); //2
            putchar0(0x30); //0
            putchar0(0x0d); //cr
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x23);  
#else  
			UDR0 = 0x23 ;  
#endif  

            sprintf(str,"TX12");
            put_str(4,16,str,1);   
            rx_led_delay = 2500;  

            inverter_seq++;
            break;         
        case 57:
            putchar0(0x31); //1
            putchar0(0x32); //2
            putchar0(0x33); //3
            putchar0(0x0d); //cr
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x23);  
#else  
			UDR0 = 0x23 ;  
#endif       
            inverter_seq++;
            break;         
        case 58:
        case 59:
            inverter_seq++;
            break;           
            
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
        case 61:     //Inv-13: //23 31 33 30 0d
            //putchar0(0x23); //
            putchar0(0x31); //1
            putchar0(0x33); //3
            putchar0(0x30); //0
            putchar0(0x0d); //cr
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x23);  
#else  
			UDR0 = 0x23 ;  
#endif  

            sprintf(str,"TX13");
            put_str(4,16,str,1);   
            rx_led_delay = 2500;  

            inverter_seq++;
            break;         
        case 62:
            putchar0(0x31); //0
            putchar0(0x33); //1
            putchar0(0x33); //3
            putchar0(0x0d); //cr
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x23);  
#else  
			UDR0 = 0x23 ;  
#endif       
            inverter_seq++;
            break;         
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
        case 66:     //Inv-14: //23 31 34 30 0d
            //putchar0(0x23); //
            putchar0(0x31); //1
            putchar0(0x34); //4
            putchar0(0x30); //0
            putchar0(0x0d); //cr
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x23);  
#else  
			UDR0 = 0x23 ;  
#endif  

            sprintf(str,"TX14");
            put_str(4,16,str,1);   
            rx_led_delay = 2500;  

            inverter_seq++;
            break;         
        case 67:
            putchar0(0x31); //1
            putchar0(0x34); //4
            putchar0(0x33); //3
            putchar0(0x0d); //cr
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x23);  
#else  
			UDR0 = 0x23 ;  
#endif       
            inverter_seq++;
            break;         
        case 68:
        case 69:
            inverter_seq++;
            break;           
            
        case 70:
           if (eeInverterCount > 14) { 
                if (sendInverterCount[14] < 100) {
                    sendInverterCount[14]++;
                }            
               inverter_seq++;
           } else {
            inverter_seq = 0;               
            }
            break;     
        case 71:     //Inv-15: //23 31 33 30 0d
            //putchar0(0x23); //
            putchar0(0x31); //1
            putchar0(0x35); //5
            putchar0(0x30); //0
            putchar0(0x0d); //cr
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x23);  
#else  
			UDR0 = 0x23 ;  
#endif  

            sprintf(str,"TX15");
            put_str(4,16,str,1);   
            rx_led_delay = 2500;  

            inverter_seq++;
            break;         
        case 72:
            putchar0(0x31); //1
            putchar0(0x35); //5
            putchar0(0x33); //3
            putchar0(0x0d); //cr
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x23);  
#else  
			UDR0 = 0x23 ;  
#endif       
            inverter_seq++;
            break;         
        case 73:
        case 74:
            inverter_seq++;
            break;               


        case 75:
           if (eeInverterCount > 15) { 
                if (sendInverterCount[15] < 100) {
                    sendInverterCount[15]++;
                }            
               inverter_seq++;
           } else {
            inverter_seq = 0;               
            }
            break;     
        case 76:     //Inv-16: //23 31 34 30 0d
            //putchar0(0x23); //
            putchar0(0x31); //1
            putchar0(0x36); //6
            putchar0(0x30); //0
            putchar0(0x0d); //cr
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x23);  
#else  
			UDR0 = 0x23 ;  
#endif  

            sprintf(str,"TX16");
            put_str(4,16,str,1);   
            rx_led_delay = 2500;  

            inverter_seq++;
            break;         
        case 77:
            putchar0(0x31); //1
            putchar0(0x36); //6
            putchar0(0x33); //3
            putchar0(0x0d); //cr
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x23);  
#else  
			UDR0 = 0x23 ;  
#endif       
            inverter_seq++;
            break;         
        case 78:
        case 79:
            inverter_seq++;
            break;           
            

        case 80:
           if (eeInverterCount > 16) { 
                if (sendInverterCount[16] < 100) {
                    sendInverterCount[16]++;
                }            
               inverter_seq++;
           } else {
            inverter_seq = 0;               
            }
            break;     
        case 81:     //Inv-17: //23 31 33 30 0d
            //putchar0(0x23); //
            putchar0(0x31); //1
            putchar0(0x37); //7
            putchar0(0x30); //0
            putchar0(0x0d); //cr
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x23);  
#else  
			UDR0 = 0x23 ;  
#endif  

            sprintf(str,"TX17");
            put_str(4,16,str,1);   
            rx_led_delay = 2500;  

            inverter_seq++;
            break;         
        case 82:
            putchar0(0x31); //0
            putchar0(0x37); //7
            putchar0(0x33); //3
            putchar0(0x0d); //cr
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x23);  
#else  
			UDR0 = 0x23 ;  
#endif       
            inverter_seq++;
            break;         
        case 83:
        case 84:
            inverter_seq++;
            break;               


        case 85:
           if (eeInverterCount > 17) { 
                if (sendInverterCount[17] < 100) {
                    sendInverterCount[17]++;
                }            
               inverter_seq++;
           } else {
            inverter_seq = 0;               
            }
            break;     
        case 86:     //Inv-18: //23 31 34 30 0d
            //putchar0(0x23); //
            putchar0(0x31); //1
            putchar0(0x38); //8
            putchar0(0x30); //0
            putchar0(0x0d); //cr
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x23);  
#else  
			UDR0 = 0x23 ;  
#endif  

            sprintf(str,"TX18");
            put_str(4,16,str,1);   
            rx_led_delay = 2500;  

            inverter_seq++;
            break;         
        case 87:
            putchar0(0x31); //1
            putchar0(0x38); //8
            putchar0(0x33); //3
            putchar0(0x0d); //cr
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x23);  
#else  
			UDR0 = 0x23 ;  
#endif       
            inverter_seq++;
            break;         
        case 88:
        case 89:
            inverter_seq++;
            break;           
                        
                
        case 90:
           if (eeInverterCount > 18) { 
                if (sendInverterCount[18] < 100) {
                    sendInverterCount[18]++;
                }            
               inverter_seq++;
           } else {
            inverter_seq = 0;               
            }
            break;     
        case 91:     //Inv-19: //23 31 33 30 0d
            //putchar0(0x23); //
            putchar0(0x31); //1
            putchar0(0x39); //9
            putchar0(0x30); //0
            putchar0(0x0d); //cr
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x23);  
#else  
			UDR0 = 0x23 ;  
#endif  

            sprintf(str,"TX19");
            put_str(4,16,str,1);   
            rx_led_delay = 2500;  

            inverter_seq++;
            break;         
        case 92:
            putchar0(0x31); //1
            putchar0(0x39); //9
            putchar0(0x33); //3
            putchar0(0x0d); //cr
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x23);  
#else  
			UDR0 = 0x23 ;  
#endif       
            inverter_seq++;
            break;         
        case 93:
        case 94:
            inverter_seq++;
            break;               


        case 95:
           if (eeInverterCount > 19) { 
                if (sendInverterCount[19] < 100) {
                    sendInverterCount[19]++;
                }            
               inverter_seq++;
           } else {
            inverter_seq = 0;               
            }
            break;     
        case 96:     //Inv-20: //23 31 34 30 0d
            //putchar0(0x23); //
            putchar0(0x32); //2
            putchar0(0x30); //0
            putchar0(0x30); //0
            putchar0(0x0d); //cr
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x23);  
#else  
			UDR0 = 0x23 ;  
#endif  

            sprintf(str,"TX20");
            put_str(4,16,str,1);   
            rx_led_delay = 2500;  

            inverter_seq++;
            break;         
        case 97:
            putchar0(0x32); //2
            putchar0(0x30); //0
            putchar0(0x33); //3
            putchar0(0x0d); //cr
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x23);  
#else  
			UDR0 = 0x23 ;  
#endif       
            inverter_seq++;
            break;         
        case 98:
        case 99:
            inverter_seq++;
            break;        
              
        case 100:
         if (eeInverterCount > 20) { 
                if (sendInverterCount[20] < 100) {
                    sendInverterCount[20]++;
                }            
               inverter_seq++;
           } else {
            inverter_seq = 0;               
            }            
            break;
        default:  
            inverter_seq = 0;
            break;
    }
}


void rx0Control_Kaco39(void) {   
   char rxdata;           
    unsigned char ic1,ic2,iPos;
   rxdata = getchar0();

   switch(rx_seq0) {         
       case 0:
           //0a 2a 30 31 6e 20 32
            //if (rxdata == 0x0a) {
            if (rxdata == 0x2a) {
                timeout0 = 250;  
    
               rcnt = 0;           
               memset(rxbuff,0,sizeof(rxbuff));

               rxbuff[rcnt++] = rxdata;                          
               rx_seq0++;
            } else if (rxdata ==0x02) {
                timeout0 = 250;
               rx_seq0 = 200;
            }
            break; 
            
      case 1:        
            rxbuff[rcnt++] = rxdata;
            rx_seq0++;
         break;
                 
      case 2:        
            rxbuff[rcnt++] = rxdata;
            rx_seq0++;
         break; 
                
      case 3:        
            rxbuff[rcnt++] = rxdata;
           if (rxdata == 0x33) {
                rx_seq0 = 100;
         } else {
                rx_seq0 = 11;
            }  
         break;     

        case 11:   
            rxbuff[rcnt++] = rxdata;
            if (rcnt == 105) {
               if (rxdata == 0x0d) {
                   if (rxbuff[1] == 0x30) {       
                      invNo = rxbuff[2] - 0x31;
                    } else if (rxbuff[1] == 0x31) {
                      invNo = rxbuff[2] + 10 - 0x31;
                    } else if (rxbuff[1] == 0x32) {
                      invNo = rxbuff[2] + 20 - 0x31;
                    } else {
                       return;
                    }
                    
                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[18];str[1]=rxbuff[19];str[2]=rxbuff[20];
                    inverter[invNo].solar_cell_voltage = atoi(str);            
                        
                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[24];str[1]=rxbuff[25];//str[2]=rxbuff[25];//str[3]=rxbuff[19];
                    inverter[invNo].solar_cell_current = atoi(str);
                        
                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[69];str[1]=rxbuff[70];str[2]=rxbuff[71];
                    inverter[invNo].power_solar = atoi(str);   
    //sprintf(str,"%3d  ",inverter[0].power_solar);
    //put_str(0,0,str,1);
                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[31];str[1]=rxbuff[32];str[2]=rxbuff[33];
                    inverter[invNo].inv_u_voltage = atoi(str);       
                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[43];str[1]=rxbuff[44];str[2]=rxbuff[45];
                    inverter[invNo].inv_v_voltage =  atoi(str);
                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[57];str[1]=rxbuff[58];str[2]=rxbuff[59];
                    inverter[invNo].inv_w_voltage =  atoi(str);
                        
                    inverter[invNo].inv_frequency = 600;

//================================================================================                    1111111111
//000000000011111111112222222222333333333344444444445555555555666666666677777777778888888888999999999900000000001
//012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890
//------------------------------------------------------------------------------ --
//*01n 16 50kH3P 4  597.6 68.48  233.2 57.92  231.0 58.04  231.4 57.92 40947 40106 1.000  46.9 223000 D634 
//*01n 16 50kH3P 4  634.6  2.60  229.6  2.70  229.8  2.71  227.7  2.70  1651  1617 1.000  35.7 307738 F1F8
//ADDR    CAPA STA  VDC1  IDC1   VAC1  IAC1   VAC2  IAC2   VAC3  IAC3  PDC   PAC   CosPi  TEMP DailyW 

//*01n 16 50kH3P 8  714.1  0.00  228.8  0.00  230.4  0.00  228.5  0.00     0     0 1.000  35.6 307729 4140   //KACO 50K Bluenet

     
                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[37];str[1]=rxbuff[38];
                    inverter[invNo].inv_u_current = atoi(str);
                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[50];str[1]=rxbuff[51];
                    inverter[invNo].inv_v_current = atoi(str);
                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[63];str[1]=rxbuff[64];
                    inverter[invNo].inv_w_current = atoi(str);
                    
                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[75];str[1]=rxbuff[76];str[2]=rxbuff[77];
                    inverter[invNo].power_inv_now = atoi(str);     
    //                inverter[0].power_inv_now = inverter[0].power_inv_day_total; 

//sprintf(str,"%3d  ",inverter[0].power_inv_now);
//put_str(1,0,str,1);          

                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[93];str[1]=rxbuff[94];str[2]=rxbuff[95];str[3]=rxbuff[96];
                    inverter[invNo].power_inv_day_total = atoi(str);            
                    inverter[invNo].power_inv_day_total /= 10;            
                    
                    //memset(str,0,sizeof(str));  
                    //str[0]=rxbuff[70];str[1]=rxbuff[71];str[2]=rxbuff[72];str[3]=rxbuff[73];str[4]=rxbuff[74];str[5]=rxbuff[75];str[6]=rxbuff[76];
//                    if (atol(str) > 0) {
//                        inverter[invNo].power_inv_total = 0; //atol(str);
//                    }            
                    
                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[15];//str[1]=rxbuff[15]; //str[2]=rxbuff[7];
                    if (atoi(str) < 255) { 
                        inverter[invNo].inverter_status[0] = atoi(str);            
                    } else {
                        inverter[invNo].inverter_status[0] = 255;            
                    }
                    inverter[invNo].inverter_status[1] = inverter[invNo].inverter_status[0];
                    inverter[invNo].inverter_status[2] = 0;
                    inverter[invNo].inverter_status[3] = 0;
                                                  //127 ~ 9
                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[83];str[1]=rxbuff[84];str[2]=rxbuff[85];
               inverter[invNo].power_inv_pf = atoi(str);

                    sendInverterCount[invNo] = 0;
                    buzzer_flag |= BUZZER_TIC;
                    //put_str(4,16,C_RXOK,1);        
                sprintf(str,"RX%02d",invNo+1);
                put_str(4,16,str,1);   
                    rx_led_delay = 2500;

                    rx_seq0 = 0;
                } else {
                   rx_seq0++;
                }
            }
            break;         
         

        case 12:   
            rxbuff[rcnt++] = rxdata;
            if (rcnt == 106) {
               if (rxdata == 0x0d) {
                   if (rxbuff[1] == 0x30) {       
                      invNo = rxbuff[2] - 0x31;
                    } else if (rxbuff[1] == 0x31) {
                      invNo = rxbuff[2] + 10 - 0x31;
                    } else {
                       return;
                    }
                    
               if (rxbuff[16] == 0x20) {
                  memset(str,0,sizeof(str));
                       str[0]=rxbuff[15];
                       if (atoi(str) < 255) { 
                           inverter[invNo].inverter_status[0] = atoi(str);            
                       } else {
                           inverter[invNo].inverter_status[0] = 255;            
                       }
                       inverter[invNo].inverter_status[1] = inverter[invNo].inverter_status[0];
                       inverter[invNo].inverter_status[2] = 0;
                       inverter[invNo].inverter_status[3] = 0;
               
                  memset(str,0,sizeof(str));
                  str[0]=rxbuff[18];str[1]=rxbuff[19];str[2]=rxbuff[20];
                  inverter[invNo].solar_cell_voltage = atoi(str);            
                  memset(str,0,sizeof(str));
                  str[0]=rxbuff[24];str[1]=rxbuff[25];
                  inverter[invNo].solar_cell_current = atoi(str);
                  memset(str,0,sizeof(str));
                  str[0]=rxbuff[69];str[1]=rxbuff[70];str[2]=rxbuff[71];
                  inverter[invNo].power_solar = atoi(str);   

                  memset(str,0,sizeof(str));
                  str[0]=rxbuff[31];str[1]=rxbuff[32];str[2]=rxbuff[33];
                  inverter[invNo].inv_u_voltage = atoi(str);       
                  memset(str,0,sizeof(str));
                  str[0]=rxbuff[44];str[1]=rxbuff[45];str[2]=rxbuff[46];
                  inverter[invNo].inv_v_voltage =  atoi(str);
                  memset(str,0,sizeof(str));
                  str[0]=rxbuff[57];str[1]=rxbuff[58];str[2]=rxbuff[59];
                  inverter[invNo].inv_w_voltage =  atoi(str);

                  memset(str,0,sizeof(str));
                  str[0]=rxbuff[37];str[1]=rxbuff[38];
                  inverter[invNo].inv_u_current = atoi(str);
                  memset(str,0,sizeof(str));
                  str[0]=rxbuff[50];str[1]=rxbuff[51];
                  inverter[invNo].inv_v_current = atoi(str);
                  memset(str,0,sizeof(str));
                  str[0]=rxbuff[63];str[1]=rxbuff[64];
                  inverter[invNo].inv_w_current = atoi(str);
                  
                  memset(str,0,sizeof(str));
                  str[0]=rxbuff[75];str[1]=rxbuff[76];str[2]=rxbuff[77];
                  inverter[invNo].power_inv_now = atoi(str);     
               
                  inverter[invNo].inv_frequency = 600;
                  inverter[invNo].power_inv_pf = 0;

                  memset(str,0,sizeof(str));
                       str[0]=rxbuff[94];str[1]=rxbuff[95];str[2]=rxbuff[96];str[3]=rxbuff[97];
                       inverter[invNo].power_inv_day_total = atoi(str);
                       inverter[invNo].power_inv_day_total /= 10;
               }else {
                       memset(str,0,sizeof(str));
                       str[0]=rxbuff[15]; str[1]=rxbuff[16]; //str[2]=rxbuff[7];
                  inverter[invNo].inverter_status[0] = atoi(str);            
                       inverter[invNo].inverter_status[1] = inverter[invNo].inverter_status[0];
                       inverter[invNo].inverter_status[2] = 0;
                       inverter[invNo].inverter_status[3] = 0;
                                                     //127 ~ 9
                       if (atoi(str) < 10) { 
                     memset(str,0,sizeof(str));
                     str[0]=rxbuff[18];str[1]=rxbuff[19];str[2]=rxbuff[20];
                     inverter[invNo].solar_cell_voltage = atoi(str);            
                     memset(str,0,sizeof(str));
                     str[0]=rxbuff[24];str[1]=rxbuff[25];//str[2]=rxbuff[25];//str[3]=rxbuff[19];
                     inverter[invNo].solar_cell_current = atoi(str);
                     memset(str,0,sizeof(str));
                     str[0]=rxbuff[69];str[1]=rxbuff[70];str[2]=rxbuff[71];
                     inverter[invNo].power_solar = atoi(str);   

                     memset(str,0,sizeof(str));
                     str[0]=rxbuff[31];str[1]=rxbuff[32];str[2]=rxbuff[33];
                     inverter[invNo].inv_u_voltage = atoi(str);       
                     memset(str,0,sizeof(str));
                     str[0]=rxbuff[43];str[1]=rxbuff[44];str[2]=rxbuff[45];
                     inverter[invNo].inv_v_voltage =  atoi(str);
                     memset(str,0,sizeof(str));
                     str[0]=rxbuff[57];str[1]=rxbuff[58];str[2]=rxbuff[59];
                     inverter[invNo].inv_w_voltage =  atoi(str);

                     memset(str,0,sizeof(str));
                     str[0]=rxbuff[37];str[1]=rxbuff[38];
                     inverter[invNo].inv_u_current = atoi(str);
                     memset(str,0,sizeof(str));
                     str[0]=rxbuff[50];str[1]=rxbuff[51];
                     inverter[invNo].inv_v_current = atoi(str);
                     memset(str,0,sizeof(str));
                     str[0]=rxbuff[63];str[1]=rxbuff[64];
                     inverter[invNo].inv_w_current = atoi(str);
                     
                     memset(str,0,sizeof(str));
                     str[0]=rxbuff[75];str[1]=rxbuff[76];str[2]=rxbuff[77];
                     inverter[invNo].power_inv_now = atoi(str);     
                  
                     inverter[invNo].inv_frequency = 600;

                       } else {
                     memset(str,0,sizeof(str));
                     str[0]=rxbuff[19];str[1]=rxbuff[20];str[2]=rxbuff[21];
                     inverter[invNo].solar_cell_voltage = atoi(str);            
                     memset(str,0,sizeof(str));
                     str[0]=rxbuff[25];str[1]=rxbuff[26];//str[2]=rxbuff[25];//str[3]=rxbuff[19];
                     inverter[invNo].solar_cell_current = atoi(str);
                     memset(str,0,sizeof(str));
                     str[0]=rxbuff[70];str[1]=rxbuff[71];str[2]=rxbuff[72];
                     inverter[invNo].power_solar = atoi(str);   

                     memset(str,0,sizeof(str));
                     str[0]=rxbuff[32];str[1]=rxbuff[33];str[2]=rxbuff[34];
                     inverter[invNo].inv_u_voltage = atoi(str);       
                     memset(str,0,sizeof(str));
                     str[0]=rxbuff[44];str[1]=rxbuff[45];str[2]=rxbuff[46];
                     inverter[invNo].inv_v_voltage =  atoi(str);
                     memset(str,0,sizeof(str));
                     str[0]=rxbuff[58];str[1]=rxbuff[59];str[2]=rxbuff[60];
                     inverter[invNo].inv_w_voltage =  atoi(str);

                     memset(str,0,sizeof(str));
                     str[0]=rxbuff[38];str[1]=rxbuff[39];
                     inverter[invNo].inv_u_current = atoi(str);
                     memset(str,0,sizeof(str));
                     str[0]=rxbuff[51];str[1]=rxbuff[52];
                     inverter[invNo].inv_v_current = atoi(str);
                     memset(str,0,sizeof(str));
                     str[0]=rxbuff[64];str[1]=rxbuff[65];
                     inverter[invNo].inv_w_current = atoi(str);
                     
                     memset(str,0,sizeof(str));
                     str[0]=rxbuff[76];str[1]=rxbuff[77];str[2]=rxbuff[78];
                     inverter[invNo].power_inv_now = atoi(str);     
                  
                     inverter[invNo].inv_frequency = 600;

                       }
                  
   //================================================================================                    1111111111
   //000000000011111111112222222222333333333344444444445555555555666666666677777777778888888888999999999900000000001
   //012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890
   //------------------------------------------------------------------------------ --
   //*01n 16 50kH3P 4  696.7  1.03  229.5  1.61  231.1  1.68  229.1  1.60   747   709 0.957c  35.6 307729 DB1C
   //*01n 16 50kH3P 75  588.6  0.00  229.5  0.00  230.3  0.00  228.6  0.00     0     0 1.000  36.9 308349 8457
   //ADDR    CAPA  STA  VDC1  IDC1   VAC1  IAC1   VAC2  IAC2   VAC3  IAC3  PDC   PAC   CosPi  TEMP DailyW 

        
       //                inverter[0].power_inv_now = inverter[0].power_inv_day_total; 

   //sprintf(str,"%3d  ",inverter[0].power_inv_now);
   //put_str(1,0,str,1);          

                       memset(str,0,sizeof(str));

                  // 180509 일일발전량 한칸씩 밀리는 현상 수정
                       //str[0]=rxbuff[93];str[1]=rxbuff[94];str[2]=rxbuff[95];str[3]=rxbuff[96];
                  str[0]=rxbuff[94];str[1]=rxbuff[95];str[2]=rxbuff[96];str[3]=rxbuff[97];
                  
                       inverter[invNo].power_inv_day_total = atoi(str);            
                       inverter[invNo].power_inv_day_total /= 10;            
                                      
                       //memset(str,0,sizeof(str));
                       //str[0]=rxbuff[83];str[1]=rxbuff[84];str[2]=rxbuff[85];
                  inverter[invNo].power_inv_pf = 950;
               }
                    sendInverterCount[invNo] = 0;
                    buzzer_flag |= BUZZER_TIC;
                    //put_str(4,16,C_RXOK,1);        
                sprintf(str,"RX%02d",invNo+1);
                put_str(4,16,str,1);   
                    rx_led_delay = 2500;

                    rx_seq0 = 0;
                } else {
                   rx_seq0++;
                }
            }
            break;         
         

      //KACO 20K
        case 13: 
            rxbuff[rcnt++] = rxdata;
            if (rcnt == 129) {
               if (rxdata == 0x0d) {
                   if (rxbuff[1] == 0x30) {       
                      invNo = rxbuff[2] - 0x31;
                    } else if (rxbuff[1] == 0x31) {
                      invNo = rxbuff[2] + 10 - 0x31;
                    } else {
                       return;
                    }
                    
                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[17];str[1]=rxbuff[18];str[2]=rxbuff[19];
                    inverter[invNo].solar_cell_voltage = atoi(str);            
                        
                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[23];str[1]=rxbuff[24];//str[2]=rxbuff[25];//str[3]=rxbuff[19];
                    inverter[invNo].solar_cell_current = atoi(str);
                    //inverter[0].solar_cell_current /= 10;            
                        
                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[93];str[1]=rxbuff[94];str[2]=rxbuff[95];
                    inverter[invNo].power_solar = atoi(str);   
                    
    //sprintf(str,"%3d  ",inverter[0].power_solar);
    //put_str(0,0,str,1);

                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[55];str[1]=rxbuff[56];str[2]=rxbuff[57];
                    inverter[invNo].inv_u_voltage = atoi(str);       
                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[68];str[1]=rxbuff[69];str[2]=rxbuff[70];
                    inverter[invNo].inv_v_voltage =  atoi(str);
                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[81];str[1]=rxbuff[82];str[2]=rxbuff[83];
                    inverter[invNo].inv_w_voltage =  atoi(str);
                        
                    inverter[invNo].inv_frequency = 600;


//0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000111111111111111111111111111111111111111111111111 1
//0000000000111111111122222222223333333333444444444455555555556666666666777777777788888888889999999999000000000011111111112222222222333333333344444444 4
//0123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567 8
//-------------------------------------------------------------------------------
//*12n 20 200TL 4  642.3  1.50   968  632.9  1.10   698  228.6  2.58  229.4  2.58  229.1  2.52  1667  1676 1.000  35.7  65221 F1F8
//*03n 20 200TL 4  512.1  7.22  3700  674.4  1.15   776  228.5  6.38  229.3  6.39  228.5  6.35  4476  4318 1.000  40.4  65042 E8E5  //KACO 20K
//ADDR    CAPA STA VDC1   IDC1   PDC1 VDC2   IDC2   PDC2 VAC1   IAC1  VAC2   IAC2  VAC3   IAC3  PDC   PAC  CosPi  TEMP  DailyW 

                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[61];str[1]=rxbuff[62];
                    inverter[invNo].inv_u_current = atoi(str);
                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[74];str[1]=rxbuff[75];
                    inverter[invNo].inv_v_current = atoi(str);
                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[87];str[1]=rxbuff[88];
                    inverter[invNo].inv_w_current = atoi(str);
                    
                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[99];str[1]=rxbuff[100];str[2]=rxbuff[101];
                    inverter[invNo].power_inv_now = atoi(str);     
    //                inverter[0].power_inv_now = inverter[0].power_inv_day_total; 

//sprintf(str,"%3d  ",inverter[0].power_inv_now);
//put_str(1,0,str,1);          

                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[117];str[1]=rxbuff[118];str[2]=rxbuff[119];str[3]=rxbuff[120];
                    inverter[invNo].power_inv_day_total = atoi(str);            
                    inverter[invNo].power_inv_day_total /= 10;            
                    
                    //memset(str,0,sizeof(str));  
                    //str[0]=rxbuff[70];str[1]=rxbuff[71];str[2]=rxbuff[72];str[3]=rxbuff[73];str[4]=rxbuff[74];str[5]=rxbuff[75];str[6]=rxbuff[76];
//                    if (atol(str) > 0) {
//                        inverter[invNo].power_inv_total = 0; //atol(str);
//                    }            
                    
                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[14];//str[1]=rxbuff[15]; //str[2]=rxbuff[7];
                    if (atoi(str) < 255) { 
                        inverter[invNo].inverter_status[0] = atoi(str);            
                    } else {
                        inverter[invNo].inverter_status[0] = 255;            
                    }
                    inverter[invNo].inverter_status[1] = inverter[invNo].inverter_status[0];
                    inverter[invNo].inverter_status[2] = 0;
                    inverter[invNo].inverter_status[3] = 0;
                                                  //127 ~ 9
                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[107];str[1]=rxbuff[108];str[2]=rxbuff[109];
               inverter[invNo].power_inv_pf = atoi(str);

                    sendInverterCount[invNo] = 0;
                    buzzer_flag |= BUZZER_TIC;
                    //put_str(4,16,C_RXOK,1);        
                sprintf(str,"RX-%01X",invNo+1);
                put_str(4,16,str,1);   
                    rx_led_delay = 2500;

                    rx_seq0 = 0;
                } else {
                   rx_seq0++;
                }
            }
            break;
                
/////////////////
      //KACO 20K NEMo8 보은설치 2017/07/11
        case 14: 
            rxbuff[rcnt++] = rxdata;
            if (rcnt == 130) {
               if (rxdata == 0x0d) {
                   if (rxbuff[1] == 0x30) {       
                      invNo = rxbuff[2] - 0x31;
                    } else if (rxbuff[1] == 0x31) {
                      invNo = rxbuff[2] + 10 - 0x31;
                    } else {
                       return;
                    }
                    
                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[18];str[1]=rxbuff[19];str[2]=rxbuff[20];
                    inverter[invNo].solar_cell_voltage = atoi(str);            
                        
                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[24];str[1]=rxbuff[25];   //IDC1
                    inverter[invNo].solar_cell_current = atoi(str);

                    str[0]=rxbuff[43];str[1]=rxbuff[44];   //IDC2
                    inverter[invNo].solar_cell_current += atoi(str);
                    //inverter[0].solar_cell_current /= 10;            
                        
                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[94];str[1]=rxbuff[95];str[2]=rxbuff[96];
                    inverter[invNo].power_solar = atoi(str);   
                    
    //sprintf(str,"%3d  ",inverter[0].power_solar);
    //put_str(0,0,str,1);

                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[56];str[1]=rxbuff[57];str[2]=rxbuff[58];
                    inverter[invNo].inv_u_voltage = atoi(str);       
                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[69];str[1]=rxbuff[70];str[2]=rxbuff[71];
                    inverter[invNo].inv_v_voltage =  atoi(str);
                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[82];str[1]=rxbuff[83];str[2]=rxbuff[84];
                    inverter[invNo].inv_w_voltage =  atoi(str);
                        
                    inverter[invNo].inv_frequency = 600;

//old
//0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000111111111111111111111111111111111111111111111111 1
//0000000000111111111122222222223333333333444444444455555555556666666666777777777788888888889999999999000000000011111111112222222222333333333344444444 4
//0123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567 8
//-------------------------------------------------------------------------------
//*12n 20 200TL 4  642.3  1.50   968  632.9  1.10   698  228.6  2.58  229.4  2.58  229.1  2.52  1667  1676 1.000  35.7  65221 F1F8


//2017-07-10
//================================================================================                    1111111111111111111111111111111111111111111111
//00000000001111111111222222222233333333334444444444555555555566666666667777777777888888888899999999990000000000111111111122222222223333333333444444
//01234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345
//------------------------------------------------------------------------------ --
//*01n 20 200L32 4  540.0  2.93  1594  551.0  2.83  1553  230.6  4.46  227.0  4.59  231.3  4.54  3147  3059 1.000  45.6  87836 5DC8 //KACO 20K
//*01n 20 200L32 4  637.4  8.94  5703  643.1  4.59  2958  216.7 13.13  217.4 13.19  217.1 13.22  8662  8538 1.000  38.8  11270 411A //KAC0 20K Blueplnet NEMO ENG
//*01n 20 200L32 4  551.7  2.74  1510  550.7  2.69  1487  231.0  4.53  227.5  4.66  231.3  4.61  2998  3051 1.000  45.6  87792 4839
//ADDR    CAPA STA VDC1   IDC1   PDC1 VDC2   IDC2   PDC2 VAC1   IAC1  VAC2   IAC2  VAC3   IAC3  PDC   PAC  CosPi  TEMP  DailyW 
                
         

                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[62];str[1]=rxbuff[63];
                    inverter[invNo].inv_u_current = atoi(str);
                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[75];str[1]=rxbuff[76];
                    inverter[invNo].inv_v_current = atoi(str);
                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[88];str[1]=rxbuff[89];
                    inverter[invNo].inv_w_current = atoi(str);
                    
                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[100];str[1]=rxbuff[101];str[2]=rxbuff[102];
                    inverter[invNo].power_inv_now = atoi(str);     
    //                inverter[0].power_inv_now = inverter[0].power_inv_day_total; 

//sprintf(str,"rCnt:%3d  ",rcnt);
//put_str(1,0,str,1);          

                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[118];str[1]=rxbuff[119];str[2]=rxbuff[120];str[3]=rxbuff[121];
                    inverter[invNo].power_inv_day_total = atoi(str);            
                    inverter[invNo].power_inv_day_total /= 10;            
                    
                    //memset(str,0,sizeof(str));  
                    //str[0]=rxbuff[70];str[1]=rxbuff[71];str[2]=rxbuff[72];str[3]=rxbuff[73];str[4]=rxbuff[74];str[5]=rxbuff[75];str[6]=rxbuff[76];
//                    if (atol(str) > 0) {
//                        inverter[invNo].power_inv_total = 0; //atol(str);
//                    }            
                    
                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[15];//str[1]=rxbuff[15]; //str[2]=rxbuff[7];
                    if (atoi(str) < 255) { 
                        inverter[invNo].inverter_status[0] = atoi(str);            
                    } else {
                        inverter[invNo].inverter_status[0] = 255;            
                    }
                    inverter[invNo].inverter_status[1] = inverter[invNo].inverter_status[0];
                    inverter[invNo].inverter_status[2] = 0;
                    inverter[invNo].inverter_status[3] = 0;
                                                  //127 ~ 9
                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[107];str[1]=rxbuff[108];str[2]=rxbuff[109];
               inverter[invNo].power_inv_pf = atoi(str);

                    sendInverterCount[invNo] = 0;
                    buzzer_flag |= BUZZER_TIC;
                    //put_str(4,16,C_RXOK,1);        
                sprintf(str,"RX-%01X",invNo+1);
                put_str(4,16,str,1);   
                    rx_led_delay = 2500;

                    rx_seq0 = 0;
                } else {
                   rx_seq0++;
                }
            }
            break;
                
//////////////////            
            
            
        case 15: 
            rxbuff[rcnt++] = rxdata;
            if (rcnt == 148) {
               if (rxdata == 0x0d) {
                   if (rxbuff[1] == 0x30) {       
                      invNo = rxbuff[2] - 0x31;
                    } else if (rxbuff[1] == 0x31) {
                      invNo = rxbuff[2] + 10 - 0x31;
                    } else {
                       return;
                    }
                    
                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[17];str[1]=rxbuff[18];str[2]=rxbuff[19];
                    inverter[invNo].solar_cell_voltage = atoi(str);            
                        
                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[23];str[1]=rxbuff[24];//str[2]=rxbuff[25];//str[3]=rxbuff[19];
                    inverter[invNo].solar_cell_current = atoi(str);
                    //inverter[0].solar_cell_current /= 10;            
                        
                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[112];str[1]=rxbuff[113];str[2]=rxbuff[114];
                    inverter[invNo].power_solar = atoi(str);   
                    
    //sprintf(str,"%3d  ",inverter[0].power_solar);
    //put_str(0,0,str,1);
                    
                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[74];str[1]=rxbuff[75];str[2]=rxbuff[76];
                    inverter[invNo].inv_u_voltage = atoi(str);       
                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[87];str[1]=rxbuff[88];str[2]=rxbuff[89];
                    inverter[invNo].inv_v_voltage =  atoi(str);
                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[100];str[1]=rxbuff[101];str[2]=rxbuff[102];
                    inverter[invNo].inv_w_voltage =  atoi(str);
                        
                    inverter[invNo].inv_frequency = 600;


//0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000111111111111111111111111111111111111111111111111 1
//0000000000111111111122222222223333333333444444444455555555556666666666777777777788888888889999999999000000000011111111112222222222333333333344444444 4
//0123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567 8
//-------------------------------------------------------------------------------
//*01n 23 390TL 48  581.1  0.00     0  578.2  0.00     0  580.0  0.00     0    1.2  0.00    1.9  0.00    2.0  0.00     0     0 1.000  28.9      0 00DB D  
//ADDR    CAPA STA   VDC1  IDC1  PDC1   VDC2  IDC2  PDC2   VDC3  IDC3  PDC3   VAC1  IAC1   VAC2  IAC2   VAC3  IAC3   PDC   PAC CosPi  TEMP DailyW 
//*01n 23 390TL 4  473.8 14.73  6981  471.1 14.87  7008  482.2 21.75 10493  226.7 35.49  228.0 35.38  226.3 35.50 24483 23936 1.000  50.7  54758 D1F5
//*01n 23 390TL 4  475.0 15.58  7402  456.2 16.26  7420  473.9 23.62 11195  228.0 37.26  229.2 37.12  227.0 37.25 26018 25427 1.000  54.4  70268 26D1


                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[80];str[1]=rxbuff[81];
                    inverter[invNo].inv_u_current = atoi(str);
                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[93];str[1]=rxbuff[94];
                    inverter[invNo].inv_v_current = atoi(str);
                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[106];str[1]=rxbuff[107];
                    inverter[invNo].inv_w_current = atoi(str);
                    
                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[118];str[1]=rxbuff[119];str[2]=rxbuff[120];
                    inverter[invNo].power_inv_now = atoi(str);     
    //                inverter[0].power_inv_now = inverter[0].power_inv_day_total; 

//sprintf(str,"%3d  ",inverter[0].power_inv_now);
//put_str(1,0,str,1);          

                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[136];str[1]=rxbuff[137];str[2]=rxbuff[138];str[3]=rxbuff[139];
                    inverter[invNo].power_inv_day_total = atoi(str);            
                    inverter[invNo].power_inv_day_total /= 10;            
                    
                    //memset(str,0,sizeof(str));  
                    //str[0]=rxbuff[70];str[1]=rxbuff[71];str[2]=rxbuff[72];str[3]=rxbuff[73];str[4]=rxbuff[74];str[5]=rxbuff[75];str[6]=rxbuff[76];
//                    if (atol(str) > 0) {
//                        inverter[invNo].power_inv_total = 0; //atol(str);
//                    }            
                    
                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[14];str[1]=rxbuff[15]; //str[2]=rxbuff[7];
                    if (atoi(str) < 255) { 
                        inverter[invNo].inverter_status[0] = atoi(str);            
                    } else {
                        inverter[invNo].inverter_status[0] = 255;            
                    }
                    inverter[invNo].inverter_status[1] = inverter[invNo].inverter_status[0];
                    inverter[invNo].inverter_status[2] = 0;
                    inverter[invNo].inverter_status[3] = 0;
                                                  //127 ~ 9
                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[126];str[1]=rxbuff[127];str[2]=rxbuff[128];
               inverter[invNo].power_inv_pf = atoi(str);

                    sendInverterCount[invNo] = 0;
                    buzzer_flag |= BUZZER_TIC;
                    //put_str(4,16,C_RXOK,1);        
                sprintf(str,"RX%01X",invNo+1);
                put_str(4,16,str,1);   
                    rx_led_delay = 2500;

                    rx_seq0 = 0;
                
                
                

                } else {
                   rx_seq0++;
                }
            }
            break;
            

               
        case 16: 
            rxbuff[rcnt++] = rxdata;
            if (rcnt == 149) {
               if (rxdata == 0x0d) {      
                   //invNo = rxbuff[2] - 0x31;
                   if (rxbuff[1] == 0x30) {       
                      invNo = rxbuff[2] - 0x31;
                    } else if (rxbuff[1] == 0x31) {
                      invNo = rxbuff[2] + 10 - 0x31;
                    } else {
                       return;
                    }

//================================================================================
//000000000011111111112222222222333333333344444444445555555555666666666677777777 7
//012345678901234567890123456789012345678901234567890123456789012345678901234567 8
//------------------------------------------------------------------------------ --
//*000 005 482.8 132.30 063900 393.2 091.60 062100 37 0341458   100k   000007831 D

//         PV-V  PV-C    63.9w u-V   U-A    U-W    tmp d-tot           tot-

                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[18];str[1]=rxbuff[19];str[2]=rxbuff[20];
                    inverter[invNo].solar_cell_voltage = atoi(str);            
                    
                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[24];str[1]=rxbuff[25];str[2]=rxbuff[26];   //str[3]=rxbuff[19];
                    inverter[invNo].solar_cell_current = atoi(str);
                    //inverter[invNo].solar_cell_current /= 10;            
                    
                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[113];str[1]=rxbuff[114];str[2]=rxbuff[115];//str[0]=rxbuff[112];str[1]=rxbuff[113];str[2]=rxbuff[114];
                    inverter[invNo].power_solar = atoi(str);

                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[75];str[1]=rxbuff[76];str[2]=rxbuff[77];
                    inverter[invNo].inv_u_voltage = atoi(str);       
                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[88];str[1]=rxbuff[89];str[2]=rxbuff[90];
                    inverter[invNo].inv_v_voltage =  atoi(str);
                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[101];str[1]=rxbuff[102];str[2]=rxbuff[103];
                    inverter[invNo].inv_w_voltage =  atoi(str);
                    
                    inverter[invNo].inv_frequency = 600;




//0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000111111111111111111111111111111111111111111111111 1
//0000000000111111111122222222223333333333444444444455555555556666666666777777777788888888889999999999000000000011111111112222222222333333333344444444 4
//0123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567 8
//-------------------------------------------------------------------------------
//*01n 23 390TL 48  581.1  0.00     0  578.2  0.00     0  580.0  0.00     0    1.2  0.00    1.9  0.00    2.0  0.00     0     0 1.000  28.9      0 00DB D  
//ADDR    CAPA STA   VDC1  IDC1  PDC1   VDC2  IDC2  PDC2   VDC3  IDC3  PDC3   VAC1  IAC1   VAC2  IAC2   VAC3  IAC3   PDC   PAC CosPi  TEMP DailyW 

                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[81];str[1]=rxbuff[82];
                    inverter[invNo].inv_u_current = atoi(str);
                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[94];str[1]=rxbuff[95];
                    inverter[invNo].inv_v_current = atoi(str);
                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[107];str[1]=rxbuff[108];
                    inverter[invNo].inv_w_current = atoi(str);
                    
                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[119];str[1]=rxbuff[120];str[2]=rxbuff[121];
                    inverter[invNo].power_inv_now = atoi(str);     
    //                inverter[0].power_inv_now = inverter[0].power_inv_day_total;       

                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[137];str[1]=rxbuff[138];str[2]=rxbuff[139];//str[3]=rxbuff[55];
                    inverter[invNo].power_inv_day_total = atoi(str);            
                    
                    //memset(str,0,sizeof(str));  
                    //str[0]=rxbuff[70];str[1]=rxbuff[71];str[2]=rxbuff[72];str[3]=rxbuff[73];str[4]=rxbuff[74];str[5]=rxbuff[75];str[6]=rxbuff[76];
//                    if (atol(str) > 0) {
//                        inverter[invNo].power_inv_total = 0; //atol(str);
//                    }            
                    
                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[14];str[1]=rxbuff[15]; //str[2]=rxbuff[7];
                    if (atoi(str) < 255) { 
                        inverter[invNo].inverter_status[0] = atoi(str);            
                    } else {
                        inverter[invNo].inverter_status[0] = 255;            
                    }
                    inverter[invNo].inverter_status[1] = inverter[invNo].inverter_status[0];
                    inverter[invNo].inverter_status[2] = 0;
                    inverter[invNo].inverter_status[3] = 0;
                                                  //127 ~ 9
                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[127];str[1]=rxbuff[128];str[2]=rxbuff[129];
               inverter[invNo].power_inv_pf = atoi(str);

                    sendInverterCount[invNo] = 0;
                    buzzer_flag |= BUZZER_TIC;  
                sprintf(str,"RX%-01X",invNo+1);
                put_str(4,16,str,1);   
                    //put_str(4,16,C_RXOK,1);   
                    rx_led_delay = 2500;

                    rx_seq0 = 0;
                
                } else {
                   rx_seq0++;
                }
            }                     
            break;  


        case 17: 
            rxbuff[rcnt++] = rxdata;
            if (rcnt == 150) {
               if (rxdata == 0x0d) {      
                   //invNo = rxbuff[2] - 0x31;
                   if (rxbuff[1] == 0x30) {       
                      invNo = rxbuff[2] - 0x31;
                    } else if (rxbuff[1] == 0x31) {
                      invNo = rxbuff[2] + 10 - 0x31;
                    } else {
                       return;
                    }

                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[19];str[1]=rxbuff[20];str[2]=rxbuff[21];
                    inverter[invNo].solar_cell_voltage = atoi(str);            
                    
                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[25];str[1]=rxbuff[26];str[2]=rxbuff[27];   //str[3]=rxbuff[19];
                    inverter[invNo].solar_cell_current = atoi(str);
                    inverter[invNo].solar_cell_current /= 10;            
                    
                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[114];str[1]=rxbuff[115];
                    inverter[invNo].power_solar = atoi(str);

                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[76];str[1]=rxbuff[77];str[2]=rxbuff[78];
                    inverter[invNo].inv_u_voltage = atoi(str);       
                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[89];str[1]=rxbuff[90];str[2]=rxbuff[91];
                    inverter[invNo].inv_v_voltage =  atoi(str);
                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[102];str[1]=rxbuff[103];str[2]=rxbuff[104];
                    inverter[invNo].inv_w_voltage =  atoi(str);
                    
                    inverter[invNo].inv_frequency = 600;


//0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000111111111111111111111111111111111111111111111111 1
//0000000000111111111122222222223333333333444444444455555555556666666666777777777788888888889999999999000000000011111111112222222222333333333344444444 4
//0123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567 8
//-------------------------------------------------------------------------------
//*01n 23 600TL 121  708.7  0.01    16  709.5  0.10    73  707.5  0.09    70  222.8  0.00  222.9  0.00  218.3  0.00   160     0 1.000  34.8 140398 D437
//ADDR    CAPA  STA   VDC1  IDC1  PDC1   VDC2  IDC2  PDC2   VDC3  IDC3  PDC3   VAC1  IAC1   VAC2  IAC2   VAC3  IAC3   PDC   PAC CosPi  TEMP DailyW 

                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[82];str[1]=rxbuff[83];
                    inverter[invNo].inv_u_current = atoi(str);
                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[95];str[1]=rxbuff[96];
                    inverter[invNo].inv_v_current = atoi(str);
                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[108];str[1]=rxbuff[109];
                    inverter[invNo].inv_w_current = atoi(str);
                    
                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[120];str[1]=rxbuff[121];
                    //str[2]=rxbuff[122];str[0]=rxbuff[120];str[1]=rxbuff[121];
                    inverter[invNo].power_inv_now = atoi(str);     
    //                inverter[0].power_inv_now = inverter[0].power_inv_day_total;       

                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[138];str[1]=rxbuff[139];str[2]=rxbuff[140];//str[3]=rxbuff[55];
                    inverter[invNo].power_inv_day_total = atoi(str);            
                    
                    //memset(str,0,sizeof(str));  
                    //str[0]=rxbuff[70];str[1]=rxbuff[71];str[2]=rxbuff[72];str[3]=rxbuff[73];str[4]=rxbuff[74];str[5]=rxbuff[75];str[6]=rxbuff[76];
//                    if (atol(str) > 0) {
//                        inverter[invNo].power_inv_total = 0; //atol(str);
//                    }            
                    
                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[15];str[1]=rxbuff[16]; //str[2]=rxbuff[7];
                    if (atoi(str) < 255) { 
                        inverter[invNo].inverter_status[0] = atoi(str);            
                    } else {
                        inverter[invNo].inverter_status[0] = 255;            
                    }
                    inverter[invNo].inverter_status[1] = inverter[invNo].inverter_status[0];
                    inverter[invNo].inverter_status[2] = 0;
                    inverter[invNo].inverter_status[3] = 0;
                                                  //127 ~ 9
                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[128];str[1]=rxbuff[129];str[2]=rxbuff[130];
               inverter[invNo].power_inv_pf = atoi(str);

                    sendInverterCount[invNo] = 0;
                    buzzer_flag |= BUZZER_TIC;  
                sprintf(str,"RX-%01X",invNo+1);
                put_str(4,16,str,1);   
                    //put_str(4,16,C_RXOK,1);   
                    rx_led_delay = 2500;

                    rx_seq0 = 0;
                
                } else {
                   rx_seq0 = 0;
                }
            }                     
            break;  
            
      case 100:   
            rxbuff[rcnt++] = rxdata;
            if (rxdata == 0x0d) {      
                //invNo = rxbuff[2] - 0x31;
                if (rxbuff[1] == 0x30) {       
                    invNo = rxbuff[2] - 0x31;
                } else if (rxbuff[1] == 0x31) {
                    invNo = rxbuff[2] + 10 - 0x31;
                } else if (rxbuff[1] == 0x32) {
                    invNo = rxbuff[2] + 20 - 0x31;
                } else {
                    return;
                }                       
                     
                ic2 = 0;
                for(ic1=0; ic1<rcnt; ic1++) {
               if ( (rxbuff[ic1] == 0x20) && (rxbuff[ic1+1] != 0x20) ) {
                        ic2++;
                        if (ic2 == 4) {
                           iPos = ic1;
                           ic1 = rcnt;  
                        }
                    }                
                }                      
                                          
                ic2 = 0;
                memset(str,0,sizeof(str));
               for(ic1=iPos; ic1<rcnt; ic1++ ){
                   if ((ic2 > 0) && (rxbuff[ic1] == 0x20)) {
                       ic1 = rcnt;
                      inverter[invNo].power_inv_total = atol(str) / 1000;            
                    } else {
                      str[ic2++] = rxbuff[ic1];
                    }
                }    

//            sprintf(str,"RTOT:%04d%04d  ",inverter[invNo].power_inv_total/10000, inverter[invNo].power_inv_total%10000);
//            put_str(0,0,str,1);   
                //put_str(4,16,C_RXOK,1);   
                rx_led_delay = 2500;

                rx_seq0 = 0;
            }                     
            break;  
            
            
                     
      //System Setting /////////////////////////////////////            
      case 200:               
            rcnt = 0;
            if (rxdata == 0xa5) {         //RD_DATA
                rx_seq0 = 220;
            } else if (rxdata == 0xaa) {   //WR_DATA
            rcnt = 0;
                rx_seq0 = 210;      
            } else {
                rx_seq0 = 0;
            }
         break;
      case 210:     //WR_DATA
         rxbuff[rcnt++] = rxdata;
         if (rcnt == 5) {
            rx_seq0++;
         }         
         break;  
              
      case 211:  
         if (rxdata == 0x03) {
            rx_seq0++;
         } else {
            rx_seq0 = 0;
         }  
         break;
      case 212:  
         if (rxdata == 0x0d) {   
            eePortNumber = rxbuff[0] * 0x100 + rxbuff[1];
            eeSendDelay = rxbuff[2] * 0x100 + rxbuff[3]; 
                eeSendDelay *= 1000; 
                eeInverterCount = rxbuff[4];
             sprintf(str,"%04d", eePortNumber);
            put_str(1,6,str,2);    
               //send_system_parameter();   
            buzzer_flag |= BUZZER_TIC;
         }
         rx_seq0 = 0;         
         break;
         
         
      case 220:  
         if (rxdata == 0x03) {
            rx_seq0++;
         } else {
            rx_seq0 = 0;
         }  
         break;
      case 221:  
         if (rxdata == 0x0d) {
               send_system_parameter();   
            buzzer_flag |= BUZZER_TIC;
         }
         rx_seq0 = 0;         
         break;
      default:
         rx_seq0 = 0;
         break;
   }
}


