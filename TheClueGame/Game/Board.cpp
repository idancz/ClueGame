#include "Board.h"

//distructor
Board::~Board()
{
	for (int i = 0; i < m_players_cnt; i++)
	{
		for (int j = 0; j < m_players[i]->get_cards_cnt(); j++)
		{
			delete m_players[i]->get_cards()[j];
		}
		delete m_players[i];
	}
	delete[]m_players;
}

//insert player to array of player pointers
void Board::insert_player(Player* p)
{
	if (!m_players_cnt)
		m_players = new Player*;							//if the Player array ampty
	else
	{
		Player** temp = new Player*[m_players_cnt];			//create temp player array
		for (int i = 0; i < m_players_cnt; i++)
			temp[i] = m_players[i];							//save players in temp array
		delete[] m_players;									//delete players
		m_players = new Player*[m_players_cnt + 1];			//create larger new players array 
		for (int i = 0; i < m_players_cnt; i++)
			m_players[i] = temp[i];							//copy back from temp to new players array
		delete[] temp;
	}
	m_players[m_players_cnt++] = p;							//insert new player 
	set_player();
}

//set player on board
void Board::set_player()
{
	for (int i = 0; i < m_players_cnt; i++)
	{
		int row = m_players[i]->get_position().get_x();
		int col = m_players[i]->get_position().get_y();
		m_board[row][col] = m_players[i]->get_player_cr();
	}
}

//transfer player from current position to new provided position
void Board::transfer_player(int idx, Point p)
{
	int row = m_players[idx]->get_position().get_x();
	int col = m_players[idx]->get_position().get_y();
	if(m_board[row][col-3] == ' '|| m_board[row][col + 3] == ' ')
		m_board[row][col] = ' ';
	else													//if inside a room doesn't mark '_'
		m_board[row][col] = '_';
	m_players[idx]->get_position() = p;
	row = m_players[idx]->get_position().get_x();
	col = m_players[idx]->get_position().get_y();
	m_board[row][col] = m_players[idx]->get_player_cr();	//mark on board player char
}

//moves players on board
//check steps validity
//check if player inside romm alredy
//allows you to move with keys in different directions
bool Board::move_player(int idx)
{
	int length = m_players[idx]->use_dice().get_dice();			//player steps amount on board
	for (int i = 0; i < length; i++)
	{
		m_players[idx]->m_flag = true;
		char c;
		cout << "Select movement direction:\nW = up\nS = down\nD = right\nA = left\n";
		cin >> c;
		if (!check_dest(c, idx))							  //check if the step valid
		{
			i--;
			continue;
		}
		char symb = m_players[idx]->get_player_cr();
		int row = m_players[idx]->get_position().get_x();
		int col = m_players[idx]->get_position().get_y();
		m_board[row][col] = '_';
		//move player on board
		if (c == 'w' || c == 'W') {												//move up
			m_players[idx]->get_position().dec_m_x();
			row = m_players[idx]->get_position().get_x();
		}
		else if (c == 's' || c == 'S') {											   //move down
			m_players[idx]->get_position().inc_m_x();
			row = m_players[idx]->get_position().get_x();
		}
		else if (c == 'a' || c == 'A') {											   //move left
			for (int i = 0; i < 4; i++)
				m_players[idx]->get_position().dec_m_y();
			col = m_players[idx]->get_position().get_y();
		}
		else if (c == 'd' || c == 'D') {											   //move right
			for (int i = 0; i < 4; i++)
				m_players[idx]->get_position().inc_m_y();
			col = m_players[idx]->get_position().get_y();
		}
	
		m_board[row][col] = symb;							   //mark player char on board
		print_board();
		Point check = m_players[idx]->get_position();
		if (m_players[idx]->m_flag)
		{
			if (check_entrance(check))						  //checks if player arrive to room entrance
			{
				Point p = m_rooms.enter_to_room(m_players[idx]->get_position(), m_players[idx]->get_player_cr());
				transfer_player(idx, p);					 //transfer player from current position to new position
				print_board();								 //print board
				m_players[idx]->m_flag = false;				 //flag that says that player is in room
				return true;
			}
		}
		print_left_steps(length - i,idx);					//print remaining steps
	}
	return false;
}

//exit from room
//make a suggestion
bool Board::room_option(int idx)
{
	Point temp1 = m_players[idx]->get_position();
	Point temp2 =  m_rooms.search_room(m_players[idx]->get_position(), m_players[idx]->get_player_cr());	//checks if player inside a	 room
	if (temp1 == temp2)
		return false;
	cout << "Select option:\n1.Suggest\n2.Exit the room\n";
	char c = '@';
	while(c!='1' && c!='2')
		cin >> c;
	if (c == '1')
	{
		m_players[idx]->get_ev_book().show_evidence();
		suggest(idx);														
		return true;
	}	
	else
		transfer_player(idx, temp2);
	print_board();
	return false;
}

