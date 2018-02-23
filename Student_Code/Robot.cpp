#include "Robot.h"
#include <cmath>

//when does a fighter use its special ability?
Robot::Robot(string name, string type, int max_hp, int strength, int speed, int magic)
	: Fighter(name, type, max_hp, strength, speed, magic)
{
	max_energy = magic * 2;
	cur_energy = max_energy;
	damage = strength;
	bonus_damage = 0;
}

Robot::~Robot()
{
}

int Robot::getDamage() //This value is equal to the Robot's strength plus any additional damage added for having just used its special ability.
 {
	int getdamage = strength + bonus_damage;
	bonus_damage = 0;
	return getdamage;
 }




/*	Restores a fighter's current hit points to its maximum hit points.
 *		Robot:
 *	Also restores a Robot's current energy to its maximum value (which is 2 times its magic).
 *	Also resets a Robot's bonus damage (calculated when a Robot uses its ability) to 0. */
void Robot::reset(){
	cur_energy = max_energy;
	cur_hp = max_hp;
	bonus_damage = 0;
}

/*	Increases the fighter's current hit points by an amount equal to one sixth of
 *	the fighter's strength.  This method must increase the fighter's current hit
 *	points by at least one.  Do not allow the current hit points to exceed the
 *	maximum hit points.*/
void Robot::regenerate(){
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

/*
	/////////////////////////////////////////////////?OR//////////////
	double strong = strength;
	double temphp = (strong / 6);
	int addpoint = temphp;
	if(addpoint ==0){addpoint = 1;}
	if ((cur_hp + hp_point) < max_hp){cur_hp += hp_point;}
	else cur_hp = max_hp;*/

}




	/*  Attempts to perform a special ability based on the type of fighter.  The
	 *	fighter will attempt to use this special ability just prior to attacking
	 *	every turn.
	 *		Robot: Shockwave Punch
	 *	Adds bonus damage to the Robot's next attack (and only its next attack) equal to (strength  * ((current_energy/maximum_energy)^4)).
	 *	Can only be used if the Robot has at least [ROBOT_ABILITY_COST] energy.
	 *	Decreases the Robot's current energy by [ROBOT_ABILITY_COST] (after calculating the additional damage) when used.
	 *		Examples:
	 *		strength=20, current_energy=20, maximum_energy=20		=> bonus_damage=20
	 *		strength=20, current_energy=15, maximum_energy=20		=> bonus_damage=6
	 *		strength=20, current_energy=10, maximum_energy=20		=> bonus_damage=1
	 *		strength=20, current_energy=5,  maximum_energy=20		=> bonus_damage=0
	 *	Robot Note:
	 *	The bonus damage formula should be computed using double arithmetic, and only
	 *	the final result should be cast into an integer.
	 *	Return true if the ability was used; false otherwise. */
bool Robot::useAbility(){

	if (cur_energy >= ROBOT_ABILITY_COST){
		double doublebonus = (strength  * (pow((cur_energy / max_energy), 4)));
		bonus_damage = doublebonus;
		cur_energy -= ROBOT_ABILITY_COST;
		return true;
	}
	else return false;
/*	\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\OR/////////////////////
	double cenery = cur_energy;
	double menergy = max_energy;
	double strong = strength;
	if (cur_energy >= ROBOT_ABILITY_COST){
		double doublebonus = (strength  * (pow((cenergy / menergy), 4)));
		bonus_damage = doublebonus;
		cur_energy = cur_energy - ROBOT_ABILITY_COST;
		return true;
	}
	else return false;
	*/
}
