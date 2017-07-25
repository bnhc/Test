#__Coding:UTF-8__

#FileName:hc_sr04_Serial.py
#Auther:bnhc
#Content:Send the data(Get from the hc_sr04) to the Serial

import RPi.GPIO as GPIO
import time
import serial

#Get the Distance Data
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

#Set Sensor
GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)
GPIO.setup(2,GPIO.OUT,initial=GPIO.LOW)
GPIO.setup(3,GPIO.IN)


#Set Serial
ser = serial.Serial('/dev/ttyS0',115200)
print('Serial is Open ?',ser.isOpen())
if(ser.isOpen()):
    print('Serial is Open True')
    time.sleep(1.5)
    try:
        while True:
            m = checkdist()
            print("Distance %0.1f m"%m)
            ser.write(str(round(m,3))+'m')
            ser.flushInput()
            time.sleep(0.8)
    except KeyboardInterrupt:
        GPIO.cleanup()
        if ser !=None:
            ser.close()
else:
    print('Serial Not Open')

    
        



