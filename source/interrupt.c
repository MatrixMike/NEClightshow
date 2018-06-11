/*============================================================================
** PROJECT      = 78K0 Demonstration Board (Lightshow)
** MODULE       = interrupt.c
** SHORT DESC.  = -
** DEVICE       = uPD78F0066
** VERSION      = 1.0
** DATE         = 02.01.2000
** LAST CHANGE  = -
** ===========================================================================
** Description:  Interrupt service routines for Lightshow
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

//-----------------------------------------------------------------------------
// Defines
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Include files
//-----------------------------------------------------------------------------
#include <in78000.h>
#include "df0066.h"             
#include "defines.h"

//-----------------------------------------------------------------------------
// Global variables
//-----------------------------------------------------------------------------
extern bit           bTimer51Flag;     // Status Flag Timer51
extern bit           bKey1Flag;        // Status Flag Key1
extern bit           bKey2Flag;        // Status Flag Key2

extern saddr unsigned char ucLEDs;
static saddr unsigned char ucOldLEDs; 
/* ============================================================================
**  Module name: vTimer0
**
**  Description:
**               This module is the Interrupt service routine for Timer0
**
**  Operation:
**               
** ============================================================================
*/
interrupt [INTTM00_vect] void vTimer0(void)
{
    static saddr unsigned char ucFlag;
    static saddr unsigned char ucOldLEDs; 
    if (ucOldLEDs==ucLEDs){
        if (ucFlag==0x01){
          ucFlag=0x00;
          LED=0xff;                        // all LEDs off
        }
        else{
          ucFlag=0x01;
          LED=ucLEDs;                      // Output LED value 
        }
    }                  
    else{
      ucOldLEDs=ucLEDs;                    // save current LED value 
      LED=ucLEDs;                          // Output LED value 
      ucFlag=0x01;                            
    }
}



/* ============================================================================
**  Module name: vTimer51
**
**  Description:
**               This module is the Interrupt service routine for Timer51
**
**  Operation:
**               -
** ============================================================================
*/
interrupt [INTTM51_vect] void vTimer51(void)
{
    bTimer51Flag = 1 ;                  // Set status flag Timer51
}



/* ============================================================================
**  Module name: vKey2
**
**  Description:
**               This module is the Interrupt service routine for 
**               the external interrupt P2 (-> Key2)
**
**  Operation:
**               -
** ============================================================================
*/
interrupt [INTP2_vect] void vKey2(void)
{
    bKey2Flag = 1 ;                    // Set status flag Key2 
}

/* ============================================================================
**  Module name: vKey1
**
**  Description:
**               This module is the Interrupt service routine for 
**               the external interrupt P3 (-> Key1)
**
**  Operation:
**               -
** ============================================================================
*/
interrupt [INTP3_vect] void vKey1(void)
{
    bKey1Flag = 1 ;                    // Set status flag Key1
}


