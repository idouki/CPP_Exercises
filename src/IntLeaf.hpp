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

private:
    int _data;
};