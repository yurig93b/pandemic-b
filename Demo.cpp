/**
 * Demo program for Pandemic exercise - OperationsExpert role
 * 
 * Author: Erel Segal-Halevi
 * Since : 2021-04
 */

#include "sources/Board.hpp"
#include "sources/City.hpp"
#include "sources/Color.hpp"

#include "sources/OperationsExpert.hpp"

using namespace pandemic;

#include <iostream>
#include <stdexcept>
#include "sources/Medic.hpp"
#include "sources/OperationsExpert.hpp"
#include "sources/City.hpp"
#include "sources/Scientist.hpp"

using namespace std;

#define CURRENT_BOARD_STATUS "Current board status \n"
int main() {
	Board board;  // Initialize an empty board (with 0 disease cubes in any city).
	Medic m(board, Seoul);
    OperationsExpert op(board, Tokyo);
    Scientist s(board, op.get_location(), 1);

    std::cout << CURRENT_BOARD_STATUS;
	std::cout << board << std::endl;

    std::cout << "OperationsExpert is in " << board.get_city_info(op.get_location()).name << " and builds there.\n";
    op.build();

    std::cout << "Scientist gets 1 card for "<< board.get_city_info(op.get_location()).name << " and discovers a cure there.\n";
    s.take_card(s.get_location());
    s.discover_cure(board.get_city_info(s.get_location()).color);

    std::cout << board.get_city_info(op.get_location()).name << " is very ill.\n";
    board[op.get_location()] = 99999999;

    std::cout << CURRENT_BOARD_STATUS;
    std::cout << board << std::endl;

    std::cout << "Medic gets a card to " << board.get_city_info(op.get_location()).name <<  " and flies there directly.\n";
    m.take_card(op.get_location());
    m.fly_direct(op.get_location());

    std::cout << CURRENT_BOARD_STATUS;
    std::cout << board << std::endl;
    std::cout << board.get_city_info(op.get_location()).name << " was healed in a joint operation.\n" << std::endl;
}

