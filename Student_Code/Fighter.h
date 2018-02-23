#pragma once

#include "FighterInterface.h"
//#include "ArenaInterface.h"
//using namespace std;

class Fighter : public FighterInterface
{

protected:

	string name; 	//Name - The fighter's name
	string type; 	//Robot Archer Cleric
	int cur_hp;		//Current Hit Points - The amount of health the fighter has, with a specified maximum; reaching 0 is equivalent to losing. A Fighter's starting Hit Points (which is a Fighter's maximum Hit Points) must be greater than 0. There is no upper bound to what a Fighter's starting/maximum Hit Points could be.
	int max_hp; 	// Max Hit Points - The specified maximum amount of health the fighter has, with a specified maximum.
	int strength;	//Strength - Physical power, used to determine hit point regeneration. Must be greater than 0. No maximum value.
	int speed;		//Speed - Dexterity and physical movement, used to reduce damage when being attacked. Must be greater than 0. No maximum value.
	int magic;		//Magic - Magical prowess, used for some special abilities. Must be greater than 0. No maximum value.
	int damage;
	int damage_taken;

public:

	Fighter(string name, string type, int max_hp, int strength, int speed, int magic);
	virtual ~Fighter();

	string getName();
	int getMaximumHP();
	int getCurrentHP();
	int getStrength();
	int getSpeed();
	int getMagic();

	virtual int getDamage() = 0;
	void takeDamage(int damage);
	virtual void reset() = 0;
	virtual void regenerate() = 0;
	virtual bool useAbility() = 0;

};
