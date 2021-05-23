//
// Created by Yuri Grigorian on 18/05/2021.
//

#ifndef PANDEMIC_B_COLORINFO_HPP
#define PANDEMIC_B_COLORINFO_HPP
#include "Color.hpp"
#include "string"

namespace pandemic{
    struct ColorInfo {
        std::string name;
        Color color;
        bool has_cure;

        ColorInfo(std::string _name, Color _c): name(_name), color(_c), has_cure(false){};
    };

}



#endif //PANDEMIC_B_COLORINFO_HPP
