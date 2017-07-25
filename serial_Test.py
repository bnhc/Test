import serial
import time

ser = serial.Serial('/dev/ttyS0',115200)

def main():
    while True:
        #count = ser.inWaiting()
        #if count !=0:
        print('Serial isOpen',ser.isOpen())
        print('Send Data Start')
        recv = "From Raspberry return\n\n"
        ser.write(recv)
        ser.flushInput()
        time.sleep(0.1)
        print('Send Data End')

if __name__=='__main__':
    try:
        main()
    except KeyboardInterrupt:
        if ser !=None:
            ser.close()
