from flask import Flask, render_template
from flask_socketio import SocketIO
import time
import threading
import random  # Replace with actual gesture import
import json

# Flask app setup
app = Flask(__name__, static_folder="web_app", template_folder="web_app")
socketio = SocketIO(app, cors_allowed_origins="*")

# Simulated gesture data source (replace with real module later)
def generate_fake_gesture_data():
    while True:
        gesture_data = {
            "gesture": str(random.randint(0, 5)),
            "confidence": round(random.uniform(0.8, 1.0), 2),
            "timestamp": time.strftime('%Y-%m-%dT%H:%M:%SZ'),
            "hand_detected": True
        }
        socketio.emit("gesture_data", gesture_data)
        time.sleep(1)

@app.route('/')
def index():
    return app.send_static_file("index.html")

# Start gesture simulation in background thread
threading.Thread(target=generate_fake_gesture_data, daemon=True).start()

if __name__ == "__main__":
    print("[INFO] Flask WebSocket server running at http://localhost:5000")
    socketio.run(app, host="0.0.0.0", port=5000)
