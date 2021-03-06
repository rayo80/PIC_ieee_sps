/* 
 * File:   main.c
 * Author: sergi
 *
 * Created on 6 de octubre de 2020, 01:30 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <pic18f45k50.h>
#include <xc.h>
#include "configuracion.h"
#define _XTAL_FREQ 2000000UL

void oscilador(void);
int luces[8]={0x01,0x03,0x07,0x0F,0x1F,0x3F,0x7F,0xFF};
/*
 * 
 */
int main(int argc, char** argv) {
    TRISD=0;
    TRISA=0;
    PORTD=0;
    ANSELA=0;
    PORTA=0;
    
    while(1){
        for(int i=0;i<8;i++){           
            PORTD=luces[i];   
            __delay_ms(500);                  
        }
        for(int k=0;k<8;k++){           
            PORTA=luces[k];   
            __delay_ms(500);                  
        }
        PORTD=0;
        PORTA=0;
        __delay_ms(500);
    }
    return (EXIT_SUCCESS);
}

void oscilador(void){
    OSCCON=0X40;
    OSCCON2=0X00;
}                                                                                                                                                                                                                                                                                                                                                                                                                     