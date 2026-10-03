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
    int resolution_coefficent = 1;
    Texture2D background_texture;
    void GenerateBackground();
};