#pragma once

//TODO: replace with a layer that adds raylib later
#include <raylib.h>

struct Theme {
    Color First;
    Color Second;
    Color Accent;
    Color Error;
    Color Warning;
    Color Info;
    Color BackgroundFirst;
    Color BackgroundSecond;
    Font  MainFont;
};

Color ConvertHexToRGBA(const char* hex);