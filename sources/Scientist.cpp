//
// Created by Yuri Grigorian on 05/05/2021.
//

#include "Scientist.hpp"

using namespace pandemic;

Scientist::Scientist(Board &b, City c, int cards_needed) : Player(b, c), cards_needed(cards_needed) {};

Player &Scientist::discover_cure(Color c) {
    if (this->cards_needed < 0) {
        throw std::runtime_error("Bad needed card val.");
    }
    return this->_discover_cure(c, this->cards_needed, true, true);
};

std::string Scientist::role() { return "Scientist"; }