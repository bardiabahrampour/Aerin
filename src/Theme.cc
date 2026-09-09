#include "Theme.h"

#include <cstdio>
#include <cstring>

Color ConvertHexToRGBA(const char* hex) {
    if (hex[0] == '#') ++hex;
    unsigned int value = 0;
    std::sscanf(hex,"%x",&value);

    if (std::strlen(hex) == 6){
        return {
            static_cast<unsigned char>((value >> 16) & 0xFF),
            static_cast<unsigned char>((value >> 8) & 0xFF),
            static_cast<unsigned char>(value & 0xFF),
            255
        };
    }

    return {
        static_cast<unsigned char>((value >> 24) & 0xFF),
        static_cast<unsigned char>((value >> 16) & 0xFF),
        static_cast<unsigned char>((value >> 8) & 0xFF),
        static_cast<unsigned char>(value & 0xFF),
    };
}