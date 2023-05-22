import serial

arduino = serial.Serial("COM7", 115200);
data_arduino = arduino.readline();
decode = str(data_arduino[0:len(data_arduino)].decode("utf-8"));
print(decode)
