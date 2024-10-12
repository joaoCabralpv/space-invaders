#include<raylib.h>
#include"utils.h"

Texture2D LoadRezisedImage(const char* fileName, int width, int height) {
  Image img = LoadImage(fileName);
  ImageResize(&img,32,16); 
  return LoadTextureFromImage(img);
}