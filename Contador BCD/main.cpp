// PIC18F4550 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1L
#pragma config PLLDIV = 1   	// PLL Prescaler Selection bits (No prescale (4 MHz oscillator input drives PLL directly))
#pragma config CPUDIV = OSC1_PLL2// System Clock Postscaler Selection bits ([Primary Oscillator Src: /1][96 MHz PLL Src: /2])
#pragma config USBDIV = 1   	// USB Clock Selection bit (used in Full-Speed USB mode only; UCFG:FSEN = 1) (USB clock source comes directly from the primary oscillator block with no postscale)

// CONFIG1H
#pragma config FOSC = HS    	// Oscillator Selection bits (HS oscillator (HS))
#pragma config FCMEN = OFF  	// Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor disabled)
#pragma config IESO = OFF   	// Internal/External Oscillator Switchover bit (Oscillator Switchover mode disabled)

// CONFIG2L
#pragma config PWRT = OFF   	// Power-up Timer Enable bit (PWRT disabled)
#pragma config BOR = OFF    	// Brown-out Reset Enable bits (Brown-out Reset disabled in hardware and software)
#pragma config BORV = 3     	// Brown-out Reset Voltage bits (Minimum setting 2.05V)
#pragma config VREGEN = OFF 	// USB Voltage Regulator Enable bit (USB voltage regulator disabled)

// CONFIG2H
#pragma config WDT = OFF    	// Watchdog Timer Enable bit (WDT disabled (control is placed on the SWDTEN bit))
#pragma config WDTPS = 32768	// Watchdog Timer Postscale Select bits (1:32768)

// CONFIG3H
#pragma config CCP2MX = OFF 	// CCP2 MUX bit (CCP2 input/output is multiplexed with RB3)
#pragma config PBADEN = OFF 	// PORTB A/D Enable bit (PORTB<4:0> pins are configured as digital I/O on Reset)
#pragma config LPT1OSC = OFF	// Low-Power Timer 1 Oscillator Enable bit (Timer1 configured for higher power operation)
#pragma config MCLRE = OFF  	// MCLR Pin Enable bit (RE3 input pin enabled; MCLR pin disabled)

// CONFIG4L
#pragma config STVREN = OFF 	// Stack Full/Underflow Reset Enable bit (Stack full/underflow will not cause Reset)
#pragma config LVP = OFF    	// Single-Supply ICSP Enable bit (Single-Supply ICSP disabled)
#pragma config ICPRT = OFF  	// Dedicated In-Circuit Debug/Programming Port (ICPORT) Enable bit (ICPORT disabled)
#pragma config XINST = OFF  	// Extended Instruction Set Enable bit (Instruction set extension and Indexed Addressing mode disabled (Legacy mode))

// CONFIG5L
#pragma config CP0 = OFF    	// Code Protection bit (Block 0 (000800-001FFFh) is not code-protected)
#pragma config CP1 = OFF    	// Code Protection bit (Block 1 (002000-003FFFh) is not code-protected)
#pragma config CP2 = OFF    	// Code Protection bit (Block 2 (004000-005FFFh) is not code-protected)
#pragma config CP3 = OFF    	// Code Protection bit (Block 3 (006000-007FFFh) is not code-protected)

// CONFIG5H
#pragma config CPB = OFF    	// Boot Block Code Protection bit (Boot block (000000-0007FFh) is not code-protected)
#pragma config CPD = OFF    	// Data EEPROM Code Protection bit (Data EEPROM is not code-protected)

// CONFIG6L
#pragma config WRT0 = OFF   	// Write Protection bit (Block 0 (000800-001FFFh) is not write-protected)
#pragma config WRT1 = OFF   	// Write Protection bit (Block 1 (002000-003FFFh) is not write-protected)
#pragma config WRT2 = OFF   	// Write Protection bit (Block 2 (004000-005FFFh) is not write-protected)
#pragma config WRT3 = OFF   	// Write Protection bit (Block 3 (006000-007FFFh) is not write-protected)

