#pragma once

#include "Widget.h"
#include <string>

struct Button : public Widget {
    void Draw() override;
    void Update() override;
    
private:
    std::string name;
    
};
