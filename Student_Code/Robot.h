#pragma once
#include "Fighter.h"

using namespace std;


class Robot : public Fighter
{
private:
	double max_energy;
	double cur_energy;

	int bonus_damage;

public:
	Robot(string name, string type, int max_hp, int strength, int speed, int magic);
	~Robot();
	int getDamage();
	void reset();
	void regenerate();
	bool useAbility();

};