// CONFIG6H
#pragma config WRTC = OFF   	// Configuration Register Write Protection bit (Configuration registers (300000-3000FFh) are not write-protected)
#pragma config WRTB = OFF   	// Boot Block Write Protection bit (Boot block (000000-0007FFh) is not write-protected)
#pragma config WRTD = OFF   	// Data EEPROM Write Protection bit (Data EEPROM is not write-protected)

// CONFIG7L
#pragma config EBTR0 = OFF  	// Table Read Protection bit (Block 0 (000800-001FFFh) is not protected from table reads executed in other blocks)
#pragma config EBTR1 = OFF  	// Table Read Protection bit (Block 1 (002000-003FFFh) is not protected from table reads executed in other blocks)
#pragma config EBTR2 = OFF  	// Table Read Protection bit (Block 2 (004000-005FFFh) is not protected from table reads executed in other blocks)
#pragma config EBTR3 = OFF  	// Table Read Protection bit (Block 3 (006000-007FFFh) is not protected from table reads executed in other blocks)

// CONFIG7H
#pragma config EBTRB = OFF  	// Boot Block Table Read Protection bit (Boot block (000000-0007FFh) is not protected from table reads executed in other blocks)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#define _XTAL_FREQ 4000000 //add valor da frequência do oscilador principal em Hertz
#include <xc.h>

void main(void) {
	TRISCbits.RC0 = 1; // Botão aumenta
	TRISCbits.RC1 = 1; // Botão diminui
	TRISDbits.RD0 = 0; // Led D4
	TRISDbits.RD1 = 0; // Led D3
	TRISDbits.RD2 = 0; // Led D2
	TRISDbits.RD3 = 0; // Led D1
	PORTD = 0xFF; // Todos os leds em nível alto (desligados)

	int count = 0; // Iniciando com 0 a variável contadora

	while (1) {
    		if (PORTCbits.RC0 == 0 || PORTCbits.RC1 == 0) { // Se clicou no botão INIC ou DESC
        		if (PORTCbits.RC0 == 0) { // Se clicou no botão INIC
            			__delay_ms(200);
            			if (count <= 9) { // Se count for menor ou igual a 9
                			__delay_ms(200);
                			count++; // Incrementa
            			} else {
                			count = 9;
            			}
        		} else if (PORTCbits.RC1 == 0) { // Se clicou no botão DESC
            			__delay_ms(200);
            			if (count >= 0) { // Se count for maior ou igual a 0
                			__delay_ms(200);
                			count--; // Decrementa
            			} else {
                			count = 0;
            			}
        		}

    	}


    		switch (count) {
        			case 0:
            	PORTDbits.RD0 = 1;
            	PORTDbits.RD1 = 1;
            	PORTDbits.RD2 = 1;
            	PORTDbits.RD3 = 1;
            	break;
        	case 1:
            	PORTDbits.RD0 = 0;
            	PORTDbits.RD1 = 1;
            	PORTDbits.RD2 = 1;
            	PORTDbits.RD3 = 1;
            	break;
        	case 2:
            	PORTDbits.RD0 = 1;
            	PORTDbits.RD1 = 0;
            	PORTDbits.RD2 = 1;
            	PORTDbits.RD3 = 1;
            	break;
        	case 3:
            	PORTDbits.RD0 = 0;
            	PORTDbits.RD1 = 0;
            	PORTDbits.RD2 = 1;
            	PORTDbits.RD3 = 1;
            	break;
        	case 4:
            	PORTDbits.RD0 = 1;
            	PORTDbits.RD1 = 1;
            	PORTDbits.RD2 = 0;
            	PORTDbits.RD3 = 1;
            	break;
        	case 5:
            	PORTDbits.RD0 = 0;
            	PORTDbits.RD1 = 1;
            	PORTDbits.RD2 = 0;
            	PORTDbits.RD3 = 1;
            	break;
        	case 6:
            	PORTDbits.RD0 = 1;
            	PORTDbits.RD1 = 0;
            	PORTDbits.RD2 = 0;
            	PORTDbits.RD3 = 1;
            	break;
        	case 7:
            	PORTDbits.RD0 = 0;
            	PORTDbits.RD1 = 0;
            	PORTDbits.RD2 = 0;
            	PORTDbits.RD3 = 1;
            	break;
        	case 8:

