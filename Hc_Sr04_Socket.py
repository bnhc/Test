

#FileName:hc_sr04_test.py
#Auther:bnhc
#Content:Send the data(Get from the hc_sr04) to the Socket Client form ScokServer

import RPi.GPIO as GPIO
import time
import socket

#Get the Data
def checkdist():
    #set Pin 02 DC Power +5V
    GPIO.output(2,GPIO.HIGH)
    #Sleep /S
    time.sleep(0.000015)
    #set Pin 02 DC Power 0V
    GPIO.output(2,GPIO.LOW)
    #Not Receiver
    while not GPIO.input(3):
        pass
    #Time of Receiver
    t1 = time.time()
    while GPIO.input(3):
        pass
    #Time of UnReceiver
    t2 = time.time()
    return 1.0*(t2-t1)*343/2

#Begin
#Sensor Start
GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)
GPIO.setup(2,GPIO.OUT,initial=GPIO.LOW)
GPIO.setup(3,GPIO.IN)

#time.sleep(2)

#Open the Socket Server
host = ''
port = 9999
s = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.bind((host,port))
s.listen(4)
while True:
    conn,addr= s.accept()
    if conn:
        data = conn.recv(1024)
        print(data)
        break
#Get the Data from Sensor
time.sleep(1.5)
try:
    while True:
        m = checkdist()
        print("Distance %0.2f m"%m)    
        conn.sendall((str(round(m,4))+'\n').encode())
        print('Send Data OK')  
        time.sleep(0.8)
except KeyboardInterrupt:
    GPIO.cleanup()

    
        



