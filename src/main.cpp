#include <Arduino.h>
#include "headers/mqtt.h"
#include "headers/settings.h"
#include "headers/web.h"

void settingsChanged(Settings s){
  WiFi.mode(WIFI_OFF);
  mqttSetup();
}


void settingsSetup(){
  if(!settingsSet()){
    Serial.println("Settings Default");
    Settings settings = createSettings((char*)"default"
      , (char*)"*******"
      , (char*)"*******"
      , (char*)"GrgOpnrCnfg"
      , (char*)"192.168.2.17"
      , (char*)"1883"
      , (char*)"pi"
      , (char*)"raspberry"
      , (char*)"GarageButtonState"
      , (char*)"GarageDoorState");
      storeSettings(settings);
      delay(10000);
  }
  //setSettingsChangedHandler(*settingsChanged);
  //setWifiStateChangedHandler(*wifiConnectionChanged);
  //setMqttStateChangedHandler(*mqttConnectionChanged);
  //setMqttTopicStateChangedHandler(*mqttTopicStateChanged);
}


void setup() {
    // put your setup code here, to run once:
    WiFi.mode(WIFI_OFF);
    Serial.begin(115200);
    Serial.setDebugOutput(true);
    delay(5000);
    for(uint8_t t = 4; t > 0; t--) {
       Serial.printf("[SETUP] WAIT %d...\n", t);
       delay(1000);
    }

    settingsSetup();
    mqttSetup();
    webSetup();
}

void loop() {
    // put your main code here, to run repeatedly:
    mqttLoop();
}
