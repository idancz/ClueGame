#ifndef  _CardsPack_
#define  _CardsPack_

#include "MurderEnvelope.h"
#include "Card.h"
#include <vector>
#include <algorithm>



class CardsPack
{
private:
	vector<vector<Card*>> packs;				  //players packs of cards vector
	
public:
	CardsPack(MurderEnvelope&, int, char);		   //constructor
	CardsPack() { };						  	   //diffult constructor
	~CardsPack();							  	   //distractor
	vector<Card*> get_pack(int)const;		  	   // return packs by idx
	Card* str_to_card(string);				  	   //change string to card*
};											  

#endif