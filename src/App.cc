#include "App.h"
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

App::App() : width{0} , height{0}{
//  just for prototyping
//  will change definetelyl
    main_theme.BackgroundSecond = ConvertHexToRGBA("#31572c");
    main_theme.BackgroundFirst = ConvertHexToRGBA("#90a955");
}

App::~App() {
    UnloadTexture(background_texture);
    CloseWindow();
}

void App::Init() {

    InitWindow(GetMonitorWidth(GetCurrentMonitor()),
               GetMonitorHeight(GetCurrentMonitor()),
               "Aerin");
    width = GetScreenWidth();
    height = GetScreenHeight();

    GenerateBackground();

    SetTargetFPS(GetMonitorRefreshRate(GetCurrentMonitor()));
    
}

void App::MainLoop() {
    while(!WindowShouldClose()) {
        BeginDrawing();
            DrawTexture(background_texture,0,0,WHITE);
        EndDrawing();
    }
}

//TODO: will do it later ,right now its completely broken
bool App::ReadConfig() {
    
}

static constexpr int Bayer4x4[4][4] = {
    { 0,  8,  2, 10 },
    {12,  4, 14,  6 },
    { 3, 11,  1,  9 },
    {15,  7, 13,  5 }
};

Color DitheredGradient(Color top, Color bottom, int x, int y, int height) {
    float t = (float)y / (float)(height - 1);

    float r = top.r + (bottom.r - top.r) * t;
    float g = top.g + (bottom.g - top.g) * t;
    float b = top.b + (bottom.b - top.b) * t;

    // Very small +/- 0.5 dither around the ideal value.
    float dither = ((Bayer4x4[y & 3][x & 3] + 0.5f) / 16.0f) - 0.5f;

    r += dither;
    g += dither;
    b += dither;

    return {
        (unsigned char)std::clamp((int)r, 0, 255),
        (unsigned char)std::clamp((int)g, 0, 255),
        (unsigned char)std::clamp((int)b, 0, 255),
        255
    };
}

void App::GenerateBackground() {

    
    Image background_img = GenImageColor(width,height,BLACK);

    for(int y=0; y<height; ++y) {
        for(int x=0; x<width; ++x) {
            Color* pixels = (Color*)background_img.data;
            pixels[y * width + x] =
                DitheredGradient(
                    main_theme.BackgroundFirst,
                    main_theme.BackgroundSecond,
                    x,y,height
                );
        }
    }
    background_texture = LoadTextureFromImage(background_img);
    UnloadImage(background_img);
}