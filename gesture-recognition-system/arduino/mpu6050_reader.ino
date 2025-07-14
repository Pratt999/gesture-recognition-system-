
#include <Wire.h>

// MPU6050 Registers
const int MPU_ADDR = 0x68;

int16_t ax, ay, az;
int16_t gx, gy, gz;

void setup() {
  Wire.begin();
  Serial.begin(9600);

  // Wake up MPU6050 (write 0 to power management register)
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x6B);  // PWR_MGMT_1
  Wire.write(0);
  Wire.endTransmission(true);

  Serial.println("📡 MPU6050 Initialized");
}

void loop() {
  // Request 14 bytes from MPU6050
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x3B);  // Starting register for Accel values
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_ADDR, 14, true);

  // Read Accelerometer values
  ax = Wire.read() << 8 | Wire.read();
  ay = Wire.read() << 8 | Wire.read();
  az = Wire.read() << 8 | Wire.read();

  // Skip temperature bytes
  Wire.read(); Wire.read();

  // Read Gyroscope values
  gx = Wire.read() << 8 | Wire.read();
  gy = Wire.read() << 8 | Wire.read();
  gz = Wire.read() << 8 | Wire.read();

  // Output to Serial
  Serial.print("Accel (X,Y,Z): ");
  Serial.print(ax); Serial.print(", ");
  Serial.print(ay); Serial.print(", ");
  Serial.print(az); Serial.print(" | ");

  Serial.print("Gyro (X,Y,Z): ");
  Serial.print(gx); Serial.print(", ");
  Serial.print(gy); Serial.print(", ");
  Serial.println(gz);

  delay(200);  // Adjust refresh rate as needed
}
