#ifndef  _Rooms_
#define  _Rooms_

#include "Card.h"
#include "Point.h"
#include <map>
#include <vector>
#include <algorithm>

class Rooms																						  
{
protected:
	//maps of saved points at room for any player
	map<char, Point> st_room;
	map<char, Point> ha_room;
	map<char, Point> lo_room;
	map<char, Point> Li_room;
	map<char, Point> di_room;
	map<char, Point> bi_room;
	map<char, Point> ba_room1;
	map<char, Point> ba_room2;
	map<char, Point> ki_room;
	map<char, Point> co_room;

	//points of room entrance
	vector<Point> enterce = { Point(3, 14), Point(5, 38), Point(4, 66), Point(10, 10),Point(8, 70),
							  Point(13, 6),Point(18, 38), Point(18, 50),Point(18, 74), Point(20, 14) };
	//vector of room cards
	vector<cards> room_cd = { hall, study, lounge, dinning, kitchen, ball, conservatory, billiard, Library };
public:
	Rooms();								  //constructor
	Point enter_to_room(Point, char);		  //chk if player at room entrance
	Point search_room(Point, char);			  //chk if player at the room
	cards which_room_am_I(Point, char);		  //return where player in rooms 
};


#endif


