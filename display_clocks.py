#!/usr/bin/env python3

import I2C_LCD_driver
import time
from datetime import datetime
import pytz
from pytz import timezone
import serial
import string


mylcd = I2C_LCD_driver.lcd()

ser = serial.Serial(
        port='/dev/ttyUSB0',
        baudrate = 9600,
        parity=serial.PARITY_NONE,
        stopbits=serial.STOPBITS_ONE,
        bytesize=serial.EIGHTBITS,
        timeout=1
)
ser.flushInput()

while True:

	sydney = timezone('Australia/Sydney')
	sydney_time = datetime.now(sydney)
	paris = timezone('Europe/Paris')
	paris_time = datetime.now(paris)

	y=ser.readline().decode().strip()
	temp = (y.strip().replace(","," ")).split(' ')[0]
	hum = (y.strip().replace(","," ")).split(' ')[0-1]
	Temperature = str(temp)
	Humidity = str(hum)

	mylcd.lcd_display_string("Local : %s" %time.strftime("%H:%M:%S"), 1)
	mylcd.lcd_display_string("Paris : %s" %paris_time.strftime("%H:%M:%S"), 2)
	mylcd.lcd_display_string("Sydney: %s" %sydney_time.strftime("%H:%M:%S"), 3)
	mylcd.lcd_display_string_2("Tc = " + Temperature, " H% = " + Humidity, 4)
