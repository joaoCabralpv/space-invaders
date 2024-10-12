#include "raylib.h"


int main() {
  const int screenWidth = 800;
  const int screenHeight = 600;
  InitWindow(screenWidth, screenHeight, "Space invaders");
  Texture2D s10pf1 = LoadTexture("assets/10pf1.png"); 
  SetTargetFPS(60);
  //while (IsTextureReady(s10pf1)); // Waits until the Texture is loaded
   
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    //DrawText("Space invaders", 20, 20, 20, BLACK);
    DrawTexture(s10pf1,screenWidth/2 - s10pf1.width/2, screenHeight/2 - s10pf1.height/2,WHITE);
    EndDrawing();
  }
  UnloadTexture(s10pf1);
  CloseWindow();
  return 0;
}