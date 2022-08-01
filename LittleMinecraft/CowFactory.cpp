#include "CowFactory.h"

// CowFactory default constructor
CowFactory::CowFactory() {}

// CowFactory destructor
CowFactory::~CowFactory() {} 

// CowFactory CreateCreature function
Creature* CowFactory::CreateCreature() {
	return new Cow();
}

