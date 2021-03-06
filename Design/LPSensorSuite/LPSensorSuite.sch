EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Second Generation Low Power Sensor Suite"
Date "2022-06-02"
Rev "1.0"
Comp "Team 13"
Comment1 "Wenyu Bi, Eyal Eynis, Travis Johnson, Wei Yan"
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Device:Battery BT1
U 1 1 622AA96F
P 750 7100
F 0 "BT1" H 858 7146 50  0000 L CNN
F 1 "3.3V" H 858 7055 50  0000 L CNN
F 2 "" V 750 7160 50  0001 C CNN
F 3 "~" V 750 7160 50  0001 C CNN
	1    750  7100
	1    0    0    -1  
$EndComp
$Comp
L Connector:USB_A J5
U 1 1 622AD8D4
P 1500 7050
F 0 "J5" H 1557 7517 50  0000 C CNN
F 1 "USB_A" H 1557 7426 50  0001 C CNN
F 2 "Connectors_USB:USB_Micro-B_Wuerth-629105150521_CircularHoles" H 1650 7000 50  0001 C CNN
F 3 " ~" H 1650 7000 50  0001 C CNN
	1    1500 7050
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x10_Male J1
U 1 1 622B25BB
P 3550 1700
F 0 "J1" H 3650 2350 50  0000 C CNN
F 1 "Conn_01x10_Male" H 3450 2250 50  0000 C CNN
F 2 "" H 3550 1700 50  0001 C CNN
F 3 "~" H 3550 1700 50  0001 C CNN
	1    3550 1700
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x10_Male J4
U 1 1 622B472D
P 3500 5400
F 0 "J4" H 3608 5981 50  0000 C CNN
F 1 "Conn_01x10_Male" H 3608 5890 50  0000 C CNN
F 2 "" H 3500 5400 50  0001 C CNN
F 3 "~" H 3500 5400 50  0001 C CNN
	1    3500 5400
	1    0    0    -1  
$EndComp
$Comp
L Device:R R1
U 1 1 622BA2BF
P 6700 3600
F 0 "R1" V 6493 3600 50  0000 C CNN
F 1 "5k" V 6584 3600 50  0000 C CNN
F 2 "" V 6630 3600 50  0001 C CNN
F 3 "~" H 6700 3600 50  0001 C CNN
	1    6700 3600
	0    1    1    0   
$EndComp
$Comp
L Device:R R2
U 1 1 622BA536
P 6700 4050
F 0 "R2" V 6493 4050 50  0000 C CNN
F 1 "5k" V 6584 4050 50  0000 C CNN
F 2 "" V 6630 4050 50  0001 C CNN
F 3 "~" H 6700 4050 50  0001 C CNN
	1    6700 4050
	0    1    1    0   
$EndComp
Wire Wire Line
	750  6900 750  6450
Wire Wire Line
	750  6450 1900 6450
$Comp
L power:GND #PWR0101
U 1 1 622BDF6B
P 8250 4050
F 0 "#PWR0101" H 8250 3800 50  0001 C CNN
F 1 "GND" H 8255 3877 50  0000 C CNN
F 2 "" H 8250 4050 50  0001 C CNN
F 3 "" H 8250 4050 50  0001 C CNN
	1    8250 4050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0102
U 1 1 622BE4D2
P 8400 6000
F 0 "#PWR0102" H 8400 5750 50  0001 C CNN
F 1 "GND" H 8405 5827 50  0000 C CNN
F 2 "" H 8400 6000 50  0001 C CNN
F 3 "" H 8400 6000 50  0001 C CNN
	1    8400 6000
	1    0    0    -1  
$EndComp
Wire Wire Line
	1500 7600 1900 7600
Wire Wire Line
	750  7300 750  7600
Wire Wire Line
	750  7600 1500 7600
Connection ~ 1500 7600
Wire Wire Line
	6850 4050 6950 4050
Wire Wire Line
	6950 4050 6950 3800
Wire Wire Line
	6950 3800 7100 3800
