#pragma once
#include <string>
#include <iostream>

class Kid{
public:
    Kid(const std::string& name, int money):
        _name {name},
        _money {money}
    {}

    std::string get_name() const {
        return _name;
    }

    int get_money() const {
        return _money;
    }

    friend std::ostream& operator<<(std::ostream& stream, const Kid& kid){
        stream << kid._name << " has " << kid._money << " euros.";
        return stream;
    }

private:
    std::string _name;
    int _money = 0;
};