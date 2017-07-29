#__Coding:UTF-8__


import os
import time

#Install All apks from app
def installApps():
    filepath = raw_input('Please Input the FilePath or FileName:')
    #Get the files from the filepath
    files = os.listdir(filepath)
    for f in files:
	    print('adb install -r '+f)
	    text = os.popen('adb install -r app/'+f)
	    time.sleep(2)
	    print text.read()

#Delete APK by the packageName
def deleteApps():
	packageName = raw_input('Please input the packageName:')
	os.popen('adb uninstall '+packageName)


#Clear the Logcat
def clearLogCat():
	print('start clear logcat')
	os.popen('adb logcat -c')



while(True):
    print('1:install All apks')
    print('2:deleteAPP by packageName')
    print('3:clear all logcat\n')

    number =int(raw_input('Please input the Number:'))
    if number == 1:
	    print('Install APPS')
	    installApps()
    elif number == 2:
	    deleteApps()
    elif number == 3:
	    clearLogCat()