#ifndef GAME_H
#define GAME_H
#include "Level.h"
#include "Input.h"
#include "Audio.h"
#include "Renderer.h"

class Game {
	public:
			Level level;
			Entity* player;
			Input* input; //references to the engine's systems
			Audio* audio;
			Renderer* renderer;
			int tickCount = 0;
			bool isRunning = true;
	    virtual void setup() = 0;
			virtual void handleInput() = 0;
	    virtual void loop() = 0;
			virtual void stop() = 0;
};

#endif

