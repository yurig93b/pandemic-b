//
// Created by Yuri Grigorian on 05/05/2021.
//

#ifndef PANDEMIC_A_BOARD_HPP
#define PANDEMIC_A_BOARD_HPP

#include "City.hpp"
#include <iostream>
#include <unordered_map>
#include "CityInfo.hpp"
#include "ColorInfo.hpp"
#include <fstream>

#define CITIES_FILE "cities_map.txt"

namespace pandemic {

    class Board {
        std::unordered_map<City, CityInfo> cities;
        std::unordered_map<Color, ColorInfo> colors;

        void load_cities();
        void load_colors();

        public:
            Board();

            /// Checks if all diseases are cleared.
            /// \return true if clean else false
            bool is_clean();

            void remove_cures();

            /// Gets a reference to disease counter of a city.
            /// \param c City to access
            /// \return reference to disease counter of a city.
            int& operator[](City c);

            /// Fetch CityInfo object.
            /// \param c City
            /// \return CityInfo
            CityInfo& get_city_info(City c);

            /// Fetch ColorInfo object.
            /// \param c City
            /// \return ColorInfo
            ColorInfo& get_color_info(ColorInfo c);
            friend std::ostream& operator<<(std::ostream& os, const Board& b);

    };
}


#endif //PANDEMIC_A_BOARD_HPP
