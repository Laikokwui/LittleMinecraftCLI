#pragma once
#include "ItemEnchancement.h"

class Sharpening : public ItemEnchancement {
public:
	// Sharpening default constructor
	Sharpening();
	// Sharpening constructor with one parameter
	Sharpening(Item* aItem);
	// Sharpening destructor
	~Sharpening();

	// Sharpening description
	string Description();
};

