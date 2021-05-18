//
// Created by Yuri Grigorian on 18/05/2021.
//

#ifndef PANDEMIC_B_COLORINFO_HPP
#define PANDEMIC_B_COLORINFO_HPP
#include "Color.hpp"

namespace pandemic{
    struct ColorInfo {
        Color color;
        bool has_cure;

        ColorInfo(Color _c): color(_c), has_cure(false){};
    };

}



#endif //PANDEMIC_B_COLORINFO_HPP
