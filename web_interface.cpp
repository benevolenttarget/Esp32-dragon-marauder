#include "web_interface.h"
#include "radar_handler.h"
#include <ESPAsyncWebServer.h>
#include <FS.h>
#include <SPIFFS.h>

AsyncWebServer server(80);

void initWebServer() {
  SPIFFS.begin(true);

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *req) {
    req->send(SPIFFS, "/index.html", "text/html");
  });

  server.on("/camera", HTTP_GET, [](AsyncWebServerRequest *req) {
    camera_fb_t *fb = esp_camera_fb_get();
    if (!fb) {
      req->send(500, "text/plain", "Camera error");
      return;
    }
    req->send_P(200, "image/jpeg", fb->buf, fb->len);
    esp_camera_fb_return(fb);
  });

  server.on("/status", HTTP_GET, [](AsyncWebServerRequest *req) {
    String json = "{\"targetLocked\":" + String(humanDetected ? "true" : "false") + "}";
    req->send(200, "application/json", json);
  });

  server.serveStatic("/", SPIFFS, "/");
  server.begin();
}
