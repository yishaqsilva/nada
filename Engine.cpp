#include "Engine.h"
#include "Game.h"
#include "Renderer.h"
#include <Arduino.h>

Engine::Engine(Game* g) : game(g){
	game->audio = &audio; //give the game access to the engine's audio and input system
	game->input = &input;
	game->renderer = &renderer;
}

void Engine::setup(){
	Serial.begin(9600);
	audio.setup();
	input.setup();
	renderer.setup();
	game->isRunning = true;
	game->setup();
	renderer.renderText("NADA", 6, 0);
	renderer.renderText("ENGINE", 5, 1);
	delay(2000);
	//setup the renderer if need be
}

void Engine::loop(){
		game->handleInput();
		if (game->isRunning){
				game->loop(); //update the game
				game->tickCount++;
		}
}