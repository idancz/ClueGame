#ifndef  _SecretPassage_
#define  _SecretPassage_

#include "Point.h"
#include "Card.h"
#include "Rooms.h"
#include <map>
#include <algorithm>

class SecretPassage:public Rooms
{
private:
	map<cards, Point> m_passages;
public:
	SecretPassage() {};
	Point check_Passage(char, Point);
};

#endif