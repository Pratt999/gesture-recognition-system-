#ifndef MPU_LIBRARY_H
#define MPU_LIBRARY_H

#include <Wire.h>

#define MPU_ADDR 0x68  // Default I2C address for MPU6050

class MPU6050 {
  public:
    int16_t ax, ay, az;
    int16_t gx, gy, gz;

    // Initialize I2C and wake up MPU6050
    void begin() {
      Wire.begin();
      Wire.beginTransmission(MPU_ADDR);
      Wire.write(0x6B);  // PWR_MGMT_1 register
      Wire.write(0);     // Wake up MPU6050
      Wire.endTransmission(true);
    }

    // Read raw acceleration and gyroscope values
    void readRawData() {
      Wire.beginTransmission(MPU_ADDR);
      Wire.write(0x3B);  // Starting register for Accel readings
      Wire.endTransmission(false);
      Wire.requestFrom(MPU_ADDR, 14, true);

      // Acceleration
      ax = Wire.read() << 8 | Wire.read();
      ay = Wire.read() << 8 | Wire.read();
      az = Wire.read() << 8 | Wire.read();

      Wire.read(); Wire.read();  // Skip temp

      // Gyroscope
      gx = Wire.read() << 8 | Wire.read();
      gy = Wire.read() << 8 | Wire.read();
      gz = Wire.read() << 8 | Wire.read();
    }

    // Debug print to Serial
    void printData() {
      Serial.print("Accel (X,Y,Z): ");
      Serial.print(ax); Serial.print(", ");
      Serial.print(ay); Serial.print(", ");
      Serial.print(az); Serial.print(" | ");

      Serial.print("Gyro (X,Y,Z): ");
      Serial.print(gx); Serial.print(", ");
      Serial.print(gy); Serial.print(", ");
      Serial.println(gz);
    }
};

#endif // MPU_LIBRARY_H
