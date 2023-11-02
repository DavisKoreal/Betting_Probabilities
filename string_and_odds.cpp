#include "string_and_odds.hpp"

using namespace std;

string_and_odds::string_and_odds(string sentence, vector<double> odds)
{
    games_outcomes_sentence = sentence;
    games_outcomes_odds = odds;
    double x = 1;
    for(auto i: odds)
    {
        x *= i;
    }
    total_odds = x;
    relative_probability = 1/total_odds;
}