/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC16F1619
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "mcc_generated_files/mcc.h"
#include "bsp_counter.h"
#include "FLash.h"
#include "HEFLash.h"
#include <assert.h>
#include <string.h>

#pragma __IDLOC( 4D8A );

#define KeyPushTimeSum      600     //press and hole for 3 seconds to clear HEF data

/*
                         Main application
 */
volatile unsigned char gInterruptFlag;
volatile unsigned char gEnterFlag;
volatile unsigned char gExitFlag;

volatile unsigned char  gTimer0NormalFalshCnt;
volatile unsigned char  gTimer0NormalFlashFlag;
volatile unsigned char  gTimer0AlarmFlashFlag;

volatile unsigned char  gTimer3Flag;

volatile unsigned long KeyPushTimeCnt;
volatile unsigned char KeyClearHEFFlag;


BoxCntStruct gBoxCntStruct;


unsigned char HEFBufferData[FLASH_ROWSIZE];

void _fassert(int line, const char *file, const char *expr)
{
    TRISC = 0xf0;
    PORTC = PORTC;
}


void LCDSendData(int RS, uint8_t value)
{
    D0_LAT = value & 1;
    D1_LAT = (value & 2) >> 1;
    D2_LAT = (value & 4) >> 2;
    D3_LAT = (value & 8) >> 3;
    D4_LAT = (value & 16) >> 4;
    D5_LAT = (value & 32) >> 5;
    D6_LAT = (value & 64) >> 6;
    D7_LAT = (value & 128) >> 7; 
    if(RS > 0)
    {
        RS_LAT = 1;
    }
    else
    {
        RS_LAT = 0;
    }
    EN_SetHigh();
    __delay_ms(1);
    EN_SetLow();
    __delay_ms(10); 
}

void LCDInit()
{
    EN_LAT = 0;
    RS_LAT = 0;
    D0_LAT = 0;
    D1_LAT = 0;
    D2_LAT = 0;
    D3_LAT = 0;
    D4_LAT = 0;
    D5_LAT = 0;
    D6_LAT = 0;
    D7_LAT = 0; 

    __delay_ms(50);
    LCDSendData(0, 0b00111000);
    
    // Send second init command as per data sheet instructions (Function Set)
    __delay_ms(50);
    LCDSendData(0, 0b00111000);
    
    // Send third init command as per data sheet instructions (Function Set)
    __delay_ms(50);
    LCDSendData(0, 0b00111000);
    
   // Send fourth init package as per data sheet instructions 
    __delay_ms(50);
    LCDSendData(0, 0b00111000); //Function Set
    LCDSendData(0, 0b00001111); //Display Off
    LCDSendData(0, 0b00000001); //Display Clear
    LCDSendData(0, 0b00000110); //Entry Mode Set
}
uint8_t display_data_1[]={"S:000M:000L:000"};
uint8_t display_data_2[]={"Z:000G:000"};
uint8_t clearingData[] = {"Clearing Data ..."};
uint8_t clearDataOk_1[] = {"Data clearing "};
uint8_t clearDataOk_2[] = {"completed "};
//uint8_t display_data_2_alarm[] = {""};
//uint8_t display_data_2_jam[] = {""};

void Print(uint8_t *str)
{
    while(*str !='\0')
    {
        LCDSendData(1,*str);
        str++;
        __delay_ms(1);
    }
}

