#include "ArrayNode.hpp"

#include <string>

std::string ArrayNode::print() const {
    auto to_string = std::string {};
    auto separateur = std::string {""};
    
    to_string += "[";

    // stringstream plus efficace
    for(const auto &child_ptr : _childs){
        to_string += separateur;
        to_string += child_ptr->print();
        separateur = ",";
    }

    to_string += "]";
    return to_string;
}

void ArrayNode::push_back(std::unique_ptr<Node> child) {
    _childs.push_back(std::move(child));
}