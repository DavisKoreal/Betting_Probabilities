#include "main.hpp"
using namespace std;

    t_eam::t_eam()
    {
        team_name = "Draw Match ";
        odd = 2.34;
    }   

    t_eam::t_eam(string Team, double Odd)
    {
        team_name = Team;
        odd = Odd;
        team_wins = Team +" wins  ";
    }  