#pragma once

#include <string>

#include "InstanceCounter.hpp"

class Node: public InstanceCounter {
public:    
    virtual std::string print();
};
