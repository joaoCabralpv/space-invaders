#pragma once
#include <raylib.h>
#include "utils.h"
#include "enemy.h"

Texture2D LoadRezisedImage(const char* fileName, int width, int height);

GlobalEnemyState InitGlobalEnemyState();

Texture2D* CreateTexture2DArray(Texture2D Texture1, Texture2D Texture2);

Enemy Create10p(int posX, int posY);

Margin CalculateMargins();

Enemy* CreateEnemyArray();