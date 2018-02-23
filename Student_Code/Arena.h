#pragma once
#include <sstream>
//#include <string>
//#include <vector>
//#include <cmath>
#include "ArenaInterface.h"
#include "FighterInterface.h"
#include "Fighter.h"

using namespace std;


class Arena : public ArenaInterface
{
protected:
	vector<FighterInterface*> FighterInventory;

public:
	Arena();
	~Arena();

	bool addFighter(string info);
	bool removeFighter(string name);
	FighterInterface* getFighter(string name);
	int getSize();

};

