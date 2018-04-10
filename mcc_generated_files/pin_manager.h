/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC16F1619
        Driver Version    :  2.01
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.45
        MPLAB 	          :  MPLAB X 4.15	
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

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set Key aliases
#define Key_TRIS                 TRISAbits.TRISA1
#define Key_LAT                  LATAbits.LATA1
#define Key_PORT                 PORTAbits.RA1
#define Key_WPU                  WPUAbits.WPUA1
#define Key_OD                   ODCONAbits.ODA1
#define Key_ANS                  ANSELAbits.ANSA1
#define Key_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define Key_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define Key_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define Key_GetValue()           PORTAbits.RA1
#define Key_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define Key_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define Key_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define Key_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define Key_SetPushPull()        do { ODCONAbits.ODA1 = 0; } while(0)
#define Key_SetOpenDrain()       do { ODCONAbits.ODA1 = 1; } while(0)
#define Key_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define Key_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set RA2 procedures
#define RA2_SetHigh()               do { LATAbits.LATA2 = 1; } while(0)
#define RA2_SetLow()                do { LATAbits.LATA2 = 0; } while(0)
#define RA2_Toggle()                do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define RA2_GetValue()              PORTAbits.RA2
#define RA2_SetDigitalInput()       do { TRISAbits.TRISA2 = 1; } while(0)
#define RA2_SetDigitalOutput()      do { TRISAbits.TRISA2 = 0; } while(0)
#define RA2_SetPullup()             do { WPUAbits.WPUA2 = 1; } while(0)
#define RA2_ResetPullup()           do { WPUAbits.WPUA2 = 0; } while(0)
#define RA2_SetAnalogMode()         do { ANSELAbits.ANSA2 = 1; } while(0)
#define RA2_SetDigitalMode()        do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set LED1 aliases
#define LED1_TRIS                 TRISAbits.TRISA4
#define LED1_LAT                  LATAbits.LATA4
#define LED1_PORT                 PORTAbits.RA4
#define LED1_WPU                  WPUAbits.WPUA4
#define LED1_OD                   ODCONAbits.ODA4
#define LED1_ANS                  ANSELAbits.ANSA4
#define LED1_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define LED1_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define LED1_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define LED1_GetValue()           PORTAbits.RA4
#define LED1_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define LED1_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define LED1_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define LED1_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define LED1_SetPushPull()        do { ODCONAbits.ODA4 = 0; } while(0)
#define LED1_SetOpenDrain()       do { ODCONAbits.ODA4 = 1; } while(0)
#define LED1_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define LED1_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set LED2 aliases
#define LED2_TRIS                 TRISAbits.TRISA5
#define LED2_LAT                  LATAbits.LATA5
#define LED2_PORT                 PORTAbits.RA5
#define LED2_WPU                  WPUAbits.WPUA5
#define LED2_OD                   ODCONAbits.ODA5
#define LED2_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define LED2_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define LED2_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define LED2_GetValue()           PORTAbits.RA5
#define LED2_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define LED2_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define LED2_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define LED2_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define LED2_SetPushPull()        do { ODCONAbits.ODA5 = 0; } while(0)
#define LED2_SetOpenDrain()       do { ODCONAbits.ODA5 = 1; } while(0)

// get/set D0 aliases
#define D0_TRIS                 TRISBbits.TRISB5
#define D0_LAT                  LATBbits.LATB5
#define D0_PORT                 PORTBbits.RB5
#define D0_WPU                  WPUBbits.WPUB5
#define D0_OD                   ODCONBbits.ODB5
#define D0_ANS                  ANSELBbits.ANSB5
#define D0_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define D0_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define D0_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define D0_GetValue()           PORTBbits.RB5
#define D0_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define D0_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define D0_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define D0_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define D0_SetPushPull()        do { ODCONBbits.ODB5 = 0; } while(0)
#define D0_SetOpenDrain()       do { ODCONBbits.ODB5 = 1; } while(0)
#define D0_SetAnalogMode()      do { ANSELBbits.ANSB5 = 1; } while(0)
#define D0_SetDigitalMode()     do { ANSELBbits.ANSB5 = 0; } while(0)

