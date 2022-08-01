#include "SheepFactory.h"

// SheepFactory default constructor
SheepFactory::SheepFactory() {}

// SheepFactory destructor
SheepFactory::~SheepFactory() {}

// SheepFactory CreateCreature function
Creature* SheepFactory::CreateCreature() {
	return new Sheep(); // return new sheep
}

