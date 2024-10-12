#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include "enemy.h"
#include "utils.h"

int main() {
  double start = GetTime();

  const int screenWidth = 800;
  const int screenHeight = 600;

  InitWindow(screenWidth, screenHeight, "Space invaders");

  /*Image is10pf1 = LoadImage("assets/10pf1.png");
  ImageResize(&is10pf1,32,16); 
  Texture2D s10pf1 = LoadTextureFromImage(is10pf1);

  Image is10pf2 = LoadImage("assets/10pf2.png"); 
  ImageResize(&is10pf2,32,16); 
  Texture2D s10pf2 = LoadTextureFromImage(is10pf2);*/

  Texture2D s10pf1 = LoadRezisedImage("assets/10pf1.png",32,16);
  Texture2D s10pf2 = LoadRezisedImage("assets/10pf2.png",32,16);

  // Global enemy state
  GlobalEnemyState enemyState;
  enemyState.move_last_time = start;
  enemyState.move_time_s = 1.0;
  int lenght = 2;
  Texture2D* s10pTextures = (Texture2D*)calloc(lenght,sizeof(Texture2D));

  s10pTextures[0] = s10pf1;
  s10pTextures[1] = s10pf2;

  Enemy e10p;
  e10p.Textures = s10pTextures;
  e10p.maxTexture = lenght;
  e10p.posX = 200;
  e10p.posY = 200;

  Enemy* enemyArray = calloc(1,sizeof(e10p));
  enemyArray[0] = e10p;

  SetTargetFPS(60);
   
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(BLACK);
    UpdateEnemies(enemyArray,LEN(enemyArray),&enemyState);    
    DrawEnemy(&enemyArray[0]);
    EndDrawing();
  }
  UnloadTexture(s10pf1);
  CloseWindow();
  return 0;
}