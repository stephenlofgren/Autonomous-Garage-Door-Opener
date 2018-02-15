#include "headers/settings.h"
#include "headers/diagnostics.h"

bool eepromStarted = false;
Settings _loadedSettings;

void startEeprom(){
  EEPROM.begin(512);
  eepromStarted = true;
}

Settings createSettings(char key[32]
    , char ssid[32]
    , char password[32]
    , char accessPointName[32]
    , char mqttServer[32]
    , char mqttPort[32]
    , char mqttUid[32]
    , char mqttPass[32]
    , char pubTopic[32]
    , char subTopic[32]){
  Settings settings;
  strcpy(settings.key, key);
  strcpy(settings.ssid, ssid);
  strcpy(settings.password, password);
  strcpy(settings.accessPointName, accessPointName);
  strcpy(settings.mqttPort, mqttPort);
  strcpy(settings.mqttServer, mqttServer);
  strcpy(settings.mqttUid, mqttUid);
  strcpy(settings.mqttPass, mqttPass);
  strcpy(settings.pubTopic, pubTopic);
  strcpy(settings.subTopic, subTopic);
  return settings;
}

template <class T> int EEPROM_writeAnything(int ee, const T& value)
{
    if(!eepromStarted){
      startEeprom();
    }
    const byte* p = (const byte*)(const void*)&value;
    unsigned int i;
    for (i = 0; i < sizeof(value); i++)
          EEPROM.write(ee++, *p++);
    Serial.print("Eeprom wrote ");
    Serial.println(i);
    return i;
}

template <class T> int EEPROM_readAnything(int ee, T& value)
{
    if(!eepromStarted){
      startEeprom();
    }
    byte* p = (byte*)(void*)&value;
    unsigned int i;
    for (i = 0; i < sizeof(value); i++)
          *p++ = EEPROM.read(ee++);
    Serial.print("Eeprom read ");
    Serial.println(i);
    return i;
}

void storeSettings(Settings s){
  Serial.print("Stored Settings - ");
  printSettings(s);
  EEPROM_writeAnything(CONFIG_START, s);
  EEPROM.commit();
}

Settings getSettings(){
  Settings s;
  EEPROM_readAnything(CONFIG_START, s);
  //Serial.print("Read in Settings - ");
  //printSettings(s);
  _loadedSettings = s;
  return s;
}

bool settingsSet(){
  Settings s = getSettings();
  if(strcmp(s.key,"default")==0 || strcmp(s.key,"set")==0){
    Serial.printf("key set: %s\n", s.key);
    return true;
  }
  else{
    Serial.println("settings not yet set");
    return false;
  }
}
