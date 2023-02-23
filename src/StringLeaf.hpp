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

private:
    std::string _data;
};
