#include "Fighter.h"

Fighter::Fighter(string name, string type, int max_hp, int strength, int speed, int magic)
{
	this->name = name;
	this->type = type;
	this->max_hp = max_hp;
	this->strength = strength;
	this->speed = speed;
	this->magic = magic;
	cur_hp = this->max_hp;
	damage = 0;
	damage_taken = 0;
}

Fighter::~Fighter(){}

// Returns the name fo this fighter.
string Fighter::getName()
{
	return name;
}

//Returns the maximum hit points of this fighter.
int Fighter::getMaximumHP()
{
	return max_hp;
}

//Returns the current hit points of this fighter.
int Fighter::getCurrentHP()
{
	return cur_hp;
}

//Returns the strength stat of this fighter.
int Fighter::getStrength()
{
	return strength;
}

//Returns the speed stat of this fighter.
int Fighter::getSpeed()
{
	 return speed;
}

//Returns the magic stat of this fighter.
int Fighter::getMagic()
 {
	 return magic;
 }

/*	takeDamage(int)
 *	Reduces the fighter's current hit points by an amount equal to the given
 *	damage minus one fourth of the fighter's speed.  This method must reduce
 *	the fighter's current hit points by at least one.  It is acceptable for
 *	this method to give the fighter negative current hit points.
 *	Examples:
 *		damage=10, speed=7		=> damage_taken=9
 *		damage=10, speed=9		=> damage_taken=8
 *		damage=10, speed=50		=> damage_taken=1 */
void Fighter::takeDamage(int damage)
 {
	//std::cout << name << ": fighter in function: takeDamage " << cur_hp << ": cur_hp before\n";
	double damage_taken = (damage-(speed/4));

	if (damage_taken < 1){
		cur_hp = cur_hp - 1;
		return;
	}
	int int_damage_taken = (damage - (speed/4));
	cur_hp = cur_hp - int_damage_taken;

	//std::cout << name << ": fighter in function: takeDamage " << cur_hp << ": cur_hp after\n";

	return;

////////////////////////////////////////////////////////////////////////////////////////////////OR//////////////////////////
/*	double tempspeed = (speed/4) +.5;
	int newspeed = tempspeed;
	damage_taken = damage - newspeed;
	if (damage_taken == 0){damage_taken = 1;}
	cur_hp = cur_hp - damage_taken;
/////////////////////////////////////////////////////////////////////////////////////////////////OR//////////////////////////
	int newspeed = (speed/4) +.5;
	damage_taken = damage - newspeed;
	if (damage_taken == 0){damage_taken = 1;}
	cur_hp = cur_hp - damage_taken;
/////////////////////////////////////////////////////////////////////////////////////////////////OR//////////////////////////
	if ((damage -(speed / 4)) < 1){
		cur_hp = cur_hp -1;
		return;
	}
	cur_hp = cur_hp - (damage -(speed / 4));
	return;
*/

 }
