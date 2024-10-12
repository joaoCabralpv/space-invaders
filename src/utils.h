#pragma once
#include <raylib.h>

#define LEN(x)  (sizeof(x) / sizeof((x)[0]))

Texture2D LoadRezisedImage(const char* fileName, int width, int height);