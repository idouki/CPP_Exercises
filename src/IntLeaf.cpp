#include "IntLeaf.hpp"

#include "IntLeaf.hpp"

#include <iostream>
#include <string>

IntLeaf::IntLeaf(int data):
    Leaf {NodeKind::INT},
    _data {data}
    {}

std::string IntLeaf::print() const{
    return std::to_string(_data);
}