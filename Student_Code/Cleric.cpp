#include "Cleric.h"

Cleric::Cleric(string name, string type, int max_hp, int strength, int speed, int magic)
	: Fighter(name, type, max_hp, strength, speed, magic)
{
	damage = magic;
	max_mana = magic * 5;
	cur_mana = max_mana;
}

Cleric::~Cleric(){}


int Cleric::getDamage()
 {
	return damage;
 }

void Cleric::reset(){
	cur_hp = max_hp;
	cur_mana = max_mana;
}


/*	Increases the fighter's current hit points by an amount equal to one sixth of
 *	the fighter's strength.  This method must increase the fighter's current hit
 *	points by at least one.  Do not allow the current hit points to exceed the
 *	maximum hit points.
*		Cleric:
*	Also increases a Cleric's current mana by an amount equal to one fifth of the
*	Cleric's magic.  This method must increase the Cleric's current mana by at
*	least one.Do not allow the current mana to exceed the maximum mana(again, 5 times its magic).*/
void Cleric::regenerate(){

//	std::cout << hp_point << ": hp_point\n";
	//std::cout << cur_hp << ": cur_hp\n";

	int mana_point = (magic/ 5);
	if (mana_point == 0 && (cur_mana < max_mana)){
		cur_mana++;
	}
	else if ((cur_mana + mana_point) < max_hp){
		cur_mana += mana_point;
	}
	else if ((cur_mana + mana_point) >= max_hp){
		cur_mana = max_mana;
	}//ok, we're good

	int hp_point = (strength / 6);
	//std::cout << hp_point << ": hp_point\n";
	//std::cout << cur_hp << ": cur_hp\n";
	if (hp_point == 0 && cur_hp < max_hp){
		cur_hp++;
		//std::cout << hp_point << ": hp_point\n";
		//std::cout << cur_hp << ": cur_hp\n";
	}
	else if ((cur_hp + hp_point) < max_hp){
		cur_hp += hp_point;
		//std::cout << hp_point << ": hp_point\n";
		//std::cout << cur_hp << ": cur_hp\n";
	}
	else if ((cur_hp + hp_point) >= max_hp){
		cur_hp = max_hp;
		//std::cout << hp_point << ": hp_point\n";
		//std::cout << cur_hp << ": cur_hp\n";
	}



/*/////////////////////////////////////////////////////////////OR/////////
	double strong = strength;
	double temphp = (strong / 6);
	int addpoint = temphp;
	if(addpoint ==0){addpoint = 1;}
	if ((cur_hp + addpoint) < max_hp){cur_hp += hp_point;}
	else cur_hp = max_hp;

	double magik = magic;
	double tempmana = (magik / 5);
	int addmana = tempmana;
	if ((cur_mana + addmana) < max_mana){cur_mana += mana_point;}
	else cur_mana = max_mana;
*/
}



/*	Attempts to perform a special ability based on the type of fighter.  The
 *	fighter will attempt to use this special ability just prior to attacking
 *	every turn.
 *		Cleric: Healing Light
 *	Increases the Cleric's current hit points by an amount equal to one third of its magic.
 *	Can only be used if the Cleric has at least [CLERIC_ABILITY_COST] mana.
 *	Will be used even if the Cleric's current HP is equal to their maximum HP.
 *	Decreases the Cleric's current mana by [CLERIC_ABILITY_COST] when used.
 *	Cleric Note:
 *	This ability, when successful, must increase the Cleric's current hit points
 *	by at least one, unless doing so would given the Cleric more hit points than its maximum hit points.
 *	Do not allow the current hit points to exceed the maximum hit points.
 *	Return true if the ability was used; false otherwise.*/
bool Cleric::useAbility(){

	double doublebonus = (magic / 3);

	int bonus_pts = doublebonus;


	if (cur_mana >= CLERIC_ABILITY_COST){

		if ((cur_hp + bonus_pts) > max_hp){
			cur_hp = max_hp;
		}
		else cur_hp += bonus_pts;
		cur_mana -= CLERIC_ABILITY_COST;
		return true;
	}
	else return false;
		/*//////////////////////////////////////////////OR///////////
	double magik + magic;
	double tempbonus = (magik/3);
	int bonuspts = tempbonus;
	if(cur_mana >= CLERIC_ABILITY_COST){
		if((cur_hp + bonuspts) <= ma_hp){
			cur_hp += bonuspts;
		}
	else cur_hp = max_hp;
	cur_mana -= CLERIC_ABLILITY_COST;
	}
	else return false;*/
}




