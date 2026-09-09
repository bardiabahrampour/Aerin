#pragma once

#include "Widget.h"
#include <string>

struct Button : public Widget {
    Button();
    Button(int sizex, int sizey , int posx, int posy);
    void Draw() override;
    void Update() override;
    
private:
    std::string name;
    
};
