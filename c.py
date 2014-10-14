#!/Python33/python.exe
import serial
import cgi

print ("STATUS: 200 OK\n")
req = cgi.FieldStorage();

try:
  	ser = serial.Serial(req['p'].value, 9600, timeout=1)
except: 
  	print("error")
  	exit()

ser.write(bytes(req['c'].value,'latin'))
if int(req['r'].value) == 1:
	res = '';
	while not res:
		res = ser.readline()
	print(res.decode('UTF-8'))
else:
	print ("ok")
ser.close()