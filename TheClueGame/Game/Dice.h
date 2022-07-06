#ifndef  _Dice_
#define  _Dice_

#include <iostream>
#include <string>
using namespace std;

#define DICE_RANG 12

class Dice
{
private:
	int m_dice;
public:
	Dice() { m_dice = 0; };		//constructor
	void roll_the_dice();		//roll dice-random number bet 1-12
	void print_dice()const;		//print dice number
	int get_dice()const;		// get m_dice
};

#endif
