#include "EvidenceBook.h"

void EvidenceBook::insert_my_cards(vector<Card*> cd, int len, const char player)
{
	for (int i = 0; i < len; i++)
	{
		m_notepad[cd[i]->who_am_I() + 1][decod_player(player)] = 'V';	 //mark v at player cards 
		string::iterator it;
		for (it = m_str.begin(); it < m_str.end(); it++)
		{
			if (*it == player)
				continue;
			m_notepad[cd[i]->who_am_I() + 1][decod_player(*it)] = 'X'; //mark x at other player 
		}
	}
}



void EvidenceBook::mark_evidence(char player, cards row, bool b)
{
	if (row == last_cardes)
		return;
	char s;
	if (b)
		s = 'V';														   //mark v if player have the card
	else
		s = 'X';														   //mark x if player don have the card
	int col = decod_player(player);
	if (b)
	{
		m_notepad[row + 1][col] = s;
		string::iterator it;
		for (it = m_str.begin(); it < m_str.end(); it++)
		{
			if (*it == player)
				continue;
			m_notepad[row + 1][decod_player(*it)] = 'X';
		}
	}
	else
		m_notepad[row + 1][col] = s;										//mark at row and columb at EvidenceBook
}
																		  
int EvidenceBook::decod_player(char player)								  //decode char to position at EvidenceBook
{
	switch (player)
	{
	case 'S':
		return 15;
	case 'P':
		return 19;
	case 'M':
		return 23;
	case 'G':
		return 27;
	case 'R':
		return 31;
	case 'O':
		return 35;
	default:
		break;
	}
	return -1;
}

void EvidenceBook::show_evidence()
{
	for (int i = 0; i < 22; i++)
	{
		cout << m_notepad[i] << endl;							  //print evidencebook
	}
}

string EvidenceBook::get_notepad(int idx)const
{
	return m_notepad[idx];
}

void EvidenceBook::set_notepad(string str, int idx)
{
	m_notepad[idx] = str;
}

ostream& operator<<(ostream& data, const EvidenceBook& book)
{
	for (int k = 0; k < BookRow; k++)
		data << book.get_notepad(k) << endl;
	return data;
}

istream& operator>>(istream& data, EvidenceBook& book)
{
	char c[BookCol];
	data.getline(c, BookCol);
	for (int i = 0; i < BookRow; i++)
	{
		char str[BookCol];
		data.getline(str, BookCol);
		book.set_notepad(str, i);
	}
	return data;
}