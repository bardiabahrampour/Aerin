#include <raylib.h>

/*
    animation speed should be set to monitor refresh rate
    if speed is for example x , and its 60hz,
    then when the monitor refresh rate is 120hz
    animation speed should be 1/2x
*/

int anim_speed_coeefficent = 1;
int refresh_rate = 0;
int current_monitor = 0;

#ifndef NDEBUG
constexpr int DEBUG_WINDOW_WIDTH = 800;
constexpr int DEBUG_WINDOW_HEIGHT = 450;
#endif

int main(int argc,char** argv) {
    InitWindow(GetScreenWidth(),GetScreenHeight(),"TVGui");
    current_monitor = GetCurrentMonitor();
    refresh_rate = GetMonitorRefreshRate(current_monitor);
    SetTargetFPS(refresh_rate);
    
    //we set our animation speed by 60hz
    //the final speed will be changed by the coeeficent
    anim_speed_coeefficent = 60/refresh_rate;
    
    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}