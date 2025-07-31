#include "utils.h"
#include "Entity.h"
#include "Config.h"
#include <Arduino.h>

bool isOnScreen(Entity* entity){
  int x = entity->position[0];
  int y = entity->position[1];

  return x < SCREEN_X && y < SCREEN_Y && x >= 0 && y >= 0;
}

void log(const char* message){
  Serial.print(message);
}