#include "Renderer.h"
#include "Game.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h> //this is essentially our graphics api
#include "Level.h"
#include "Entity.h"
#include "Config.h"
#include "utils.h"

#if defined(ARDUINO) && ARDUINO >= 100
#define printByte(args)  write(args);
#else
#define printByte(args)  print(args,BYTE);
#endif

Renderer::Renderer() : lcd(0x27, 16, 2){}

void Renderer::setup(){
   lcd.init();
   if (BACKLIGHT == 1){
      lcd.backlight();
   }
   createPlayerChar();
}

void Renderer::renderLevel(Level level){
    lcd.clear(); //first clear the screen
  
    renderPlayer(&level.player); //render the player first
   
    Entity* obstacle = &level.obstacles[0]; //pointer to the fist variable of the array
    for (int i = 1; i < NO_ENTITY; ++i){ //next we render the other entities, which constitute the rest of the level
       renderEntity(obstacle, "|");
       obstacle++;
    }
}

//an alternative approach would of course be to have each gameobject own a render function, but for now i prefer it a simple store of values.
void Renderer::renderEntity(Entity* entity, const String character){
       //cull to view space, final expression checks whether. in this case view space is world space
      if (isOnScreen(entity)){
         lcd.setCursor(entity->position[0], entity->position[1]); //move the cursor to the position of the entity
         lcd.print(character); //finally display the entity on the screen;
     }
}

void Renderer::renderPlayer(Entity* player){
    renderEntity(player, "x");
}

void Renderer::createPlayerChar(){
   uint8_t duck[8]  = {0x0,0xc,0x1d,0xf,0xf,0x6,0x0};
   lcd.createChar(4, duck); //define the player duck character
}

void Renderer::clearScreen(){
   lcd.clear();
}

void Renderer::renderText(const String text, int x, int y){
   lcd.setCursor(x,y);
   lcd.print(text);
}
void Renderer::renderNumber(int number, int x, int y){
   lcd.setCursor(x,y);
   lcd.print(number);
}
