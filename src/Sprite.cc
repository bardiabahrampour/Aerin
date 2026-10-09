#include "Sprite.h"

Sprite::Sprite() {

}

Sprite::Sprite(const char* src,int posx=0,int posy=0,Color tint=WHITE) {
    Image tmp_img   = LoadImage(src);
    this->texture   = LoadTextureFromImage(tmp_img);
    this->posx      = posx;
    this->posy      = posy;
    this->tint      = tint;
}

Sprite::Sprite(Texture2D texture,int posx=0,int posy=0,Color tint=WHITE) {
    this->texture   = texture;
    this->posx      = posx;
    this->posy      = posy;
    this->tint      = tint;
}

Texture Sprite::GetTexture() {
    return this->texture;
}

Color Sprite::GetTint() {
    return this->tint;
}

int Sprite::GetPosx() {
    return this->posx;
}

int Sprite::GetPosy() {
    return this->posy;
}