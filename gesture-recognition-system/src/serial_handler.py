import serial
import time

class SerialHandler:
    def __init__(self, port='COM3', baudrate=9600, timeout=1):
        try:
            self.arduino = serial.Serial(port, baudrate=baudrate, timeout=timeout)
            time.sleep(2)  # Allow time for Arduino reset
            print(f"[Serial] Connected to {port} at {baudrate} baud.")
        except serial.SerialException as e:
            print(f"[Serial] Error: {e}")
            self.arduino = None

        self.last_gesture = None

    def send_gesture(self, gesture):
        if self.arduino is None:
            return

        # Avoid sending the same gesture repeatedly
        if gesture != self.last_gesture:
            command = f"G:{gesture}\n"
            self.arduino.write(command.encode())
            print(f"[Serial] Sent: {command.strip()}")
            self.last_gesture = gesture

    def close(self):
        if self.arduino and self.arduino.is_open:
            self.arduino.close()
            print("[Serial] Connection closed.")
