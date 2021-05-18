//
// Created by Yuri Grigorian on 05/05/2021.
//

#ifndef PANDEMIC_A_GENESPLICER_HPP
#define PANDEMIC_A_GENESPLICER_HPP


#include "Player.hpp"

namespace pandemic {
    class GeneSplicer : public Player {
        public:
            using Player::Player;
            /// Can discover cure with any 5 cards.
            /// \param c Color
            /// \return Player
            Player & discover_cure(Color c) override;
            static std::string role();

    };
}



#endif //PANDEMIC_A_GENESPLICER_HPP
