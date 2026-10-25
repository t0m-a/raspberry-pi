#!/usr/bin/env python3

import I2C_LCD_driver
import socket
import fcntl
import struct
import time
import serial
import string
import re
from urllib.request import urlopen


mylcd = I2C_LCD_driver.lcd()

def get_wan(wanip3):
    wanip = urlopen("https://api.ipify.org").read()
    wanip2 = str(wanip)
    wanip3 = re.sub("['b'']", '', wanip2)
    return wanip3

def get_ip_address(ifname):
    s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    return socket.inet_ntoa(fcntl.ioctl(
        s.fileno(),
        0x8915,
	struct.pack('256s', ifname[:15].encode('utf-8'))
    )[20:24])
    s2 = str(s)

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
        y=ser.readline().decode().strip()
        temp = (y.strip().replace(","," ")).split(' ')[0]
        hum = (y.strip().replace(","," ")).split(' ')[0-1]
        Temperature = str(temp)
        Humidity = str(hum)
        mylcd.lcd_display_string(get_ip_address('wlan0'), 2)
        mylcd.lcd_display_string(get_wan('wanip3'), 3)
        mylcd.lcd_display_string("Time: %s" %time.strftime("%H:%M:%S"), 1)
        mylcd.lcd_display_string_2("Tc = " + Temperature, " H% = " + Humidity, 4)