#pragma once

#include <string>
#include <memory>
#include <iostream>

#include "InstanceCounter.hpp"
#include "NodeKind.hpp"

class StringLeaf;
class IntLeaf;
class ArrayNode;
class ObjectNode;
class Node;

class Node: public InstanceCounter {
public:    
    // Virtuals functions
    virtual ~Node(){}
    virtual std::string print() const = 0;
    virtual int height() const = 0;
    virtual int node_count() const = 0;
    virtual std::unique_ptr<Node> deep_copy() const= 0;
    virtual bool operator==(const Node& other) const = 0;

    StringLeaf* as_StringLeaf();
    IntLeaf* as_IntLeaf();
    ArrayNode* as_ArrayNode();
    ObjectNode* as_ObjectNode();

    const IntLeaf* as_IntLeaf() const ;
    const StringLeaf* as_StringLeaf() const ;
    const ObjectNode* as_ObjectNode() const ;
    const ArrayNode* as_ArrayNode() const ;

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