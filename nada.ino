//nada is a tiny game engine i made so i wont get bored of arduino
#include "DuckGame.h"
#include "Engine.h"

DuckGame duckGame; //we get an instance of our game
Engine nada(&duckGame); //load our game into the engine

void setup() {
    nada.setup(); //we setup  pinMode(12, INPUT);
}

void loop() {
     nada.loop();//now we run the game
}
