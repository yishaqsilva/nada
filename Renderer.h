#ifndef RENDERER_H
#define RENDERER_H
#include "Level.h"
#include "Entity.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h> //this is essentially our graphics api


class Renderer{
	private:
		LiquidCrystal_I2C lcd;
		void createPlayerChar();
		void renderEntity(Entity* entity, const String character); //rather than models, we simply have characters
		void renderPlayer(Entity* player);

	public:
		void setup();
		void clearScreen();
		void renderText(const String text, int x, int y);
		void renderNumber(int number, int x, int y);
		void renderLevel(Level level);
		Renderer();

};

#endif
