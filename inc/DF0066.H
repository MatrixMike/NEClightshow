/*------------------------------------------------------------
 *	         - uPD78F0066.h -
 *
 *	NEC 78K0 microcontroller device uPD78F0066.
 *
 *	Declarations of Special Function Registers (SFR) and
 *	interrupt vector addresses.
 *
 *	This header file may be used by both the NEC 78K0/K0S
 *	assembler, A78000 and compiler, ICC78000.
 *
 *	Df0066.H created from device file df0066.78k [V1.00]
 *	Include file generator E2.03a
 *------------------------------------------------------------*/

#ifndef __IO78f0066_INCLUDED
#define __IO78f0066_INCLUDED

#if ((__TID__ >> 8) & 0x7F) != 30
#error "Df0066.H file for use with A78000 / ICC78000 V3.xx only"
#endif

#if ((__TID__ >> 4) & 0x0F) != 1
#error "Df0066.H file for use with A78000 / ICC78000 option -v1 only"
#endif

/*************************************************
 *      SFR macros
 *************************************************/

#define	__IO_NB	0x00010000	/* No bit access */
#define	__IO_WO	0x00020000	/* Write-only    */
#define	__IO_RO	0x00040000	/* Read-only     */

/*************************************************
 *      SFR declarations
 *************************************************/

sfr	P0 	= 0xFF00; 
sfr	P2 	= 0xFF02; 
sfr	P3 	= 0xFF03; 
sfr	P4 	= 0xFF04; 
sfr	P5 	= 0xFF05; 
sfr	P6 	= 0xFF06; 
sfr	P7 	= 0xFF07; 
sfr	P8 	= 0xFF08; 
sfr	P9 	= 0xFF09; 
sfrp	CR00 	= 0xFF0A | __IO_NB; 
sfrp	CR01 	= 0xFF0C | __IO_NB; 
sfrp	TM0 	= 0xFF0E | __IO_NB | __IO_RO; 
sfr	CR50 	= 0xFF10 | __IO_NB; 
sfr	CR51 	= 0xFF11 | __IO_NB; 
sfrp	TM5 	= 0xFF12 | __IO_NB | __IO_RO; 
sfr	TM50 	= 0xFF12 | __IO_NB | __IO_RO; 
sfr	TM51 	= 0xFF13 | __IO_NB | __IO_RO; 
sfr	ADCR0 	= 0xFF15 | __IO_NB | __IO_RO; 
sfr	SIO1 	= 0xFF17 | __IO_NB; 
sfr	SIO30 	= 0xFF18 | __IO_NB; 
sfr	SIO31 	= 0xFF19 | __IO_NB; 
sfr	RXB0 	= 0xFF1A | __IO_NB | __IO_RO; 
sfr	TXS0 	= 0xFF1A | __IO_NB | __IO_WO; 
sfr	PM0 	= 0xFF20; 
sfr	PM2 	= 0xFF22; 
sfr	PM3 	= 0xFF23; 
sfr	PM4 	= 0xFF24; 
sfr	PM5 	= 0xFF25; 
sfr	PM6 	= 0xFF26; 
sfr	PM7 	= 0xFF27; 
sfr	PM8 	= 0xFF28; 
sfr	PM9 	= 0xFF29; 
sfr	PU0 	= 0xFF30; 
sfr	PU2 	= 0xFF32; 
sfr	PU3 	= 0xFF33; 
sfr	PU4 	= 0xFF34; 
sfr	PU5 	= 0xFF35; 
sfr	PU6 	= 0xFF36; 
sfr	PU7 	= 0xFF37; 
sfr	PU8 	= 0xFF38; 
sfr	PU9 	= 0xFF39; 
sfr	CKS 	= 0xFF40; 
sfr	WTM 	= 0xFF41; 
sfr	WDCS 	= 0xFF42 | __IO_NB; 
sfr	MEM 	= 0xFF47; 
sfr	EGP 	= 0xFF48; 
sfr	EGN 	= 0xFF49; 
sfr	TMC0 	= 0xFF60; 
sfr	PRM0 	= 0xFF61 | __IO_NB; 
sfr	CRC0 	= 0xFF62; 
sfr	TOC0 	= 0xFF63; 
sfr	CSIM1 	= 0xFF68; 
sfr	ADTC0 	= 0xFF69; 
sfr	ADTP0 	= 0xFF6A | __IO_NB; 
sfr	ADTI0 	= 0xFF6B; 
sfr	TMC50 	= 0xFF70; 
sfr	TCL50 	= 0xFF71 | __IO_NB; 
sfr	TMC51 	= 0xFF74; 
sfr	TCL51 	= 0xFF75 | __IO_NB; 
sfr	ADM0 	= 0xFF80; 
sfr	ADS0 	= 0xFF81 | __IO_NB; 
sfr	ASIM0 	= 0xFFA0; 
sfr	ASIS0 	= 0xFFA1 | __IO_NB | __IO_RO; 
sfr	BRGC0 	= 0xFFA2 | __IO_NB; 
sfr	CSIM30 	= 0xFFB0; 
sfr	CSIM31 	= 0xFFB1; 
sfrp	IF0 	= 0xFFE0 | __IO_NB; 
sfr	IF0L 	= 0xFFE0; 
sfr	IF0H 	= 0xFFE1; 
sfr	IF1L 	= 0xFFE2; 
sfrp	MK0 	= 0xFFE4 | __IO_NB; 
sfr	MK0L 	= 0xFFE4; 
sfr	MK0H 	= 0xFFE5; 
sfr	MK1L 	= 0xFFE6; 
sfrp	PR0 	= 0xFFE8 | __IO_NB; 
sfr	PR0L 	= 0xFFE8; 
sfr	PR0H 	= 0xFFE9; 
sfr	PR1L 	= 0xFFEA; 
sfr	IMS 	= 0xFFF0 | __IO_NB; 
sfr	CLKM 	= 0xFFF2 | __IO_NB | __IO_WO; 
sfr	IXS 	= 0xFFF4; 
sfr	MM 	= 0xFFF8; 
sfr	WDTM 	= 0xFFF9; 
sfr	OSTS 	= 0xFFFA | __IO_NB; 
sfr	PCC 	= 0xFFFB; 

