#include "Graphics.h"

void Graphics::Init() {
    InitWindow(
        GetMonitorWidth(GetCurrentMonitor()),
        GetMonitorHeight(GetCurrentMonitor()),
        "Aerin"
    );
//  seems dumb but is actually like a double check
//  to see if the GetMonitor functions failed
    this->width =   GetScreenWidth();
    this->height =  GetScreenHeight();
    this->resolution_coefficent = 1920/width;

    SetTargetFPS(GetMonitorRefreshRate(GetCurrentMonitor()));
}

void Graphics::Update() {
    BeginDrawing();
    for(auto a : this->graphics_data) {
        DrawTexture(a.GetTexture(),a.GetPosx(),a.GetPosy(),a.GetTint());
    }
    this->graphics_data.clear();

    
}