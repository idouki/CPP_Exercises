#include "IntLeaf.hpp"

#include <iostream>
#include <string>

IntLeaf::IntLeaf(int data):
    _data {data}
    {}

std::string IntLeaf::print() {
    return std::to_string(_data);
}