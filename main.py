import serial
import time
import winsound

# be sure to connect to HC-06 through bluetooth settings before running this.

print("Start...")
port = "COM8"  # sometimes COM7, sometimes COM8??
bluetooth = serial.Serial(port, 9600)
print("Connected!")
bluetooth.flushInput()

while True:
    input_data = bluetooth.readline()
    message = input_data.decode()
    print(message)
    if message.__contains__("detected"):
        print("Motion Detected at "+time.ctime(time.time()))
        beep_length = 3
        for x in range(10):
            winsound.Beep(1000, 3 * 1000)
            time.sleep(3 * 1000 * 2)

    time.sleep(0.1)
