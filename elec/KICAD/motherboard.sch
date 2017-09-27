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
LIBS:teensy
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
L Teensy3.6 U1
U 1 1 59BEA7AD
P 4800 3350
F 0 "U1" H 4800 5650 60  0000 C CNN
F 1 "Teensy3.6" H 4800 1050 60  0000 C CNN
F 2 "" H 4800 3350 60  0000 C CNN
F 3 "" H 4800 3350 60  0000 C CNN
	1    4800 3350
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR3
U 1 1 59BEA825
P 3600 5100
F 0 "#PWR3" H 3600 4850 50  0001 C CNN
F 1 "GND" H 3600 4950 50  0000 C CNN
F 2 "" H 3600 5100 50  0001 C CNN
F 3 "" H 3600 5100 50  0001 C CNN
	1    3600 5100
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR2
U 1 1 59BEA857
P 3600 3900
F 0 "#PWR2" H 3600 3650 50  0001 C CNN
F 1 "GND" H 3600 3750 50  0000 C CNN
F 2 "" H 3600 3900 50  0001 C CNN
F 3 "" H 3600 3900 50  0001 C CNN
	1    3600 3900
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR1
U 1 1 59BEA88F
P 3600 1300
F 0 "#PWR1" H 3600 1050 50  0001 C CNN
F 1 "GND" H 3600 1150 50  0000 C CNN
F 2 "" H 3600 1300 50  0001 C CNN
F 3 "" H 3600 1300 50  0001 C CNN
	1    3600 1300
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR4
U 1 1 59BEA8CB
P 6000 2500
F 0 "#PWR4" H 6000 2250 50  0001 C CNN
F 1 "GND" H 6000 2350 50  0000 C CNN
F 2 "" H 6000 2500 50  0001 C CNN
F 3 "" H 6000 2500 50  0001 C CNN
	1    6000 2500
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR5
U 1 1 59BEA8F1
P 6050 3800
F 0 "#PWR5" H 6050 3550 50  0001 C CNN
F 1 "GND" H 6050 3650 50  0000 C CNN
F 2 "" H 6050 3800 50  0001 C CNN
F 3 "" H 6050 3800 50  0001 C CNN
	1    6050 3800
	1    0    0    -1  
$EndComp
Wire Wire Line
	5800 3750 6050 3750
Wire Wire Line
	6050 3650 6050 3800
Wire Wire Line
	5800 3650 6050 3650
Connection ~ 6050 3750
Wire Wire Line
	5800 2450 6000 2450
Wire Wire Line
	6000 2450 6000 2500
Wire Wire Line
	3800 5050 3600 5050
Wire Wire Line
	3600 5050 3600 5100
Wire Wire Line
	3800 3850 3600 3850
Wire Wire Line
	3600 3850 3600 3900
Wire Wire Line
	3800 1250 3600 1250
Wire Wire Line
	3600 1250 3600 1300
$EndSCHEMATC
