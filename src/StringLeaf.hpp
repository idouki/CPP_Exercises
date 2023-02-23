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

private:
    std::string _data;
};
