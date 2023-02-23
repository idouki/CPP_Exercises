#pragma once

#include "Node.hpp"

#include <memory>
#include <map>

class ObjectNode : public Node {
public:
    ObjectNode():
        Node{NodeKind::OBJECT}
    {}    

    std::string print() const override;

    static std::unique_ptr<ObjectNode> make_ptr(){
        return std::make_unique<ObjectNode>();
    }

    void insert(std::string key, std::unique_ptr<Node> child);

    int child_count() const { return _childs.size(); }

private:
    std::map<std::string, std::unique_ptr<Node>> _childs;
};
