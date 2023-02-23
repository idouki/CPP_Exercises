#pragma once

#include "Node.hpp"

class Leaf : public Node {
public:

    Leaf(NodeKind kind):
    Node {kind}
    {}
};