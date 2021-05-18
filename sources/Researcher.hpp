//
// Created by Yuri Grigorian on 05/05/2021.
//

#ifndef PANDEMIC_A_RESEARCHER_HPP
#define PANDEMIC_A_RESEARCHER_HPP

#include "Player.hpp"

namespace pandemic{
    class Researcher: public Player{
        public:
            using Player::Player;
            /// Can discover cure in any city.
            /// \param c Color
            /// \return Player
            Player & discover_cure(Color c) override;
            static std::string role();

    };
}

#endif //PANDEMIC_A_RESEARCHER_HPP
