//
// Created by Yuri Grigorian on 18/05/2021.
//

#ifndef PANDEMIC_B_CITYINFO_HPP
#define PANDEMIC_B_CITYINFO_HPP
#include "City.hpp"
#include "Color.hpp"
#include "set"
#include "string"

namespace pandemic{
    struct CityInfo{
        std::string name;
        City city;
        Color color;
        std::set<City> links;
        int disease_count;
        bool has_research_facility;

        CityInfo(std::string _name, City _city, Color _color): name(_name), city(_city), color(_color), links(), disease_count(0), has_research_facility(
                false){};

        void add_link(City c){
            links.insert(c);
        }

        bool is_connected_to(City c){
            return this->links.find(c) != this->links.end();
        }
    };
}


#endif //PANDEMIC_B_CITYINFO_HPP