void Data_Toseg()
{
    display_data_1[2] = (gBoxCntStruct.SmallBoxCnt%1000/100)+0x30;
    display_data_1[3] = (gBoxCntStruct.SmallBoxCnt%100/10)+0x30;
    display_data_1[4] = (gBoxCntStruct.SmallBoxCnt%10)+0x30;
    
    
    display_data_1[7] = (gBoxCntStruct.MiddleBoxCnt%1000/100)+0x30;
    display_data_1[8] = (gBoxCntStruct.MiddleBoxCnt%100/10)+0x30;
    display_data_1[9] = (gBoxCntStruct.MiddleBoxCnt%10)+0x30;
    
    display_data_1[12] = (gBoxCntStruct.LargeBoxCnt%1000/100)+0x30;
    display_data_1[13] = (gBoxCntStruct.LargeBoxCnt%100/10)+0x30;
    display_data_1[14] = (gBoxCntStruct.LargeBoxCnt%10)+0x30;
    
    display_data_2[2] = (gBoxCntStruct.BoxSum%1000/100)+0x30;
    display_data_2[3] = (gBoxCntStruct.BoxSum%100/10)+0x30;
    display_data_2[4] = (gBoxCntStruct.BoxSum%10)+0x30;
    
    display_data_2[7] = (gBoxCntStruct.JamCnt%1000/100)+0x30;
    display_data_2[8] = (gBoxCntStruct.JamCnt%100/10)+0x30;
    display_data_2[9] = (gBoxCntStruct.JamCnt%10)+0x30;
    
    //HEFBufferData[2] = (unsigned char)(gBoxCntStruct.SmallBoxCnt >> 16);
    HEFBufferData[3] = (unsigned char)(gBoxCntStruct.SmallBoxCnt >> 8);
    HEFBufferData[4] = (unsigned char)(gBoxCntStruct.SmallBoxCnt);
            
    //HEFBufferData[6] = (unsigned char)(gBoxCntStruct.MiddleBoxCnt >> 16);
    HEFBufferData[7] = (unsigned char)(gBoxCntStruct.MiddleBoxCnt >> 8);
    HEFBufferData[8] = (unsigned char)(gBoxCntStruct.MiddleBoxCnt);
            
    //HEFBufferData[10] = (unsigned char)(gBoxCntStruct.LargeBoxCnt >> 16);
    HEFBufferData[11] = (unsigned char)(gBoxCntStruct.LargeBoxCnt >> 8);
    HEFBufferData[12] = (unsigned char)(gBoxCntStruct.LargeBoxCnt );
            
    //HEFBufferData[14] = (unsigned char)(gBoxCntStruct.BoxSum >> 16);
    HEFBufferData[15] = (unsigned char)(gBoxCntStruct.BoxSum >> 8);
    HEFBufferData[16] = (unsigned char)(gBoxCntStruct.BoxSum );
         
    //HEFBufferData[18] = (unsigned char)(gBoxCntStruct.JamCnt >> 16);
    HEFBufferData[19] = (unsigned char)(gBoxCntStruct.JamCnt >> 8);
    HEFBufferData[20] = (unsigned char)(gBoxCntStruct.JamCnt );
    
    INTERRUPT_GlobalInterruptDisable();
    HEFLASH_writeBlock(0, (void*)&HEFBufferData,sizeof(HEFBufferData));
    INTERRUPT_GlobalInterruptEnable();
}

void HEFLASH_checkData(void)
{
    unsigned r;
__delay_ms(200);
    r = HEFLASH_readBlock(HEFBufferData, 0, FLASH_ROWSIZE);
    assert(0 == r);
    if(0xAA == HEFBufferData[0])
    {
        gBoxCntStruct.SmallBoxCnt = (unsigned int)((HEFBufferData[3] << 8) + (HEFBufferData[4]));
        
        gBoxCntStruct.MiddleBoxCnt = (unsigned int)((HEFBufferData[7] << 8) + (HEFBufferData[8]));
        
        gBoxCntStruct.LargeBoxCnt = (unsigned int)((HEFBufferData[11] << 8) + (HEFBufferData[12]));
        
        gBoxCntStruct.BoxSum = (HEFBufferData[13] << 24) + (HEFBufferData[14] << 16) + \
                                    (HEFBufferData[15] << 8) + (HEFBufferData[16]);
        
        gBoxCntStruct.JamCnt = (unsigned int)((HEFBufferData[19] << 8) + (HEFBufferData[20]));
        
        display_data_1[2] = (gBoxCntStruct.SmallBoxCnt%1000/100)+0x30;
        display_data_1[3] = (gBoxCntStruct.SmallBoxCnt%100/10)+0x30;
        display_data_1[4] = (gBoxCntStruct.SmallBoxCnt%10)+0x30;
    
    
        display_data_1[7] = (gBoxCntStruct.MiddleBoxCnt%1000/100)+0x30;
        display_data_1[8] = (gBoxCntStruct.MiddleBoxCnt%100/10)+0x30;
        display_data_1[9] = (gBoxCntStruct.MiddleBoxCnt%10)+0x30;
    
        display_data_1[12] = (gBoxCntStruct.LargeBoxCnt%1000/100)+0x30;
        display_data_1[13] = (gBoxCntStruct.LargeBoxCnt%100/10)+0x30;
        display_data_1[14] = (gBoxCntStruct.LargeBoxCnt%10)+0x30;
    
        display_data_2[2] = (gBoxCntStruct.BoxSum%1000/100)+0x30;
        display_data_2[3] = (gBoxCntStruct.BoxSum%100/10)+0x30;
        display_data_2[4] = (gBoxCntStruct.BoxSum%10)+0x30;
    
        display_data_2[7] = (gBoxCntStruct.JamCnt%1000/100)+0x30;
        display_data_2[8] = (gBoxCntStruct.JamCnt%100/10)+0x30;
        display_data_2[9] = (gBoxCntStruct.JamCnt%10)+0x30;        
    }
    else
    {
        memset(&HEFBufferData, 0, sizeof(HEFBufferData));
        HEFBufferData[0] = 0xAA;
        r == HEFLASH_writeBlock(0, (void*)&HEFBufferData,sizeof(HEFBufferData));
        assert (0 == r);
    }
}

