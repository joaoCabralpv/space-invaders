#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include "enemy.h"
#include "utils.h"
#include "setup.h"

int main() {

  const int screenWidth = 800;
  const int screenHeight = 600;

  //Init window
  InitWindow(screenWidth, screenHeight, "Space invaders");

  //Load Textures

  // Global enemy state
  GlobalEnemyState enemyState = InitGlobalEnemyState();

  // Put 10p's frames into an array


  // Setup Enemy Struct


  // Put all enemies into an array
  int lenght;
  Enemy* enemyArray = CreateEnemyArray(&enemyState,&lenght);
  printf("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA",lenght);

  SetTargetFPS(60);
   
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(BLACK);
    printf("B\n");
    UpdateEnemies(enemyArray,lenght,&enemyState);    
    EndDrawing();
  }
  //free(s10pTextures);
  free(enemyArray);
  //UnloadTexture(s10pf1);
  //UnloadTexture(s10pf2);
  CloseWindow();
  return 0;
}