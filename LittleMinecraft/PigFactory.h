#pragma once

#include "CreatureFactory.h"
#include "Pig.h"
#include <iostream>

using namespace std;

// PigFactory (derived class to CreatureFactory)
class PigFactory : public CreatureFactory {
public:
	// PigFactory default constructor
	PigFactory();

	// PigFactory destructor
	~PigFactory();

	// PigFactory CreateCreature function
	Creature* CreateCreature(); 
};

