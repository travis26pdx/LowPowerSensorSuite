EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Low Power Sensor Suite Junction Board"
Date "2022-06-02"
Rev "1.1"
Comp "Team 13"
Comment1 "Weny Bi, Eyal Eynis, Travis Johnson, Wei Yan"
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L power:+3.3V #PWR0101
U 1 1 624806CC
P 3750 1100
F 0 "#PWR0101" H 3750 950 50  0001 C CNN
F 1 "+3.3V" H 3765 1273 50  0000 C CNN
F 2 "" H 3750 1100 50  0001 C CNN
F 3 "" H 3750 1100 50  0001 C CNN
	1    3750 1100
	1    0    0    -1  
$EndComp
Wire Wire Line
	3750 1100 3750 1250
Wire Wire Line
	3750 1250 3450 1250
Text Label 3750 1450 2    50   ~ 0
P6_1
Wire Wire Line
	3750 1450 3450 1450
Text Label 3750 1550 2    50   ~ 0
P6_0
Wire Wire Line
	3750 1550 3450 1550
Text Label 3750 2050 2    50   ~ 0
P7_1
Text Label 3750 2150 2    50   ~ 0
P7_0
Wire Wire Line
	3750 2150 3450 2150
Wire Wire Line
	3750 2050 3450 2050
Wire Wire Line
	3950 2150 3950 2250
Wire Wire Line
	3950 2250 3450 2250
$Comp
L power:+5V #PWR0102
U 1 1 624820A8
P 3950 2150
F 0 "#PWR0102" H 3950 2000 50  0001 C CNN
F 1 "+5V" H 3965 2323 50  0000 C CNN
F 2 "" H 3950 2150 50  0001 C CNN
F 3 "" H 3950 2150 50  0001 C CNN
	1    3950 2150
	1    0    0    -1  
$EndComp
Text Label 3750 4700 2    50   ~ 0
P4_3
Text Label 3750 4600 2    50   ~ 0
P2_5
Text Label 3750 4500 2    50   ~ 0
P2_6
$Comp
L Connector:Conn_01x32_Male J8
U 1 1 62482672
P 7750 2600
F 0 "J8" H 7858 4189 50  0000 C CNN
F 1 "Conn_01x32_Male" H 7858 4190 50  0001 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_2x16_Pitch2.54mm" H 7750 2600 50  0001 C CNN
F 3 "~" H 7750 2600 50  0001 C CNN
	1    7750 2600
	-1   0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0103
U 1 1 62488C2E
P 7100 1500
F 0 "#PWR0103" H 7100 1350 50  0001 C CNN
F 1 "+3.3V" H 7115 1673 50  0000 C CNN
F 2 "" H 7100 1500 50  0001 C CNN
F 3 "" H 7100 1500 50  0001 C CNN
	1    7100 1500
	-1   0    0    -1  
$EndComp
Text Label 7250 1300 0    50   ~ 0
P6_1
Text Label 7250 1500 0    50   ~ 0
P6_0
$Comp
L power:GND #PWR0104
U 1 1 62489537
P 3950 2500
F 0 "#PWR0104" H 3950 2250 50  0001 C CNN
F 1 "GND" H 3955 2327 50  0000 C CNN
F 2 "" H 3950 2500 50  0001 C CNN
F 3 "" H 3950 2500 50  0001 C CNN
	1    3950 2500
	1    0    0    -1  
$EndComp
Wire Wire Line
	3450 2350 3950 2350
Wire Wire Line
	3950 2350 3950 2500
$Comp
L power:GND #PWR0105
U 1 1 62489BEE
P 6850 1200
F 0 "#PWR0105" H 6850 950 50  0001 C CNN
F 1 "GND" H 6855 1027 50  0000 C CNN
F 2 "" H 6850 1200 50  0001 C CNN
F 3 "" H 6850 1200 50  0001 C CNN
	1    6850 1200
	-1   0    0    -1  
$EndComp
Wire Wire Line
	7550 1300 7250 1300
Wire Wire Line
	7550 1500 7250 1500
$Comp
L power:+3.3V #PWR0106
U 1 1 6248AA95
P 7050 3300
F 0 "#PWR0106" H 7050 3150 50  0001 C CNN
F 1 "+3.3V" H 7065 3473 50  0000 C CNN
F 2 "" H 7050 3300 50  0001 C CNN
F 3 "" H 7050 3300 50  0001 C CNN
	1    7050 3300
	-1   0    0    -1  