void main(void)
{
    
    // initialize the device
    SYSTEM_Initialize();
    bsp_CounterInit();
    LCDInit();
    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:
    
    HEFLASH_checkData();
    
    LCDSendData(0, 0b10000000); //set cursor to start of 1nd line
    Print(display_data_1);
    __delay_ms(200);
    LCDSendData(0, 0b11000000); //set cursor to start of 2nd line
    Print(display_data_2);
    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();


    while (1)
    {
        // Add your application code
        if(gInterruptFlag)
       {
            //LED1_Toggle();
            gInterruptFlag = 0;  
        }
        
        if(0 == Key_GetValue() )
        {
            __delay_ms(5);
            if(0 == Key_GetValue() )
            {
                KeyPushTimeCnt++;
                if(KeyPushTimeCnt > KeyPushTimeSum)
                {
                    KeyClearHEFFlag = 1;
                    KeyPushTimeCnt = 0;
                    LCDSendData(0, 0b10000000);
                    Print(clearingData);
                    __delay_ms(1000);
                }
                gBoxCntStruct.AlarmFlag = 0;
                gBoxCntStruct.JamFlag = 0;
            }
        } 
        else
        {
            KeyPushTimeCnt = 0;
        }
        
        if(1 == Key_GetValue() && 1 == KeyClearHEFFlag )
        {
            KeyClearHEFFlag = 0;
            memset(&HEFBufferData, 0, sizeof(HEFBufferData));
            HEFBufferData[0] = 0xAA;
            INTERRUPT_GlobalInterruptDisable();
            HEFLASH_writeBlock(0, (void*)&HEFBufferData,sizeof(HEFBufferData));
            INTERRUPT_GlobalInterruptEnable();
            LCDSendData(0, 0b10000000);
            Print(clearDataOk_1);
            LCDSendData(0, 0b11000000);
            Print(clearDataOk_2);
            __delay_ms(800);
        }
        
        if(gTimer0NormalFlashFlag)
        {
            gTimer0NormalFlashFlag = 0;
            
             LED1_Toggle();
             if(0 == gBoxCntStruct.AlarmFlag)
             {
                LED2_LAT = ~LED1_LAT; 
             }
        }
        if(1 == gTimer0AlarmFlashFlag)
        {
            gTimer0AlarmFlashFlag = 0;
            if(1 == gBoxCntStruct.AlarmFlag)
            {
               LED2_LAT = ~LED2_LAT;
            }
        }
        
//        bsp_RA2InterruptISRCallback();    
//        if(gTimer3Flag)
//        {
//            gTimer3Flag = 0;
//            bsp_TimerInterruptISRCallback();
//        }
        
        if(gBoxCntStruct.DisplayReflashFlag)
        {
            //LED2_Toggle();
            gBoxCntStruct.DisplayReflashFlag = 0;
            Data_Toseg();
            LCDSendData(0, 0b10000000); //set cursor to start of 1nd line
            Print(display_data_1);
            LCDSendData(0, 0b11000000); //set cursor to start of 2nd line
            //if(0 == gBoxCntStruct.AlarmFlag && 0 == gBoxCntStruct.JamFlag)
            //{
                Print(display_data_2);
            //}
//            if(1 == gBoxCntStruct.AlarmFlag && 0 == gBoxCntStruct.JamFlag)
//            {
//                Print(display_data_2_alarm);
//            }
            /*if(1 == gBoxCntStruct.JamFlag)
            {
                Print(display_data_2_jam);
            }*/
                
            
        }
        
    }
}
/**
 End of File
*/