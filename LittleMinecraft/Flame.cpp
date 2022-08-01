#include "Flame.h"

// Flame default constructor
Flame::Flame() {}

// Flame contructor with one parameter
Flame::Flame(Item* aItem) : ItemEnchancement(aItem) {}

// Flame destructor
Flame::~Flame() {}

// Flame description
string Flame::Description() {
	fItem->setID("flame_" + fItem->getID());
	fItem->setName("Flame" + fItem->getName());
	fItem->setDamage(fItem->getDamage() + 15);
	fItem->setDurability(fItem->getDurability() - 1);
	return fItem->Description() + "\nFlame";
}

