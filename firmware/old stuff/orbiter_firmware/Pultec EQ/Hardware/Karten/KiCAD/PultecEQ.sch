EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:PultecEQ-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L BC547 Q1
U 1 1 58E38F2A
P 4700 2100
F 0 "Q1" H 4900 2175 50  0000 L CNN
F 1 "BC547" H 4900 2100 50  0000 L CNN
F 2 "TO-92" H 4900 2025 50  0000 L CIN
F 3 "" H 4700 2100 50  0000 L CNN
	1    4700 2100
	1    0    0    -1  
$EndComp
$Comp
L R R1
U 1 1 58E39087
P 4800 1550
F 0 "R1" V 4880 1550 50  0000 C CNN
F 1 "1000 k" V 4700 1550 50  0000 C CNN
F 2 "" V 4730 1550 50  0000 C CNN
F 3 "" H 4800 1550 50  0000 C CNN
	1    4800 1550
	1    0    0    -1  
$EndComp
Wire Wire Line
	4800 1700 4800 1900
$Comp
L GND #PWR2
U 1 1 58E392BB
P 4800 2500
F 0 "#PWR2" H 4800 2250 50  0001 C CNN
F 1 "GND" H 4800 2350 50  0000 C CNN
F 2 "" H 4800 2500 50  0000 C CNN
F 3 "" H 4800 2500 50  0000 C CNN
	1    4800 2500
	1    0    0    -1  
$EndComp
Wire Wire Line
	4800 2300 4800 2500
$Comp
L +15V #PWR1
U 1 1 58E3939A
P 4800 1350
F 0 "#PWR1" H 4800 1200 50  0001 C CNN
F 1 "+15V" H 4800 1490 50  0000 C CNN
F 2 "" H 4800 1350 50  0000 C CNN
F 3 "" H 4800 1350 50  0000 C CNN
	1    4800 1350
	1    0    0    -1  
$EndComp
Wire Wire Line
	4800 1350 4800 1400
$EndSCHEMATC