$EndComp
$Comp
L power:GND #PWR0107
U 1 1 6248AFF2
P 7150 3700
F 0 "#PWR0107" H 7150 3450 50  0001 C CNN
F 1 "GND" H 7155 3527 50  0000 C CNN
F 2 "" H 7150 3700 50  0001 C CNN
F 3 "" H 7150 3700 50  0001 C CNN
	1    7150 3700
	-1   0    0    -1  
$EndComp
Wire Wire Line
	7550 3400 7150 3400
Wire Wire Line
	7150 3400 7150 3700
Wire Wire Line
	7550 3500 7050 3500
Wire Wire Line
	7050 3500 7050 3300
Wire Wire Line
	3750 4500 3450 4500
Wire Wire Line
	3750 4600 3450 4600
$Comp
L Connector:Conn_01x06_Male J7
U 1 1 6248CFE0
P 8350 4750
F 0 "J7" H 8458 5131 50  0000 C CNN
F 1 "N2O Sensor" H 8458 5040 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_2x03_Pitch2.54mm" H 8350 4750 50  0001 C CNN
F 3 "~" H 8350 4750 50  0001 C CNN
	1    8350 4750
	-1   0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x03_Male J5
U 1 1 62480029
P 8650 5800
F 0 "J5" H 8758 5989 50  0000 C CNN
F 1 "Conn_01x03_Male" H 8758 5990 50  0001 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x03_Pitch2.54mm" H 8650 5800 50  0001 C CNN
F 3 "~" H 8650 5800 50  0001 C CNN
	1    8650 5800
	-1   0    0    -1  
$EndComp
Text Label 7100 5700 0    50   ~ 0
P4_3
$Comp
L power:GND #PWR0109
U 1 1 6248EB8F
P 7250 6000
F 0 "#PWR0109" H 7250 5750 50  0001 C CNN
F 1 "GND" H 7255 5827 50  0000 C CNN
F 2 "" H 7250 6000 50  0001 C CNN
F 3 "" H 7250 6000 50  0001 C CNN
	1    7250 6000
	1    0    0    -1  
$EndComp
Wire Wire Line
	7250 6000 7250 5900
$Comp
L power:+3.3V #PWR0110
U 1 1 6248F688
P 7000 4350
F 0 "#PWR0110" H 7000 4200 50  0001 C CNN
F 1 "+3.3V" H 7015 4523 50  0000 C CNN
F 2 "" H 7000 4350 50  0001 C CNN
F 3 "" H 7000 4350 50  0001 C CNN
	1    7000 4350
	1    0    0    -1  
$EndComp
Text Label 6450 4750 0    50   ~ 0
P2_6
Text Label 6450 4850 0    50   ~ 0
P2_5
$Comp
L LPSensorSuite:HIH8120-021-001 U6
U 1 1 6247D6D7
P 5250 3600
F 0 "U6" H 5250 4067 50  0000 C CNN
F 1 "HIH6120-021-001" H 5250 3976 50  0000 C CNN
F 2 "SensorSuiteBoard:HIH8120_breakout" H 5250 3600 50  0001 L BNN
F 3 "" H 5250 3600 50  0001 L BNN
F 4 "Honeywell" H 5250 3600 50  0001 L BNN "MANUFACTURER"
	1    5250 3600
	1    0    0    -1  
$EndComp
$Comp
L Device:R R1
U 1 1 6247E126
P 4250 3500
F 0 "R1" V 4135 3500 50  0000 C CNN
F 1 "R" V 4134 3500 50  0001 C CNN
F 2 "Resistors_THT:R_Box_L13.0mm_W4.0mm_P9.00mm" V 4180 3500 50  0001 C CNN
F 3 "~" H 4250 3500 50  0001 C CNN
	1    4250 3500
	0    1    1    0   
$EndComp
$Comp
L Device:R R2
U 1 1 6247E3BF
P 4250 3700
F 0 "R2" V 4135 3700 50  0000 C CNN
F 1 "R" V 4134 3700 50  0001 C CNN
F 2 "Resistors_THT:R_Box_L13.0mm_W4.0mm_P9.00mm" V 4180 3700 50  0001 C CNN
F 3 "~" H 4250 3700 50  0001 C CNN
	1    4250 3700
	0    1    1    0   
