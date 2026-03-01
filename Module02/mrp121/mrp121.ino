#include <Wire.h>
#include "Adafruit_MPR121.h"

Adafruit_MPR121 cap = Adafruit_MPR121();
uint16_t lastTouched = 0;

void setup() {
  Serial.begin(115200);
  delay(500);

  Wire.begin(D2, D1); // SDA, SCL

  if (!cap.begin(0x5A)) {
    Serial.println("MPR121 not found!");
    while (1) delay(10);
  }

  Serial.println("MPR121 Ready");
  Serial.println("Touch a pad to see output...");
}

void loop() {
  uint16_t touched = cap.touched();

  // Only print when the touch state changes
  if (touched != lastTouched) {
    Serial.print("Touched bits: 0x");
    Serial.println(touched, HEX);

    for (uint8_t i = 0; i < 12; i++) {
      bool now = touched & (1 << i);
      bool before = lastTouched & (1 << i);

      if (now && !before) {
        Serial.print("Electrode ");
        Serial.print(i);
        Serial.println(" touched");
      }
      if (!now && before) {
        Serial.print("Electrode ");
        Serial.print(i);
        Serial.println(" released");
      }
    }

    lastTouched = touched;
  }

  delay(50);
}