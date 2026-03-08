import serial

ser = serial.Serial('/dev/ttyACM0', 115200, timeout=5)
while True:
    resp = ser.readline(1).decode('utf-8')
    print(resp, end='')
