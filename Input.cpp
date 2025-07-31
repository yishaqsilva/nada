#include "Input.h"
#include <Arduino.h>
#include "Config.h"

void Input::setup(){
    pinMode(INPUT_PIN, INPUT_PULLUP);
}

bool Input::consumeClick(){
    return digitalRead(INPUT_PIN) == 1;
}