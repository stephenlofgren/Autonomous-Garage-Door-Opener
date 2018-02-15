#ifndef SETTINGS_H
#define SETTINGS_H

#include <EEPROM.h>
#include <Arduino.h>  // for type definitions

#define CONFIG_START 32

typedef struct {
  char key[32];
  char ssid[32];
  char password[32];
  char accessPointName[32];
  char mqttServer[32];
  char mqttPort[32];
  char mqttUid[32];
  char mqttPass[32];
  char pubTopic[32];
  char subTopic[32];
} Settings, *pSettings;

Settings createSettings(char key[32]
    , char ssid[32]
    , char password[32]
    , char accessPointName[32]
    , char mqttServer[32]
    , char mqttPort[32]
    , char mqttUid[32]
    , char mqttPass[32]
    , char pubTopic[32]
    , char subTopic[32]);

Settings loadSettings();

void storeSettings(Settings s);

Settings getSettings();

bool settingsSet();

#endif
