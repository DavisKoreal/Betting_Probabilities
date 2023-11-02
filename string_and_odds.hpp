#ifndef STRING_AND_ODDS_HPP
#define STRING_AND_ODDS_HPP

#include <string>
#include <vector>
using namespace std;

class string_and_odds
{
public:
    string games_outcomes_sentence;
    vector<double> games_outcomes_odds;
    double total_odds;
    double relative_probability;

    string_and_odds(string sentence, vector<double> odds);

};


#endif 