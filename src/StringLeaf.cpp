#include "StringLeaf.hpp"

StringLeaf::StringLeaf(std::string data):
    Leaf(NodeKind::STRING),
    _data {data}
    {}

std::string StringLeaf::print() const {
    return "\"" +_data + "\"";
}