//print player remaining steps on board 
void Board::print_left_steps(int length, int idx)
{
	cout << "Player " << m_players[idx]->get_player_cr() <<" Number of remaining steps: " << length-1 << endl;
}

//print board
void Board::print_board()const
{
	system("CLS");
	for (int i = 0; i < 25; i++)
	{
		cout << m_board[i] << endl;
	}
}

//checking whether the next step would be valid 
bool Board::check_dest(char c, int idx)
{
	int row = m_players[idx]->get_position().get_x();
	int col = m_players[idx]->get_position().get_y();
	switch (c)
	{
	case 'w':
		row--;
		break;
	case 'W':
		row--;
		break;
	case 's':
		row++;
		break;
	case 'S':
		row++;
		break;
	case 'a':
		col -= 4;
		break;
	case 'A':
		col -= 4;
		break;
	case 'd':
		col += 4;
		break;
	case 'D':
		col += 4;
		break;
	default:
		break;
	}
	if (row < 0 || row > 24 || col < 0 || col > 84)			 //checks borders of the board
	{
		cout << "Out of Board !" << endl;
		return false;
	}
	char temp = m_board[row][col];							 
	if(temp == '#')											 //checks walls
	{ 
		cout << "It is a wall !" << endl;
		return false;
	}
	else if (temp == ' ')									 //blocking unplanned entrance to rooms
	{
		cout << "You must go out first !" << endl;
		return false;
	}														 //checks if another player took the place
	else if (temp == 'S' || temp == 'P' || temp == 'M' || temp == 'G' || temp == 'R' || temp == 'O')
	{
		cout << "You cant go there !" << endl;
		return false;
	}
	return true;
}

void Board::print_error()const
{
	cout << "You can not step twice in the same place !" << endl;
}

//checks if player enter to room
bool Board::check_entrance(Point p)
{
	for (int i = 0; i < 10; i++)
	{
		if (p == m_room_entrances[i])
			return true;
	}
	return false;
}

//return specific player
Player& Board::get_player(int idx)
{
	return *m_players[idx];
}

//make suggestion
//passes on all players and check if they have the accusation cards
//if some player have more then one cerd allowing him to chose which card reveal
//marks evidence at player EvidenceBook
void Board::suggest(int idx)
{
	int num1 = -1, num2 = -1;
	cout << "Who do you think committed the murder ?\nEnter the appropriate number:\n"
		"0.Miss Scarlet  1.Mrs Peacock  2.Col Mustard  3.Mr Green  4.Prof Plum  5.Dr Orchid\n";
	check_inputs(num1);
	cards c1 = m_players[idx]->num_to_cards(num1, 1);							//character card
	cout << "With what weapon the murder was committed ?\nEnter the appropriate number:\n"
		"0.Candl Stick  1.Knife  2.Lead Pipe  3.Gun  4.Rope  5.Pipe Wrench\n";
	check_inputs(num2);
	cards c2 = m_players[idx]->num_to_cards(num2, 3);							//weapon card
	cards r = where_am_I(m_players[idx]->get_position());						//room card
	for (int i = 0; i < m_players_cnt; i++)
	{
		vector<cards> card;
		int ev_cnt = 0;												//not checking player card who makes the suggestion
		if (i == idx)
			continue;
		if (search_evidence(*m_players[i], c1))
		{
			ev_cnt++;
			card.push_back(c1);
		}
		if (search_evidence(*m_players[i], c2))
		{
			ev_cnt++;
			card.push_back(c2);
		}
		if (search_evidence(*m_players[i], r))
		{
			ev_cnt++;
			card.push_back(r);
		}
		if (ev_cnt >= 1)
		{
			int choice = 0;														
			if (ev_cnt >= 2)										//if there is more then one suggestion card in a player
			{
				cout << "Player " << m_players[i]->get_player_cr() << " Select which card you want to reveal:\n";
				for (int j = 0; j < ev_cnt; j++)					//let the player decide which card he prefer to reveal
					cout << j << "." << card_to_str(card[j])<< "	";
				check_choice(choice, ev_cnt);
			}
			cout << "Player " << m_players[i]->get_player_cr() << " have a " << card_to_str(card[choice]) <<" !!\n\n";
			m_players[idx]->get_ev_book().mark_evidence(m_players[i]->get_player_cr(), card[choice], true);
			return;
		}
	}
	for (int i = 0; i < m_players_cnt; i++)							//If no player has any of suggestion cards
	{
		if (i == idx)
			continue;
		m_players[idx]->get_ev_book().mark_evidence(m_players[i]->get_player_cr(), c1, false);
		m_players[idx]->get_ev_book().mark_evidence(m_players[i]->get_player_cr(), c2, false);
		m_players[idx]->get_ev_book().mark_evidence(m_players[i]->get_player_cr(), r, false);
	}
	cout << "No one has the cards that you suggested !\n";
}

