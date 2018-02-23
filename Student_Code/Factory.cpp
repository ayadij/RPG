#include "Factory.h"
#include "ArenaInterface.h"
#include "FighterInterface.h" // do i really need to include all this? should i not include fighter interface?
#include "Arena.h"
#include "Fighter.h"
#include "Archer.h"
#include "Cleric.h"
#include "Fighter.h"
#include "Robot.h"

//You may add #include statments here

using namespace std;

/*
 *	Unlike all other documents provided, you may modify this document slightly (but do not change its name)
 */
//=======================================================================================
/*
 *	createArena()
 *
 *	Creates and returns an object whose class extends ArenaInterface.
 *	This should be an object of a class you have created.
 *
 *	Example: If you made a class called "Arena", you might say, "return new Arena();".
 */
ArenaInterface* Factory::createArena()
{
	return new Arena(); //Modify this line						/expected type-specifier before Arena();
}
//=======================================================================================
