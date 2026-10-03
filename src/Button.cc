#include "Button.h"

Button::Button() : Widget() {

}

Button::Button(int sizex,int sizey,int posx=0,int posy=0) : Widget() {
    sizex = sizex;
    sizey = sizey;
    posx  = posx;
    posy  = posy;
}

//temporary workaround
void Button::MakeButton() {
    Sprite background;
    Sprite text;
    Sprite overlay;
}

void Button::Draw(){

}

void Button::Update(){

}