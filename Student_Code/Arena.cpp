#include <sstream>
#include "Arena.h"
#include "Archer.h"
#include "Cleric.h"
#include "Robot.h"

Arena::Arena(){}
Arena::~Arena(){}


/*	addFighter(string)
 *	Adds a new fighter to the collection of fighters in the arena. Do not allow
 *	duplicate names.  Reject any string that does not adhere to the format
 *	outlined in the lab specs.
 *
 *	Return true if a new fighter was added; false otherwise.*/
bool Arena::addFighter(string info)
{
	stringstream ss(info);
	string name;
	string type;
	int max_hp;
	int strength;
	int speed;
	int magic;
	int check = -1;
	const int unique = -1;
	bool error = false;

	//ss >> name >> type >> max_hp >> strength >> speed >> magic

	ss >> name;
	if (ss.fail()) {error = true;}

	ss >> type;
	if (ss.fail() || ((type != "R") && (type != "A") && (type != "C"))) {error = true;}

	ss >> max_hp;
	if (ss.fail() || (max_hp < 1)) {error = true;}

	ss >> strength;
	if (ss.fail() || (strength <= 0)) {	error = true;}

	ss >> speed;
	if (ss.fail() || (speed <= 0)) {error = true;}

	ss >> magic;
	if (ss.fail()|| (magic <= 0)) {error = true;}

	if(getline(ss, info)){
		error = true;
	}


	for (int i = 0; i < FighterInventory.size(); i++){
		if (name == FighterInventory[i]->getName()){
			check = i;
		}
		else check = unique;
	}

	if (check == unique && !error){
		if (type == "R"){
			FighterInterface* newRobot = new Robot(name, type, max_hp, strength, speed, magic);
			FighterInventory.push_back(newRobot);
		}
		if (type == "A"){
			FighterInterface* newArcher = new Archer(name, type, max_hp, strength, speed, magic);
			FighterInventory.push_back(newArcher);
		}
		if (type == "C"){
			FighterInterface* newCleric = new Cleric(name, type, max_hp, strength, speed, magic);
			FighterInventory.push_back(newCleric);
		}
		return true;
	}
	else return false;
}


/*	removeFighter(string)
 *	Removes the fighter whose name is equal to the given name.  Does nothing if
 *	no fighter is found with the given name.
 *	Return true if a fighter is removed; false otherwise.*/
bool Arena::removeFighter(string name)
{
	const int unique = -1;
	int check = -1;
	for (int i = 0; i < FighterInventory.size(); i++){
		if (name == FighterInventory[i]->getName()){
			FighterInventory.erase(FighterInventory.begin() + i);
			check = i;
		}
	}
	if(check != unique) {return true;}
	else {return false;}
}


/*	getFighter(string)
*	Returns the memory address of a fighter whose name is equal to the given
*	name.  Returns NULL if no fighter is found with the given name.
*	Return a memory address if a fighter is found; NULL otherwise.*/
FighterInterface* Arena::getFighter(string name)
{
	int check = -1;
	const int unique = -1;
	for (int i = 0; i < FighterInventory.size(); i++){
		if (name == FighterInventory[i]->getName()){
			return FighterInventory[i];
			check = i;
		}
		else check = unique;
	}
	if(check == unique) {return NULL;}
}


/*	getSize()
*	Returns the number of fighters in the arena.
*	Return a non-negative integer.*/
int Arena::getSize()
{
	return FighterInventory.size();
}



