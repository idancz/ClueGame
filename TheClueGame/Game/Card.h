#ifndef  _Card_
#define  _Card_

#include <cstdlib>
#include <vector>
#include <iostream>
#include <string>
using namespace std;

#define NUM_OF_CHARACTERS 6
#define NUM_OF_ROOMS 9
#define NUM_OF_WEAPONS 7

enum  cards { MissScarlet, MrsPeacock, ColMustard, MrGreen, ProfPlum, DrOrchid,
	          hall, study, lounge, dinning, kitchen, ball, conservatory, billiard, Library,
			  CandlStick, Knife, LeadPipe, Gun, Rope, PipeWrench, last_cardes };

class Card
{
protected:
	const char m_type;							   //card type(r,w,c)
public:
	Card(char c) : m_type(c) {};					//constructor
	virtual ~Card() = 0 {};							//abstract distractor
	virtual void show_card() const = 0;				//abstract function for print the cards
	virtual string card_to_str(cards)const = 0;		//abstract function to converte the card to string
	virtual cards who_am_I() const = 0;				//abstract function	 to identify Type of card
	virtual const char get_m_type() const = 0;		//abstract function	get m_player 

};

#endif