$Comp
L power:+3.3V #PWR0103
U 1 1 622C0ABC
P 6400 3550
F 0 "#PWR0103" H 6400 3400 50  0001 C CNN
F 1 "+3.3V" H 6415 3723 50  0000 C CNN
F 2 "" H 6400 3550 50  0001 C CNN
F 3 "" H 6400 3550 50  0001 C CNN
	1    6400 3550
	1    0    0    -1  
$EndComp
Wire Wire Line
	6550 3600 6400 3600
Wire Wire Line
	6400 3600 6400 3550
Wire Wire Line
	6550 4050 6400 4050
Wire Wire Line
	8100 3900 8250 3900
Wire Wire Line
	8250 3900 8250 4050
$Comp
L power:+3.3V #PWR0104
U 1 1 622C462C
P 8250 3400
F 0 "#PWR0104" H 8250 3250 50  0001 C CNN
F 1 "+3.3V" H 8265 3573 50  0000 C CNN
F 2 "" H 8250 3400 50  0001 C CNN
F 3 "" H 8250 3400 50  0001 C CNN
	1    8250 3400
	1    0    0    -1  
$EndComp
Wire Wire Line
	8250 3400 8250 3500
Wire Wire Line
	8250 3500 8100 3500
$Comp
L Connector:Conn_01x32_Male P1
U 1 1 622CE5D7
P 10250 2550
F 0 "P1" H 10222 2524 50  0000 R CNN
F 1 "DC9018B-B" H 10222 2433 50  0000 R CNN
F 2 "" H 10250 2550 50  0001 C CNN
F 3 "~" H 10250 2550 50  0001 C CNN
	1    10250 2550
	-1   0    0    -1  
$EndComp
Text Label 8050 1250 0    50   ~ 0
P6_1
Text Label 8050 1450 0    50   ~ 0
P6_0
Wire Notes Line
	9900 900  9900 4300
Wire Notes Line
	9900 4300 10850 4300
Wire Notes Line
	10850 4300 10850 900 
Wire Notes Line
	10850 900  9900 900 
Text Notes 2450 650  0    50   ~ 0
TI MSP430FR5994 Launchpad Dev Board
Text Notes 2550 6650 0    50   ~ 0
Micro-USB - Fig. 31
Text Notes 3650 1000 2    50   ~ 0
BoosterPack Headers\nFig. 27
Text Notes 9850 850  0    50   ~ 0
SmartMesh IP DC9018B-B
Wire Notes Line
	2000 6350 2000 7700
Wire Notes Line
	550  7700 550  6350
Wire Notes Line
	550  6350 2000 6350
Text Notes 650  6300 0    50   ~ 0
3.3V Battery Pack
Text Notes 2450 750  0    50   ~ 0
URL: https://www.ti.com/lit/pdf/slau678
Text Notes 2250 6750 3    50   ~ 0
MICRO-USB CABLE
Text Notes 3350 1300 0    50   ~ 0
+3V3
Text Notes 3300 2600 0    50   ~ 0
+5V
Wire Notes Line
	2900 6500 3850 6500
Text Notes 2950 1600 0    50   ~ 0
P6.0_UTXD_J1.4
Text Notes 2950 1500 0    50   ~ 0
P6.1_URXD_J1.3
Text Notes 2850 2100 0    50   ~ 0
P7.1_I2CSCL_J1.9
Text Notes 2850 2200 0    50   ~ 0
P7.0_I2CSDA_J1.10
Text Notes 3200 5800 0    50   ~ 0
P4.3
Text Notes 3100 550  0    50   ~ 0
U2
Text Notes 10150 700  0    50   ~ 0
U3
Wire Notes Line
	2000 7700 550  7700
$Comp
L power:+3.3V #PWR0106
U 1 1 622C142C
P 4900 1100
F 0 "#PWR0106" H 4900 950 50  0001 C CNN
F 1 "+3.3V" H 4915 1273 50  0000 C CNN
F 2 "" H 4900 1100 50  0001 C CNN
F 3 "" H 4900 1100 50  0001 C CNN
	1    4900 1100
	1    0    0    -1  
