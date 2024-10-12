#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include "enemy.h"
#include "utils.h"

int main() {
  double start = GetTime();

  const int screenWidth = 800;
  const int screenHeight = 600;

  const int enemyWidth = 32;
  const int enemyHight = 16;

  //Init window
  InitWindow(screenWidth, screenHeight, "Space invaders");

  //Load Textures
  Texture2D s10pf1 = LoadRezisedImage("assets/10pf1.png",enemyWidth,enemyHight);
  Texture2D s10pf2 = LoadRezisedImage("assets/10pf2.png",enemyWidth,enemyHight);

  // Global enemy state
  GlobalEnemyState enemyState;
  enemyState.move_last_time = start;
  enemyState.move_time_s = 0.1;
  enemyState.enemyWidth = enemyWidth;
  enemyState.enemyHight = enemyHight;
  enemyState.goDown = false;
  enemyState.direction = 1;

  // Put 10p's frames into an array
  int lenght = 2;
  Texture2D* s10pTextures = (Texture2D*)calloc(lenght,sizeof(Texture2D));
  s10pTextures[0] = s10pf1;
  s10pTextures[1] = s10pf2;

  // Setup Enemy Struct
  Enemy e10p;
  e10p.Textures = s10pTextures;
  e10p.lenTextures = lenght;
  e10p.currentTexture = 0;
  e10p.posX = 200;
  e10p.posY = 200;

  // Put all enemies into an array
  Enemy* enemyArray = calloc(1,sizeof(e10p));
  enemyArray[0] = e10p;

  SetTargetFPS(60);
   
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(BLACK);
    UpdateEnemies(enemyArray,LEN(enemyArray),&enemyState);    
    EndDrawing();
  }
  free(s10pTextures);
  free(enemyArray);
  UnloadTexture(s10pf1);
  UnloadTexture(s10pf2);
  CloseWindow();
  return 0;
}