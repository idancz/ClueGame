#ifndef  _WeaponCard_
#define  _WeaponCard_
#include "Card.h"

class WeaponCard : public Card
{
private:
	cards m_Weapon;										  //room card
public:
	WeaponCard(cards, char);							  //constructor		
	~WeaponCard() {};									  //distractor			
	void show_card() const;								  //print the cards		
	cards who_am_I() const;								  //identify Type of card
	string card_to_str(cards)const;						  //converte the card to string
	const char get_m_type() const;						  //get m_player
};
#endif