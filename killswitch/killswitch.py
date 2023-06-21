#!/usr/bin/env python3
import serial
import time
if __name__ == '__main__':
    ser = serial.Serial('dev/ttyACM0', 9600, timeout=1)
    print(f'Sent {bytes} bytes\n')
    if ser.in_waiting > 0:
        line = ser.readline().decode('utf-8').rstrip()
        print(f'I received: {line}\n')
    else: 
        print("No data received.")
    time.sleep(1)