$EndComp
Text Label 4650 3500 2    50   ~ 0
P7_1
Text Label 4650 3700 2    50   ~ 0
P7_0
Wire Wire Line
	4750 3700 4400 3700
Wire Wire Line
	4400 3500 4750 3500
Wire Wire Line
	4100 3500 4000 3500
Wire Wire Line
	4000 3500 4000 3700
Wire Wire Line
	4000 3700 4100 3700
Wire Wire Line
	4000 3500 4000 3400
Connection ~ 4000 3500
$Comp
L power:+3.3V #PWR0111
U 1 1 62480C01
P 4000 3400
F 0 "#PWR0111" H 4000 3250 50  0001 C CNN
F 1 "+3.3V" H 4015 3573 50  0000 C CNN
F 2 "" H 4000 3400 50  0001 C CNN
F 3 "" H 4000 3400 50  0001 C CNN
	1    4000 3400
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0112
U 1 1 62480F94
P 6550 3450
F 0 "#PWR0112" H 6550 3300 50  0001 C CNN
F 1 "+3.3V" H 6565 3623 50  0000 C CNN
F 2 "" H 6550 3450 50  0001 C CNN
F 3 "" H 6550 3450 50  0001 C CNN
	1    6550 3450
	1    0    0    -1  
$EndComp
Wire Wire Line
	5850 3400 5750 3400
$Comp
L power:GND #PWR0113
U 1 1 62481F0C
P 6550 3900
F 0 "#PWR0113" H 6550 3650 50  0001 C CNN
F 1 "GND" H 6555 3727 50  0000 C CNN
F 2 "" H 6550 3900 50  0001 C CNN
F 3 "" H 6550 3900 50  0001 C CNN
	1    6550 3900
	1    0    0    -1  
$EndComp
Wire Wire Line
	5850 3800 5750 3800
Wire Wire Line
	7100 5700 7500 5700
$Comp
L Connector:Conn_01x03_Male J51
U 1 1 6248660F
P 7850 5800
F 0 "J51" H 7958 5989 50  0000 C CNN
F 1 "Conn_01x03_Male" H 7958 5990 50  0001 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x03_Pitch2.54mm" H 7850 5800 50  0001 C CNN
F 3 "~" H 7850 5800 50  0001 C CNN
	1    7850 5800
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x03_Male J50
U 1 1 62486F0E
P 7700 5800
F 0 "J50" H 7808 5989 50  0000 C CNN
F 1 "Conn_01x03_Male" H 7808 5990 50  0001 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x03_Pitch2.54mm" H 7700 5800 50  0001 C CNN
F 3 "~" H 7700 5800 50  0001 C CNN
	1    7700 5800
	-1   0    0    -1  
$EndComp
Wire Wire Line
	8050 5700 8450 5700
Wire Wire Line
	8450 5800 8050 5800
Wire Wire Line
	8050 5900 8450 5900
Wire Wire Line
	7500 5800 7000 5800
Wire Wire Line
	7000 5800 7000 5550
Wire Wire Line
	7250 5900 7500 5900
$Comp
L Connector:Conn_01x06_Male J71
U 1 1 62494097
P 7650 4750
F 0 "J71" H 7758 5131 50  0000 C CNN
F 1 "N2O Sensor" H 7758 5040 50  0001 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x06_Pitch2.54mm" H 7650 4750 50  0001 C CNN
F 3 "~" H 7650 4750 50  0001 C CNN
	1    7650 4750
	1    0    0    -1  
$EndComp
Wire Wire Line
	7850 4550 8150 4550
Wire Wire Line
	8150 4650 7850 4650
Wire Wire Line
	7850 4750 8150 4750
Wire Wire Line
	8150 4850 7850 4850
Wire Wire Line
	7850 4950 8150 4950
Wire Wire Line
	8150 5050 7850 5050
$Comp
L Connector:Conn_01x06_Male J70
U 1 1 6249A2E8
P 7400 4750
F 0 "J70" H 7508 5131 50  0000 C CNN
F 1 "N2O Sensor" H 7508 5040 50  0001 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x06_Pitch2.54mm" H 7400 4750 50  0001 C CNN
F 3 "~" H 7400 4750 50  0001 C CNN
	1    7400 4750
	-1   0    0    -1  
