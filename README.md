# ✋ Gesture Recognition and Replication System (0–5)

A streamlined system that recognizes hand gestures (numbers 0–5) via webcam, displays results on a web interface, and simulates gesture replication on an Arduino-controlled artificial hand.

---

## 🚀 Features

- Real-time hand detection and classification using MediaPipe
- Simple rule-based gesture recognition (0–5)
- Live gesture display on a web interface with confidence and status
- Arduino-based control of 10 servo motors (2 per finger)
- Smooth, accurate gesture replication on an artificial hand

---

## 🗂️ Project Structure
gesture-recognition-system/
├── README.md # Project overview
├── requirements.txt # Python dependencies
├── src/
│ ├── gesture_detection.py # Webcam gesture detection using MediaPipe
│ ├── web_app/ # Web UI (HTML, CSS, JS)
│ ├── communication.py # Flask + WebSocket server
│ └── serial_handler.py # Python-serial communication with Arduino
├── arduino/
│ ├── servo_controller.ino # Arduino sketch to control 10 servos
│ ├── servo_library.h # Utility functions for servos
│ └── wiring_diagrams/ # Circuit diagrams for servo setup
├── data/ # (Optional) Sample frames, recordings
