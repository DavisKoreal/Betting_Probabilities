#ifndef T_EAM_HPP
#define T_EAM_HPP
#include <string>
using namespace std;

class t_eam
{
    public:
        string team_name;
        string team_wins;
        double odd;

    t_eam();  
    t_eam(string Team, double Odd);  
};

#endif