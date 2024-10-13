#include <raylib.h>
#include <stdlib.h>
#include <math.h>
#include"utils.h"
#include"enemy.h"

  // Setings
  const int enemyWidth = 48;
  const int enemyHight = 24;

  const int verticalEnemySpace = 10;
  const int horisontalEnemySpace = 10;

  const int bottomMargin = 100;
  const double enemyMoveTime = 0.1; //in seconds

  const int enemyColumNumber = 11;
  const int enemyRowNumber = 5;
  const int enemyClolumnSpaces = 16;

  const int topEnemyRowPos = 50;

  Texture2D* e10pTextureArray;



Texture2D LoadRezisedImage(const char* fileName, int width, int height) {
  Image img = LoadImage(fileName);
  ImageResize(&img,32,16); 
  return LoadTextureFromImage(img);
}

GlobalEnemyState InitGlobalEnemyState() {
  double start = GetTime();

  GlobalEnemyState enemyState;
  enemyState.move_last_time = start;
  enemyState.move_time_s = enemyMoveTime;
  enemyState.enemyWidth = enemyWidth;
  enemyState.enemyHight = enemyHight;
  enemyState.goDown = false;
  enemyState.direction = 1;
  enemyState.bottomMargin = bottomMargin;
  return enemyState;
}

Texture2D* CreateTexture2DArray(Texture2D Texture1, Texture2D Texture2) {
  int lenght = 2;
  Texture2D* Array = (Texture2D*)calloc(lenght,sizeof(Texture2D));
  Array[0] = Texture1;
  Array[1] = Texture2;
  return Array;
}

Enemy Create10p(int posX, int posY) {
  Enemy e10p;
  e10p.Textures = e10pTextureArray;
  e10p.lenTextures = 2;
  e10p.currentTexture = 0;
  e10p.posX = posX;
  e10p.posY = posY;
  return e10p;
}

Margin CalculateMargins() {
  double width = enemyClolumnSpaces*(enemyWidth+horisontalEnemySpace);
  double buffer = (width-GetScreenWidth())/2.0;
  Margin margin; 
  margin.leftMargin = ceil(buffer);
  margin.rightMargin = GetScreenWidth()-floor(buffer);
  return margin;
}

Enemy* CreateEnemyArray(GlobalEnemyState *state, int *out_lenght) {
  double totalEnemyMargin = (double)enemyClolumnSpaces-enemyColumNumber;

  int leftEnemyMargin = ceil(totalEnemyMargin/2.0);
  int rightEnemyMargin = floor(totalEnemyMargin/2.0);

  int leftEnemyX = (state->horisontalMargins.leftMargin)+(leftEnemyMargin*enemyWidth);

  int lenght = enemyRowNumber*enemyColumNumber;
  *out_lenght = lenght;
  Enemy* enemyArray = calloc(lenght,sizeof(Enemy));
  int index = 0;

  e10pTextureArray = CreateTexture2DArray(LoadRezisedImage("assets/10pf1.png",enemyWidth,enemyHight),LoadRezisedImage("assets/10pf2.png",enemyWidth,enemyHight));



  for (int enemyRow=0;enemyRow<=enemyRowNumber;enemyRow++) { // Loops trough all the enemy rows
    int posY = topEnemyRowPos+(enemyRow*(enemyHight+verticalEnemySpace));
    for (int enemyColumn=0;enemyColumn<=enemyColumNumber;enemyColumn++) {  // Loops trough all the enemy columns
      int posX = state->horisontalMargins.leftMargin+(enemyColumn*(enemyWidth+horisontalEnemySpace));
      enemyArray[index] = Create10p(posX,posY);
      index++;
    }
  }
}