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


---

## 🧠 Gesture Mapping

| Gesture | Description         | Servo State (Example)         |
|---------|---------------------|-------------------------------|
| 0       | Fist                | All servos at 90°             |
| 1       | Index finger        | Thumb & index open            |
| 2       | Peace sign          | Thumb, index, middle open     |
| 3       | Three fingers       | Thumb + 3 fingers open        |
| 4       | Four fingers        | Only pinky closed             |
| 5       | Open hand           | All fingers extended          |

---

## 🛠️ Requirements

### Software

- Python 3.7+
- Arduino IDE
- Browser (Chrome/Firefox)

### Python Dependencies

Install using:

```bash
pip install -r requirements.txt
```

**###Libraries Used**  
opencv-python  
mediapipe  
flask, flask-socketio  
pyserial


**###Hardware**  
Webcam    
Arduino Uno/Nano  
10x SG90 Servo Motors  
External power supply (5V 2A+)
Jumper wires, breadboard/perfboard

**🧪 How to Run**  

1. Gesture Detection (Python)
bash
Copy
Edit
python src/gesture_detection.py

3. Web Interface
Start the Flask server:

bash
Copy
Edit
python src/communication.py
Then open:

arduino
Copy
Edit
http://localhost:5000/  

3. Arduino Servo Control
Upload servo_controller.ino to Arduino using the Arduino IDE.

Connect the servos as per wiring_diagrams/.

4. Real-Time Replication
serial_handler.py sends recognized gestures over serial to Arduino.

**🤝 Contributing**
Pull requests, ideas, and improvements are welcome!
Please open an issue for bug reports or feature requests.

**📜 License**
MIT License — use it freely, modify it safely.

**👨‍💻 Author**
Made with ❤️ by Surya Pratap
GitHub: @Pratt999

