//
// Created by Yuri Grigorian on 05/05/2021.
//

#include "Player.hpp"

using namespace pandemic;

Player::Player(Board &b, City c): board(b), city(c){};

void Player::ensure_has_card(City c) const{
    if(this->cards.find(c) == this->cards.end()){
        throw std::runtime_error("No needed card.");
    }
}

void Player::remove_card(City c){
    this->ensure_has_card(c);
    this->cards.erase(c);
}

std::set<City> Player::collect_cards_by_color(Color c, int num, bool enforce_needed_num){
    std::set<City> collected_cards = {};

    for(const auto &card: this->cards){
        if(this->board.get_city_info(card).color == c || c == AnyColor){
            collected_cards.insert(card);
            if(collected_cards.size() == num){
                break;
            }
        }
    }

    // Ensure we collected enough cards
    if(enforce_needed_num && num != collected_cards.size()){
        throw std::runtime_error("Could not find enough cards.");
    }

    return collected_cards;
}

void Player::remove_cards_by_set(const std::set<City> &cards){
    for(const auto &card : cards){
        this->cards.erase(card);
    }
}

bool Player::change_city(City c){
    if(c == this->city){
        return false;
    }
    this->city = c;
    return true;
}

Player& Player::_treat(City c, bool enforce_city_match){
    if(enforce_city_match && c != this->city){
        throw std::runtime_error("City mismatch.");
    }

    CityInfo &city_info = this->board.get_city_info(c);
    if(city_info.disease_count == 0){
        throw std::runtime_error("Not disease to cure.");
    }

    ColorInfo &color_info = this->board.get_color_info(city_info.color);
    Player::cure_city(city_info,color_info);

    return *this;
};

void Player::cure_city(CityInfo &city_info, ColorInfo &color_info){
    if(color_info.has_cure){
        city_info.disease_count = 0;
    } else{
        city_info.disease_count--;
    }
}

Player& Player::_discover_cure(Color c, int cards_needed, bool enforce_needed_city_research_center, bool any_card){

    ColorInfo &ci = this->board.get_color_info(c);

    if(ci.has_cure){
        return *this;
    }

    if(enforce_needed_city_research_center && !this->board.get_city_info(this->city).has_research_facility){
        throw std::runtime_error("Current city has no research center");
    }

    std::set<City> collected_cards = this->collect_cards_by_color(any_card? AnyColor: c, cards_needed, true);
    ci.has_cure = true;
    this->remove_cards_by_set(collected_cards);

    return *this;
};

void Player::ensure_not_travel_cities_differ(City target_city) const{
    if(this->city == target_city){
        throw std::runtime_error("Cant go from the same city to same city.");
    }
}

void Player::build(){
    CityInfo &ci = this->board.get_city_info(this->city);
    if(ci.has_research_facility){
        return;
    }

    this->ensure_has_card(this->city);
    ci.has_research_facility = true;
    this->remove_card(this->city);
};

Player& Player::drive(City c){
    this->ensure_not_travel_cities_differ(c);

    if(!this->board.get_city_info(this->city).is_connected_to(c)){
        throw std::runtime_error("No route to city.");
    }
    this->change_city(c);
    return *this;
};

Player& Player::take_card(City c){
    this->cards.insert({c});
    return *this;
};

Player& Player::fly_direct(City c){
    this->ensure_not_travel_cities_differ(c);

    this->remove_card(c);
    this->change_city(c);
    return *this;
};

Player& Player::fly_charter(City c){
    this->ensure_not_travel_cities_differ(c);

    this->remove_card(this->city);
    this->change_city(c);
    return *this;
};

Player& Player::fly_shuttle(City c){
    this->ensure_not_travel_cities_differ(c);

    if(!this->board.get_city_info(c).has_research_facility || !this->board.get_city_info(this->city).has_research_facility){
        throw std::runtime_error("No research facility.");
    }
    this->change_city(c);
    return *this;
};

Player& Player::treat(City c){
    return this->_treat(c, true);
}

Player& Player::discover_cure(Color c){
    return this->_discover_cure(c, DEFAULT_CARDS_NEEDED, true, true);
};

 std::string Player::role(){throw std::runtime_error("Not impl.");}

City Player::get_location() const {return city;}

bool Player::has_card(City c) const{
    return this->cards.find(c) != this->cards.end();
}