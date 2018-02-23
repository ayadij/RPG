#pragma once
#include "Fighter.h"

using namespace std;


class Cleric : public Fighter
{
private:
	int cur_mana;
	int max_mana;


public:
	Cleric(string name, string type, int max_hp, int strength, int speed, int magic);
	~Cleric();

	int getDamage();
	void reset();
	void regenerate();
	bool useAbility();

};
