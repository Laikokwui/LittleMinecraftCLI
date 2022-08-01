#include "Toughness.h"

// Toughness default constructor
Toughness::Toughness() {}

// Toughness constructor with one parameter
Toughness::Toughness(Item* aItem) : ItemEnchancement(aItem) {}

// Toughness destructor
Toughness::~Toughness() {}

// Toughness description
string Toughness::Description() {
	fItem->setID("tough_" + fItem->getID());
	fItem->setName("Tough" + fItem->getName());
	fItem->setDamage(fItem->getDamage() - 3);
	fItem->setDurability(fItem->getDurability() + 8);
	return fItem->Description() + "\nToughness";
}

