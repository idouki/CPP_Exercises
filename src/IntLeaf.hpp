#pragma once

#include <string>
#include <memory>

#include "Leaf.hpp"
#include "NodeKind.hpp"

class IntLeaf : public Leaf {
public:
    IntLeaf(int);

     int data() const { return _data; }

    std::string print() const override;

    static std::unique_ptr<IntLeaf> make_ptr(int data){
        return std::make_unique<IntLeaf>(data);
    }

    int height() const override {return 0;}

    int node_count() const override {return 1;}

    bool operator==(const Node& other) const override {
        auto int_leaf_other = other.as_IntLeaf();

        if(int_leaf_other == nullptr){
            return false;
        }

        return int_leaf_other->_data == this->_data;
    }

    std::unique_ptr<Node> deep_copy()const override {
        return make_ptr(_data);
    }

private:
    int _data;
};