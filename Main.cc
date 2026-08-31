#include "App.h"

int main(int argc,char** argv) {
    App app;
    try {
        app.Init();
        app.MainLoop();
    } catch (...){
        return 1;
    }
    return 0;
}