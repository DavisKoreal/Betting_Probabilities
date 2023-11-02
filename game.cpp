#include "modules.hpp"

using namespace std;


    game::game(t_eam home, t_eam draw, t_eam away)
    {
        game_information[0] = home;
        game_information[1] = draw;
        game_information[2] = away;
    }
