#pragma once

#include "pixels.hpp"

#include "../lib/lib.hpp"

#include <stdint.h>
#include <cstddef>
#include <functional>
#include <string>
#include <array>
#include <iostream>

template <typename P, size_t W, size_t H>
class Image{
public:
    Image() = default;

    Image(const P& pixel):
        _pixels{}{
            fill_array(pixel);
        }

    Image<P, W, H>(const std::function<P(const size_t i, const size_t j)> & functor)
    {
        for(size_t j = 0; j < H; j++)
            for(size_t i = 0; i < W; i++)
                _pixels[j][i] = functor(i, j);

    }

    P& operator()(const size_t i, const size_t j)
    {
        return _pixels[j][i];
    }    

    const P& operator()(const size_t i, const size_t j) const
    {
        return _pixels[j][i];
    }    

private:
    void fill_array(const P &pixel){
        for(size_t i = 0; i < H; i++){
            std::array<P, W> tmp;
            tmp.fill(pixel);
            _pixels[i] = tmp;
        }
    }

private:    
    std::array<std::array<P, W>, H> _pixels;
};

template <typename A,typename B, size_t W, size_t H>
const Image<A, W, H> operator+(const Image<A, W, H> &l, const Image<B, W, H> &r) {
    Image<A, W, H> image = {};

    for(size_t j = 0; j < H; j++)
        for(size_t i = 0; i < W; i++)
            image(i, j) = l(i, j) + r(i, j);
        
    return image;
}

