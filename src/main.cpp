#include <Arduino.h>
constexpr uint32_t BLINK_INTERVAL_MS = 500;

uint32_t lastToggleMs = 0;
bool ledOn = false;

void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.println("LED: OFF");
}

void loop() {
  const uint32_t now = millis();
  if (now - lastToggleMs >= BLINK_INTERVAL_MS) {
    lastToggleMs = now;
    ledOn = !ledOn;
    digitalWrite(LED_BUILTIN, ledOn ? LOW : HIGH);
    Serial.println(ledOn ? "LED: ON" : "LED: OFF");
  }
}