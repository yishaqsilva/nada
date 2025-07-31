#ifndef LEVEL_H
#define LEVEL_H
#include "Config.h"
#include "Entity.h"
//a level is simply a store of entities or gameobjects

typedef struct{
	Entity player;
	Entity obstacles[NO_ENTITY]; //a level will have a fixed amount of entities
}Level;


#endif
