#pragma once
#include <raylib.h>
/*
    Widget:
    universal class for bascially everything that appears on screen.
*/

struct Widget {
    virtual void Draw();
    virtual void Update();
    virtual ~Widget() = default;
protected:
    enum class WidgetState {
        STATE_NEUTRAL,
        STATE_HOVERED,
        STATE_PRESSED,
    };

    WidgetState state = WidgetState::STATE_NEUTRAL;
    int posx=0,posy=0;
    int sizex = 0, sizey = 0;
    Color Background_Color;
    Color Foreground_Color;
    
};