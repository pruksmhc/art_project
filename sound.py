import serial
import time
from playsound import playsound

# Replace with your actual serial port (e.g., '/dev/tty.usbmodemXXXX')
serial_port = '/dev/cu.usbmodem2101'
baud_rate = 9600  # Match this with your Arduino's baud rate
sound_file = '/Users/yadapruksachatkun/Downloads/mmm.mp3'
# Open the serial connection
ser = serial.Serial(serial_port, baud_rate)
time.sleep(2)  # Wait for the serial connection to initialize

print("Listening for obstacle detection...")

try:
    while True:
        # Read from the serial port
        if ser.in_waiting > 0:
            line = ser.readline().decode('utf-8').strip()
            print(line)
            if "detected!" in line:
                print("Obstacle detected, playing sound!")
                playsound(sound_file)
except KeyboardInterrupt:
    print("Program stopped by user.")
finally:
    ser.close()

