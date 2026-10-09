#pragma once
#include <raylib.h>
#include "Button.h"
#include "Theme.h"
#include "Graphics.h"

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
    Aerin::Texture background_texture;
    void GenerateBackground();
    std::vector<Sprite> graphics_data;
    std::vector<Button> buttons;
};