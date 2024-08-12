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
#include "nxlcd.h"
#define _XTAL_FREQ 20000000 //20hz de cristal
//nomeando as portas
#define C3 PORTBbits.RB0
#define C2 PORTBbits.RB1
#define C1 PORTBbits.RB2
#define C0 PORTBbits.RB3
#define L0 PORTBbits.RB4
#define L1 PORTBbits.RB5
#define L2 PORTBbits.RB6
#define L3 PORTBbits.RB7
#define D4 PORTDbits.RD4
#define D5 PORTDbits.RD5
#define D6 PORTDbits.RD6
#define D7 PORTDbits.RD7
#define RS PORTEbits.RE0
#define E PORTEbits.RE1
#define CLR PORTEbits.RE3

void main(void) {
    //definindo as portas de saida (D - barramento de dado do teclado)
// (E - controle)
    TRISDbits.TRISD4 = 0;
    TRISDbits.TRISD5 = 0;
    TRISDbits.TRISD6 = 0;
    TRISDbits.TRISD7 = 0;
    TRISEbits.TRISE0 = 0;
    TRISEbits.TRISE1 = 0;
    //defindo as portas de saida (C)
    TRISBbits.TRISB0 = 0;
    TRISBbits.TRISB1 = 0;
    TRISBbits.TRISB2 = 0;
    TRISBbits.TRISB3 = 0;
    //defindo as portas de entrada (L)
    TRISBbits.TRISB4 = 1;
    TRISBbits.TRISB5 = 1;
    TRISBbits.TRISB6 = 1;
    TRISBbits.TRISB7 = 1;
    //denominando as portas de saida como 1
    C0 = 1;
    C1 = 1;
    C2 = 1;
    C3 = 1;
    D4 = 1;
    D5 = 1;
    D6 = 1;
    D7 = 1;

    //Inicialização do LCD
    OpenXLCD(FOUR_BIT & LINES_5X7);
    WriteCmdXLCD(0x01); // Limpa o LCD com retorno do cursor
    __delay_ms(10);
    WriteCmdXLCD(0x86); // Posiciona na Coluna 7 Linha 1
    putrsXLCD("TECLA"); // Escreve a string TECLA

    while (1) {//loop infinito
        //selecionando a coluna 0
        C0 = 0;
        C1 = 1;
        C2 = 1;
        C3 = 1;

        __delay_ms(50);

        if (!L0) {
        WriteCmdXLCD(0xC7); // Seleciona a posição Coluna 8 e Linha 2
            putcXLCD('1'); // Escreve o caractere 1
        } else if (!L1) {
        WriteCmdXLCD(0xC7); // Seleciona a posição Coluna 8 e Linha 2
            putcXLCD('4'); // Escreve o caractere 4
        } else if (!L2) {
        WriteCmdXLCD(0xC7); // Seleciona a posição Coluna 8 e Linha 2
            putcXLCD('7'); // Escreve o caractere 7
        } else if (!L3) {
        WriteCmdXLCD(0xC7); // Seleciona a posição Coluna 8 e Linha 2
            putcXLCD('F'); // Escreve o caractere F
        }

        //selecionando a coluna 1
        C0 = 1;
        C1 = 0;
        C2 = 1;
        C3 = 1;
        __delay_ms(50);
        if (!L0) {
        WriteCmdXLCD(0xC7); // Seleciona a posição Coluna 8 e Linha 2
            putcXLCD('2'); // Escreve o caractere 2
        } else if (!L1) {
        WriteCmdXLCD(0xC7); // Seleciona a posição Coluna 8 e Linha 2
            putcXLCD('5'); // Escreve o caractere 5
        } else if (!L2) {
        WriteCmdXLCD(0xC7); // Seleciona a posição Coluna 8 e Linha 2
            putcXLCD('8'); // Escreve o caractere 8
        } else if (!L3) {
        WriteCmdXLCD(0xC7); // Seleciona a posição Coluna 8 e Linha 2
            putcXLCD('0'); // Escreve o caractere 0
        }

        //selecionando a coluna 2
        C0 = 1;
        C1 = 1;
        C2 = 0;
        C3 = 1;
        __delay_ms(50);
        if (!L0) {
        WriteCmdXLCD(0xC7); // Seleciona a posição Coluna 8 e Linha 2
            putcXLCD('3'); // Escreve o caractere 3
        } else if (!L1) {
        WriteCmdXLCD(0xC7); // Seleciona a posição Coluna 8 e Linha 2
            putcXLCD('6'); // Escreve o caractere 6
        } else if (!L2) {
        WriteCmdXLCD(0xC7); // Seleciona a posição Coluna 8 e Linha 2
            putcXLCD('9'); // Escreve o caractere 9
        } else if (!L3) {
        WriteCmdXLCD(0xC7); // Seleciona a posição Coluna 8 e Linha 2
            putcXLCD('E'); // Escreve o caractere E
        }

        //selecionando a coluna 3
        C0 = 1;
        C1 = 1;
        C2 = 1;
        C3 = 0;
        __delay_ms(50);
        if (!L0) {
        WriteCmdXLCD(0xC7); // Seleciona a posição Coluna 8 e Linha 2
            putcXLCD('A'); // Escreve o caractere A
        }
        if (!L1) {
        WriteCmdXLCD(0xC7); // Seleciona a posição Coluna 8 e Linha 2
            putcXLCD('B'); // Escreve o caractere B
        }
        if (!L2) {
        WriteCmdXLCD(0xC7); // Seleciona a posição Coluna 8 e Linha 2
            putcXLCD('C'); // Escreve o caractere C
        }
        if (!L3) {
        WriteCmdXLCD(0xC7); // Seleciona a posição Coluna 8 e Linha 2
            putcXLCD('D'); // Escreve o caractere D
        }
    }//fim de loop
}//fim de main
