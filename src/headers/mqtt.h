#ifndef MQTT_H
#define MQTT_H

#include <ESP8266WiFi.h>
#include "headers/settings.h"
#include "headers/diagnostics.h"

void mqttSetup();
void mqttLoop();
#endif
