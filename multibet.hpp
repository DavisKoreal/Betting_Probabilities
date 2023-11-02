#ifndef MULTIBET_HPP
#define MULTIBET_HPP
#include "modules.hpp"
#include "string_and_odds.hpp"

using namespace std;

class multibet
{
    /**
     * @games: a vector that stores 5 instances of class game.
     * @combinations: a vector that stores the various combinations of 
     *              an event with 3 possible outcomes and 5 different happenings
     * @sequence_combinations: maps the combinations vector into a vector of strings
     *              that is human readable
     * @most_probable_events: maps probabilities to the sequence_combinations string vector
     * **/
    public:
        vector<game> games;
        vector<vector<int>> combinations;
        vector<string_and_odds> sequence_combinations;
        map<double, vector<string>> most_probable_events;

        void get_combinations();
        void get_sequence_combinations();
        void addone(vector<int> & sequence);
        multibet(vector<game> today_games);
        void get_most_probable_events();

};

#endif