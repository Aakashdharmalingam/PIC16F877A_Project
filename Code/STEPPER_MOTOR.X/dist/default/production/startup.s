
	; Microchip MPLAB XC8 C Compiler V2.50
	; Copyright (C) 2024 Microchip Technology Inc.

	; Auto-generated runtime startup code for final link stage.

	;
	; Compiler options:
	;
	; -q --opt=none --chip=16f877a \
	; -Mdist/default/production/STEPPER_MOTOR.X.production.map \
	; -DXPRJ_default=default -L--defsym=__MPLAB_BUILD=1 \
	; --dfp=C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC16Fxxx_DFP/1.6.156/xc8 \
	; --opt=+asmfile --addrqual=ignore -P --warn=-3 --asmlist --std=c99 \
	; --output=+elf:multilocs --stack=compiled:auto:auto --summary=+xml \
	; --summarydir=dist/default/production/memoryfile.xml \
	; -oSTEPPER_MOTOR.X.production.elf --objdir=dist/default/production \
	; --outdir=dist/default/production build/default/production/newmain.p1 \
	; -L--fixupoverflow=error --callgraph=none \
	; --errformat=%f:%l:%c: error: (%n) %s \
	; --warnformat=%f:%l:%c: warning: (%n) %s \
	; --msgformat=%f:%l:%c: advisory: (%n) %s
	;


	processor	16F877A

	global	_main,start,reset_vec
	fnroot	_main
	psect	code,class=CODE,delta=2
	psect	powerup,class=CODE,delta=2
	psect	reset_vec,class=CODE,delta=2
	psect	maintext,class=CODE,delta=2
	C	set	0
	Z	set	2
	PCL	set	2
	INDF	set	0

	STATUS	equ	3
	PCLATH	equ	0Ah

	psect	eeprom_data,class=EEDATA,delta=2,space=3,noexec
	psect	intentry,class=CODE,delta=2
	psect	sivt,class=CODE,delta=2
	psect	functab,class=ENTRY,delta=2
	global	intlevel0,intlevel1,intlevel2, intlevel3, intlevel4, intlevel5
intlevel0:
intlevel1:
intlevel2:
intlevel3:
intlevel4:
intlevel5:
	psect	init,class=CODE,delta=2
	psect	cinit,class=CODE,delta=2
	psect	text,class=CODE,delta=2
	psect	end_init,class=CODE,delta=2
	psect	clrtext,class=CODE,delta=2
	FSR	set	4
	psect	strings,class=CODE,delta=2,reloc=256

	global ___stacklo, ___stackhi
	___stacklo	equ	0
	___stackhi	equ	0


	psect	stack,class=STACK,space=2,noexec
	global ___stack_lo, ___stack_hi, ___int_stack_lo, ___int_stack_hi
	global ___sp,___int_sp
	___sp:
	___int_sp:
	___stack_lo:
	___stack_hi:
	___int_stack_lo:
	___int_stack_hi:
	psect	reset_vec
reset_vec:
	; No powerup routine
	; No interrupt routine(s)

; No heap to be allocated
	psect	heap,class=HEAP,space=7,noexec
	global ___heap_lo
	___heap_lo	equ	0
	global ___heap_hi
	___heap_hi	equ	0



	psect	init
start:
	psect	end_init
	global start_initialization
	ljmp start_initialization	;jump to C runtime clear & initialization

psect common,class=COMMON,space=1
psect bank0,class=BANK0,space=1
psect bank1,class=BANK1,space=1
psect bank2,class=BANK2,space=1
psect bank3,class=BANK3,space=1
psect ram,class=RAM,space=1
psect abs1,class=ABS1,space=1
psect sfr0,class=SFR0,space=1
psect sfr1,class=SFR1,space=1
psect sfr2,class=SFR2,space=1
psect sfr3,class=SFR3,space=1


	end	start