/*************************************************
 *      SFR bit definitions
 *************************************************/

#define CLOE	 CKS.4
#define BZOE	 CKS.7
#define WTM0	 WTM.0
#define WTM1	 WTM.1
#define OVF0	 TMC0.0
#define TMC02	 TMC0.2
#define TMC03	 TMC0.3
#define TOE0	 TOC0.0
#define LVR0	 TOC0.2
#define LVS0	 TOC0.3
#define OSPE	 TOC0.5
#define OSPT	 TOC0.6
#define SCL100	 CSIM1.0
#define SCL101	 CSIM1.1
#define OSLINT	 CSIM1.2
#define SLEN	 CSIM1.3
#define LCSK10	 CSIM1.4
#define ATE0	 CSIM1.5
#define DIR10	 CSIM1.6
#define CSIE10	 CSIM1.7
#define BUSY00	 ADTC0.0
#define BUSY10	 ADTC0.1
#define STRB0	 ADTC0.2
#define TRF0	 ADTC0.3
#define ERR0	 ADTC0.4
#define ERCE0E	 ADTC0.5
#define ARLD0	 ADTC0.6
#define RE0	 ADTC0.7
#define ADTI07	 ADTI0.7
#define TOE50	 TMC50.0
#define LVR50	 TMC50.2
#define LVS50	 TMC50.3
#define TCE50	 TMC50.7
#define TOE51	 TMC51.0
#define LVR51	 TMC51.2
#define LVS51	 TMC51.3
#define TCE51	 TMC51.7
#define ADCS0	 ADM0.7
#define RXE0	 ASIM0.6
#define TXE0	 ASIM0.7
#define CSIE30	 CSIM30.7
#define CSIE31	 CSIM31.7
#define WDTIF	 IF0L.0
#define PIF0	 IF0L.1
#define PIF1	 IF0L.2
#define PIF2	 IF0L.3
#define PIF3	 IF0L.4
#define SERIF0	 IF0L.5
#define SRIF0	 IF0L.6
#define STIF0	 IF0L.7
#define CSIIF30	 IF0H.0
#define CSIIF31	 IF0H.1
#define CSIIF1	 IF0H.2
#define TMIF00	 IF0H.3
#define TMIF01	 IF0H.4
#define TMIF50	 IF0H.5
#define TMIF51	 IF0H.6
#define WTIIF	 IF0H.7
#define WTIF	 IF1L.0
#define ADIF0	 IF1L.1
#define WDTMK	 MK0L.0
#define PMK0	 MK0L.1
#define PMK1	 MK0L.2
#define PMK2	 MK0L.3
#define PMK3	 MK0L.4
#define SERMK0	 MK0L.5
#define SRMK0	 MK0L.6
#define STMK0	 MK0L.7
#define CSIMK30	 MK0H.0
#define CSIMK31	 MK0H.1
#define CSIMK1	 MK0H.2
#define TMMK00	 MK0H.3
#define TMMK01	 MK0H.4
#define TMMK50	 MK0H.5
#define TMMK51	 MK0H.6
#define WTIMK	 MK0H.7
#define WTMK	 MK1L.0
#define ADMK0	 MK1L.1
#define WDTPR	 PR0L.0
#define PPR0	 PR0L.1
#define PPR1	 PR0L.2
#define PPR2	 PR0L.3
#define PPR3	 PR0L.4
#define SERPR0	 PR0L.5
#define SRPR0	 PR0L.6
#define STPR0	 PR0L.7
#define CSIPR30	 PR0H.0
#define CSIPR31	 PR0H.1
#define CSIPR1	 PR0H.2
#define TMPR00	 PR0H.3
#define TMPR01	 PR0H.4
#define TMPR50	 PR0H.5
#define TMPR51	 PR0H.6
#define WTIPR	 PR0H.7
#define WTPR0	 PR1L.0
#define ADPR0	 PR1L.1
#define RUN	 WDTM.7
#define CSS	 PCC.4
#define CLS	 PCC.5
#define FRC	 PCC.6
#define MCC	 PCC.7

/*************************************************
 *      Interrupt vector definitions
 *************************************************/

#define	RESET_vect	(0x0000)
#define	INTWDT_vect	(0x0004)
#define	INTWDT_vect	(0x0004)
#define	INTP0_vect	(0x0006)
#define	INTP1_vect	(0x0008)
#define	INTP2_vect	(0x000A)
#define	INTP3_vect	(0x000C)
#define	INTSER0_vect	(0x000E)
#define	INTSR0_vect	(0x0010)
#define	INTST0_vect	(0x0012)
#define	INTCSI30_vect	(0x0014)
#define	INTCSI31_vect	(0x0016)
#define	INTSCI1_vect	(0x0018)
#define	INTTM00_vect	(0x001A)
#define	INTTM01_vect	(0x001C)
#define	INTTM50_vect	(0x001E)
#define	INTTM51_vect	(0x0020)
#define	INTWTI_vect	(0x0022)
#define	INTWT_vect	(0x0024)
#define	INTAD0_vect	(0x0026)
#define	BRK_vect	(0x003E)

#endif /* __IO78f0066_INCLUDED */
