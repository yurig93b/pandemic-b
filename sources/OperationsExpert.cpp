//
// Created by Yuri Grigorian on 05/05/2021.
//

#include "OperationsExpert.hpp"

using namespace pandemic;

void OperationsExpert::build() {
    CityInfo &ci = this->board.get_city_info(this->city);
    ci.has_research_facility = true;

};

std::string OperationsExpert::role() { return "OperationsExpert"; }