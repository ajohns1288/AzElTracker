EESchema Schematic File Version 4
EELAYER 30 0
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
L MCU_Module:Arduino_Nano_v3.x A1
U 1 1 6249DD66
P 3150 3100
F 0 "A1" H 3150 2011 50  0000 C CNN
F 1 "Arduino_Nano_v3.x" H 3150 1920 50  0000 C CNN
F 2 "Module:Arduino_Nano" H 3150 3100 50  0001 C CIN
F 3 "http://www.mouser.com/pdfdocs/Gravitech_Arduino_Nano3_0.pdf" H 3150 3100 50  0001 C CNN
	1    3150 3100
	1    0    0    -1  
$EndComp
$Comp
L Driver_Motor:Pololu_Breakout_A4988 A2
U 1 1 6249ECB8
P 7250 1750
F 0 "A2" H 7300 2631 50  0000 C CNN
F 1 "Pololu_Breakout_A4988" H 7300 2540 50  0000 C CNN
F 2 "Module:Pololu_Breakout-16_15.2x20.3mm" H 7525 1000 50  0001 L CNN
F 3 "https://www.pololu.com/product/2980/pictures" H 7350 1450 50  0001 C CNN
	1    7250 1750
	1    0    0    -1  
$EndComp
$Comp
L Driver_Motor:Pololu_Breakout_A4988 A3
U 1 1 624A00A3
P 7250 4100
F 0 "A3" H 7300 4981 50  0000 C CNN
F 1 "Pololu_Breakout_A4988" H 7300 4890 50  0000 C CNN
F 2 "Module:Pololu_Breakout-16_15.2x20.3mm" H 7525 3350 50  0001 L CNN
F 3 "https://www.pololu.com/product/2980/pictures" H 7350 3800 50  0001 C CNN
	1    7250 4100
	1    0    0    -1  
$EndComp
$Comp
L power:+12V #PWR0101
U 1 1 624A13A4
P 2300 1150
F 0 "#PWR0101" H 2300 1000 50  0001 C CNN
F 1 "+12V" H 2315 1323 50  0000 C CNN
F 2 "" H 2300 1150 50  0001 C CNN
F 3 "" H 2300 1150 50  0001 C CNN
	1    2300 1150
	1    0    0    -1  
$EndComp
$Comp
L Connector:Screw_Terminal_01x02 J1
U 1 1 624A1FBA
P 2600 1150
F 0 "J1" H 2680 1142 50  0000 L CNN
F 1 "Screw_Terminal_01x02" H 2680 1051 50  0000 L CNN
F 2 "TerminalBlock:TerminalBlock_bornier-2_P5.08mm" H 2600 1150 50  0001 C CNN
F 3 "~" H 2600 1150 50  0001 C CNN
	1    2600 1150
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0102
U 1 1 624A2FD6
P 2300 1250
F 0 "#PWR0102" H 2300 1000 50  0001 C CNN
F 1 "GND" H 2305 1077 50  0000 C CNN
F 2 "" H 2300 1250 50  0001 C CNN
F 3 "" H 2300 1250 50  0001 C CNN
	1    2300 1250
	1    0    0    -1  
$EndComp
Wire Wire Line
	2400 1150 2300 1150
Wire Wire Line
	2400 1250 2300 1250
Wire Wire Line
	3150 4100 3250 4100
$Comp
L power:GND #PWR0103
U 1 1 624A4788
P 2600 4150
F 0 "#PWR0103" H 2600 3900 50  0001 C CNN
F 1 "GND" H 2605 3977 50  0000 C CNN
F 2 "" H 2600 4150 50  0001 C CNN
F 3 "" H 2600 4150 50  0001 C CNN
	1    2600 4150
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0104
U 1 1 624A53A8
P 7250 5050
F 0 "#PWR0104" H 7250 4800 50  0001 C CNN
F 1 "GND" H 7255 4877 50  0000 C CNN
F 2 "" H 7250 5050 50  0001 C CNN
F 3 "" H 7250 5050 50  0001 C CNN
	1    7250 5050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0105
