/*============================================================================
** PROJECT      = 78K0 Demonstration Board
** MODULE       = lightshow.c
** SHORT DESC.  = -
** DEVICE       = uPD78F0066
** VERSION      = 1.0
** DATE         = 02.01.2000
** LAST CHANGE  = -
** ===========================================================================
** Description:  A predefined sequence of patterns is shown. Every push of
**               Key1 selects the next pattern, every push of Key 2 selects
**               the previous pattern.
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
// mjh change 1 for watching action of build tools
//Monday, 11 June 2018
#define mjh 1
//-----------------------------------------------------------------------------
// Include files
//-----------------------------------------------------------------------------
#include <in78000.h>
#include "DF0066.h"
#include "defines.h"
#include "mjhdefines.h"

//-----------------------------------------------------------------------------
// Function prototyps
//-----------------------------------------------------------------------------
void vFlashLED (unsigned char);	// Flash LED's
void vRestartT2 (void);		// Restart Timer2
void vWait50 (unsigned char);	// n *  50ms delay

extern void vShow1 (void);	// Lightshow 1
extern void vShow2 (void);	// Lightshow 2
extern void vShow3 (void);	// Lightshow 3
extern void vShow4 (void);	// Lightshow 4
extern void vShow5 (void);	// Lightshow 5
extern void vShow6 (void);	// Lightshow 6
extern void vShow7 (void);	// Lightshow 7
extern void vShow8 (void);	// Lightshow 8
extern void vShow9 (void);    // Lightshow 9 - new - mjh
extern void vHardwareInit (void);	// Initialization Hardware
extern void vSoftwareInit (void);	// Initialization measurement variables

//-----------------------------------------------------------------------------
// Global variables
//-----------------------------------------------------------------------------
bit bTimer51Flag;		// Status Flag Timer
bit bKey1Flag;			// Status Key1
bit bKey2Flag;			// Status Key2
saddr unsigned char ucLEDs = 0xff;	// LED output value

void (*pShow[8]) (void) =
{
  vShow1, vShow2,		// Function-Pointer array
vShow3, vShow4, vShow5, vShow6, vShow7, vShow8, vShow9};

/* ============================================================================
**  Module name: vFlashLED
**
**  Description:
**               This module flashes all LEDs n times.
**
**  Operation:
**               -
** ============================================================================
*/
void
vFlashLED (unsigned char Number)
{
  while (Number > 0)
    {
      ucLEDs = 0x00;
      vWait50 (10);		// Delay of 500 ms
      ucLEDs = 0xff;
      vWait50 (10);		// Delay of 500 ms
      Number--;
    }
  return;
}

/* ============================================================================
**  Module name: vRestartT51
**
**  Description:
**               This module restarts Timer51
**
**  Operation:
**               -
** ============================================================================
*/
void
vRestartT2 (void)
{
  bTimer51Flag = 0;		// Reset Timer51 Flag
  TMC51 .7 = 0;			// Stop  Timer51
  TMC51 .7 = 1;			// Start Timer51
}


/* ============================================================================
**  Module name: vWait50
**
**  Description:
**               This module delays the program for n * 50 ms.
**
**  Operation:
**               -
** ============================================================================
*/
void
vWait50 (unsigned char Number)
{
#ifdef SIMULATOR		// shortens the delay time (/32)
  Number = Number >> 5;		// if using the Simulator
  if (Number == 0)
    Number++;
#endif
  vRestartT2 ();

  while (Number > 0)
    {
      while (bTimer51Flag == 0)
	{
	}
      bTimer51Flag = 0;		// Reset status flag Timer51
      Number--;
    }
  return;
}






/* ============================================================================
**  main function
** ============================================================================
*/

void
main (void)
{
  unsigned char i = 0;
  _DI ();			// Disable all interrupts
  vHardwareInit ();		// Peripheral settings
  vSoftwareInit ();		// Variable Initialization
  _EI ();			// Enable all interrupts
  TMC0 = 0x0C;			// Start Timer 0
  vFlashLED (2);		// Signal Program start
  while (TRUE)
    {
      if (bKey1Flag == 1)
	{			// Key1 pressed ?
	  bKey1Flag = 0;	// Reset status flag Key1
	  if (i < 7)
	    i++;
	  else
	    i = 0;
	}
      if (bKey2Flag == 1)
	{			// Key1 pressed ?
	  bKey2Flag = 0;	// Reset status flag Key1
	  if (i > 0)
	    i--;
	  else
	    i = 7;
	}
      pShow[i] ();		// call selected show
    }
}
