#pragma once

#include "Node.hpp"
#include <memory>
#include <vector>

class ArrayNode : public Node{
public:
    ArrayNode():
        Node {NodeKind::ARRAY}
    {}

    std::string print() const override ;

    static std::unique_ptr<ArrayNode> make_ptr(){ return std::make_unique<ArrayNode>(); }

    int child_count() const { return _childs.size(); }

    void push_back(std::unique_ptr<Node> child);

private:
    std::vector<std::unique_ptr<Node>> _childs;
};