U 1 1 624A595D
P 7350 2650
F 0 "#PWR0105" H 7350 2400 50  0001 C CNN
F 1 "GND" H 7355 2477 50  0000 C CNN
F 2 "" H 7350 2650 50  0001 C CNN
F 3 "" H 7350 2650 50  0001 C CNN
	1    7350 2650
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0106
U 1 1 624A5FF6
P 3350 2000
F 0 "#PWR0106" H 3350 1850 50  0001 C CNN
F 1 "+5V" H 3365 2173 50  0000 C CNN
F 2 "" H 3350 2000 50  0001 C CNN
F 3 "" H 3350 2000 50  0001 C CNN
	1    3350 2000
	1    0    0    -1  
$EndComp
$Comp
L power:+12V #PWR0107
U 1 1 624A693D
P 3050 2000
F 0 "#PWR0107" H 3050 1850 50  0001 C CNN
F 1 "+12V" H 3065 2173 50  0000 C CNN
F 2 "" H 3050 2000 50  0001 C CNN
F 3 "" H 3050 2000 50  0001 C CNN
	1    3050 2000
	1    0    0    -1  
$EndComp
Wire Wire Line
	3050 2100 3050 2000
Wire Wire Line
	3350 2100 3350 2000
Wire Wire Line
	7450 2550 7350 2550
Wire Wire Line
	7350 2650 7350 2550
Connection ~ 7350 2550
Wire Wire Line
	7350 2550 7250 2550
Wire Wire Line
	7250 5050 7250 4900
Wire Wire Line
	7250 4900 7450 4900
Connection ~ 7250 4900
$Comp
L power:+12V #PWR0108
U 1 1 624A7918
P 7450 850
F 0 "#PWR0108" H 7450 700 50  0001 C CNN
F 1 "+12V" H 7465 1023 50  0000 C CNN
F 2 "" H 7450 850 50  0001 C CNN
F 3 "" H 7450 850 50  0001 C CNN
	1    7450 850 
	1    0    0    -1  
$EndComp
$Comp
L power:+12V #PWR0109
U 1 1 624A814A
P 7450 3200
F 0 "#PWR0109" H 7450 3050 50  0001 C CNN
F 1 "+12V" H 7465 3373 50  0000 C CNN
F 2 "" H 7450 3200 50  0001 C CNN
F 3 "" H 7450 3200 50  0001 C CNN
	1    7450 3200
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0110
U 1 1 624A8896
P 7250 3200
F 0 "#PWR0110" H 7250 3050 50  0001 C CNN
F 1 "+5V" H 7265 3373 50  0000 C CNN
F 2 "" H 7250 3200 50  0001 C CNN
F 3 "" H 7250 3200 50  0001 C CNN
	1    7250 3200
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0111
U 1 1 624A9237
P 7250 850
F 0 "#PWR0111" H 7250 700 50  0001 C CNN
F 1 "+5V" H 7265 1023 50  0000 C CNN
F 2 "" H 7250 850 50  0001 C CNN
F 3 "" H 7250 850 50  0001 C CNN
	1    7250 850 
	1    0    0    -1  
$EndComp
Wire Wire Line
	7250 850  7250 1050
Wire Wire Line
	7450 850  7450 1050
Wire Wire Line
	7200 3200 7200 3400
Wire Wire Line
	7200 3400 7250 3400
Wire Wire Line
	7450 3200 7450 3400
Wire Wire Line
	7200 3200 7250 3200
$Comp
L Jumper:Jumper_2_Open JP2
U 1 1 624ABAF1
P 6550 3700
F 0 "JP2" H 6550 3935 50  0000 C CNN
F 1 "Jumper_2_Open" H 6550 3844 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 6550 3700 50  0001 C CNN
F 3 "~" H 6550 3700 50  0001 C CNN
	1    6550 3700
	1    0    0    -1  
$EndComp
$Comp
L Jumper:Jumper_2_Open JP1
U 1 1 624AC8AC
P 6500 1350
F 0 "JP1" H 6500 1585 50  0000 C CNN
F 1 "Jumper_2_Open" H 6500 1494 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 6500 1350 50  0001 C CNN
F 3 "~" H 6500 1350 50  0001 C CNN
	1    6500 1350
	1    0    0    -1  
$EndComp
Wire Wire Line
	6850 1350 6700 1350
Wire Wire Line
	6850 1450 6300 1450
Wire Wire Line
	6300 1450 6300 1350
Wire Wire Line
	6850 3700 6750 3700
