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

  Texture2D s10pf1 = LoadTexture("assets/10pf1.png"); 
  Texture2D s10pf2 = LoadTexture("assets/10pf2.png"); 
  
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
  Enemy* enemyArray = calloc(1,sizeof(e10p));
  enemyArray[0] = e10p;

  SetTargetFPS(60);
   
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    UpdateEnemies(enemyArray,LEN(enemyArray),&enemyState);    
    DrawTexture(enemyArray[0].Textures[enemyArray[0].currentTexture],screenWidth/2, screenHeight/2,WHITE);
    EndDrawing();
  }
  UnloadTexture(s10pf1);
  CloseWindow();
  return 0;
}