import serial
import socket
from datetime import datetime
arduino = serial.Serial('COM4', 9600, timeout=.1)
file = open("testfile.txt", "a")
heart = 0
gsr = 0
ok1 = False
ok2 = False
while True:
	data = arduino.readline()[:-2] #the last bit gets rid of the new-line chars
	if data.decode("utf-8").endswith("heart"):
		heart = data.decode("utf-8")[:-5]
		print("Heart:"+ heart)
		ok1 = True
	if data.decode("utf-8").endswith("gsr"):
		gsr = data.decode("utf-8")[:-3]
		print("GSR:"+ gsr)
		ok2 = True
	if ok1 and ok2:
		ok1=ok2=0
		file = open("testfile.txt", "a")
		dt = datetime.now()
		file.write(str(dt)+" "+str(gsr)+" "+str(heart)+"\n")
		file.close()
