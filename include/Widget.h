#pragma once
#include <raylib.h>
#include <Sprite.h>
#include <vector>

/*
    Widget:
    universal class for bascially everything that appears on screen.
*/

struct Widget {
    virtual void Draw(std::vector<Sprite> &graphics_data);
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