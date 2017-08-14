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
    

#Sensor  Like:XiaoMi It  will'not response  in 60S if it sensor by perple
def detct():
    print("Start Sensor")
    flag=False
    try:
        while True:
            if flag==True:
                print("Time in  60S")
                if time.time()-startTime>=60:
                    flag=False 
            else:
                if GPIO.input(12)==True:
                    print("Yes   "+time.asctime(time.localtime(time.time())))
                    flag = True
                    startTime = time.time()
                else:
                    print("No    "+time.asctime(time.localtime(time.time())))
            time.sleep(1.0)
    except KeyboardInterrupt:
        GPIO.cleanup()


init()
detct()
#Clear
GPIO.cleanup()
