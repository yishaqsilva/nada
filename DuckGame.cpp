#include "DuckGame.h"
#include "Entity.h"
#include "Game.h"
#include <stdlib.h>
#include <Arduino.h>
#include "utils.h"
#include "Config.h"
#define TICKTIME 50
#define SPAWN_WIDTH 16

void DuckGame::setup(){
    player = &level.player;
    startLevel();
}

void DuckGame::handleInput(){
    controlPlayer();
}

void DuckGame::loop(){
    if (damage){
        renderLives();
    }else{
        moveObstacles();
        renderer->renderLevel(level); //render the updated scene
    }
}

void DuckGame::controlPlayer(){
        
    if(input->consumeClick()){   //update the player's position based on the input
        int y = player->position[1];
        if (y == 0){
            y = 1;
        }else{
            y = 0;
        }
        player->position[1] = y;
    }
}

void DuckGame::setPosition(Entity* entity, int x, int y){
      entity->position[0] = x;
      entity->position[1] = y;
}

void DuckGame::placeObstacles(){
    Entity* obstacle = &level.obstacles[0];
    srand(analogRead(0)); 

    for (int i = 0; i < NO_ENTITY; ++i){ //next we render the other entities, which constitute the rest of the level
       placeObstacle(obstacle);
       obstacle++;
    }
}

void DuckGame::placeObstacle(Entity* obstacle){
       int minX, maxX, finalX, finalY;
       minX = lastX + 2; //the next obstacle should at least be 2 faces forward
       maxX = minX + SPAWN_WIDTH; //can be placed within 10 spaces after this;
       
       finalX = rand() % (maxX - minX + 1) + minX;
       finalY = rand() % 2; //values can only be between 0 and 1;

       setPosition(obstacle, finalX, finalY);
       lastX = finalX % SPAWN_WIDTH; //limit
}

void DuckGame::moveObstacles(){

     Entity* obstacle = &level.obstacles[0];
     if (tickCount % TICKTIME == 0){ //move the entities to the left every 50 ticks
        for (int i = 0; i < NO_ENTITY; ++i){ //next we render the other entities, which constitute the rest of the level
            obstacle->position[0]--;
            if (!isOnScreen(obstacle)){
                placeObstacle(obstacle);
            }
            if (isColliding(obstacle, player)){
                damage = true;
            }
            //store the last position in case it is needed to offset
            obstacle++;
        }
     }
}

bool DuckGame::isColliding(Entity* a, Entity* b){
    return a->position[0] == b->position[0] && a->position[1] == b->position[1];
}

void DuckGame::renderLives(){
    renderer->clearScreen();
    lives--;
    if (lives > 0){
        renderer->renderNumber(lives + 1, 7, 0);
        delay(1000);
        renderer->renderNumber(lives, 7, 0);
        delay(1000);
        renderer->clearScreen();
        startLevel();
    }else{
        renderer->renderText("YOU", 7, 0);
        renderer->renderText("LOSE", 6, 1);
    }
}

void DuckGame::startLevel(){
       damage = false;
       setPosition(player, 0, 0);
       placeObstacles();
}

void DuckGame::stop(){

}