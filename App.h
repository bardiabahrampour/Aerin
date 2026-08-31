#pragma once
#include <raylib.h>
#include "Button.h"
#include "Theme.h"

struct App {
    App();
    ~App();
    bool ReadConfig();
    void Init();
    void MainLoop();
private:
    Theme main_theme;
    int width,height;
    Texture2D background_texture;
    void GenerateBackground();
};