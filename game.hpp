#ifndef GAME_HPP
#define GAME_HPP
#include <map>
#include "t_eam.hpp"
using namespace std;
class game
{
    public:
        map<int, t_eam> game_information;

    game(t_eam home, t_eam draw, t_eam away);

};

#endif