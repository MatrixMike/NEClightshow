/*============================================================================
** PROJECT      = 78K0 Demonstration Board
** MODULE       = init.c
** SHORT DESC.  = -
** DEVICE       = uPD78F0066
** VERSION      = 1.0
** DATE         = 02.01.2000
** LAST CHANGE  = -
** ===========================================================================
** Description:  Initialization of Registers and Bit Variables
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
// Include files
//-----------------------------------------------------------------------------
#include <in78000.h>
#include "DF0066.h"                       
#include "defines.h"

//-----------------------------------------------------------------------------
// Global variables
//-----------------------------------------------------------------------------
extern bit           bTimer51Flag;     // Status Flag Timer51
extern bit           bKey1Flag;        // Status Flag Key1
extern bit           bKey2Flag;        // Status Flag Key2


/* ============================================================================
**  Module name: vHardwareInit
**
**  Description:
**               This module is to initialize some peripheral hardware.
**
**  Operation:
**               Sets the clock generator, the port modes and output latches
**               and initializes the interrupts.
** ============================================================================
*/
void vHardwareInit(void)               // Hardware inizialization
{
// clock generator setting
//------------------------
    PCC  = 0x00;                       // Use high speed mode 
    OSTS = 0x02;                       // 2^15/fx ms wait after STOP release by interrupt
    IMS  = 0xCC;                       // Select 1024 Byte RAM and 48k Byte ROM
    IXS  = 0x04;                       // Select 4096 Byte RAM 

// port setting
//-------------
    P0     = 0x00;                     // Set output latch to 0
    P2     = 0x00;                     // Set output latch to 0
    P3     = 0x00;                     // Set output latch to 0
    P4     = 0x00;                     // Set output latch to 0
    P5     = 0xff;                     // Set output latch to 0xff
    P6     = 0x00;                     // Set output latch to 0
    P7     = 0x00;                     // Set output latch to 0
    P8     = 0x00;                     // Set output latch to 0
    P8     = 0x00;                     // Set output latch to 0
    PM0    = 0xFF;                     // Port 0 =  input (8-bits)
    PM2    = 0xFF;                     // Port 2 =  input (8-bits) 
    PM3    = 0xFF;                     // Port 3 =  input (8-bits)       
    PM4    = 0x00;                     // Port 4 =  input (8-bits)
    PM5    = 0x00;                     // Port 5 = output (8-bits)
    PM6    = 0xFF;                     // Port 6 =  input (4-bits) 
    PM7    = 0x88;                     // Port 7.7,7.3 input, other output 
    PM8    = 0xE0;                     // Port 8 = output (5 bits)
    PM9    = 0xFF;                     // Port 9 =  input (3-bits) 
   
// interrupt setting                    
//------------------

    IF0L   = 0x00;                     // Reset all interrupt request bits
    IF0H   = 0x00;
    IF1L   = 0x00;
    MK0L   = 0xFF;                     // Disable all interrupts 
    MK0H   = 0xFF;
    MK1L   = 0xFF;  
    PR0L   = 0xFF;                     // Set all interrupts to low priority
    PR0H   = 0xFF;             
    PR1L   = 0xFF;            

// ext. Interrupt setting
// -------------------

    EGP    = 0x0C;                     // Enable ext.interrupt rising edge 
    EGN    = 0x00;                     // P2, P3
    PMK2   = FALSE;                    // Enable Port P0.2 interrupt (Mask Flag Register)
    PMK3   = FALSE;                    // Enable Port P0.3 interrupt (Mask Flag Register)
  
// 8 Bit Timer setting
// --------------
    TMC50  = 0x00;                     // Stop timer operation
    TMC51  = 0x00;                     // Stop timer operation
    TCL51  = 0x07;                     // Set timer clock :  fx/2^11 (4.194304 MHz -> 2048 Hz)   Hz 
    CR51   = 0x66;                     // Timer51 compare value =>  50ms intervall
    TMIF51 = FALSE;                    // Clear interrupt request Bit Timer51
    TMMK51 = FALSE;                    // Enable Timer51 Interrupt
    TMC51  = 0x80;                     // Start Timer 51
                                       // no output, single mode
                                       // clear and start by matching TM51 and CR51
// 16 Bit Timer setting
// --------------------
   
    TMC0   = 0x02;                     // Stop and Clear Timer 0
    CRC0   = 0x00;                     // Register CR00, CR01 operate as compare register
    CR00   = 0x028F;                   // Compare values for 10ms Intervall 
    TOC0   = 0x00;                     // Disable Timer output                                       
    PRM0   = 0x02;                     // Clock selection: fx/2^6 (4.194304 MHz -> 65537 Hz)
    TMIF00 = FALSE;                    // Clear interrupt request Bit Timer0
    TMMK00 = FALSE;                    // Enable Timer0 Interrupt
}

/* ============================================================================
**  Module name: vSoftwareInit
**
**  Description:
**               This module is to initialize the bit variables 
**
**  Operation:
**               -
** ============================================================================
*/
 
void vSoftwareInit(void)
{
    bTimer51Flag = FALSE;              // Reset status flag Timer51
    bKey1Flag    = FALSE;              // Reset status flag Key1
    bKey2Flag    = FALSE;              // Reset status flag Key2
}
