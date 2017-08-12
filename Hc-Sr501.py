import RPi.GPIO as GPIO
import time


#init
def init():
    print("Init GPIO")
    GPIO.setmode(GPIO.BCM)
    GPIO.setwarnings(False)
    GPIO.setup(12,GPIO.IN)
    GPIO.setup(4,GPIO.OUT,initial=GPIO.HIGH)
    print("Give the Power...Initing....")
    

#Sensor
def detct():
    print("Start Sensor")
    try:
        while True:
            if GPIO.input(12)==True:
                print("Yes   "+time.asctime(time.localtime(time.time())))
                #Maybe Person or || other Thing
                             



            else:
                print("No    "+time.asctime(time.localtime(time.time())))
            time.sleep(1.0)
    except KeyboardInterrupt:
        GPIO.cleanup()


init()
detct()
#Clear
GPIO.cleanup()
