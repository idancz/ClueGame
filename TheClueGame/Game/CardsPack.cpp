#include "CardsPack.h"

CardsPack::CardsPack(MurderEnvelope& envelope, int p_num, char control)
{
	if (control == '1')
	{
		vector<cards> vec = { MissScarlet, MrsPeacock, ColMustard, MrGreen, ProfPlum, DrOrchid,
			hall, study, lounge, dinning, kitchen, ball, conservatory, billiard, Library,
			CandlStick, Knife, LeadPipe, Gun, Rope, PipeWrench };

		for (int i = 0; i < 3; i++)
		{
			cards temp = envelope.get_envelope()[i]->who_am_I();
			vec.erase(find(vec.begin(), vec.end(), temp));
		}

		for (int i = 0; i < p_num; i++)
		{
			vector<Card*> v;
			packs.push_back(v);
		}

		while (vec.size() != 0)
		{
			for (int j = 0; j < p_num; j++)
			{
				random_shuffle(vec.begin(), vec.end());
				cards temp = vec[vec.size() - 1];
				if (temp <= DrOrchid)
					packs[j].push_back(new CharacterCard(temp, 'c'));
				else if (temp >= hall && temp <= Library)
					packs[j].push_back(new RoomCard(temp, 'r'));
				else
					packs[j].push_back(new WeaponCard(temp, 'w'));
				vec.pop_back();
				if (vec.size() == 0)
					break;
			}
		}
	}
}

CardsPack::~CardsPack()
{
	/*vector<vector<Card*>>::iterator it1;
	for (it1 = packs.begin(); it1 < packs.end(); it1++)
	{
		vector<Card*> ::iterator it2;
		for (it2 = it1->begin(); it2 < it1->end(); it2++)
		{
			delete *it2;
		}
	}*/
}

vector<Card*> CardsPack::get_pack(int idx)const
{
	return packs[idx];
}


Card* CardsPack::str_to_card(string c)
{
	cards cr;
	if (c == "MissScarlet")
		cr = MissScarlet;
	else if (c == "MrsPeacock")
		cr = MrsPeacock;
	else if (c == "ColMustard")
		cr = ColMustard;
	else if (c == "MrGreen")
		cr = MrGreen;
	else if (c == "ProfPlum")
		cr = ProfPlum;
	else if (c == "DrOrchid")
		cr = DrOrchid;
	else if (c == "hall")
		cr = hall;
	else if (c == "study")
		cr = study;
	else if (c == "lounge")
		cr = lounge;
	else if (c == "dinning")
		cr = dinning;
	else if (c == "kitchen")
		cr = kitchen;
	else if (c == "ball")
		cr = ball;
	else if (c == "conservatory")
		cr = conservatory;
	else if (c == "billiard")
		cr = billiard;
	else if (c == "Library")
		cr = Library;
	else if (c == "CandlStick")
		cr = CandlStick;
	else if (c == "Knife")
		cr = Knife;
	else if (c == "LeadPipe")
		cr = LeadPipe;
	else if (c == "Gun")
		cr = Gun;
	else if (c == "Rope")
		cr = Rope;
	else if (c == "PipeWrench")
		cr = PipeWrench;

	if (cr <= DrOrchid)
		return (new CharacterCard(cr, 'c'));
	else if (cr >= hall && cr <= Library)
		return (new RoomCard(cr, 'r'));
	return (new WeaponCard(cr, 'w'));
}