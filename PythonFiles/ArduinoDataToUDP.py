import serial
import socket
arduino = serial.Serial('COM4', 9600, timeout=.1)
UDP_IP = "127.0.0.1"
UDP_PORT = 5005
sock = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
while True:
	data = arduino.readline()[:-2] #the last bit gets rid of the new-line chars
	if data:
		print(data)
		sock.sendto(data,(UDP_IP,UDP_PORT))
