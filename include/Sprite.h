#pragma once
#include <raylib.h>

class Sprite {
    Texture texture;
    Color tint;
    int sizex,sizey,posx,posy;
    public:
    Sprite();
    Sprite(const char* src,int posx,int posy,Color tint);
    Sprite(Texture2D texture,int posx,int posy,Color tint);
    Texture GetTexture();
    Color   GetTint();
    int     GetPosx();
    int     GetPosy();
};