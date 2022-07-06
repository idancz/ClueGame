#include "CharacterCard.h"


CharacterCard::CharacterCard(cards c, char cr):Card(cr)
{
	m_character = c;												//save character card
}

void CharacterCard::show_card() const
{
	cout << card_to_str(m_character) << endl;						//print card 
}

cards CharacterCard::who_am_I() const
{
	return m_character;												//return type of card
}

string CharacterCard::card_to_str(cards c)const							//converte card charcter to string
{
	switch (c)
	{
	case MissScarlet:
		return "MissScarlet";
	case MrsPeacock:
		return "MrsPeacock";
	case ColMustard:
		return "ColMustard";
	case MrGreen:
		return "MrGreen";
	case ProfPlum:
		return "ProfPlum";
	case DrOrchid:
		return "DrOrchid";
	default:
		break;
	}
	return "?";
} 

const char CharacterCard::get_m_type() const
{
	return m_type;									  // return player char
}

//ostream& operator<<(ostream& data, Character& c)
//{
//	data << c.card_to_str(c.who_am_I()) << " ";
//	return data;
//}