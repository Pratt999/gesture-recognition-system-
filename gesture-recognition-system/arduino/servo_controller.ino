#include <Servo.h>
#include "servo_library.h"  // Include the modular servo library

// Gesture-to-servo angle mappings [gesture][10 servos]
int gesture_positions[6][NUM_SERVOS] = {
  {90, 90, 90, 90, 90, 90, 90, 90, 90, 90},  // Gesture 0: Fist
  {45, 90, 90, 90, 90, 45, 90, 90, 90, 90},  // Gesture 1: Index
  {45, 45, 90, 90, 90, 45, 45, 90, 90, 90},  // Gesture 2: Peace
  {45, 45, 45, 90, 90, 45, 45, 45, 90, 90},  // Gesture 3: Three
  {45, 45, 45, 45, 90, 45, 45, 45, 45, 90},  // Gesture 4: Four
  {45, 45, 45, 45, 45, 45, 45, 45, 45, 45}   // Gesture 5: Open hand
};

// Servo pin mapping
int servoPins[NUM_SERVOS] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

// Instantiate the ServoController
ServoController sc(servoPins);

// Buffer for serial input
String input = "";
int currentGesture = -1;

void setup() {
  Serial.begin(9600);
  sc.attachAll();  // Attach all servos
  Serial.println("✅ Servo controller ready");
}

void loop() {
  while (Serial.available()) {
    char c = Serial.read();
    if (c == '\n') {
      processInput(input);
      input = "";
    } else {
      input += c;
    }
  }
}

// Parses and applies gesture from command
void processInput(String command) {
  if (command.startsWith("G:")) {
    int gesture = command.substring(2).toInt();
    if (gesture >= 0 && gesture <= 5 && gesture != currentGesture) {
      currentGesture = gesture;
      sc.moveToPositions(gesture_positions[gesture]);
      Serial.print("👉 Gesture applied: ");
      Serial.println(gesture);
    }
  }
}


