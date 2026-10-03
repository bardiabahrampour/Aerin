#pragma once

#include "Widget.h"
#include "Sprite.h"
#include <vector>
#include <string>

#define BUTTON_RECT_X 200
#define BUTTON_RECT_Y 100

/*
    NOT IMPLEMENTED YET!!
    will change MakeButton() to seperate
    fucntions based of states
*/
enum class ButtonState {
    BUTTON_IDLE,
    BUTTON_HOVERED,
    BUTTON_CLICKED,
    BUTTON_UNAVAILABLE,
    BUTTON_HIDDEN,
    BUTTON_ERROR
};

struct Button : public Widget {
    Button();
    Button(int sizex, int sizey , int posx, int posy);
    void MakeButton();
    void Draw() override;
    void Update() override;
    std::vector<Sprite> render;
private:
    std::string name;
    ButtonState state = ButtonState::BUTTON_IDLE;
};
