#pragma once

#include <string>

#include "InstanceCounter.hpp"
#include "NodeKind.hpp"

class Node: public InstanceCounter {
public:    
    // Virtuals functions
    virtual ~Node(){}
    virtual std::string print() const = 0;
    virtual int height() const = 0;
    virtual int node_count() const = 0;
    
    Node() = default;
    Node(NodeKind kind):
    _kind {kind}
    {}

    NodeKind kind() const{
        return _kind;
    };


protected:
    NodeKind _kind;
};