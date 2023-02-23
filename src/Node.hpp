#pragma once

#include <string>

#include "InstanceCounter.hpp"
#include "NodeKind.hpp"

class Node: public InstanceCounter {
public:    
    virtual ~Node(){}
    virtual std::string print() const = 0;
    
    NodeKind kind() const{
        return _kind;
    };

    Node(NodeKind kind):
    _kind {kind}
    {}

    Node() = default;

protected:
    NodeKind _kind;
};