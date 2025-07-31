#ifndef ENGINE_H
#define ENGINE_H

#include "Game.h"
#include "Renderer.h"


class Engine{
	private:
		Game* game;
		const Audio audio;
		const Input input;
		const Renderer renderer;
		
	public:
		Engine(Game* g);
		void setup();
		void loop();
		
};

#endif
