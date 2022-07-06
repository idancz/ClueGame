#include "Player.h"

//constructor 1
Player::Player(const char player, Point pos, vector<Card*> pack, bool status) : m_player_cr(player)
{
	m_cards = pack;
	++player_counter;
	m_position = pos;
	m_cards_cnt = pack.size();
	m_status = status;
	m_ev_book.insert_my_cards(pack, m_cards_cnt, player);
}

//constructor 2
Player::Player(char player, Point pos) :m_player_cr(player)
{
	++player_counter;
	m_cards_cnt = 0;
	m_position = pos;
	m_status = true;
}
 
//return player position
Point& Player::get_position()
{
	return m_position;
}

//return player char 
char Player::get_player_cr()const
{
	return m_player_cr;
}

//return number of players
int Player::get_player_counter()const
{
	return player_counter;
}

//prints all cards
void  Player::show_card()const
{
	for (int i = 0; i < m_cards_cnt; i++)
		m_cards[i]->show_card();
}

//return player position in room
Point Player::where_am_I()const
{
	return m_room;

}

//set room position
void Player::set_room(Point p)
{
	m_room = p;
}

//manage player moves on the board by select options:
//1.rool dice	2.make accusation	3.show evidence book
bool Player::select_move(MurderEnvelope envelope)
{
	while (true)
	{
		char num = '@';
		cout <<"Player "<< get_player_cr() << " Select move:\n1.Rool the dice\n2.Accuse\n3.Show evidence book\n";
		while (num >'3' || num <'1')
		{
			cin >> num;
		}
		if (num == '1')
		{
			m_dice.roll_the_dice();
			m_dice.print_dice();
			return false;
		}
		else if (num == '2')
		{
			if (accuse(envelope))
				return true;						//if murder solved true 
			return false;
		}
		else
		{
			m_ev_book.show_evidence();
			continue;
		}
	}
	return false;
}

//return Dice object
Dice& Player::use_dice()
{
	return m_dice;
}

//return player status (true = active/false = lost)
bool Player::get_status()const
{
	return m_status;
}

//make accusation
//check if the accused cards in the murder envalope
// announce on winning and losses
bool Player::accuse(MurderEnvelope envelope)
{
	cout << "Who do you want to accuse?\n"
		"0.Miss Scarlet  1.Mrs Peacock  2.Col Mustard  3.Mr Green  4.Prof Plum  5.Dr Orchid\n";
	int c = check_inputs(5);
	cout << "In what room did the murder occur?\n"
		"0.hall  1.study  2.lounge  3.dinning  4.kitchen  5.ball  6.conservatory  7.billiard  8.Library\n";
	int r = check_inputs (8);
	cout << "With what weapon?\n"
		"0.Candl Stick  1.Knife  2.Lead Pipe  3.Gun  4.Rope  5.Pipe Wrench\n";
	int w = check_inputs(5);
																								
	cards W = num_to_cards(w, 3);																//decode selected option to card
	cards R = num_to_cards(r, 2);				
	cards C = num_to_cards(c, 1);
	if (envelope.search_inside(W) && envelope.search_inside(R) && envelope.search_inside(C))	//check if the accusation is true 
	{
		cout << "You solved the murder "<< m_player_cr <<" you are the winner !!\n";
		return true;
	}
	m_status = false;
	cout << "Incorrect accusation " << m_player_cr << " you lost !!\n";
	Sleep(1500);
	return false;
}

//check if input valid
int Player::check_inputs(int len)
{
	int num;
	cin >> num;
	bool cond = ((num <= len) && (num >= 0));
	while ((!cin.good()) || (!cond))
	{
		cout << "ERROR input! Try again...\n";
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cin >> num;
		cond = ((num <= 5) && (num >= 0));
	}
	return num;
}

//return number of cards
int Player::get_cards_cnt()const
{
	return m_cards_cnt;
}

//check if input valid
void Player::check_inputs(int& num)
{
	do
	{
		if (num != -1)
			cout << "Error input !" << endl;
		cin >> num;
	} while ((num > 5) || (num < 0));
}

//decode number to card
//control = 1 return character card type
//control = 2 return room card type
//control = 3 return weapon card type
cards Player::num_to_cards(int num, int ctrl)
{
	if (ctrl == 1)
	{
		switch (num)
		{
		case 0:
			return MissScarlet;
		case 1:
			return MrsPeacock;
		case 2:
			return ColMustard;
		case 3:
			return MrGreen;
		case 4:
			return ProfPlum;
		case 5:
			return DrOrchid;
		}
	}
	else if (ctrl == 2)
	{
		switch (num)
		{
		case 0:
			return hall;
		case 1:
			return study;
		case 2:
			return lounge;
		case 3:
			return dinning;
		case 4:
			return kitchen;
		case 5:
			return ball;
		case 6:
			return conservatory;
		case 7:
			return billiard;
		case 8:
			return Library;
		}
	}
	else
	{
		switch (num)
		{
		case 0:
			return CandlStick;
		case 1:
			return Knife;
		case 2:
			return LeadPipe;
		case 3:
			return Gun;
		case 4:
			return Rope;
		case 5:
			return PipeWrench;
		}
	}
	return last_cardes;
}

//return player cards pack
vector<Card*> Player::get_cards()const
{
	return m_cards;
}

//return EvidenceBook object
EvidenceBook& Player::get_ev_book()
{
	return m_ev_book;
}

//save game data to file
ostream& operator<<(ostream& data, Player& player)
{
	data <<player.get_player_cr() << " "<< player.get_cards_cnt()<<endl;
	for (int j = 0; j < player.get_cards_cnt(); j++)
		data << player.get_cards()[j]->card_to_str(player.get_cards()[j]->who_am_I()) << " ";
	data << endl <<player.get_position()<< " " << player.get_status() <<endl << player.get_ev_book();
	return data;
}

//load data from file
istream& operator>> (istream& data, Player& player)
{
	data >> player.get_ev_book();
	return data;
}