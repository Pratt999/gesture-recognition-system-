#ifndef SERVO_LIBRARY_H
#define SERVO_LIBRARY_H

#include <Servo.h>

#define NUM_SERVOS 10
#define STEP_DELAY 20     // Delay between steps in milliseconds
#define MOVE_STEPS 30     // Number of interpolation steps for smooth motion

class ServoController {
  public:
    Servo servos[NUM_SERVOS];
    int pins[NUM_SERVOS];

    // Constructor to initialize servo pin array
    ServoController(int servoPins[NUM_SERVOS]) {
      for (int i = 0; i < NUM_SERVOS; i++) {
        pins[i] = servoPins[i];
      }
    }

    // Attach all servos and set to neutral (90°)
    void attachAll() {
      for (int i = 0; i < NUM_SERVOS; i++) {
        servos[i].attach(pins[i]);
        servos[i].write(90);
      }
    }

    // Move all servos smoothly to target positions
    void moveToPositions(int targetAngles[NUM_SERVOS]) {
      for (int s = 0; s <= MOVE_STEPS; s++) {
        for (int i = 0; i < NUM_SERVOS; i++) {
          int current = servos[i].read();
          int target = constrain(targetAngles[i], 0, 180);
          int stepVal = current + (target - current) * s / MOVE_STEPS;
          servos[i].write(stepVal);
        }
        delay(STEP_DELAY);
      }
    }
};

#endif  // SERVO_LIBRARY_H
