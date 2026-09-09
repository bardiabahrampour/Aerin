#include <raylib.h>
#include <string>
#include <vector>
#include <iostream>

/*
    animation speed should be set to monitor refresh rate
    if speed is for example x , and its 60hz,
    then when the monitor refresh rate is 120hz
    animation speed should be 1/2x
*/

typedef unsigned char byte;

int anim_speed_coeefficent = 1;
int refresh_rate = 0;
int current_monitor = 0;

#ifndef NDEBUG
constexpr int DEBUG_WINDOW_WIDTH = 800;
constexpr int DEBUG_WINDOW_HEIGHT = 450;
#endif

/*
    PROTOTYPE:
        this is a very basic prottype 
        a linear menu with animations
        and a translucent background
        NO IMAGES ONLY VECTORS
*/

struct Theme {
    Color Primary;
    Color Secondary;
/*
    Font MainFont;
*/
};

enum class ButtonState {
    NEUTRAL,
    HOVER,
    PRESSED
};

struct Button {
    void setName(std::string name);
    void setTheme(Theme &theme);
    void Draw(int posx,int posy);
    void Update();
    void SetState(ButtonState state_p);
private:
    std::string name;
    ButtonState state = ButtonState::NEUTRAL;
    Color CurrentColor;
    Color MainColor;
    byte Transparency = 40;
    int OffsetRectX = 0,OffsetRectY = 0;
    int OffsetX = 0,OffsetY = 0;
};

void Button::setName(std::string name) {
    this->name = name;
}

void Button::setTheme(Theme &theme) {
    this->MainColor = theme.Primary;
}
/*
    typically the neutral color should be
    the same as main but transparent,
    hover be still a little transparent but lighter
    also larger(anim)
    pressed should be bold darker and a little smaller
    than hovered
*/
void Button::Update() {
    switch (this->state)
    {
    case ButtonState::NEUTRAL:
        CurrentColor = Color{MainColor.r,MainColor.g,MainColor.b,Transparency};
        OffsetRectX = 0;
        OffsetRectY = 0;
        OffsetX = 0;
        OffsetY = 0;
        break;
    case ButtonState::HOVER:
        CurrentColor = Color{MainColor.r,MainColor.g,MainColor.b,Transparency + 50};
        OffsetRectX = 30;
        OffsetRectY = 30;
        OffsetX = -15;
        OffsetY = -15;
        break;
    case ButtonState::PRESSED:
        CurrentColor = MainColor;
        OffsetRectX = 3;
        OffsetRectY = 3;
        OffsetX = -3;
        OffsetY = -3;
        break;
    default:
        break;
    }
}

void Button::SetState(ButtonState state_p) {
    this->state = state_p;
}

void Button::Draw(int posx,int posy) {
    DrawRectangle(posx + OffsetX,posy + OffsetY,250 + OffsetRectX, 200 + OffsetRectY,CurrentColor);
    DrawText(this->name.c_str(),posx + ((250 + OffsetRectX) - MeasureText(this->name.c_str(),20))/2 + OffsetX,posy+(100+(OffsetRectY/2))+OffsetY-10,20,WHITE);
}

int main(int argc,char** argv) {
    InitWindow(GetScreenWidth(),GetScreenHeight(),"TVGui");
    current_monitor = GetCurrentMonitor();
    refresh_rate = GetMonitorRefreshRate(current_monitor);
    SetTargetFPS(refresh_rate);
    ToggleFullscreen();
    
    Theme theme = {.Primary = DARKBLUE,.Secondary=DARKBLUE};
    std::vector<std::string> button_ids = {"Main Menu", "Settings" , "Extras" , "Credits" , "Quit" , "Exit to Windows"};
    std::vector<Button> buttons;

    for(auto a : button_ids) {
        Button b;
        b.setName(a);
        b.setTheme(theme);
        buttons.push_back(b);
    }
    
    //we set our animation speed by 60hz
    //the final speed will be changed by the coeeficent
    anim_speed_coeefficent = 60/refresh_rate;

    int cursor = 0;
    
    while(!WindowShouldClose()) {
        if(IsKeyPressed(KEY_RIGHT) && cursor < buttons.size()){
            cursor++;
        } else if (IsKeyPressed(KEY_LEFT) && cursor > 0){
            cursor--;
        }
        BeginDrawing();
        ClearBackground(BLACK);

        DrawRectangleGradientH(0,0,GetScreenWidth(),GetScreenHeight(),DARKBLUE,BLUE);
    
        for(int i = 0;i < buttons.size();i++) {
            if(cursor == i && IsKeyPressed(KEY_ENTER)) buttons[i].SetState(ButtonState::PRESSED);
            else if(cursor == i) buttons[i].SetState(ButtonState::HOVER);
            else buttons[i].SetState(ButtonState::NEUTRAL);
            buttons[i].Update();
            buttons[i].Draw(i*300,50);
        }
    
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