$EndComp
Wire Wire Line
	7000 4350 7000 4550
Wire Wire Line
	7000 4550 7200 4550
$Comp
L Device:R R3
U 1 1 624B3559
P 6900 4750
F 0 "R3" V 6785 4750 50  0000 C CNN
F 1 "R" V 6784 4750 50  0001 C CNN
F 2 "Resistors_THT:R_Box_L13.0mm_W4.0mm_P9.00mm" V 6830 4750 50  0001 C CNN
F 3 "~" H 6900 4750 50  0001 C CNN
	1    6900 4750
	0    1    1    0   
$EndComp
Wire Wire Line
	7050 4750 7200 4750
$Comp
L Device:R R4
U 1 1 624B3AC1
P 6900 4850
F 0 "R4" V 7000 4850 50  0000 C CNN
F 1 "R" V 6784 4850 50  0001 C CNN
F 2 "Resistors_THT:R_Box_L13.0mm_W4.0mm_P9.00mm" V 6830 4850 50  0001 C CNN
F 3 "~" H 6900 4850 50  0001 C CNN
	1    6900 4850
	0    1    1    0   
$EndComp
Wire Wire Line
	7050 4850 7200 4850
Wire Wire Line
	6750 4850 6450 4850
Wire Wire Line
	6750 4750 6450 4750
$Comp
L Connector:Conn_01x02_Male J60
U 1 1 624B6C97
P 6250 3500
F 0 "J60" H 6358 3589 50  0000 C CNN
F 1 "Conn_01x02_Male" H 6358 3590 50  0001 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02_Pitch2.54mm" H 6250 3500 50  0001 C CNN
F 3 "~" H 6250 3500 50  0001 C CNN
	1    6250 3500
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x02_Male J61
U 1 1 624B76F0
P 6150 3500
F 0 "J61" H 6300 3600 50  0000 R CNN
F 1 "Conn_01x02_Male" H 6258 3590 50  0001 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02_Pitch2.54mm" H 6150 3500 50  0001 C CNN
F 3 "~" H 6150 3500 50  0001 C CNN
	1    6150 3500
	-1   0    0    -1  
$EndComp
Wire Wire Line
	6550 3450 6550 3500
Wire Wire Line
	6550 3500 6450 3500
Wire Wire Line
	6550 3900 6550 3600
Wire Wire Line
	6550 3600 6450 3600
Wire Wire Line
	5950 3600 5850 3600
Wire Wire Line
	5850 3600 5850 3800
Wire Wire Line
	5950 3500 5850 3500
Wire Wire Line
	5850 3500 5850 3400
$Comp
L Connector:Conn_01x10_Male J1
U 1 1 624F9941
P 3250 1650
F 0 "J1" H 3358 2139 50  0000 C CNN
F 1 "Conn_01x10_Male" H 3358 2140 50  0001 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x10_Pitch2.54mm" H 3250 1650 50  0001 C CNN
F 3 "~" H 3250 1650 50  0001 C CNN
	1    3250 1650
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x10_Male J3
U 1 1 624FA1F6
P 3250 2650
F 0 "J3" H 3150 2850 50  0000 C CNN
F 1 "Conn_01x10_Male" H 3358 3140 50  0001 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x10_Pitch2.54mm" H 3250 2650 50  0001 C CNN
F 3 "~" H 3250 2650 50  0001 C CNN
	1    3250 2650
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x10_Male J2
U 1 1 624FB305
P 3250 4400
F 0 "J2" H 3358 4889 50  0000 C CNN
F 1 "Conn_01x10_Male" H 3358 4890 50  0001 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x10_Pitch2.54mm" H 3250 4400 50  0001 C CNN
F 3 "~" H 3250 4400 50  0001 C CNN
	1    3250 4400
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x10_Male J4
U 1 1 624FBB65
P 3250 5400
F 0 "J4" H 3150 5750 50  0000 C CNN
F 1 "Conn_01x10_Male" H 3358 5890 50  0001 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x10_Pitch2.54mm" H 3250 5400 50  0001 C CNN
F 3 "~" H 3250 5400 50  0001 C CNN
	1    3250 5400
	1    0    0    -1  
