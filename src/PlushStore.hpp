#pragma once

#include <string>
#include <Plush.hpp>

class PlushStore{
public:
    PlushStore(std::string name){
        _name = name;
    }

    std::string get_name() const{
        return _name;
    }

    int get_wealth_amount() const{
        return _wealth_amount;
    }

    int get_stock_size() const{
        return _stock_size;
    }

    int get_debt_amount() const{
        return _debt_amount;
    }

     int get_experience() const{
        return _experience;
    }

    void loan(int loan_amount){
        _wealth_amount += loan_amount;
        _debt_amount += loan_amount * 1.1;
    }

    int make_plush(int cost){
        if(_wealth_amount == 0){
            return 0;
        }
        _wealth_amount -= (cost > _wealth_amount) ? cost - _wealth_amount : cost;
        _stock_size++;
        _experience++;
        return cost + _experience;
    }


private:
    std::string _name;
    int _stock_size = 0;
    int _wealth_amount = 0;
    int _debt_amount =0;
    int _experience = 0;
};
