#pragma once

#include <string>
#include <memory>

#include "Leaf.hpp"
#include "NodeKind.hpp"

class StringLeaf : public Leaf {

public:
    StringLeaf(std::string);

    std::string print() const override;

    std::string data() const { return _data; }

    static std::unique_ptr<StringLeaf> make_ptr(std::string data){
        return std::make_unique<StringLeaf>(data);
    }

    int height() const override {return 0;}

    int node_count() const override {return 1;}

    bool operator==(const Node& other) const override {
        auto string_leaf_other = other.as_StringLeaf();

        if(string_leaf_other == nullptr){
            return false;
        }

        return string_leaf_other->_data == this->_data;
    }

    std::unique_ptr<Node> deep_copy() const override {
        return make_ptr(_data);
    }

private:
    std::string _data;
};
