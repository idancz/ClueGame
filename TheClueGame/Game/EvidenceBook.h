#ifndef  _EvidenceBook_
#define  _EvidenceBook_
#include "Card.h"

#define BookCol 39
#define BookRow 22

class EvidenceBook
{
private:
	string m_str = { "SPMGRO"};
	string m_notepad[22] = { {"|            |_S_|_P_|_M_|_G_|_R_|_O_|" } ,
							{ "|Miss Scarlet|___|___|___|___|___|___|" } ,
							{ "|Mrs Peacock |___|___|___|___|___|___|" } ,
							{ "|Col Mustard |___|___|___|___|___|___|" } ,
							{ "|Mr Green    |___|___|___|___|___|___|" } ,
							{ "|Prof Plum   |___|___|___|___|___|___|" } ,
							{ "|Dr Orchid   |___|___|___|___|___|___|" } ,
							{ "|Hall        |___|___|___|___|___|___|" } ,
							{ "|Study       |___|___|___|___|___|___|" } ,
							{ "|Lounge      |___|___|___|___|___|___|" } ,
							{ "|Dinning     |___|___|___|___|___|___|" } ,
							{ "|Kitchen     |___|___|___|___|___|___|" } ,
							{ "|Ball        |___|___|___|___|___|___|" } ,
							{ "|Conservatory|___|___|___|___|___|___|" } ,
							{ "|Billiard    |___|___|___|___|___|___|" } ,
							{ "|Library     |___|___|___|___|___|___|" } ,
							{ "|Candl Stick |___|___|___|___|___|___|" } ,
							{ "|Knife       |___|___|___|___|___|___|" } ,
							{ "|Lead Pipe   |___|___|___|___|___|___|" } ,
							{ "|Gun         |___|___|___|___|___|___|" } ,
							{ "|Rope        |___|___|___|___|___|___|" } ,
							{ "|Pipe Wrench |___|___|___|___|___|___|" } };
	
public:
	EvidenceBook() {};									    //deafult constructor
	void insert_my_cards(vector<Card*>, int , const char);	//mark the player cards at evidencebook
	void mark_evidence(char, cards, bool);				    //mark one evidence card at evidencebook
	int decod_player(char);								    //decode player char to place at the evidencebook
	void show_evidence();								    //print evidencebook
	string get_notepad(int)const;
	void set_notepad(string, int);

	friend ostream& operator<<(ostream&, const EvidenceBook&);	   //save to file
	friend istream& operator>>(istream&, EvidenceBook&);		   //read from file
};


#endif