$EndComp
Wire Wire Line
	3750 1300 4900 1300
$Comp
L power:+5V #PWR0107
U 1 1 623030E8
P 4900 2550
F 0 "#PWR0107" H 4900 2400 50  0001 C CNN
F 1 "+5V" H 4915 2723 50  0000 C CNN
F 2 "" H 4900 2550 50  0001 C CNN
F 3 "" H 4900 2550 50  0001 C CNN
	1    4900 2550
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0108
U 1 1 623F8E74
P 8300 1000
F 0 "#PWR0108" H 8300 850 50  0001 C CNN
F 1 "+3.3V" H 8315 1173 50  0000 C CNN
F 2 "" H 8300 1000 50  0001 C CNN
F 3 "" H 8300 1000 50  0001 C CNN
	1    8300 1000
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0109
U 1 1 623FF321
P 8300 1650
F 0 "#PWR0109" H 8300 1400 50  0001 C CNN
F 1 "GND" H 8305 1477 50  0000 C CNN
F 2 "" H 8300 1650 50  0001 C CNN
F 3 "" H 8300 1650 50  0001 C CNN
	1    8300 1650
	1    0    0    -1  
$EndComp
Text Label 4750 1500 0    50   ~ 0
P6_1
Text Label 4750 1600 0    50   ~ 0
P6_0
Wire Notes Line
	4600 750  8600 750 
Wire Notes Line
	8600 6450 4600 6450
$Comp
L Connector:Conn_01x03_Male J08
U 1 1 623ECAE2
P 7850 5700
F 0 "J08" H 7700 5750 50  0000 C CNN
F 1 "Conn_01x03_Male" H 7450 5650 50  0000 C CNN
F 2 "" H 7850 5700 50  0001 C CNN
F 3 "~" H 7850 5700 50  0001 C CNN
	1    7850 5700
	1    0    0    -1  
$EndComp
Wire Wire Line
	8050 5700 8400 5700
Wire Wire Line
	8050 5800 8400 5800
Wire Wire Line
	8400 5800 8400 6000
Connection ~ 8400 5800
Wire Wire Line
	8400 5800 9250 5800
Wire Wire Line
	8400 5700 8400 5450
Connection ~ 8400 5700
Wire Wire Line
	8400 5700 9250 5700
Text Notes 5900 700  0    50   ~ 0
U1 Sensor Suite Junction Board
Text Notes 10300 1050 0    50   ~ 0
TX_CTSn
Text Notes 10300 1250 0    50   ~ 0
TX
Text Notes 10300 1350 0    50   ~ 0
GND
Text Notes 10300 1450 0    50   ~ 0
RX_RTSn
Text Notes 10300 3350 0    50   ~ 0
GND
Text Notes 10300 3450 0    50   ~ 0
VBAT
Wire Wire Line
	3750 2100 5050 2100
$Comp
L power:GND #PWR0110
U 1 1 6246A5E1
P 8400 5000
F 0 "#PWR0110" H 8400 4750 50  0001 C CNN
F 1 "GND" H 8405 4827 50  0000 C CNN
F 2 "" H 8400 5000 50  0001 C CNN
F 3 "" H 8400 5000 50  0001 C CNN
	1    8400 5000
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0111
U 1 1 6246B149
P 8400 4500
F 0 "#PWR0111" H 8400 4350 50  0001 C CNN
F 1 "+3.3V" H 8415 4673 50  0000 C CNN
F 2 "" H 8400 4500 50  0001 C CNN
F 3 "" H 8400 4500 50  0001 C CNN
	1    8400 4500
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x10_Male J3
U 1 1 622B3FBA
P 3500 3000
F 0 "J3" H 3600 3650 50  0000 C CNN
F 1 "Conn_01x10_Male" H 3400 3550 50  0000 C CNN
F 2 "" H 3500 3000 50  0001 C CNN
F 3 "~" H 3500 3000 50  0001 C CNN
	1    3500 3000
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x10_Male J03
U 1 1 62489DC0
P 5250 3000
F 0 "J03" H 5350 3650 50  0000 C CNN
F 1 "Conn_01x10_Male" H 5150 3550 50  0001 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x10_Pitch2.54mm" H 5250 3000 50  0001 C CNN
F 3 "~" H 5250 3000 50  0001 C CNN
	1    5250 3000
	-1   0    0    -1  
