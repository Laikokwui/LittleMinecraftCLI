#pragma once

#include "CreatureFactory.h"
#include "Cow.h"
#include <iostream>

using namespace std;

// derived class cow factory (Factory method) create cow object
class CowFactory : public CreatureFactory {
public:
	// CowFactory default constructor
	CowFactory();

	// CowFactory destructor
	~CowFactory();

	// CowFactory CreateCreature function
	Creature* CreateCreature();
};

