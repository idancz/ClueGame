#ifndef  _CharacterCard_
#define  _CharacterCard_
#include "Card.h"


class CharacterCard :public Card
{
private:
	cards m_character;							 //character card
public:
	CharacterCard(cards, char);					 //constructor
	~CharacterCard() {};						 //distractor
	void show_card() const;						 //print the cards
	cards who_am_I() const;						 //identify Type of card
	string card_to_str(cards)const;				 //converte the card to string
	const char get_m_type() const;				 //get m_player
};
#endif