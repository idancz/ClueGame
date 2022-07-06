#ifndef  _Player_
#define  _Player_

#include "Card.h"
#include "Point.h"
#include "EvidenceBook.h"
#include "MurderEnvelope.h"
#include "Dice.h"
#include <Windows.h>



class Player 
{
private:
	const char m_player_cr;		  //player char
	bool m_status;				  //player status
	Point m_position;			  //player position on board 
	Point m_room;				  //player position in rooms
	int m_cards_cnt;			  //cards counter
	vector<Card*> m_cards;		  //vector of card* for each player
	Dice m_dice;				  //dice
	EvidenceBook m_ev_book;		  //EvidenceBook for each player
	int m_steps_cnt;			  //steps at 1 turn
	static int player_counter;	  //player counter

public:
	bool m_flag = true;
	Player(const char, Point, vector<Card*>, bool status = true);	 //constructor
	Player(char, Point);								   //constructor
	void check_inputs(int&);							   //check keyboard inputs for pnum
	int check_inputs(int);								   //check keyboard inputs for accuse
	bool accuse(MurderEnvelope);						   // make accuse -choose 3 cards for murder,if player right-win else lose.
	Point where_am_I()const;							   //return room 
	void set_room(Point);								   //save player position on board
	void show_card()const;								   //show players cards
	Point& get_position();								   //return player position
	char get_player_cr()const;							   //return player char
	int get_player_counter()const;						   //return player counter
	cards num_to_cards(int, int);						   //change num to cards
	int get_cards_cnt()const;							   // get cards counter
	vector<Card*> get_cards()const;						   // get player vector cards
	EvidenceBook& get_ev_book();						   //return evidencebook of player
	bool select_move(MurderEnvelope);					   //show player options :1.roll dice 2.accuse 3.evidencebook and execute
	bool get_status()const;								   //get player status
	Dice& use_dice();									   //return dice 

	friend ostream& operator<<(ostream&, Player&);		   //operator << save player to file
	friend istream& operator>>(istream&, Player&);		   //operator >> load player from file
};
#endif