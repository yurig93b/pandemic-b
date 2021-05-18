//
// Created by Yuri Grigorian on 05/05/2021.
//

#include "Dispatcher.hpp"

using namespace pandemic;

Player &Dispatcher::fly_direct(City c) {
    if (this->board.get_city_info(this->city).has_research_facility) {
        this->ensure_not_travel_cities_differ(c);
        this->change_city(c);
        return *this;
    }

    return Player::fly_direct(c);
}

std::string Dispatcher::role() {
    return "Dispatcher";
}
