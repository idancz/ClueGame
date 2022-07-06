#ifndef  _ClueGame_
#define  _ClueGame_

#include "Player.h"
#include "Board.h"
#include "WeaponCard.h"
#include "RoomCard.h"
#include "CharacterCard.h"
#include "MurderEnvelope.h"
#include "Statistics.h"
#include "CardsPack.h"
#include<deque>
using namespace std;

#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW


	void save_game(Board& board, MurderEnvelope& envelope);		 //save game to file
	void load_game(Board& board, MurderEnvelope& envelope);		 //read game from file
	Point start_position(char c);			//set start position for players
	void num_of_players(int& p_num);		//choose number of players
	void select_character(int chr[], int n, int idx);
	int char_to_int(char& c);				//change player char to int
	bool check_y_n();						//chk yes/no options
	void start();							//print lib menu -1.start new game 2.load game 3.show statistics and execute 
	bool game_exit();						//chk exit from game
	void game(Board& board, MurderEnvelope& envelope, int& p_num, Statistics& stat); //move the turns between players until game over
	int Player::player_counter(0);


#endif