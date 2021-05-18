//
// Created by Yuri Grigorian on 05/05/2021.
//

#include "Researcher.hpp"


using namespace pandemic;


Player &Researcher::discover_cure(Color c) {
    return _discover_cure(c, DEFAULT_CARDS_NEEDED, false, true);
};

std::string Researcher::role() { return "Researcher"; }