#include "Node.hpp"

#include "IntLeaf.hpp"
#include "StringLeaf.hpp"
#include "ObjectNode.hpp"
#include "ArrayNode.hpp"

StringLeaf* Node::as_StringLeaf(){
    return dynamic_cast<StringLeaf*>(this);
}

IntLeaf* Node::as_IntLeaf(){
    return dynamic_cast<IntLeaf*>(this);
}

ArrayNode* Node::as_ArrayNode(){
    return dynamic_cast<ArrayNode*>(this);
}

ObjectNode* Node::as_ObjectNode(){
    return dynamic_cast<ObjectNode*>(this);
}

const ObjectNode* Node::as_ObjectNode() const {
    return dynamic_cast<const ObjectNode*>(this);
}

const ArrayNode* Node::as_ArrayNode() const {
    return dynamic_cast<const ArrayNode*>(this);
}

const IntLeaf* Node::as_IntLeaf() const {
    return dynamic_cast<const IntLeaf*>(this);
}

const StringLeaf* Node::as_StringLeaf() const {
    return dynamic_cast<const StringLeaf*>(this);
}