Wire Wire Line
	6350 3700 6350 3800
Wire Wire Line
	6350 3800 6850 3800
$Comp
L Connector:Conn_01x04_Female J5
U 1 1 624AF077
P 3900 5150
F 0 "J5" V 3746 5298 50  0000 L CNN
F 1 "Conn_01x04_Female" V 3837 5298 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x04_P2.54mm_Horizontal" H 3900 5150 50  0001 C CNN
F 3 "~" H 3900 5150 50  0001 C CNN
	1    3900 5150
	0    1    1    0   
$EndComp
Wire Wire Line
	2600 4150 3150 4150
Wire Wire Line
	3150 4150 3150 4100
Connection ~ 3150 4100
$Comp
L power:+5V #PWR0112
U 1 1 624B76D5
P 2550 4800
F 0 "#PWR0112" H 2550 4650 50  0001 C CNN
F 1 "+5V" H 2565 4973 50  0000 C CNN
F 2 "" H 2550 4800 50  0001 C CNN
F 3 "" H 2550 4800 50  0001 C CNN
	1    2550 4800
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0113
U 1 1 624B9453
P 3800 4800
F 0 "#PWR0113" H 3800 4650 50  0001 C CNN
F 1 "+5V" H 3815 4973 50  0000 C CNN
F 2 "" H 3800 4800 50  0001 C CNN
F 3 "" H 3800 4800 50  0001 C CNN
	1    3800 4800
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0114
U 1 1 624B9CC0
P 2650 4800
F 0 "#PWR0114" H 2650 4550 50  0001 C CNN
F 1 "GND" H 2655 4627 50  0000 C CNN
F 2 "" H 2650 4800 50  0001 C CNN
F 3 "" H 2650 4800 50  0001 C CNN
	1    2650 4800
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR0115
U 1 1 624BA1CE
P 3900 4800
F 0 "#PWR0115" H 3900 4550 50  0001 C CNN
F 1 "GND" H 3905 4627 50  0000 C CNN
F 2 "" H 3900 4800 50  0001 C CNN
F 3 "" H 3900 4800 50  0001 C CNN
	1    3900 4800
	-1   0    0    1   
$EndComp
Wire Wire Line
	2550 4800 2550 4900
Wire Wire Line
	2650 4800 2650 4950
Wire Wire Line
	3800 4800 3800 4950
Wire Wire Line
	3900 4800 3900 4950
Text GLabel 2300 2500 0    50   Input ~ 0
UART_RX
Text GLabel 2300 2600 0    50   Input ~ 0
UART_TX
Text GLabel 3800 3500 2    50   Input ~ 0
I2C_SDA
Text GLabel 3800 3600 2    50   Input ~ 0
I2C_SCL
Wire Wire Line
	3800 3500 3650 3500
Wire Wire Line
	3800 3600 3650 3600
Text GLabel 4150 4500 2    50   Input ~ 0
I2C_SCL
Text GLabel 4150 4650 2    50   Input ~ 0
I2C_SDA
Wire Wire Line
	4150 4650 4000 4650
Wire Wire Line
	4000 4650 4000 4950
Wire Wire Line
	4150 4500 3700 4500
Wire Wire Line
	3700 4500 3700 4950
Text GLabel 3050 4600 2    50   Input ~ 0
UART_RX
Text GLabel 3050 4750 2    50   Input ~ 0
UART_TX
Wire Wire Line
	3050 4750 2850 4750
Wire Wire Line
	2850 4750 2850 4950
Wire Wire Line
	2750 4600 2750 4950
Wire Wire Line
	2750 4600 3050 4600
$Comp
L Connector:Conn_01x04_Female J3
U 1 1 624C735C
P 2750 5150
F 0 "J3" V 2596 5298 50  0000 L CNN
F 1 "Conn_01x04_Female" V 2687 5298 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x04_P2.54mm_Horizontal" H 2750 5150 50  0001 C CNN
F 3 "~" H 2750 5150 50  0001 C CNN
	1    2750 5150
	0    1    1    0   
