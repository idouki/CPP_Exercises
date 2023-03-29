#pragma once

#include "../lib/lib.hpp"

#include <stdint.h>

struct RGB{
    uint8_t r,g,b;
};

struct RGBA: RGB{
    uint8_t a;    
};

struct Luma{
    uint8_t gray;    
};

template<typename A, typename B>
A from(const B & stuff);

template<typename A>
A from(const A & x)
{
    return x;
}

template <>
RGB from(const RGBA& r){
    return  {r.r, r.g, r.b};
}

template <>
RGBA from(const RGB& r){
    return  {r.r, r.g, r.b, 255};
}

template <>
Luma from(const RGB& r){
    return {lib::rgb_to_grayscale(r.r, r.g, r.b)};
}

