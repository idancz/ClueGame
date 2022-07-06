#include "RoomCard.h"


RoomCard::RoomCard(cards r, char cr) :Card (cr)
{
	m_Room = r;											//save room card
}

void RoomCard::show_card() const
{
	cout << card_to_str(m_Room) << endl;				//print card
}

cards RoomCard::who_am_I() const
{
	return m_Room;										//return type of card
}

string RoomCard::card_to_str(cards r)const					//converte card room to string
{
	switch (r)
	{
	case hall:
		return "hall";
	case study:
		return "study";
	case lounge:
		return "lounge";
	case dinning:
		return "dinning";
	case kitchen:
		return "kitchen";
	case ball:
		return "ball";
	case conservatory:
		return "conservatory";
	case billiard:
		return "billiard";
	case Library:
		return "Library";
	default:
		break;
	}
	return "?";
} 

const char RoomCard::get_m_type() const
{
	return m_type;								//return player char
}


//ostream& operator<<(ostream& data, Room& r)
//{
//	data << r.card_to_str(r.who_am_I()) << " ";
//	return data;
//}