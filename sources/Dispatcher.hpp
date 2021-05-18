//
// Created by Yuri Grigorian on 05/05/2021.
//

#ifndef PANDEMIC_A_DISPATCHER_HPP
#define PANDEMIC_A_DISPATCHER_HPP

#include "Player.hpp"

namespace pandemic{
    class Dispatcher: public Player{
        public:
            using Player::Player;
            /// When in research center, can fly anywhere he wants.
            /// \param c City
            /// \return Player
            Player & fly_direct(City c) override;
            static std::string role();
    };
}
#endif //PANDEMIC_A_DISPATCHER_HPP
