#include "ClueGame.h"


int main()
{
	srand(unsigned(time(NULL)));
	start();
	cout << endl << (_CrtDumpMemoryLeaks() ? "There Are " : "No ") << "Memory Leaks!\n";
	return 0;
}


//Library menu
//Start a new game/Load game/Show statistics/Exit
//create murder envelope
//Mix and deal cards to players
void start()
{
	while (true)
	{
		Statistics stat;
		int p_num = -1;
		char in = '@';
		cout << "GAME Menu\nSelect Option:\n1.Start a new game\n2.Load game\n3.Show statistics\n4.Exit\n";
		while(in != '1' && in != '2' && in != '3' && in != '4')cin >> in;
		MurderEnvelope envelope(in);
		if (in == '1')
			num_of_players(p_num);
		Board board;
		CardsPack pack(envelope, p_num, in);
		if (in == '1')
		{
			stat.player_count = p_num;				//number of player
			int chr[NUM_OF_CHARACTERS+1] = { 0,0,0,0,0,0,1 };
			deque<Player*> idxvdeque;
			deque<Player*>::iterator it;
			char c;
			int p;
			for (int i = 0; i < p_num; i++)
			{
				select_character(chr, NUM_OF_CHARACTERS, i);
				do
				{
					cin >> c;
					p = char_to_int(c);
				} while (chr[p]);
				chr[p] = 1;
				stat.player_chosen[p]++;	//what player char has been chosen
				idxvdeque.push_back(new Player(c, start_position(c), pack.get_pack(i)));
			}
			random_shuffle(idxvdeque.begin(), idxvdeque.end());	//determines the order of players randomly
			for (it = idxvdeque.begin(); it < idxvdeque.end(); it++)
				board.insert_player(*it);
		}
		else if (in == '2')
			load_game(board, envelope);
		else if (in == '3')
		{
			calculate_stats();
			continue;
		}
		else return;
		game(board, envelope, p_num, stat);
		envelope.empty_envelope();
	}
	
}

void select_character(int chr[], int n, int idx)
{
	cout << "Player " << idx + 1 << " select character:\n";
	string s[] = { "S = Miss Scarlet\n", "P = Mrs Peacock\n", "M = Col Mustard\n", "G = Mr Green\n", "R = Prof Plum\n", "O = Dr Orchid\n" };
	for (int i = 0; i < n; i++) {
		if (chr[i] == 0)
			cout << s[i];
	}

}

//start the game
void game(Board& board, MurderEnvelope& envelope, int& p_num, Statistics& stat)
{
	p_num = board.get_players_cnt();
	board.print_board();
	while (board.check_losers())
	{
		for (int i = 0; i < p_num; i++)
		{
			if (board.get_player(i).get_status() == false)continue;	//if player lost he cant play but stay in the game and reveal cards
			cout << board.get_player(i).get_player_cr() << " it is your turn!\n";
			if (board.room_option(i))continue;					//if secret pass used the turn end
			if (board.get_player(i).select_move(envelope) && board.get_player(i).get_status())    
			{
				stat.player_wined[i]++;					//player win
				stat.save();
				return;
			}
			if (!board.get_player(i).get_status())
			{
				stat.player_wrong_acc[i]++;				//player wrong asuume
				continue;
			}
			int dice = board.get_player(i).use_dice().get_dice();
			stat.player_throw_dice[i]++;								//statistics player throw dice
			stat.player_sum_throw[i] += dice;							//statistics player sum throw								
			bool flag = board.move_player(i);							//move players
			if (flag)													//if player enter a room
			{
				stat.room_visits[board.get_player_room(i) - 6]++;		//statistics room visitied
				if (!board.room_options(i))
				{
					board.get_player(i).get_ev_book().show_evidence();	 //show evidence book
					board.suggest(i);									 //suggest
					cout << board.get_player(i).get_player_cr() << " Do you want to accuse ? (Y/N)\n";
					if (check_y_n())									 
					{
						if (board.get_player(i).accuse(envelope))		//accuse
						{
							stat.player_wined[i]++;					   //player win
							stat.save();
							return;
						}
						else stat.player_wrong_acc[i]++;
					}	
				}
				else
				{
					stat.Player_Secret_Passage[i]++;						//statistics player use secret passage
					stat.room_visits[board.get_player_room(i) - 6]++;		//statistics room visitied
				}	
			}
			board.print_board();
		}
		save_game(board, envelope);									 //save game
		if (game_exit())
		{
			stat.save();
			stat.games_stoped++;
			return;
		}
	}
	stat.save();
	cout << "GAME OVER !! All Players guessed wrong, the murder mystery was not solved\n\n";
}

