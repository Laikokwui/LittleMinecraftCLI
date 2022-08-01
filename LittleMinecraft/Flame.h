#pragma once
#include "ItemEnchancement.h"

class Flame : public ItemEnchancement {
public:
	// Flame default constructor
	Flame();
	// Flame contructor with one parameter
	Flame(Item* aItem);
	// Flame destructor
	~Flame();

	// Flame description
	string Description();
};