$EndComp
Wire Wire Line
	4900 2550 4900 2600
Wire Wire Line
	4900 2600 5050 2600
Wire Wire Line
	3700 2600 4900 2600
$Comp
L Connector:Conn_01x10_Male J01
U 1 1 6249190E
P 5250 1700
F 0 "J01" H 5350 2350 50  0000 C CNN
F 1 "Conn_01x10_Male" H 5150 2250 50  0000 C CNN
F 2 "" H 5250 1700 50  0001 C CNN
F 3 "~" H 5250 1700 50  0001 C CNN
	1    5250 1700
	-1   0    0    -1  
$EndComp
Wire Wire Line
	4900 1100 4900 1300
Wire Wire Line
	4900 1300 5050 1300
Wire Wire Line
	3750 1500 5050 1500
Wire Wire Line
	3750 1600 5050 1600
Wire Wire Line
	3750 2200 5050 2200
Text Label 4750 2100 0    50   ~ 0
P7_1
Text Label 4750 2200 0    50   ~ 0
P7_0
Text Label 7050 3800 2    50   ~ 0
P7_0
Text Label 7050 3600 2    50   ~ 0
P7_1
Wire Wire Line
	6850 3600 7100 3600
Connection ~ 6400 3600
Wire Wire Line
	6400 3600 6400 4050
Wire Wire Line
	3700 5800 5050 5800
Wire Wire Line
	8050 5600 9250 5600
Text Label 8150 5600 0    50   ~ 0
P4_3
$Comp
L Connector:Conn_01x06_Male J05
U 1 1 624AB448
P 7700 1250
F 0 "J05" H 7808 1631 50  0000 C CNN
F 1 "Conn_01x06_Male" H 7808 1540 50  0000 C CNN
F 2 "" H 7700 1250 50  0001 C CNN
F 3 "~" H 7700 1250 50  0001 C CNN
	1    7700 1250
	1    0    0    -1  
$EndComp
Text Notes 7350 1050 0    50   ~ 0
TX_CTSn
Text Notes 7650 1250 2    50   ~ 0
TX
Text Notes 7650 1350 2    50   ~ 0
GND
Text Notes 7650 1450 2    50   ~ 0
RX_RTSn
Wire Wire Line
	7900 1050 8300 1050
Wire Wire Line
	8300 1000 8300 1050
Connection ~ 8300 1050
Wire Wire Line
	8300 1050 10050 1050
Wire Wire Line
	7900 1250 10050 1250
Wire Wire Line
	7900 1350 8300 1350
Wire Wire Line
	8300 1650 8300 1350
Connection ~ 8300 1350
Wire Wire Line
	8300 1350 10050 1350
Wire Wire Line
	7900 1450 10050 1450
$Comp
L Connector:Conn_01x04_Male J06
U 1 1 624C3BD2
P 7700 2550
F 0 "J06" H 7808 2831 50  0000 C CNN
F 1 "Conn_01x04_Male" H 7808 2740 50  0000 C CNN
F 2 "" H 7700 2550 50  0001 C CNN
F 3 "~" H 7700 2550 50  0001 C CNN
	1    7700 2550
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0112
U 1 1 624C4A03
P 8250 2850
F 0 "#PWR0112" H 8250 2600 50  0001 C CNN
F 1 "GND" H 8255 2677 50  0000 C CNN
F 2 "" H 8250 2850 50  0001 C CNN
F 3 "" H 8250 2850 50  0001 C CNN
	1    8250 2850
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0113
U 1 1 624C4F22
P 8250 2350
F 0 "#PWR0113" H 8250 2200 50  0001 C CNN
F 1 "+3.3V" H 8265 2523 50  0000 C CNN
F 2 "" H 8250 2350 50  0001 C CNN
F 3 "" H 8250 2350 50  0001 C CNN
	1    8250 2350
	1    0    0    -1  
