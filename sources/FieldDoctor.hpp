//
// Created by Yuri Grigorian on 05/05/2021.
//

#ifndef PANDEMIC_A_FIELDDOCTOR_HPP
#define PANDEMIC_A_FIELDDOCTOR_HPP


#include "Player.hpp"

namespace pandemic {
    class FieldDoctor : public Player {
        public:
            using Player::Player;
            /// Can treat adjacent cities too.
            /// \param c City
            /// \return Player
            Player & treat(City c) override;
            static std::string role();
    };
}

#endif //PANDEMIC_A_FIELDDOCTOR_HPP
