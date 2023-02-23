#pragma once

#include <string>

#include "Leaf.hpp"
#include "NodeKind.hpp"

class IntLeaf : public Leaf {
public:
    IntLeaf(int);

    int data() const { return _data; }

    NodeKind kind() const { return NodeKind::INT; }

    std::string print() override;

private:
    int _data;
};
