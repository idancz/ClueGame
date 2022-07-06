#include "MurderEnvelope.h"

MurderEnvelope::MurderEnvelope(char control )
{		
	if (control == '1')
	{
		cards temp;
		switch (rand() % 6)									//rand number for characters card
		{
		case 0:
			temp = MissScarlet;
			break;
		case 1:
			temp = MrsPeacock;
			break;
		case 2:
			temp = ColMustard;
			break;
		case 3:
			temp = MrGreen;
			break;
		case 4:
			temp = ProfPlum;
			break;
		case 5:
			temp = DrOrchid;
			break;
		}
		m_envelope.push_back(new CharacterCard(temp, '?'));		 //save characters at envelope arr

		switch (rand() % 9)										 //rand number for rooms card
		{
		case 0:
			temp = hall;
			break;
		case 1:
			temp = study;
			break;
		case 2:
			temp = lounge;
			break;
		case 3:
			temp = dinning;
			break;
		case 4:
			temp = kitchen;
			break;
		case 5:
			temp = ball;
			break;
		case 6:
			temp = conservatory;
			break;
		case 7:
			temp = billiard;
			break;
		case 8:
			temp = Library;
			break;
		}
		m_envelope.push_back(new RoomCard(temp, '?'));					//save room at envelope array

		switch (rand() % 6)												//rand number for weapons card
		{
		case 0:
			temp = CandlStick;
			break;
		case 1:
			temp = Knife;
			break;
		case 2:
			temp = LeadPipe;
			break;
		case 3:
			temp = Gun;
			break;
		case 4:
			temp = Rope;
			break;
		case 5:
			temp = PipeWrench;
			break;
		}
		m_envelope.push_back(new WeaponCard(temp, '?'));							 //save weapon at envelope array
	}
}

MurderEnvelope::~MurderEnvelope()
{/*
	for (int i = 0; i < 3; i++)
		delete m_envelope[i];*/
}

void MurderEnvelope::show_envelope()
{
	for (int i = 0; i < 3; i++)
		m_envelope[i]->show_card();									 //show cards of envelope
}

bool MurderEnvelope::search_inside(cards crd)
{
	for (int i = 0; i < 3; i++)
	{
		if (m_envelope[i]->who_am_I() == crd)						 //compare card to envlope cards
			return true;
	}
	return false;
}

vector<Card*> MurderEnvelope::get_envelope()const
{
	return m_envelope;
}

string MurderEnvelope::get_card(int idx)const
{
	return m_envelope[idx]->card_to_str(m_envelope[idx]->who_am_I());
}

void MurderEnvelope::empty_envelope()
{
	clear_cards();
	m_envelope.clear();
}

void MurderEnvelope::clear_cards()
{
	for (int i = 0; i < 3; i++)
		delete m_envelope[i];

}

void MurderEnvelope::insert_to_envelope(Card* card)
{
	m_envelope.push_back(card);
}

Card* MurderEnvelope::str_to_card(string c)
{
	cards cr;
	if (c == "MissScarlet")
		cr = MissScarlet;
	else if (c == "MrsPeacock")
		cr = MrsPeacock;
	else if (c == "ColMustard")
		cr = ColMustard;
	else if (c == "MrGreen")
		cr = MrGreen;
	else if (c == "ProfPlum")
		cr = ProfPlum;
	else if (c == "DrOrchid")
		cr = DrOrchid;
	else if (c == "hall")
		cr = hall;
	else if (c == "study")
		cr = study;
	else if (c == "lounge")
		cr = lounge;
	else if (c == "dinning")
		cr = dinning;
	else if (c == "kitchen")
		cr = kitchen;
	else if (c == "ball")
		cr = ball;
	else if (c == "conservatory")
		cr = conservatory;
	else if (c == "billiard")
		cr = billiard;
	else if (c == "Library")
		cr = Library;
	else if (c == "CandlStick")
		cr = CandlStick;
	else if (c == "Knife")
		cr = Knife;
	else if (c == "LeadPipe")
		cr = LeadPipe;
	else if (c == "Gun")
		cr = Gun;
	else if (c == "Rope")
		cr = Rope;
	else if (c == "PipeWrench")
		cr = PipeWrench;

	if (cr <= DrOrchid)
		return (new CharacterCard(cr, 'c'));
	else if (cr >= hall && cr <= Library)
		return (new RoomCard(cr, 'r'));
	return (new WeaponCard(cr, 'w'));
}

ostream& operator<<(ostream& data, const MurderEnvelope& envelope)
{
	for (int i = 0; i < 3; i++)
	{
		data << envelope.get_card(i) << " ";
	}
	data << endl;
	return data;
}


istream& operator >> (istream& data, MurderEnvelope& envelope)
{
	string str[3]; 
	for (int i = 0; i < 3; i++)
	{
		data >> str[i];
		envelope.insert_to_envelope(envelope.str_to_card(str[i]));
	}
	return data;
}


