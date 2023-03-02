#pragma once

#include "Node.hpp"

#include <memory>
#include <map>

class ObjectNode : public Node {
public:
    ObjectNode():
        Node{NodeKind::OBJECT}
    {}    

    std::string print() const override;

    static std::unique_ptr<ObjectNode> make_ptr(){
        return std::make_unique<ObjectNode>();
    }

    void insert(std::string key, std::unique_ptr<Node> child);

    int child_count() const{ return _childs.size(); }

    bool has_child(const std::string& name) const;

    Node* at(const std::string& name);

    const Node* at(const std::string& name) const{
        if(!has_child(name)){
            return nullptr;
        }

        return _childs.at(name).get();
    }

    int node_count() const override { 
        int node_count = 1 ;

        for(const auto & [key, node_ptr] : _childs){
            node_count += node_ptr->node_count();
        }

        return node_count; 
    }

    int height() const {
        int max_height = 0 ;
        
        for(const auto & [key, node_ptr] : _childs){
            max_height = std::max(node_ptr->height() + 1, max_height);
        }

        return max_height;
    }

    bool operator==(const Node& other) const override {
        auto object_leaf_other = other.as_ObjectNode();

        if(object_leaf_other == nullptr){
            return false;
        }

        return true;
    }

    std::unique_ptr<Node> deep_copy() const override {
        auto new_node = make_ptr();

        for(const auto& [key, value] : _childs){
            new_node->insert(key, value->deep_copy());
        }

        return new_node;
    }

private:
    std::map<std::string, std::unique_ptr<Node>> _childs;
};
