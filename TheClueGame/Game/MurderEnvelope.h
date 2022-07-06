#ifndef  _MurderEnvelope_
#define  _MurderEnvelope_
#include "WeaponCard.h"
#include "RoomCard.h"
#include "CharacterCard.h"

class MurderEnvelope
{
protected:
	vector<Card*> m_envelope;					 //envelope cards array

	void clear_cards();
public:
	MurderEnvelope(char control = '1');			 //constructor	
	~MurderEnvelope();							//distractor
	void show_envelope();						//show cards of envelope
	bool search_inside(cards);					//compare card to envlope cards
	vector<Card*> get_envelope()const;			//return envelope cards
	string get_card(int idx)const;				//return envelope card by idx
	void empty_envelope();						//delete cards and envelope allcations
	Card* str_to_card(string);					//change string to card
	void insert_to_envelope(Card*);				//insert card pointer to vector

	friend ostream& operator<<(ostream&, const MurderEnvelope&);   //save to file
	friend istream& operator>>(istream&, MurderEnvelope&);		   //read from file
};



#endif 