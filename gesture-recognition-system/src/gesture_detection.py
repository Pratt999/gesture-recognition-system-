import cv2
import mediapipe as mp
import time
from serial_handler import SerialHandler


# Initialize MediaPipe hand detector
mp_hands = mp.solutions.hands
mp_drawing = mp.solutions.drawing_utils

hands = mp_hands.Hands(
    static_image_mode=False,
    max_num_hands=1,
    min_detection_confidence=0.7,
    min_tracking_confidence=0.7
)

# Rule-based finger counter
def classify_gesture(hand_landmarks):
    tips = [4, 8, 12, 16, 20]
    finger_states = []

    # Thumb (different axis for comparison)
    if hand_landmarks.landmark[tips[0]].x < hand_landmarks.landmark[tips[0] - 1].x:
        finger_states.append(1)
    else:
        finger_states.append(0)

    # Other fingers
    for i in range(1, 5):
        if hand_landmarks.landmark[tips[i]].y < hand_landmarks.landmark[tips[i] - 2].y:
            finger_states.append(1)
        else:
            finger_states.append(0)

    gesture_number = sum(finger_states)
    return gesture_number, finger_states

# Webcam capture
cap = cv2.VideoCapture(0)
prev_time = 0

while cap.isOpened():
    success, frame = cap.read()
    if not success:
        break

    # Flip image for natural view
    frame = cv2.flip(frame, 1)
    rgb = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)

    result = hands.process(rgb)
    gesture = None

    if result.multi_hand_landmarks:
        for hand_landmarks in result.multi_hand_landmarks:
            mp_drawing.draw_landmarks(frame, hand_landmarks, mp_hands.HAND_CONNECTIONS)
            gesture, finger_states = classify_gesture(hand_landmarks)
            cv2.putText(frame, f"Gesture: {gesture}", (10, 40), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2)

    # FPS display
    curr_time = time.time()
    fps = 1 / (curr_time - prev_time)
    prev_time = curr_time
    cv2.putText(frame, f"FPS: {int(fps)}", (10, 80), cv2.FONT_HERSHEY_SIMPLEX, 0.8, (255, 0, 0), 2)

    cv2.imshow("Hand Gesture Detection", frame)
    if cv2.waitKey(1) & 0xFF == 27:
        break

cap.release()
cv2.destroyAllWindows()
