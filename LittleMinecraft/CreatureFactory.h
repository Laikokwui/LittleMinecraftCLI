#pragma once

#include "Creature.h"
#include "Visitor.h"
#include <iostream>

using namespace std;

// Base class (CreatureFactory)
class CreatureFactory {
public:
	// Creature Factory default constructor
	CreatureFactory();

	// Creature Factory destructor
	~CreatureFactory(); 

	// Creature Factory CreateCreature function
	virtual Creature* CreateCreature() = 0; 
};