$EndComp
Wire Wire Line
	7900 2550 8250 2550
Wire Wire Line
	9350 2550 9350 3350
Wire Wire Line
	9350 3350 10050 3350
Wire Wire Line
	7900 2650 8250 2650
Wire Wire Line
	9250 2650 9250 3450
Wire Wire Line
	9250 3450 10050 3450
Wire Wire Line
	8250 2850 8250 2650
Connection ~ 8250 2650
Wire Wire Line
	8250 2650 9250 2650
Wire Wire Line
	8250 2550 8250 2350
Connection ~ 8250 2550
Wire Wire Line
	8250 2550 9350 2550
Wire Wire Line
	7900 2450 9450 2450
Wire Wire Line
	9450 2450 9450 3250
Wire Wire Line
	9450 3250 10050 3250
Wire Wire Line
	7900 2750 9150 2750
Wire Wire Line
	9150 2750 9150 3550
Wire Wire Line
	9150 3550 10050 3550
Wire Wire Line
	7900 1150 10050 1150
Wire Wire Line
	7900 1550 10050 1550
Text Notes 2900 7250 0    50   ~ 0
GND
Text Notes 2900 6850 0    50   ~ 0
EZFET_VBUS
$Comp
L Connector:Conn_01x05_Male J102
U 1 1 622AEE40
P 2850 7050
F 0 "J102" H 3150 7400 50  0000 R CNN
F 1 "Conn_01x05_Male" H 2950 7400 50  0000 R CNN
F 2 "" H 2850 7050 50  0001 C CNN
F 3 "~" H 2850 7050 50  0001 C CNN
	1    2850 7050
	-1   0    0    -1  
$EndComp
Wire Wire Line
	3700 5700 5050 5700
Wire Wire Line
	3700 5600 5050 5600
Text Notes 3200 5700 0    50   ~ 0
P2.5
Text Notes 3200 5600 0    50   ~ 0
P2.6
Text Label 8050 4850 0    50   ~ 0
P2_5
Text Label 8050 4750 0    50   ~ 0
P2_6
$Comp
L Connector:Conn_01x05_Male J07
U 1 1 624E3AD1
P 7800 4750
F 0 "J07" H 7908 5131 50  0000 C CNN
F 1 "Conn_01x05_Male" H 7908 5040 50  0000 C CNN
F 2 "" H 7800 4750 50  0001 C CNN
F 3 "~" H 7800 4750 50  0001 C CNN
	1    7800 4750
	1    0    0    -1  
$EndComp
$Comp
L LPSensorSuite:HIH8120-021-001 U4
U 1 1 624E43FD
P 7600 3700
F 0 "U4" H 7600 4167 50  0000 C CNN
F 1 "HIH6120-021-001" H 7600 4076 50  0000 C CNN
F 2 "SIP191W41P127L490H390Q4" H 7600 3700 50  0001 L BNN
F 3 "" H 7600 3700 50  0001 L BNN
F 4 "Honeywell" H 7600 3700 50  0001 L BNN "MANUFACTURER"
	1    7600 3700
	1    0    0    -1  
$EndComp
$Comp
L LPSensorSuite:DS0002 U5
U 1 1 624E4B97
P 9400 4750
F 0 "U5" H 9400 5217 50  0000 C CNN
F 1 "DS0002" H 9400 5126 50  0000 C CNN
F 2 "DS0002" H 9800 4750 50  0001 L BNN
F 3 "" H 9400 4750 50  0001 L BNN
F 4 "Dynament" H 9400 4750 50  0001 L BNN "MANUFACTURER"
	1    9400 4750
	1    0    0    -1  
