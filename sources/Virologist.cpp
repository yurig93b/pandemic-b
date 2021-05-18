//
// Created by Yuri Grigorian on 05/05/2021.
//

#include "Virologist.hpp"


using namespace pandemic;

Player &Virologist::treat(City c) {
    if (this->has_card(c)) {
        return this->_treat(c, false);
    }

    return Player::treat(c);

};

std::string Virologist::role() { return "Virologist"; }