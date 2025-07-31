#include "Audio.h"
#include "Config.h"
#include <Arduino.h>

void Audio::setup(){
  pinMode(AUDIO_PIN, OUTPUT);
}

void Audio::playSound(int seconds){
  digitalWrite(AUDIO_PIN, HIGH);
  delay(seconds * 1000); //convert to milliseconds
  digitalWrite(AUDIO_PIN, LOW);

}