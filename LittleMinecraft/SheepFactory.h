#pragma once

#include "CreatureFactory.h"
#include "Sheep.h"
#include <iostream>

using namespace std;

// SheepFactory (derived class of CreatureFactory)
class SheepFactory : public CreatureFactory {
public:
	// SheepFactory default constructor
	SheepFactory(); 

	// SheepFactory destructor
	~SheepFactory(); 

	// SheepFactory CreateCreature function
	Creature* CreateCreature(); 
};