//check inputs
void Board::check_choice(int& choice, int ev_cnt)
{
	cin >> choice;
	bool cond = (choice >= 0 && choice < ev_cnt);
	while ((!cin.good())||(!cond))
	{
		cout << "ERROR input! Try again...\n";
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cin >> choice;
		cond = (choice >= 0 && choice < ev_cnt);
	}
}

//check if all player accused wrong and lost the game
bool Board::check_losers()
{
	for (int i = 0; i < m_players_cnt; i++)
	{
		if (m_players[i]->get_status())			//if all player lost the game
			return true;
	}
	return false;
}

//decode card to string
string Board::card_to_str(cards c)
{
	if (c == MissScarlet)
		return "Miss Scarlet";
	else if (c == MrsPeacock)
		return "Mrs Peacock";
	else if (c == ColMustard)
		return "Col Mustard";
	else if (c == MrGreen)
		return "Mr Green";
	else if (c == ProfPlum)
		return "Prof Plum";
	else if (c == DrOrchid)
		return "Dr Orchid";
	else if (c == hall)
		return "hall";
	else if (c == study)
		return "study";
	else if (c == lounge)
		return "lounge";
	else if (c == dinning)
		return "dinning";
	else if (c == kitchen)
		return "kitchen";
	else if (c == ball)
		return "ball";
	else if (c == conservatory)
		return "conservatory";
	else if (c == billiard)
		return "billiard";
	else if (c == Library)
		return "Library";
	else if (c == CandlStick)
		return "Candl Stick";
	else if (c == Knife)
		return "Knife";
	else if (c == LeadPipe)
		return "Lead Pipe";
	else if (c == Gun)
		return "Gun";
	else if (c == Rope)
		return "Rope";
	else if (c == PipeWrench)
		return "Pipe Wrench";
	return "?";
}

//search card in player cards pack
bool Board::search_evidence(Player p, cards c)
{
	bool flag = false;
	for (int i = 0; i < p.get_cards_cnt(); i++)
	{
		if (p.get_cards()[i]->who_am_I() == c)
			flag = true;
	}
	return flag;
}

//check inputs
void Board::check_inputs(int& num)
{
	cin >> num;
	bool cond = ((num <= 5) && (num >= 0));
	while ((!cin.good()) || (!cond))
	{
		cout << "ERROR input! Try again...\n";
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cin >> num;
		cond = ((num <= 5) && (num >= 0));
	}
}

//checks room secret passage
//transfer to suitable room
bool Board::room_options(int idx)
{
	Point loc = m_passage.check_Passage(m_players[idx]->get_player_cr(), m_players[idx]->get_position());
	if (m_players[idx]->get_position() == loc)
		return false;
	transfer_player(idx, loc);
	print_board();
	return true;
}

//return room type according to room entrance position
cards Board::where_am_I(Point p)
{
	if (p == Point(3, 14))
		return study;
	else if (p == Point(5, 38))
		return hall;
	else if (p == Point(4, 66))
		return lounge;
	else if (p == Point(10, 10))
		return Library;
	else if (p == Point(8, 70))
		return dinning;
	else if (p == Point(13, 6))
		return billiard;
	else if (p == Point(18, 38) || p == Point(18, 50))
		return ball;
	else if (p == Point(18, 74))
		return kitchen;
	else if (p == Point(20, 14))
		return conservatory;
	else
		return last_cardes;
}

//return number of platers
int Board::get_players_cnt()const
{
	return m_players_cnt;
}

//return the room where a player present
cards Board::get_player_room(int idx)
{
	return m_rooms.which_room_am_I(m_players[idx]->get_position(), m_players[idx]->get_player_cr());
}

//save data to file
ostream& operator<<(ostream& data, Board& board)
{
	data << board.get_player(0).get_player_counter()<<endl;
	for (int i = 0; i<board.get_player(0).get_player_counter(); i++)
		data << board.get_player(i);
	return data;
}

//load data from file
istream& operator>> (istream& data, Board& board)
{
	CardsPack pack;
	int p_num, card_num;
	char c;
	data >> p_num;										 //number of players
	for (int j = 0; j < p_num; j++)
	{
		data >> c >> card_num;							 //number of cards
		vector<Card*> cd;
		for (int i = 0; i < card_num; i++)
		{
			string str;
			data >> str;
			cd.push_back(pack.str_to_card(str));	   //decoding to cards from string
		}
		Point p;
		int stat;
		data >> p>> stat;
		Player* player = new Player(c, p, cd, stat);   //create players
		data >> *player;
		board.insert_player(player);				  //insert players to board
	}
	return data;
}