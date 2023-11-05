#include "main.hpp"
using namespace std;

int main()
{
    /**
     * Get A list of todays games with their odds
     * **/ 

    vector<game> TodaysGames;
    vector<string> homenames;
    vector<double> homeodds;
    vector<string> awaynames;
    vector<double> awayodds;
    vector<double> drawodds ;

    cout << "Please enter a list of five teams that are playing home today " << endl;
    int i = 0;
    while(i<5)
    {
        string homename;
        getline(cin, homename);
        homenames.push_back(homename);
    }

    cout << "Please enter a list of five teams that are playing away today " << endl;
    i = 0;
    while(i<5)
    {
        string awayname;
        getline(cin, awayname);
        awaynames.push_back(awayname);
    }

    cout << "Please enter a list of five odds for the home teams " << endl;
    i = 0;
    while(i<5)
    {
        double homeodd;
        cin>> homeodd;
        homeodds.push_back(homeodd);
    }

    cout << "Please enter a list of five odds for the away teams " << endl;
    i = 0;
    while(i<5)
    {
        double awayodd;
        cin>> awayodd;
        awayodds.push_back(awayodd);
    }

    cout << "Please enter a list of five odds for the draw teams " << endl;
    i = 0;
    while(i<5)
    {
        double drawodd;
        cin>> drawodd;
        drawodds.push_back(drawodd);
    }



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