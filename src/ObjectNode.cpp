#include "ObjectNode.hpp"

std::string ObjectNode::print() const {
    auto to_string = std::string {};
    auto separateur = std::string {""};
    
    to_string += "{";

    // stringstream plus efficace
    for(const auto &[key, value] : _childs){
        to_string += separateur;
        to_string += "\"" + key + "\"" + ":";
        to_string += value->print();
        separateur = ",";
    }

    to_string += "}";
    return to_string;
}

void ObjectNode::insert(std::string key, std::unique_ptr<Node> child) {
    _childs.insert_or_assign(key, std::move(child));
}

bool ObjectNode::has_child(const std::string& name) const {
    return _childs.count(name) != 0;
}

Node* ObjectNode::at(const std::string& name){

    if(!has_child(name)){
        return nullptr;
    }

    return _childs.at(name).get();
}
