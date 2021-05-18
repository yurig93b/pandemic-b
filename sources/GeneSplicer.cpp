//
// Created by Yuri Grigorian on 05/05/2021.
//

#include "GeneSplicer.hpp"

using namespace pandemic;

Player &GeneSplicer::discover_cure(Color c) {
     return this->_discover_cure(c, DEFAULT_CARDS_NEEDED, true, true);
};

std::string GeneSplicer::role() { return "GeneSplicer"; }