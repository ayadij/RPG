#include "Archer.h"


Archer::Archer(string name, string type, int max_hp, int strength, int speed, int magic)
	: Fighter(name, type, max_hp, strength, speed, magic)
{
	damage = speed;
	modified_speed = 0;
}

Archer::~Archer(){}



int Archer::getDamage()
 {
	damage = speed + modified_speed;
	return damage;
 }


int Archer::getSpeed()
{
	int new_speed = speed + modified_speed;
	return new_speed;
}



void Archer::takeDamage(int damage)
 {
	//std::cout << name << ": fighter in function: takeDamage " << cur_hp << ": cur_hp before\n";
	int new_speed = speed + modified_speed;
	double damage_taken = (damage-(new_speed/4));

	if (damage_taken < 1){
		cur_hp = cur_hp - 1;
		return;
	}
	int int_damage_taken = (damage - (new_speed/4));
	cur_hp = cur_hp - int_damage_taken;

	//std::cout << name << ": fighter in function: takeDamage " << cur_hp << ": cur_hp after\n";

	return;
 }





/*	Restores a fighter's current hit points to its maximum hit points.
 *	Archer:
 *	Also resets an Archer's current speed to its original value.*/
void Archer::reset(){
	cur_hp = max_hp;
	modified_speed = 0;
}




/*	Increases the fighter's current hit points by an amount equal to one sixth of
 *	the fighter's strength.  This method must increase the fighter's current hit
 *	points by at least one.  Do not allow the current hit points to exceed the
 *	maximum hit points.*/
void Archer::regenerate(){

	int hp_point = (strength/ 6);

	if (hp_point == 0 && cur_hp < max_hp){
		cur_hp++;
	}
	else if ((cur_hp + hp_point) <= max_hp){
		cur_hp += hp_point;
	}
	else if ((cur_hp + hp_point) >= max_hp){
		cur_hp = max_hp;
	}


/*	////////////////////////////////////////////////OR////////
	double temphp = (strength / 6) + .5;
	int addpoint = temphp;
	if(addpoint ==0){
	addpoint = 1;}
	if ((cur_hp + addpoint) <= max_hp) {cur_hp += addpoint;}
	else {}
*/
}





/*	Attempts to perform a special ability based on the type of fighter.  The
*	fighter will attempt to use this special ability just prior to attacking
*	every turn.
*		Archer: Quickstep
*	Increases the Archer's speed by one point each time the ability is used.
*	This bonus lasts until the reset() method is used.
*	This ability always works; there is no maximum bonus speed.
*	Return true if the ability was used; false otherwise.*/
bool Archer::useAbility(){
	modified_speed += 1;
	return true;
}