//check if player want to exit from the game
bool game_exit()
{
	cout << "Exit And Save Game ? (Y/N) ";
	char c;
	cin >> c;
	bool cond = (c != 'Y'&& c != 'y' && c != 'N' && c != 'n');
	while ((!cin.good()) || (cond))
	{
		cout << "ERROR input! Try again...\n";
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cin >> c;
		cond = (c != 'Y'&& c != 'y' && c != 'N' && c != 'n');
	}
	if (c == 'Y' || c == 'y')
	{
		system("CLS");
		return true;
	}	
	return false;	
}

//checks input
bool check_y_n()
{
	char s;
	cin >> s;
	while (s != 'Y'&& s != 'y' && s != 'N' && s != 'n')
	{
		cout << "ERROR input! Try again...\n";
		cin >> s;
	}
	if (s == 'Y' || s == 'y')
		return true;
	return false;
}

//load game
void load_game(Board& board, MurderEnvelope& envelope)
{
	try {
		ifstream data;
		data.open("data.txt", ios::in);
		if (!data.is_open())			   //if file error exit
		{
			cout << "File Error! Unable to load data !\n";
			exit(EXIT_FAILURE);
		}
			
		data >> envelope >> board;
		data.exceptions(ios::badbit|ios::failbit);
		data.close();
		cout << "\n File uploaded successfully !\n";
	}
	catch (exception x)
	{
		cout << "File Error! Unable to load data !\n";
	}
}

//save game
void save_game(Board& board, MurderEnvelope& envelope)
{
	try {
		ofstream data;
		data.open("data.txt", ios::out);
		data << envelope << board;
		data.close();
	}
	catch (exception x)
	{
		cout << "File Error! \n";
	}
}

//checks number of players
void num_of_players(int& p_num)
{
	cout << "Enter number of players Between 3 to 6:\n";
	cin >> p_num;
	bool cond = (p_num >= 3 && p_num <= 6);
	while ((!cin.good()) || (!cond))
	{
		cout << "ERROR input! Try again...\n";
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cin >> p_num;
		cond = (p_num >= 3 && p_num <= 6);
	}
}

//player char to int
int char_to_int(char& c)
{
	if (c == 'S' || c == 's')
	{
		c = 'S';
		return 0;
	}
	else if (c == 'P' || c == 'p')
	{
		c = 'P';
		return 1;
	}
	else if (c == 'M' || c == 'm')
	{
		c = 'M';
		return 2;
	}
	else if (c == 'G' || c == 'g')
	{
		c = 'G';
		return 3;
	}
	else if (c == 'R' || c == 'r')
	{
		c = 'R';
		return 4;
	}
	else if (c == 'O' || c == 'o')
	{
		c = 'O';
		return 5;
	}
	return 6;
}

//player start position on board according to character
Point start_position(char c)
{
	if (c == 'S')
		return Point(0, 22);
	else if (c == 'P')
		return Point(0, 58);
	else if (c == 'M')
		return Point(17, 82);
	else if (c == 'G')
		return Point(24, 62);
	else if (c == 'R')
		return Point(24, 26);
	else
		return Point(18, 2);
}