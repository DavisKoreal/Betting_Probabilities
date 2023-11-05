#include "main.hpp"
#include "string_and_odds.hpp"

using namespace std;

    /**
    initializes te multibet with a vector 
    containing 5 instances of the class game
    **/
    multibet::multibet(vector<game> todaysgames)
    {
        games = todaysgames;
    }

    /**
     * This is the function for adding one when finding the 
     * various combinations for base 3 with 5 locations
     * **/
    void multibet::addone(vector<int> &sequence)
    {
        bool additionsuccess = false;
        for(int i = 4; (i >=0) && (additionsuccess == false); i--)
        {
            if(sequence[i] < 2)
            {
                sequence[i] +=1;
                additionsuccess = true;
            }
            else
            {
                sequence[i] = 0;
            }
        }
    }


    /**
     * @brief Get the combinations object
     * Store the trinary comninations in the combinations object
     * 
     * @return ** void 
     */
    void multibet::get_combinations()
    {

        vector<int> sequence = {0,0,0,0,0};
        combinations.push_back(sequence);
        while(sequence[0]<3)
        {
            addone(sequence);
            combinations.push_back(sequence);
            if((sequence[0] == 2) && (sequence[1]==2) && (sequence[2]==2)&& (sequence[3]==2) && (sequence[4]==2))
            {
                break;
            }
        }
        cout<<"All the combinations have been stored in a vector of size " << combinations.size() << endl;
        for(auto sequencee:combinations)
        {
            for(auto i : sequencee)
            {
                cout << i;
            }
            cout << endl;
        }    
    }

    /**
     * Map the combinations object into a string of human readable 
     * sentences that will be displayed on the terminal/screen
     * **/
    void multibet::get_sequence_combinations()
    {
        cout << "I am now mapping the combinations to string phrases that are readable to you. " << endl;
        
        for(auto i:combinations)
        {
            //cout << "The vector here is of size "<< i.size() << endl;
            string sequence;
            vector<double> odds;
            int k =0;
            for(auto j: i)
            {
                odds.push_back(games[k].game_information[j].odd);
                string addand = games[k].game_information[j].team_wins;
                //cout << "the addand is " << addand<< endl;
                sequence += addand;
               k++;
            }
            cout << "\n FULL COMBINATION : ";
            cout << sequence;
            cout<< "\n\n";
            string_and_odds temp = string_and_odds(sequence, odds);
            sequence_combinations.push_back(temp);
        }

        cout << "\n I am now outputting the sequences. Please be patient. \n";

        for(auto i:sequence_combinations)
        {
            //cout << "\n\nThe sequence is " << i.games_outcomes_sentence << endl;
            //cout << "The odds are ";
            for(auto j:i.games_outcomes_odds)
            {
                cout << j << " ";
            }
            /**
            cout << endl;
            cout << "The total odds are " << i.total_odds << endl;
            cout << "The relative probability is " << i.relative_probability << endl;
            cout << endl;
            **/
        }

    }

    /**
     * Rank the most probable events and their probabilities
     * **/
    void multibet::get_most_probable_events()
    {
        cout<< "I am now getting the most probable events. Please wait. " << endl;
        map<double, string> ranking;
        for(auto i:sequence_combinations)
        {
            ranking[i.relative_probability] = i.games_outcomes_sentence;
        }
        cout << "The size of the ranking is " << ranking.size() << endl;
        cout << "OUTPUTTING THE RANKING " << endl;
        for(auto i:ranking)
        {
            cout << "The probability is " << i.first << " and the event is " << i.second << endl;
        }
    }