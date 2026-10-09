#pragma once

/*
    Currently not used,
    i am going to develop tihs alongside the app as
    a compatibility layer incase i used other renderrers
*/

#include <vector>
#include "Sprite.h"

namespace Aerin {
    typedef unsigned char   Byte;
    typedef Texture2D       Texture;
};

class Graphics {
    std::vector<Sprite> graphics_data;
    int width,height,resolution_coefficent=1;

public:
    void Init();
    void Update(); //draw
};