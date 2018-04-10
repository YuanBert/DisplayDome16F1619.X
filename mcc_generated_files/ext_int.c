/**
   EXT_INT Generated Driver File
 
   @Company
     Microchip Technology Inc.
 
   @File Name
     ext_int.c
 
   @Summary
     This is the generated driver implementation file for the EXT_INT driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs
 
   @Description
     This source file provides implementations for driver APIs for EXT_INT.
     Generation Information :
         Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
         Device            :  PIC16F1619
         Driver Version    :  1.01
     The generated drivers are tested against the following:
         Compiler          :  XC8 1.45
         MPLAB             :  MPLAB X 4.15
 */ 

 /**
   Section: Includes
 */
#include <xc.h>
#include "ext_int.h"
extern volatile unsigned char gInterruptFlag;
extern volatile unsigned char gEnterFlag;
extern volatile unsigned char gExitFlag;
void (*INT_InterruptHandler)(void);

void INT_ISR(void)
{
    EXT_INT_InterruptFlagClear();

    // Callback function gets called everytime this ISR executes
    INT_CallBack();    
}


void INT_CallBack(void)
{
    // Add your custom callback code here
    gInterruptFlag = 1;
    if(1 == OPTION_REGbits.INTEDG)
    {
        gEnterFlag = 1;
        gExitFlag = 0;
        EXT_INT_fallingEdgeSet();
    }
    else
    {
        gEnterFlag = 0;
        gExitFlag = 1;
        EXT_INT_risingEdgeSet();
    }
    if(INT_InterruptHandler)
    {
        INT_InterruptHandler();
    }
}

void INT_SetInterruptHandler(void (* InterruptHandler)(void)){
    INT_InterruptHandler = InterruptHandler;
}

void INT_DefaultInterruptHandler(void){
    // add your INT interrupt custom code
    // or set custom function using INT_SetInterruptHandler()
}

void EXT_INT_Initialize(void)
{
    
    // Clear the interrupt flag
    // Set the external interrupt edge detect
    EXT_INT_InterruptFlagClear();   
    EXT_INT_risingEdgeSet();    
    // Set Default Interrupt Handler
    INT_SetInterruptHandler(INT_DefaultInterruptHandler);
    EXT_INT_InterruptEnable();      

}

