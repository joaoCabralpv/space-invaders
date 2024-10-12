#pragma once
#include <raylib.h>

#define LEN(x)  (sizeof(x) / sizeof((x)[0])) // Calculates lenght of an array

Texture2D LoadRezisedImage(const char* fileName, int width, int height);