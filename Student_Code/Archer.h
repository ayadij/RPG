#pragma once
#include "Fighter.h"

using namespace std;


class Archer : public Fighter
{
private:
	int modified_speed;


public:
	Archer(string name, string type, int max_hp, int strength, int speed, int magic);
	~Archer();

	int getSpeed();
	int getDamage();
	void takeDamage(int damage);
	void reset();
	void regenerate();
	bool useAbility();

};