// get/set EN aliases
#define EN_TRIS                 TRISBbits.TRISB6
#define EN_LAT                  LATBbits.LATB6
#define EN_PORT                 PORTBbits.RB6
#define EN_WPU                  WPUBbits.WPUB6
#define EN_OD                   ODCONBbits.ODB6
#define EN_ANS                  ANSELBbits.ANSB6
#define EN_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define EN_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define EN_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define EN_GetValue()           PORTBbits.RB6
#define EN_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define EN_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define EN_SetPullup()          do { WPUBbits.WPUB6 = 1; } while(0)
#define EN_ResetPullup()        do { WPUBbits.WPUB6 = 0; } while(0)
#define EN_SetPushPull()        do { ODCONBbits.ODB6 = 0; } while(0)
#define EN_SetOpenDrain()       do { ODCONBbits.ODB6 = 1; } while(0)
#define EN_SetAnalogMode()      do { ANSELBbits.ANSB6 = 1; } while(0)
#define EN_SetDigitalMode()     do { ANSELBbits.ANSB6 = 0; } while(0)

// get/set RS aliases
#define RS_TRIS                 TRISBbits.TRISB7
#define RS_LAT                  LATBbits.LATB7
#define RS_PORT                 PORTBbits.RB7
#define RS_WPU                  WPUBbits.WPUB7
#define RS_OD                   ODCONBbits.ODB7
#define RS_ANS                  ANSELBbits.ANSB7
#define RS_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define RS_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define RS_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define RS_GetValue()           PORTBbits.RB7
#define RS_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define RS_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define RS_SetPullup()          do { WPUBbits.WPUB7 = 1; } while(0)
#define RS_ResetPullup()        do { WPUBbits.WPUB7 = 0; } while(0)
#define RS_SetPushPull()        do { ODCONBbits.ODB7 = 0; } while(0)
#define RS_SetOpenDrain()       do { ODCONBbits.ODB7 = 1; } while(0)
#define RS_SetAnalogMode()      do { ANSELBbits.ANSB7 = 1; } while(0)
#define RS_SetDigitalMode()     do { ANSELBbits.ANSB7 = 0; } while(0)

// get/set D1 aliases
#define D1_TRIS                 TRISCbits.TRISC1
#define D1_LAT                  LATCbits.LATC1
#define D1_PORT                 PORTCbits.RC1
#define D1_WPU                  WPUCbits.WPUC1
#define D1_OD                   ODCONCbits.ODC1
#define D1_ANS                  ANSELCbits.ANSC1
#define D1_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define D1_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define D1_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define D1_GetValue()           PORTCbits.RC1
#define D1_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define D1_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define D1_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define D1_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define D1_SetPushPull()        do { ODCONCbits.ODC1 = 0; } while(0)
#define D1_SetOpenDrain()       do { ODCONCbits.ODC1 = 1; } while(0)
#define D1_SetAnalogMode()      do { ANSELCbits.ANSC1 = 1; } while(0)
#define D1_SetDigitalMode()     do { ANSELCbits.ANSC1 = 0; } while(0)