$EndComp
$Comp
L LPSensorSuite:SEN0219 U6
U 1 1 624F2E1A
P 9750 5700
F 0 "U6" H 10080 5746 50  0000 L CNN
F 1 "SEN0219" H 10080 5655 50  0000 L CNN
F 2 "SEN0219" H 9750 5700 50  0001 L BNN
F 3 "" H 9750 5700 50  0001 L BNN
F 4 "DFRobot" H 9750 5700 50  0001 L BNN "MANUFACTURER"
	1    9750 5700
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x10_Male J2
U 1 1 624F3868
P 3500 4250
F 0 "J2" H 3600 4900 50  0000 C CNN
F 1 "Conn_01x10_Male" H 3400 4800 50  0000 C CNN
F 2 "" H 3500 4250 50  0001 C CNN
F 3 "~" H 3500 4250 50  0001 C CNN
	1    3500 4250
	1    0    0    -1  
$EndComp
Wire Wire Line
	2650 7250 1900 7250
Wire Wire Line
	1900 7250 1900 7600
Wire Wire Line
	1800 6850 1900 6850
Wire Wire Line
	1900 6450 1900 6850
Connection ~ 1900 6850
Wire Wire Line
	1900 6850 2650 6850
Wire Wire Line
	1500 7450 1500 7600
Wire Notes Line
	3900 750  2350 750 
Wire Notes Line
	2400 7300 3500 7300
Wire Notes Line
	3500 7300 3500 6550
Wire Notes Line
	3500 6550 2400 6550
Wire Notes Line
	2400 6550 2400 7300
Wire Notes Line
	3900 7650 2350 7650
Wire Notes Line
	2350 750  2350 7650
Wire Notes Line
	3900 750  3900 7650
Connection ~ 4900 1300
Connection ~ 4900 2600
Text Label 4800 5600 0    50   ~ 0
P2_6
Text Label 4800 5700 0    50   ~ 0
P2_5
$Comp
L Connector:Conn_01x10_Male J04
U 1 1 624A71A9
P 5250 5400
F 0 "J04" H 5350 6000 50  0000 C CNN
F 1 "Conn_01x10_Male" H 5150 5900 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x10_Pitch2.54mm" H 5250 5400 50  0001 C CNN
F 3 "~" H 5250 5400 50  0001 C CNN
	1    5250 5400
	-1   0    0    -1  
$EndComp
Text Label 4800 5800 0    50   ~ 0
P4_3
$Comp
L Connector:Conn_01x10_Male J02
U 1 1 6253DCFE
P 5250 4250
F 0 "J02" H 5350 4900 50  0000 C CNN
F 1 "Conn_01x10_Male" H 5150 4800 50  0001 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x10_Pitch2.54mm" H 5250 4250 50  0001 C CNN
F 3 "~" H 5250 4250 50  0001 C CNN
	1    5250 4250
	-1   0    0    -1  
$EndComp
Wire Notes Line
	3850 1000 3850 6500
Wire Notes Line
	2900 1000 2900 6500
Wire Notes Line
	2900 1000 3850 1000
Wire Notes Line
	8600 750  8600 6450
Wire Notes Line
	4600 750  4600 6450
Wire Wire Line
	8000 4850 8900 4850
Wire Wire Line
	8000 4750 8900 4750
Wire Wire Line
	8000 4950 8900 4950
Wire Wire Line
	8000 4650 8400 4650
Wire Wire Line
	8400 5000 8400 4650
Connection ~ 8400 4650
Wire Wire Line
	8400 4650 8900 4650
Wire Wire Line
	8400 4500 8400 4550
Wire Wire Line
	8000 4550 8400 4550
Connection ~ 8400 4550
Wire Wire Line
	8400 4550 8900 4550
$Comp
L power:+3.3V #PWR?
U 1 1 62998CAD
P 8400 5450
F 0 "#PWR?" H 8400 5300 50  0001 C CNN
F 1 "+3.3V" H 8415 5623 50  0000 C CNN
F 2 "" H 8400 5450 50  0001 C CNN
F 3 "" H 8400 5450 50  0001 C CNN
	1    8400 5450
	1    0    0    -1  
$EndComp
$EndSCHEMATC