$EndComp
$Comp
L Connector:Conn_01x04_Male J6
U 1 1 624C7FC9
P 8100 1850
F 0 "J6" H 8072 1732 50  0000 R CNN
F 1 "Conn_01x04_Male" H 8072 1823 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Horizontal" H 8100 1850 50  0001 C CNN
F 3 "~" H 8100 1850 50  0001 C CNN
	1    8100 1850
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x04_Male J7
U 1 1 624C8EA2
P 8150 4200
F 0 "J7" H 8122 4082 50  0000 R CNN
F 1 "Conn_01x04_Male" H 8122 4173 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Horizontal" H 8150 4200 50  0001 C CNN
F 3 "~" H 8150 4200 50  0001 C CNN
	1    8150 4200
	-1   0    0    1   
$EndComp
Wire Wire Line
	7900 1650 7750 1650
Wire Wire Line
	7900 1750 7750 1750
Wire Wire Line
	7900 1850 7750 1850
Wire Wire Line
	7900 1950 7750 1950
Wire Wire Line
	7950 4000 7750 4000
Wire Wire Line
	7950 4100 7750 4100
Wire Wire Line
	7950 4200 7750 4200
Wire Wire Line
	7950 4300 7750 4300
$Comp
L Device:CP1 C1
U 1 1 624CF7D7
P 7900 1200
F 0 "C1" H 8015 1246 50  0000 L CNN
F 1 "CP1" H 8015 1155 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D8.0mm_P3.80mm" H 7900 1200 50  0001 C CNN
F 3 "~" H 7900 1200 50  0001 C CNN
	1    7900 1200
	1    0    0    -1  
$EndComp
$Comp
L Device:CP1 C2
U 1 1 624D0FBF
P 7900 3600
F 0 "C2" H 8015 3646 50  0000 L CNN
F 1 "CP1" H 8015 3555 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D8.0mm_P3.80mm" H 7900 3600 50  0001 C CNN
F 3 "~" H 7900 3600 50  0001 C CNN
	1    7900 3600
	1    0    0    -1  
$EndComp
Wire Wire Line
	7450 3400 7900 3400
Wire Wire Line
	7900 3400 7900 3450
Connection ~ 7450 3400
Wire Wire Line
	7450 1050 7900 1050
Connection ~ 7450 1050
Wire Wire Line
	7900 3750 9000 3750
Wire Wire Line
	9000 3750 9000 4900
Wire Wire Line
	9000 4900 7450 4900
Connection ~ 7450 4900
Wire Wire Line
	7450 2550 9000 2550
Wire Wire Line
	9000 2550 9000 1400
Wire Wire Line
	9000 1400 7900 1400
Wire Wire Line
	7900 1400 7900 1350
Connection ~ 7450 2550
Text GLabel 2300 2700 0    50   Input ~ 0
EL_DIR
Text GLabel 2300 2800 0    50   Input ~ 0
EL_STEP
Text GLabel 2300 2900 0    50   Input ~ 0
AZ_DIR
Text GLabel 2300 3400 0    50   Input ~ 0
AZ_STEP
Text GLabel 3800 3100 2    50   Input ~ 0
EL_HOME_ANL
Wire Wire Line
	3800 3100 3650 3100
Text GLabel 2300 3200 0    50   Input ~ 0
EL_HOME_DIG
Text GLabel 6550 1850 0    50   Input ~ 0
AZ_DIR
Text GLabel 6550 1750 0    50   Input ~ 0
AZ_STEP
Text GLabel 6650 4200 0    50   Input ~ 0
EL_DIR
Text GLabel 6650 4100 0    50   Input ~ 0
EL_STEP
Wire Wire Line
	6850 4100 6650 4100
Wire Wire Line
	6650 4200 6850 4200
Wire Wire Line
	6550 1750 6850 1750
Wire Wire Line
	6850 1850 6550 1850
Text GLabel 2300 3100 0    50   Input ~ 0
NANO_D6
Text GLabel 2300 3000 0    50   Input ~ 0
NANO_D5
Text GLabel 2300 3800 0    50   Input ~ 0
SPI_SCK
Text GLabel 2300 3700 0    50   Input ~ 0
SPI_MISO
Text GLabel 2300 3600 0    50   Input ~ 0
SPI_MOSI
Text GLabel 2300 3500 0    50   Input ~ 0
SPI_SS
Text GLabel 2300 3300 0    50   Input ~ 0
AZ_HOME_DIG
Wire Wire Line
	2300 2500 2650 2500
Wire Wire Line
	2300 2600 2650 2600
