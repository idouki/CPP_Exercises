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

template <>
RGB from(const Luma& ri){
    const auto [r,g,b] = lib::grayscale_to_rgb(ri.gray);
    return {r,g,b};
}

template <>
RGBA from(const Luma& ri){
    return from<RGBA, RGB>(from<RGB,Luma>(ri));
}

const RGBA operator+(const RGBA& lp, const RGBA& rp){
    const auto [r, g, b, a] = lib::mix_color(lp.r, lp.g, lp.b, lp.a, rp.r, rp.g, rp.b, rp.a);
    return {r, g, b, a};
}

const RGBA operator+(const RGBA& lp, const RGB& rp){
    const auto [r, g, b, a] = lib::mix_color(lp.r, lp.g, lp.b, lp.a, rp.r, rp.g, rp.b, 255);
    return {r, g, b, a};
}

const RGB operator+(const RGB& lp, const RGBA& rp){
    const auto [r, g, b, a] = lib::mix_color(lp.r, lp.g, lp.b, 255, rp.r, rp.g, rp.b, rp.a);
    return {r, g, b};
}

const RGB operator+(const Luma& lp, const RGBA& rp){
    auto a = from<RGBA, Luma>(lp) + rp;
    return {a.r, a.g, a.b};
}

const RGB operator+(const Luma& lp, const RGB& rp){
    return lp + from<RGBA, RGB>(rp);
}

const RGB operator+(const RGB& lp, const RGB& rp){
    const auto [r, g, b, a] = lib::mix_color(lp.r, lp.g, lp.b, 255, rp.r, rp.g, rp.b, 255);
    return {r, g, b};
}