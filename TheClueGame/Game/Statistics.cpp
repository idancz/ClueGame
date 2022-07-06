#include "Statistics.h"


void Statistics::save() {	
	ofstream f;
	f.open("statistics.txt", ios::app); //append mode
	f << " " << player_count;
	f << " " << player_wined << player_wrong_acc << player_chosen << room_visits << Player_Secret_Passage;
	f << " " << player_throw_dice << player_sum_throw;
	f << " " << games_stoped << endl;
	f.close();
}

void Statistics::load() {
	ifstream f;
	f.open("statistics.txt");
	f >> *this;
	f.close();
}


ifstream & operator>>(ifstream & f, Statistics & p)
{
	int i;
	f >> p.player_count;
	for (i = 0; i < 6; i++)
		f >> p.player_wined[i];
	for (i = 0; i < 6; i++)
		f >> p.player_wrong_acc[i];
	for (i = 0; i < 6; i++)
		f >> p.player_chosen[i];
	for (i = 0; i < 9; i++)
		f >> p.room_visits[i];
	for (i = 0; i < 6; i++)
		f >> p.Player_Secret_Passage[i];
	for (i = 0; i < 6; i++)
		f >> p.player_throw_dice[i];
	for (i = 0; i < 6; i++)
		f >> p.player_sum_throw[i];
	f >> p.games_stoped;
	return f;

}


void calculate_stats()
{
	vector<Statistics> games;
	ifstream f;
	f.open("statistics.txt");
	__int64 lines = count(istreambuf_iterator<char>(f), istreambuf_iterator<char>(), '\n');
	f.seekg(ios_base::beg);
	for (int i = 0; i < lines; i++)
	{
		Statistics temp;
		f >> temp;
		games.push_back(temp);
	}

	Arr<int, 4> sum_player_count;
	Arr<int, 6> sum_player_chosen;
	Arr<int, 6> sum_player_wrong_acc;
	Arr<int, 6> sum_player_wined;
	Arr<int, 9> sum_room_visits;
	Arr<int, 6> sum_Player_Secret_Passage;
	Arr<int, 6> sum_player_throw_dice;
	Arr<int, 6> sum_player_sum_throw;
	int sum_games_stoped = 0;
	int avg_player_count = 0;

	cout << "until now " << games.size() << " games were played.\n";

	for (int i = 0; i < (int)games.size(); i++)
	{
		sum_player_count[games[i].get_player_count() - 3]++;
		sum_games_stoped += games[i].get_games_stoped();

	}
	for (int j = 0; j < 6; j++)
	{
		for (int i = 0; i < (int)games.size(); i++)
		{
			sum_player_chosen[j] += games[i].get_player_chosen()[j];				//player chosen at all games
			sum_player_wrong_acc[j] += games[i].get_player_wrong_acc()[j];			//player wrong assume at all games
			sum_player_wined[j] += games[i].get_player_wined()[j];					//player win at all games
			sum_Player_Secret_Passage[j] += games[i].get_Secret_Passage()[j];		// player uses secret pass at all games
			sum_player_throw_dice[j] += games[i].get_player_throw_dice()[j];		//times of throw dice at all games
			sum_player_sum_throw[j] += games[i].get_player_sum_throw()[j];			//sum throw at all games
		}
	}
	for (int j = 0; j < 9; j++)
	{
		for (int i = 0; i < (int)games.size(); i++)
		{
			sum_room_visits[j] += games[i].get_room_visits()[j];					//sum of all room visited at all games
		}

	}

	cout << "until now " << sum_games_stoped << " games stopped.\n";

	for (int i = 0; i < 4; i++)
	{
		if (sum_player_count[i] > 0)												//print  how much player play statistics at all games
		{
			cout << sum_player_count[i] << " games was played by " << i + 3 << " players.\n";
			avg_player_count = (sum_player_count[i] * (i + 3));
		}
	}
	if(games.size() > 0)
		avg_player_count = avg_player_count / games.size();								//average player counter at all games
	cout << "average number of players at all games: " << avg_player_count << endl;

	string c[6] = { "MissScarlet","MrsPeacock","ColMustard","MrGreen","ProfPlum","DrOrchid" };
	for (int j = 0; j < 6; j++)
	{
		cout << "Player " << c[j] << " use secret pass " << sum_Player_Secret_Passage[j] << " times ," << "chosen " << sum_player_chosen[j] << " games, wrong accusation " << sum_player_wrong_acc[j] << " games, win " << sum_player_wined[j] << " games.\n";
		cout << "Throw dice " << sum_player_throw_dice[j] << " times, sum of throws " << sum_player_sum_throw[j] << endl;
	}//print each player statistics at all games
	string st[9] = { "hall" , "study" ,"lounge" ,"dinning" ,"kitchen" ,"ball" ,"conservatory" ,"billiard" ,"Library" };
	for (int j = 0; j < 9; j++)	//print room statistics at all games
		cout << "Room " << st[j] << " visited " << sum_room_visits[j] << " times.\n";

	cout << "\n\nPress any key to return the menu...\n";
	char press;
	cin >> press;
	system("CLS");
}
