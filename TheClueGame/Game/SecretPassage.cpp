#include "SecretPassage.h"

//check if player in room with secret passage
Point SecretPassage::check_Passage(char c, Point p)
{
	bool sp = true;
	Point loc = p;
	if (p == st_room[c])
		loc = ki_room[c];
	else if (p == ki_room[c])
		loc = st_room[c];
	else if (p == lo_room[c])
		loc = co_room[c];
	else if (p == co_room[c])
		loc = lo_room[c];
	else
		sp = false;
	if (sp)					 //if player in room with secret passage
	{
		char temp;
		cout << "Select option:\n1.Secret Passage\n2.Suggestion\n";
		cin >> temp;
		bool cond = (temp >= '1' && temp <= '2');	 //check imputs
		while ((!cin.good()) || (!cond))
		{
			cout << "ERROR input! Try again...\n";
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cin >> temp;
			cond = (temp >= '1' && temp <= '2');
		}
		if (temp == '1')
			return loc;			 //return room location for pass
	}
	return p;
}

