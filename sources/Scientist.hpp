//
// Created by Yuri Grigorian on 05/05/2021.
//

#ifndef PANDEMIC_A_SCIENTIST_HPP
#define PANDEMIC_A_SCIENTIST_HPP


#include "Player.hpp"

namespace pandemic {
    class Scientist : public Player {
            int cards_needed;
        public:
            Scientist(Board &b, City c, int cards_needed);
            /// Can discover cure with n cards.
            /// \param c Color
            /// \return Player
            Player &discover_cure(Color c) override;
            static std::string role();

    };
}


#endif //PANDEMIC_A_SCIENTIST_HPP
