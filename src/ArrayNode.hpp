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
        int max_height = 1;

        for(const auto &child : _childs){
            max_height = std::max(max_height, child->height() + 1);
        }

        return max_height;
    }

private:
    std::vector<std::unique_ptr<Node>> _childs;
};