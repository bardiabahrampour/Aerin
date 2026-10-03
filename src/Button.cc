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
    render.push_back(background);
    render.push_back(text);
    render.push_back(overlay);
}

void Button::Draw(){

}

void Button::Update(){

}