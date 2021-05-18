//
// Created by Yuri Grigorian on 05/05/2021.
//

#include "Medic.hpp"

using namespace pandemic;

bool Medic::change_city(City c) {
    bool changed = Player::change_city(c);
    CityInfo &city_info = this->board.get_city_info(c);

    if (city_info.disease_count > 0 && this->board.get_color_info(city_info.color).has_cure) {
        this->treat(c);
    }
    return changed;
}

Player &Medic::treat(City c) {
    Player &res = Player::treat(c);
    this->board.get_city_info(c).disease_count = 0;
    return res;
};

std::string Medic::role() { return "Medic"; }
