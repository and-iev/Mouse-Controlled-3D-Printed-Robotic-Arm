#include <Servo.h>

Servo servoX;
Servo servoY;
Servo servoZ;

int posX = 90;
int posY = 90;
int posZ = 90;

const int gain = 1; // controls speed and reactiveness of arm

void setup() {
  Serial.begin(115200);
  servoX.attach(9);
  servoY.attach(10);
  servoZ.attach(11);
  servoX.write(posX);
  servoY.write(posY);
  servoZ.write(posZ);
  Serial.println("UNO init.");
}

void loop() {
  static char buffer[32];
  static byte index = 0;

  while (Serial.available()) {
    char c = Serial.read();

    if (c == '\n') {
      buffer[index] = '\0';
      index = 0;

      // Format: dx,dy,lmb,rmb
      char *token = strtok(buffer, ",");
      int dx = atoi(token);
      token = strtok(NULL, ",");
      int dy = atoi(token);
      token = strtok(NULL, ",");
      int lmb = atoi(token);
      token = strtok(NULL, ",");
      int rmb = atoi(token);

      if (lmb == 0 && rmb == 0) {
        // no buttons: control servo x
        posX = constrain(posX + dx * gain, 0, 180);
        servoX.write(posX);
        Serial.print("ServoX: ");
        Serial.println(posX);
      } 
      else if (lmb == 1) {
        // left button: control servo y
        posY = constrain(posY + dy * gain, 0, 180);
        servoY.write(posY);
        Serial.print("ServoY: ");
        Serial.println(posY);
      } 
      else if (rmb == 1) {
        // right button: control servo z
        posZ = constrain(posZ + dy * gain, 0, 180);
        servoZ.write(posZ);
        Serial.print("ServoZ: ");
        Serial.println(posZ);
      }

    } else if (index < sizeof(buffer) - 1) {
      buffer[index++] = c;
    }
  }
}
