//
// Created by Yuri Grigorian on 05/05/2021.
//

#ifndef PANDEMIC_A_MEDIC_HPP
#define PANDEMIC_A_MEDIC_HPP

#include "Player.hpp"

namespace pandemic{
    class Medic: public Player{
        protected:
            /// Auto treat cities after change.
            /// \param c City
            /// \return true if city changed else false
            bool change_city(City c) override;
        public:
            using Player::Player;
            /// On treat reduces disease to 0.
            /// \param c City
            /// \return Player
            Player & treat(City c) override;
            static std::string role();

    };
}
#endif //PANDEMIC_A_MEDIC_HPP
