#pragma once

class Plush
{
public:
    Plush(int cost):
        _cost {cost}
    {}
    

    Plush() = default;

    int get_cost() const{
        return _cost;
    }

    void set_cost(int cost){
        _cost = cost;
    }

private:
    int _cost = 10;
};