// get/set D2 aliases
#define D2_TRIS                 TRISCbits.TRISC2
#define D2_LAT                  LATCbits.LATC2
#define D2_PORT                 PORTCbits.RC2
#define D2_WPU                  WPUCbits.WPUC2
#define D2_OD                   ODCONCbits.ODC2
#define D2_ANS                  ANSELCbits.ANSC2
#define D2_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define D2_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define D2_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define D2_GetValue()           PORTCbits.RC2
#define D2_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define D2_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define D2_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define D2_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define D2_SetPushPull()        do { ODCONCbits.ODC2 = 0; } while(0)
#define D2_SetOpenDrain()       do { ODCONCbits.ODC2 = 1; } while(0)
#define D2_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define D2_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set D3 aliases
#define D3_TRIS                 TRISCbits.TRISC3
#define D3_LAT                  LATCbits.LATC3
#define D3_PORT                 PORTCbits.RC3
#define D3_WPU                  WPUCbits.WPUC3
#define D3_OD                   ODCONCbits.ODC3
#define D3_ANS                  ANSELCbits.ANSC3
#define D3_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define D3_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define D3_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define D3_GetValue()           PORTCbits.RC3
#define D3_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define D3_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define D3_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define D3_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define D3_SetPushPull()        do { ODCONCbits.ODC3 = 0; } while(0)
#define D3_SetOpenDrain()       do { ODCONCbits.ODC3 = 1; } while(0)
#define D3_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define D3_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set D4 aliases
#define D4_TRIS                 TRISCbits.TRISC4
#define D4_LAT                  LATCbits.LATC4
#define D4_PORT                 PORTCbits.RC4
#define D4_WPU                  WPUCbits.WPUC4
#define D4_OD                   ODCONCbits.ODC4
#define D4_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define D4_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define D4_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define D4_GetValue()           PORTCbits.RC4
#define D4_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define D4_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define D4_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define D4_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define D4_SetPushPull()        do { ODCONCbits.ODC4 = 0; } while(0)
#define D4_SetOpenDrain()       do { ODCONCbits.ODC4 = 1; } while(0)

// get/set D5 aliases
#define D5_TRIS                 TRISCbits.TRISC5
#define D5_LAT                  LATCbits.LATC5
#define D5_PORT                 PORTCbits.RC5
#define D5_WPU                  WPUCbits.WPUC5
#define D5_OD                   ODCONCbits.ODC5
#define D5_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define D5_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define D5_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define D5_GetValue()           PORTCbits.RC5
#define D5_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define D5_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define D5_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define D5_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define D5_SetPushPull()        do { ODCONCbits.ODC5 = 0; } while(0)
#define D5_SetOpenDrain()       do { ODCONCbits.ODC5 = 1; } while(0)

// get/set D6 aliases
#define D6_TRIS                 TRISCbits.TRISC6
#define D6_LAT                  LATCbits.LATC6
#define D6_PORT                 PORTCbits.RC6
#define D6_WPU                  WPUCbits.WPUC6
#define D6_OD                   ODCONCbits.ODC6
#define D6_ANS                  ANSELCbits.ANSC6
#define D6_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define D6_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define D6_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define D6_GetValue()           PORTCbits.RC6
#define D6_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define D6_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define D6_SetPullup()          do { WPUCbits.WPUC6 = 1; } while(0)
#define D6_ResetPullup()        do { WPUCbits.WPUC6 = 0; } while(0)
#define D6_SetPushPull()        do { ODCONCbits.ODC6 = 0; } while(0)
#define D6_SetOpenDrain()       do { ODCONCbits.ODC6 = 1; } while(0)
#define D6_SetAnalogMode()      do { ANSELCbits.ANSC6 = 1; } while(0)
#define D6_SetDigitalMode()     do { ANSELCbits.ANSC6 = 0; } while(0)

// get/set D7 aliases
#define D7_TRIS                 TRISCbits.TRISC7
#define D7_LAT                  LATCbits.LATC7
#define D7_PORT                 PORTCbits.RC7
#define D7_WPU                  WPUCbits.WPUC7
#define D7_OD                   ODCONCbits.ODC7
#define D7_ANS                  ANSELCbits.ANSC7
#define D7_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define D7_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define D7_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define D7_GetValue()           PORTCbits.RC7
#define D7_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define D7_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define D7_SetPullup()          do { WPUCbits.WPUC7 = 1; } while(0)
#define D7_ResetPullup()        do { WPUCbits.WPUC7 = 0; } while(0)
#define D7_SetPushPull()        do { ODCONCbits.ODC7 = 0; } while(0)
#define D7_SetOpenDrain()       do { ODCONCbits.ODC7 = 1; } while(0)
#define D7_SetAnalogMode()      do { ANSELCbits.ANSC7 = 1; } while(0)
#define D7_SetDigitalMode()     do { ANSELCbits.ANSC7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/