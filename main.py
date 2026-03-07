import serial

ser = serial.Serial('/dev/ttyACM0', 115200, timeout=5)
lastdata = ''
while True:
    resp = ser.readline(1).decode('utf-8')
    if not lastdata == resp:
        print(resp.replace('\n', ''), end='')
    lastdata = resp
