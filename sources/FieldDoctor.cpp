//
// Created by Yuri Grigorian on 05/05/2021.
//

#include "FieldDoctor.hpp"

using namespace pandemic;

Player &FieldDoctor::treat(City c) {
    CityInfo &ci = this->board.get_city_info(this->city);
    if (c != this->city && ci.links.find(c) == ci.links.end()) {
        throw std::runtime_error("Can't cure this city.");
    }

    return Player::_treat(c, false);

};

std::string FieldDoctor::role() { return "FieldDoctor"; }