$EndComp
Wire Wire Line
	7550 1600 7100 1600
Wire Wire Line
	7100 1500 7100 1600
Wire Wire Line
	6850 1200 6850 1100
Wire Wire Line
	6850 1100 7550 1100
$Comp
L power:+3.3V #PWR0108
U 1 1 6250885C
P 7000 5550
F 0 "#PWR0108" H 7000 5400 50  0001 C CNN
F 1 "+3.3V" H 7015 5723 50  0000 C CNN
F 2 "" H 7000 5550 50  0001 C CNN
F 3 "" H 7000 5550 50  0001 C CNN
	1    7000 5550
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0115
U 1 1 62508BFE
P 4250 2150
F 0 "#PWR0115" H 4250 2000 50  0001 C CNN
F 1 "+5V" H 4265 2323 50  0000 C CNN
F 2 "" H 4250 2150 50  0001 C CNN
F 3 "" H 4250 2150 50  0001 C CNN
	1    4250 2150
	1    0    0    -1  
$EndComp
Wire Wire Line
	4250 2150 4250 2250
$Comp
L Connector:Conn_01x02_Male J9
U 1 1 625207BF
P 4550 2250
F 0 "J9" H 4522 2178 50  0000 R CNN
F 1 "Conn_01x02_Male" H 4522 2133 50  0001 R CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02_Pitch2.54mm" H 4550 2250 50  0001 C CNN
F 3 "~" H 4550 2250 50  0001 C CNN
	1    4550 2250
	-1   0    0    -1  
$EndComp
Wire Wire Line
	4350 2250 4250 2250
$Comp
L power:GND #PWR?
U 1 1 62523F44
P 4250 2450
F 0 "#PWR?" H 4250 2200 50  0001 C CNN
F 1 "GND" H 4255 2277 50  0000 C CNN
F 2 "" H 4250 2450 50  0001 C CNN
F 3 "" H 4250 2450 50  0001 C CNN
	1    4250 2450
	1    0    0    -1  
$EndComp
Wire Wire Line
	4350 2350 4250 2350
Wire Wire Line
	4250 2350 4250 2450
$Comp
L Device:R R5
U 1 1 62802DC7
P 4350 5000
F 0 "R5" V 4235 5000 50  0000 C CNN
F 1 "10K" V 4150 5000 50  0000 C CNN
F 2 "Resistors_THT:R_Box_L13.0mm_W4.0mm_P9.00mm" V 4280 5000 50  0001 C CNN
F 3 "~" H 4350 5000 50  0001 C CNN
	1    4350 5000
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 62803297
P 4350 5300
F 0 "#PWR?" H 4350 5050 50  0001 C CNN
F 1 "GND" H 4355 5127 50  0000 C CNN
F 2 "" H 4350 5300 50  0001 C CNN
F 3 "" H 4350 5300 50  0001 C CNN
	1    4350 5300
	1    0    0    -1  
$EndComp
Wire Wire Line
	4350 5150 4350 5250
Wire Wire Line
	4350 4850 4350 4700
Wire Wire Line
	4350 4700 4700 4700
$Comp
L Device:Q_NJFET_DGS Q1
U 1 1 6280A675
P 4900 4700
F 0 "Q1" H 5091 4746 50  0000 L CNN
F 1 "FQU20N06LTU" H 5091 4655 50  0000 L CNN
F 2 "" H 5100 4800 50  0001 C CNN
F 3 "~" H 4900 4700 50  0001 C CNN
	1    4900 4700
	1    0    0    -1  
$EndComp
Text Label 7000 4650 0    50   ~ 0
Q1_S
Text Label 5000 4400 0    50   ~ 0
Q1_D
Text Label 7900 4650 0    50   ~ 0
Q1_D
Wire Wire Line
	5000 4400 5000 4500
Text Label 5000 5150 0    50   ~ 0
Q1_S
Wire Wire Line
	5000 5250 4350 5250
Wire Wire Line
	5000 4900 5000 5250
Connection ~ 4350 5250
Wire Wire Line
	4350 5250 4350 5300
Wire Wire Line
	7000 4650 7200 4650
Wire Wire Line
	3450 4700 3750 4700
Text Label 4350 4700 2    50   ~ 0
P4_3
$EndSCHEMATC
