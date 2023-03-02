#pragma once

#include "Node.hpp"

#include <memory>
#include <vector>
#include <algorithm>

class ArrayNode : public Node{
public:
    ArrayNode():
        Node {NodeKind::ARRAY}
    {}

    std::string print() const override ;

    static std::unique_ptr<ArrayNode> make_ptr(){ return std::make_unique<ArrayNode>(); }

    int child_count() const { return _childs.size(); }

    void push_back(std::unique_ptr<Node> child);

    int height() const override {
        int max_height = 0;

        for(const auto &child : _childs){
            max_height = std::max(max_height, child->height() + 1);
        }

        return max_height;
    }

    int node_count() const override { 
        int node_count = 1 ;

        for(const auto & node_ptr : _childs){
            node_count += node_ptr->node_count();
        }

        return node_count; 
    }

    std::vector<std::unique_ptr<Node>>::iterator begin(){
        return _childs.begin();
    }

    std::vector<std::unique_ptr<Node>>::iterator end(){
        return _childs.end();
    }

    std::vector<std::unique_ptr<Node>>::const_iterator begin() const{
        return _childs.begin();
    }

    std::vector<std::unique_ptr<Node>>::const_iterator end() const{
        return _childs.end();
    }

    bool operator==(const Node& other) const override {
        auto array_leaf_other = other.as_ArrayNode();

        if(array_leaf_other == nullptr){
            return false;
        }

        if(this->child_count() != array_leaf_other->child_count()){
            return false;
        }

        for(int index = 0; index < this->child_count(); index++ ){
            if(!(*(this->_childs[index]) == *(array_leaf_other->_childs[index]))){
                return false;
            }
        }
        return true;
    }

    std::unique_ptr<Node> deep_copy() const override {
        auto new_node = make_ptr();

        for(int i =0; i < child_count(); i++){
            new_node->push_back(_childs[i]->deep_copy());
        }

        return new_node;
    }


private:
    std::vector<std::unique_ptr<Node>> _childs;
};