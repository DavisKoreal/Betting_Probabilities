#include "main.hpp"
using namespace std;

int main()
{
    /**
     * Get A list of todays games with their odds
     * **/ 

    vector<game> TodaysGames;
    vector<string> homenames = {"Canada", "chile", "queretaro", "llaneros", "central_cordoba"};
    vector<double> homeodds = {3.1, 2.95, 2.95, 1.49, 2.8};
    vector<string> awaynames = {"Brazil", "usau19", "chivas", "atletico", "santa_fe"};
    vector<double> awayodds = {2.29, 2.02, 2.33, 6.8, 2.8};
    vector<double> drawodds = {3.15, 3.5, 3.3, 3.7, 2.85};

    for(int i = 0; i < 5; i++)
    {
        cout << "Entering the teams for today... " << endl;
        t_eam away, home, draw;
        home.team_name = homenames[i];
        home.team_wins = homenames[i] + "_wins, ";
        home.odd = homeodds[i];

        away.team_name = awaynames[i];
        away.team_wins = awaynames[i] + "_wins, ";
        away.odd = awayodds[i];

        draw.team_name = "Draw Match";
        draw.team_wins = homenames[i]+awaynames[i]+"_Draw, ";
        draw.odd = drawodds[i];
        
        TodaysGames.push_back(game(home, draw, away));
    }

    cout << "The size of Todays Games is " << TodaysGames.size() << "\n";

    for(int i=0; i < 5; i++)
    {
        cout << "The " << i+1 << "th game is " << TodaysGames[i].game_information[0].team_name << " vs " << TodaysGames[i].game_information[2].team_name << endl;
        cout << "The odd for " << TodaysGames[i].game_information[0].team_name << " is " << TodaysGames[i].game_information[0].odd << endl;
        cout << "The odd for " << TodaysGames[i].game_information[1].team_name << " is " << TodaysGames[i].game_information[1].odd << endl;
        cout << "The odd for " << TodaysGames[i].game_information[2].team_name << " is " << TodaysGames[i].game_information[2].odd << endl <<endl;
    }
    
    /**
     * Instantiate the multibet 
     * **/
    
    multibet Multibet = multibet(TodaysGames);

    //get combinations
    Multibet.get_combinations();

    //map the combinations into human readable format
    Multibet.get_sequence_combinations();

    //get most probable events and output
    Multibet.get_most_probable_events();

    return (0);
}