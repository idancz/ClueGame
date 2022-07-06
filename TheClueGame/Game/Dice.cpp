#include "Dice.h"

//rturn random number
void Dice::roll_the_dice()
{
	m_dice = (1 + (rand() % DICE_RANG));
}

//print dice result
void  Dice::print_dice()const
{
	cout << "Dice result :" << m_dice << endl;
}

//return dice result
int Dice::get_dice()const
{
	return m_dice;
}