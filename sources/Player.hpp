//
// Created by Yuri Grigorian on 05/05/2021.
//

#ifndef PANDEMIC_A_BASEPLAYER_HPP
#define PANDEMIC_A_BASEPLAYER_HPP

#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "set"

#define DEFAULT_CARDS_NEEDED 5

namespace pandemic{
    class Player{

        protected:
            Board &board;
            City city;
            std::set<City> cards;
            /// Ensure player has card, throws if not.
            /// \param c City
            void ensure_has_card(City c) const;

            /// Removes card from deck.
            /// \param c City
            void remove_card(City c);

            /// Collects a list of cards by color.
            /// \param c Color
            /// \param num num needed
            /// \param enforce_needed_num throw if not enough cards found
            /// \return set<City>
            std::set<City> collect_cards_by_color(Color c, int num, bool enforce_needed_num);

            /// Changes a city.
            /// \param c City
            /// \return true if changed else false
            virtual bool change_city(City c);

            /// Actual treatment implementation.
            /// \param c City
            /// \param enforce_city_match Should enfore current city and treated city match
            /// \return Player
            Player& _treat(City c, bool enforce_city_match);

            /// Cure city based on cure found logic.
            /// \param city_info CityInfo object.
            /// \param color_info ColorInfo
            static void cure_city(CityInfo &city_info, ColorInfo &color_info);

            /// Discover cure based on params.
            /// \param c Color
            /// \param cards_needed Card num needed
            /// \param enforce_needed_city_research_center Should research center check
            /// \param any_card Can use any card
            /// \return Player
            Player& _discover_cure(Color c, int cards_needed, bool enforce_needed_city_research_center, bool any_card);
            void ensure_not_travel_cities_differ(City target_city) const;
            void remove_cards_by_set(const std::set<City> &cards);

        public:
            Player(Board &b, City c);

            virtual void build();

            /// Drive to a nearby City.
            /// \param c City
            /// \return Player
            Player& drive(City c);

            Player& take_card(City c);

            /// Fly directly while throwing a card.
            /// \param c City
            /// \return Player
            virtual Player& fly_direct(City c);

            /// Fly directly, throw current city card.
            /// \param c City
            /// \return Player
            Player& fly_charter(City c);

            /// Fly directly while having a research center.
            /// \param c City
            /// \return Player
            Player& fly_shuttle(City c);

            virtual Player& treat(City c);

            virtual Player& discover_cure(Color c);

            static std::string role();

            City get_location() const;

            bool has_card(City c) const;
    };
}

#endif //PANDEMIC_A_BASEPLAYER_HPP
