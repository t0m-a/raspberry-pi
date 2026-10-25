#!/usr/bin/env python3
""" turn off LCD cleanly

This script will search for process using the LCD Display,
(as per the nature of the I2C LCD display,
there should be only one script at a given time accessing the display)
then it will retreive its process identification number PID,
and terminate it nicely accordingly to its PID.
Finally it will clear the screen display and turn it off.
"""

import subprocess
import I2C_LCD_driver


# Defining variables for searched strings and string encoding
searched_process_name = 'display_'
cut_grep_out_of_results = 'grep'
result_string_encoding = 'utf-8'
mylcd = I2C_LCD_driver.lcd()
LCD_NOBACKLIGHT = 0x00
run = True

def kill_script():
    # Listing processes and getting the searched process
    ps_process = subprocess.Popen(["ps", "aux"], stdout=subprocess.PIPE, shell=False)
    grep_process = subprocess.Popen(["grep", "-i", searched_process_name], stdin=ps_process.stdout, stdout=subprocess.PIPE, shell=False)
    # The .stdout.close() lines below allow the previous process to receive a SIGPIPE if the next process exits.
    ps_process.stdout.close()
    # Cleaning the result until only the PID number is returned in a string
    grep_cutout = subprocess.Popen(["grep", "-v", cut_grep_out_of_results], stdin=grep_process.stdout, stdout=subprocess.PIPE, shell=False)
    grep_process.stdout.close()
    awk = subprocess.Popen(["cut", "-c", "10-14"], stdin=grep_cutout.stdout, stdout=subprocess.PIPE, shell=False)
    grep_cutout.stdout.close()
    output = awk.communicate()[0]
    clean_output = output.decode(result_string_encoding)
    clean_output_no_new_line = clean_output.rstrip()
    PID = clean_output_no_new_line
    # Terminating the LCD script process
    subprocess.Popen(["kill", "-9", PID])

while run:
    kill_script()
    # Cleaning and shutting off LCD screen
    mylcd.lcd_clear()
    mylcd.lcd_device.write_cmd(LCD_NOBACKLIGHT)
    break

