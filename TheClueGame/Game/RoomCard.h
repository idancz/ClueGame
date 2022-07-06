#ifndef  _RoomCard_
#define  _RoomCard_
#include "Card.h"

class RoomCard :public Card
{
private:											 //room card
	cards m_Room;
public:												 //constructor	
	RoomCard(cards, char);							 //distractor
	~RoomCard() {};									 //print the cards
	void show_card() const;							 //identify Type of card
	cards who_am_I() const;							 //converte the card to string
	string card_to_str(cards)const;					 //get m_player
	const char get_m_type() const;					  

};
#endif