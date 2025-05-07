#include "radar_handler.h"
#include "oled_faces.h"

bool humanDetected = false;
const int radarPin = 32;

void initRadar() {
  pinMode(radarPin, INPUT);
}

void updateRadar() {
  bool reading = digitalRead(radarPin);
  if (reading) {
    if (!humanDetected) {
      humanDetected = true;
      drawFace("😱");
    }
  } else {
    if (humanDetected) {
      humanDetected = false;
      drawFace("😎");
    }
  }
}
