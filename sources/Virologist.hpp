//
// Created by Yuri Grigorian on 05/05/2021.
//

#ifndef PANDEMIC_A_VIROLOGIST_HPP
#define PANDEMIC_A_VIROLOGIST_HPP


#include "Player.hpp"


namespace pandemic {
    class Virologist : public Player {
        public:
            using Player::Player;
            /// Can treat any city as long has a card.
            /// \param c City
            /// \return Player
            Player & treat(City c) override;
            static std::string role();
    };
}



#endif //PANDEMIC_A_VIROLOGIST_HPP
