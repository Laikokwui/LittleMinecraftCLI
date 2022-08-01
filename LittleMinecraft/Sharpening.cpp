#include "Sharpening.h"

// Sharpening default constructor
Sharpening::Sharpening() {}

// Sharpening constructor with one parameter
Sharpening::Sharpening(Item* aItem) : ItemEnchancement(aItem) {}

// Sharpening destructor
Sharpening::~Sharpening() {}

// Sharpening description
string Sharpening::Description() {
	fItem->setID("sharp_" + fItem->getID());
	fItem->setName("Sharp" + fItem->getName());
	fItem->setDamage(fItem->getDamage() + 10);
	fItem->setDurability(fItem->getDurability() - 2);
	return fItem->Description() + "\nSharpening";
}

