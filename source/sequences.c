/*============================================================================
** PROJECT      = 78K0 Demonstration Board  (Lightshow)
** MODULE       = sequences.c
** SHORT DESC.  = -
** DEVICE       = uPD78F0066
** VERSION      = 1.0
** DATE         = 02.01.2000
** LAST CHANGE  = -
** ===========================================================================
** Description:  Definition of the sequences
**
** ===========================================================================
** Environment:  Device:         uPD78F0066                                    
**               Assembler:      A78000         Version 3.30A                     
**               C-Compiler:     ICC78000       Version 3.30A
**               Linker:         XLINK          Version 4.51O
**               Simulator:      SM78K0         Version 2.10 
** ===========================================================================
** By:          NEC Electronics (Europe) GmbH
**              Oberrather Strasse 4
**              D-40472 Duesseldorf
**
** ===========================================================================
Changes:           
** ===========================================================================
*/
/* ============================================================================
**  Module name: vShow1
**
**  Description:
**               This module defines lightshow number1.
**
**  Operation:
**               -
** ============================================================================
*/

//-----------------------------------------------------------------------------
// Include files
//-----------------------------------------------------------------------------
#include <in78000.h>
#include "DF0066.h"                       
#include "defines.h"

//-----------------------------------------------------------------------------
// Global variables
//-----------------------------------------------------------------------------
extern bit                 bTimerFlag;          // Status Flag Timer
extern bit                 bKey1Flag;           // Status Key1
extern bit                 bKey2Flag;           // Status Key2
extern saddr unsigned char ucLEDs;              // LED output
//-----------------------------------------------------------------------------
// Function prototyps
//-----------------------------------------------------------------------------
extern void   vWait50        (unsigned char);   // n *  50ms delay

/* ============================================================================
**  Module name: vShow1
**
**  Description:
**               This module defines lightshow number1.
**
**  Operation:
**               -
** ============================================================================
*/
void vShow1(void)
{
    unsigned char i;
    ucLEDs=0xFF;                       
    for(i=0;i<8;i++){
       ucLEDs=(ucLEDs<<1);
       vWait50(10);                    // Delay of 500 ms 
    }
    for(i=0;i<8;i++){
       ucLEDs=(ucLEDs>>1)+0x80;
       vWait50(10);                    // Delay of 500 ms 
    }
    return;
}
/* ============================================================================
**  Module name: vShow2
**
**  Description:
**               This module defines lightshow number2.
**
**  Operation:
**               -
** ============================================================================
*/
void vShow2(void)
{
    unsigned char i;
    ucLEDs=0xFE;
       vWait50(10);                    // Delay of 500 ms 
    for(i=0;i<7;i++){
       ucLEDs=(ucLEDs<<1)+0x01;
       vWait50(10);                    // Delay of 500 ms 
    }
    ucLEDs=0x7F;    
    for(i=0;i<7;i++){
       ucLEDs=(ucLEDs>>1)+0x80;
       vWait50(10);                    // Delay of 500 ms 
    }
    return;
}
/* ============================================================================
**  Module name: vShow3
**
**  Description:
**               This module defines lightshow number3.
**
**  Operation:
**               -
** ============================================================================
*/
void vShow3(void)
{
    unsigned char i;
    ucLEDs=0xFE;                      
    for(i=0;i<8;i++){
       vWait50(2);                    // Delay of 100 ms 
       ucLEDs=(ucLEDs<<1)+0x01;
    }
    return;
}

/* ============================================================================
**  Module name: vShow4
**
**  Description:
**               This module defines lightshow number4.
**
**  Operation:
**               -
** ============================================================================
*/
void vShow4(void)
{
    unsigned char i;
    ucLEDs=0x01;
    for(i=0;i<8;i++){
       vWait50(5);                    // Delay of 250 ms 
       ucLEDs=(ucLEDs<<1);
    }
    return;
}

/* ============================================================================
**  Module name: vShow5
**
**  Description:
**               This module defines lightshow number5.
**
**  Operation:
**               -
** ============================================================================
*/
void vShow5(void)
{
    unsigned char i;
    ucLEDs=0xEE;
    for(i=0;i<4;i++){
       vWait50(2);                     // Delay of 100 ms 
       ucLEDs = (ucLEDs << 1) + 0x01;
    }
    
    return;
}
/* ============================================================================
**  Module name: vShow6
**
**  Description:
**               This module defines lightshow number6.
**
**  Operation:
**               -
** ============================================================================
*/
void vShow6(void)
{
    unsigned char i;
    ucLEDs=0xFE;                       
    for(i=0;i<8;i++){
       vWait50(10);                    // Delay of 500 ms 
       ucLEDs=(ucLEDs<<1);
    }
    for(i=0;i<8;i++){
       ucLEDs=(ucLEDs<<1)+0x01;
       vWait50(10);                    // Delay of 500 ms 
    }   
    return;
}
/* ============================================================================
**  Module name: vShow7
**
**  Description:
**               This module defines lightshow number7.
**
**  Operation:
**               -
** ============================================================================
*/
void vShow7(void)
{
    unsigned char i;
    ucLEDs=0x7F;                      
    for(i=0;i<8;i++){
       vWait50(1);                    // Delay of 50 ms 
       ucLEDs=(ucLEDs>>1)+0x80;
    }
    return;
}

/* ============================================================================
**  Module name: vShow8
**
**  Description:
**               This module defines lightshow number8.
**
**  Operation:
**               -
** ============================================================================
*/
void vShow8(void)
{
    unsigned char i;
    ucLEDs=0xFC;
    for (i=0;i<4;i++){
      vWait50(2);                     // Delay of 100 ms 
      ucLEDs = (ucLEDs << 2) + 0x03;
    }
    return;
}

/* ============================================================================
**  Module name: vShow9
**
**  Description:
**               This module defines lightshow number9.
** added by mjh on Thinkpad R52
**  Operation:
**               -
** ============================================================================
*/
#define vShow9forTest 4
void vShow9(void)
{
    unsigned char i;
    ucLEDs=0xFC;
    for (i=0;i<vShow9forTest;i++){
      vWait50(2);                     // Delay of 100 ms 
      ucLEDs = (ucLEDs << 2) + 0x03;
    }
    return;
}

