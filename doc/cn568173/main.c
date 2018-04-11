/*
 * File:   main.c
 * Author: Lucio Di Jasio
 *
 * Created on August 28, 2013
 */
#include <xc.h>
#include "Flash.h"
#include "HEFlash.h"

#include <assert.h>
#include <string.h>

// Configuration Bit Settings

__IDLOC( 4D8A);

// CONFIG1
#pragma config FOSC = INTOSC    // Oscillator Selection Bits (INTOSC oscillator: I/O function on CLKIN pin)
#pragma config WDTE = OFF       // Watchdog Timer Enable (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable (PWRT disabled)
#pragma config MCLRE = ON       // MCLR Pin Function Select (MCLR/VPP pin function is MCLR)
#pragma config CP = OFF         // Flash Program Memory Code Protection (Program memory code protection is disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable (Brown-out Reset enabled)
#pragma config CLKOUTEN = OFF   // Clock Out Enable (CLKOUT function is disabled. I/O or oscillator function on the CLKOUT pin)
//#pragma config IESO = ON        // Internal/External Switchover Mode (Internal/External Switchover Mode is enabled)
//#pragma config FCMEN = ON       // Fail-Safe Clock Monitor Enable (Fail-Safe Clock Monitor is enabled)

// CONFIG2
#pragma config WRT = OFF        // Flash Memory Self-Write Protection (Write protection off)
#pragma config STVREN = ON      // Stack Overflow/Underflow Reset Enable (Stack Overflow or Underflow will cause a Reset)
#pragma config BORV = LO        // Brown-out Reset Voltage Selection (Brown-out Reset Voltage (Vbor), low trip point selected.)
#pragma config LPBOR = OFF      // Low-Power Brown Out Reset (Low-Power BOR is disabled)
#pragma config LVP = OFF        // Low-Voltage Programming Enable (High-voltage on MCLR/VPP must be used for programming)


void _fassert( int line, const char *file, const char *expr)
{
    TRISC = 0xf0;
    PORTC = PORTC+1;
} // _fassert



void main(void)
{
    unsigned r, i;
    unsigned wbuffer[4];
    char buffer[ FLASH_ROWSIZE];

    typedef struct {
        unsigned ID;
        char     Name[20];
        long     Amount;
    } Record;

    Record data = { 0x1234, "HE FLASH", 42};
    
    
    // testing the FLASH read (word in program memory)
    r = FLASH_read( 0x0001);
    assert( r == 0x3180);

    // read the first IDLOC
    r = FLASH_readConfig( 0x8000);
    assert( r == 4);
    
    // testing the HE FLASH read block (bytes in HE flash)
    r = HEFLASH_readBlock( buffer, 1, FLASH_ROWSIZE);
    assert ( r == 0);

    // write data to HE row 1
    r = HEFLASH_writeBlock( 1, (void*)&data, sizeof( data));
    assert ( r == 0);
    
    // empty the buffer
    memset( &data, 0, sizeof( data));
    //data.ID = 0;
    //data.Name[0] = '\0';
    //data.Amount = 0L;

    // read back its contents
    r = HEFLASH_readBlock( (void*)&data, 1, sizeof( data));
    assert ( r == 0);

    // read a single byte
    r = HEFLASH_readByte( 1, 5);
    assert( r == 'F');

    while( 1)
    {
        // stop here
    }
}


