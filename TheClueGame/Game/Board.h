#ifndef  _Board_
#define  _Board_

#include "Point.h"
#include "Player.h"
#include "SecretPassage.h"
#include "CardsPack.h"
#include "Rooms.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class Board 
{
private:
	int m_players_cnt;			//number of players
	Player** m_players;			//arr of player pointers
	SecretPassage m_passage;	//save secret passage points
	Rooms m_rooms;				//save rooms entrance points
	string m_board[25] =		//board of strings
	{ {"|###################|___|___|#######################|___|___|#######################|" }//0
	,{ "|#S.P              #|___|___|#                     #|___|___|#                  S.P#|" }//1
	,{ "|#    Study        #|___|___|#        Hall         #|___|___|#        Lounge       #|" }//2
	,{ "|###########|___|###|___|___|#                     #|___|___|#                     #|" }//3
	,{ "|___|___|___|___|___|___|___|#                     #|___|___|###|___|###############|" }//4
	,{ "|___|___|___|___|___|___|___|#######|___|###########|___|___|___|___|___|___|___|___|" }//5
	,{ "|###################|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|" }//6
	,{ "|#     Library     #|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|" }//7
	,{ "|#                 #|___|___|___|___|###############|___|___|___|###| _ |###########|" }//8
	,{ "|#                 #|___|___|___|___|###############|___|___|___|#                 #|" }//9
	,{ "|#######|___|#######|___|___|___|___|###############|___|___|___|#                 #|" }//10
	,{ "|___|___|___|___|___|___|___|___|___|#### Pool #####|___|___|___|#     Dinning     #|" }//11
	,{ "|___|___|___|___|___|___|___|___|___|###############|___|___|___|#                 #|" }//12
	,{ "|###| _ |###########|___|___|___|___|###############|___|___|___|#                 #|" }//13
	,{ "|#                 #|___|___|___|___|###############|___|___|___|#                 #|" }//14
	,{ "|#                 #|___|___|___|___|###############|___|___|___|###################|" }//15
	,{ "|#    Billiard     #|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|" }//16
	,{ "|###################|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|" }//17
	,{ "|___|___|___|___|___|___|___|#######| _ |#######| _ |#######|___|___|###| _ |#######|" }//18
	,{ "|___|___|___|___|___|___|___|#                             #|___|___|#          S.P#|" }//19
	,{ "|###########| _ |###|___|___|#             Ball            #|___|___|#             #|" }//20
	,{ "|#S.P              #|___|___|#                             #|___|___|#             #|" }//21
	,{ "|#                 #|___|___|#########             #########|___|___|#             #|" }//22
	,{ "|#  Conservatory   #|___|___|___|___|#             #|___|___|___|___|#    Kitchen  #|" }//23
	,{ "|###################|___|___|___|___|###############|___|___|___|___|###############|" }//24
	};

	bool check_dest(char, int);							  //check if the next step valid
	void print_error()const;							  //print error message
	bool check_entrance(Point);							  //check room entrance
	void print_left_steps(int, int);					  //print the steps left for player
	void set_player();									  //set first players positin on the board 
	void check_inputs(int&);							  //check inputs from keyboard
	void check_choice(int&, int);						  //check inputs from keyboard with len
	bool search_evidence(Player, cards);				  //search evidence at specipic player
	string card_to_str(cards);							  //change card to string


public:
	Board(int num = 0) { m_players_cnt = num; };		  //constructor
	~Board();											  //distructor
	void insert_player(Player*);						  //save new player at player arr
	Player& get_player(int);							  //get player pointer 
	bool move_player(int idx);							  //move player by the dice number to direction chose by player.
	void print_board()const;							  //print board
	void suggest(int);									  //make suggest at room 
	cards where_am_I(Point);							  //return room position
	void transfer_player(int, Point);					  //move player to the point
	int get_players_cnt()const;							  // get player counter
	bool room_options(int);								  //chk if room have secret passage
	bool check_losers();								  //chk if all players wrong accuse -game over
	bool room_option(int);								  //room manu:1.suggest 2.exit room
	cards get_player_room(int);


	Point m_room_entrances[10] =
	{ Point(3,14),  Point(4,66), Point(5,38), 
	  Point(8,70),  Point(10,10),  Point(13,6),
	  Point(18,38), Point(18,50), Point(18,74), Point(20,14)};

	friend ostream& operator<<(ostream&, Board&);			//operator<<
	friend istream& operator>> (istream&, Board&);			//operator>>
	 
};


#endif