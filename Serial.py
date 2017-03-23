#AUTHOR GEORGE KOUKOUZAS
#DATE 23/3/2017

import socket
import serial
import time

TCP_IP = "127.0.0.1"
TCP_PORT = 1234
BUFFER_SIZE = 1024
device = '/dev/ttyACM0'

#Initializing socket
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
#Connecting socket
s.connect((TCP_IP,TCP_PORT))

# Establishing device connection
ser = serial.Serial(device, 9600)

#reading from IP
data = s.recv(BUFFER_SIZE)

while data != None:
    ser.flush()
    #Writing to arduino
    ser.write(data)

    time.sleep(2)
    data = s.recv(BUFFER_SIZE)

s.close()
