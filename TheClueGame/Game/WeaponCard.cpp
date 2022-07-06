#include "WeaponCard.h"


WeaponCard::WeaponCard(cards w, char cr):Card(cr)
{																		//print card
	m_Weapon = w;
}

void WeaponCard::show_card() const
{
	cout << card_to_str(m_Weapon) << endl;
}																		//return type of card

cards WeaponCard::who_am_I() const
{
	return m_Weapon;
}

string WeaponCard::card_to_str(cards w)const
{																		//converte card room to string
	switch (w)
	{
	case CandlStick:
		return "CandlStick";
	case Knife:
		return "Knife";
	case LeadPipe:
		return "LeadPipe";
	case Gun:
		return "Gun";
	case Rope:
		return "Rope";
	case PipeWrench:
		return "PipeWrench";
	default:
		break;
	}
	return "?";
}

const char WeaponCard::get_m_type() const
{
	return m_type;						//return player char
}	

//ostream& operator<<(ostream& data, Weapon& w)
//{
//	data << w.card_to_str(w.who_am_I()) << " ";
//	return data;
//}