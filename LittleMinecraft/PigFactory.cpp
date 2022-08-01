#include "PigFactory.h"

// PigFactory default constructor
PigFactory::PigFactory() {}

// PigFactory destructor
PigFactory::~PigFactory() {}

// PigFactory CreateCreature function
Creature* PigFactory::CreateCreature() {
	return new Pig();
}

