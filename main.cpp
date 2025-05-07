#include <Arduino.h>
#include "camera_handler.h"
#include "radar_handler.h"
#include "web_interface.h"
#include "oled_faces.h"

void setup() {
  Serial.begin(115200);
  initOLED();
  drawFace("😴");

  initCamera();
  initRadar();
  initWebServer();

  drawFace("😎"); // Ready
}

void loop() {
  updateRadar();
  delay(100);
}