Wire Wire Line
	2300 2700 2650 2700
Wire Wire Line
	2300 2800 2650 2800
Wire Wire Line
	2300 2900 2650 2900
Wire Wire Line
	2300 3000 2650 3000
Wire Wire Line
	2300 3100 2650 3100
Wire Wire Line
	2300 3200 2650 3200
Wire Wire Line
	2300 3300 2650 3300
Wire Wire Line
	2300 3400 2650 3400
Wire Wire Line
	2300 3500 2650 3500
Wire Wire Line
	2300 3600 2650 3600
Wire Wire Line
	2300 3700 2650 3700
Wire Wire Line
	2300 3800 2650 3800
Text GLabel 3800 3200 2    50   Input ~ 0
AZ_HOME_ANL
Text GLabel 3800 3300 2    50   Input ~ 0
NANO_A2
Text GLabel 3800 3400 2    50   Input ~ 0
NANO_A3
Text GLabel 3800 3800 2    50   Input ~ 0
NANO_A7
Text GLabel 3800 3700 2    50   Input ~ 0
NANO_A6
Wire Wire Line
	3800 3200 3650 3200
Wire Wire Line
	3650 3300 3800 3300
Wire Wire Line
	3800 3400 3650 3400
Wire Wire Line
	3800 3700 3650 3700
Wire Wire Line
	3650 3800 3800 3800
$Comp
L Connector:Conn_01x04_Male J2
U 1 1 62529545
P 2650 6000
F 0 "J2" V 2804 5712 50  0000 R CNN
F 1 "Conn_01x04_Male" V 2713 5712 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Horizontal" H 2650 6000 50  0001 C CNN
F 3 "~" H 2650 6000 50  0001 C CNN
	1    2650 6000
	0    -1   -1   0   
$EndComp
$Comp
L Connector:Conn_01x04_Male J4
U 1 1 6252AE83
P 3800 6000
F 0 "J4" V 3954 5712 50  0000 R CNN
F 1 "Conn_01x04_Male" V 3863 5712 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Horizontal" H 3800 6000 50  0001 C CNN
F 3 "~" H 3800 6000 50  0001 C CNN
	1    3800 6000
	0    -1   -1   0   
$EndComp
Text GLabel 2850 5650 2    50   Input ~ 0
AZ_HOME_ANL
Text GLabel 2850 5500 2    50   Input ~ 0
AZ_HOME_DIG
Text GLabel 4000 5650 2    50   Input ~ 0
EL_HOME_ANL
Text GLabel 4000 5500 2    50   Input ~ 0
EL_HOME_DIG
Wire Wire Line
	4000 5650 4000 5800
Wire Wire Line
	4000 5500 3900 5500
Wire Wire Line
	3900 5500 3900 5800
Wire Wire Line
	2850 5650 2850 5800
Wire Wire Line
	2850 5500 2750 5500
Wire Wire Line
	2750 5500 2750 5800
Wire Wire Line
	2550 4900 2400 4900
Wire Wire Line
	2400 4900 2400 5350
Wire Wire Line
	2400 5800 2550 5800
Connection ~ 2550 4900
Wire Wire Line
	2550 4900 2550 4950
Wire Wire Line
	2400 5350 3700 5350
Wire Wire Line
	3700 5350 3700 5800
Connection ~ 2400 5350
Wire Wire Line
	2400 5350 2400 5800
$Comp
L power:GND #PWR0116
U 1 1 6253DAAA
P 2650 5700
F 0 "#PWR0116" H 2650 5450 50  0001 C CNN
F 1 "GND" H 2655 5527 50  0000 C CNN
F 2 "" H 2650 5700 50  0001 C CNN
F 3 "" H 2650 5700 50  0001 C CNN
	1    2650 5700
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR0117
U 1 1 6253E56F
P 3800 5650
F 0 "#PWR0117" H 3800 5400 50  0001 C CNN
F 1 "GND" H 3805 5477 50  0000 C CNN
F 2 "" H 3800 5650 50  0001 C CNN
F 3 "" H 3800 5650 50  0001 C CNN
	1    3800 5650
	-1   0    0    1   
$EndComp
Wire Wire Line
	3800 5650 3800 5800
Wire Wire Line
	2650 5700 2650 5800
$EndSCHEMATC
