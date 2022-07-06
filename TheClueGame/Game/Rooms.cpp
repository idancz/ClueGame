#include "Rooms.h"


Rooms::Rooms()
{
	st_room['S'] = Point(2, 14);
	st_room['P'] = Point(2, 16);
	st_room['M'] = Point(2, 18);
	st_room['G'] = Point(1, 14);
	st_room['R'] = Point(1, 16);
	st_room['O'] = Point(1, 18);

	ha_room['S'] = Point(3, 31);
	ha_room['P'] = Point(3, 33);
	ha_room['M'] = Point(3, 35);
	ha_room['G'] = Point(3, 50);
	ha_room['G'] = Point(3, 50);
	ha_room['R'] = Point(3, 48);
	ha_room['O'] = Point(3, 46);

	lo_room['S'] = Point(1, 63);
	lo_room['P'] = Point(3, 65);
	lo_room['M'] = Point(1, 67);
	lo_room['G'] = Point(1, 69);
	lo_room['R'] = Point(1, 71);
	lo_room['O'] = Point(1, 73);

	Li_room['S'] = Point(8, 3);
	Li_room['P'] = Point(8, 5);
	Li_room['M'] = Point(8, 7);
	Li_room['G'] = Point(8, 9);
	Li_room['R'] = Point(8, 11);
	Li_room['O'] = Point(8, 13);

	di_room['S'] = Point(10, 67);
	di_room['P'] = Point(10, 69);
	di_room['M'] = Point(10, 71);
	di_room['G'] = Point(10, 73);
	di_room['R'] = Point(10, 75);
	di_room['O'] = Point(10, 77);

	bi_room['S'] = Point(15, 3);
	bi_room['P'] = Point(15, 5);
	bi_room['M'] = Point(15, 7);
	bi_room['G'] = Point(15, 9);
	bi_room['R'] = Point(15, 11);
	bi_room['O'] = Point(15, 13);

	ba_room1['S'] = Point(20, 31);
	ba_room1['P'] = Point(20, 33);
	ba_room1['M'] = Point(20, 35);
	ba_room1['G'] = Point(20, 58);
	ba_room1['R'] = Point(20, 56);
	ba_room1['O'] = Point(20, 54);

	ba_room2['S'] = Point(20, 31);
	ba_room2['P'] = Point(20, 33);
	ba_room2['M'] = Point(20, 35);
	ba_room2['G'] = Point(20, 58);
	ba_room2['R'] = Point(20, 56);
	ba_room2['O'] = Point(20, 54);

	ki_room['S'] = Point(21, 71);
	ki_room['P'] = Point(21, 73);
	ki_room['M'] = Point(21, 75);
	ki_room['G'] = Point(21, 77);
	ki_room['R'] = Point(21, 79);
	ki_room['O'] = Point(21, 81);

	co_room['S'] = Point(22, 18);
	co_room['P'] = Point(22, 16);
	co_room['M'] = Point(22, 14);
	co_room['G'] = Point(22, 12);
	co_room['R'] = Point(22, 10);
	co_room['O'] = Point(22, 8);

};

Point Rooms::enter_to_room(Point p, char s)
{
	int idx;
	for (int i = 0; i < (int)enterce.size(); i++)
		if (enterce[i] == p)
		{
			idx = i;
			break;
		}
	if (idx == 0)
		return st_room[s];
	else if (idx == 1)
		return ha_room[s];
	else if (idx == 2)
		return lo_room[s];
	else if (idx == 3)
		return Li_room[s];
	else if (idx == 4)
		return di_room[s];
	else if (idx == 5)
		return bi_room[s];
	else if (idx == 6)
		return ba_room1[s];
	else if (idx == 7)
		return ba_room2[s];
	else if (idx == 8)
		return ki_room[s];
	return co_room[s];
};

Point Rooms::search_room(Point p, char s)
{
	if (p == st_room[s])
		return enterce[0];
	else if (p == ha_room[s])
		return enterce[1];
	else if (p == lo_room[s])
		return enterce[2];
	else if (p == Li_room[s])
		return enterce[3];
	else if (p == di_room[s])
		return enterce[4];
	else if (p == bi_room[s])
		return enterce[5];
	else if (p == ba_room1[s])
		return enterce[6];
	else if (p == ba_room2[s])
		return enterce[7];
	else if (p == ki_room[s])
		return enterce[8];
	else if (p == co_room[s])
		return enterce[9];
	return p;

}

cards Rooms::which_room_am_I(Point p, char s)
{
	if (ha_room[s] == p)
		return room_cd[0];
	else if (st_room[s] == p)
		return room_cd[1];
	else if (lo_room[s] == p)
		return room_cd[2];
	else if (di_room[s] == p)
		return room_cd[3];
	else if (ki_room[s] == p)
		return room_cd[4];
	else if (ba_room1[s] == p || ba_room2[s] == p)
		return room_cd[5];
	else if (co_room[s] == p)
		return room_cd[6];
	else if (bi_room[s] == p)
		return room_cd[7];
	return room_cd[8];
}
