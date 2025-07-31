#ifndef DUCKGAME_H
#define DUCKGAME_H

#include "Game.h"
#include "Level.h"
#include "Entity.h"
#include "Config.h"

class DuckGame : public Game {
    public:
      void setup() override;
      void handleInput() override;
      void loop() override;
      void stop() override;

    private:
      static const int offshoreX = ((SCREEN_X * 2) - SCREEN_X + 1) + SCREEN_X;//this calculation is used to get a position off screen for a character
      static const int offshoreY = ((SCREEN_Y * 2) - SCREEN_Y + 1) + SCREEN_Y;//done via rand() % (max - min + 1) + min, where SCREEN_X is max, and SCREEN_X is min
      int lastX = 0; //stores the last position of the variable, useful for level generation
      int lives = NO_LIVES;
      bool damage = false;
      void controlPlayer();
      void moveObstacles();
      void renderLives();
      void startLevel();
      bool isColliding(Entity* a, Entity* b);
      void setPosition(Entity* entity, int x, int y);
      void placeObstacles();
      void placeObstacle(Entity* entity);
};

#endif