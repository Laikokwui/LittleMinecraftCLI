#pragma once
#include "ItemEnchancement.h"

class Toughness : public ItemEnchancement {
public:
	// Toughness default constructor
	Toughness();
	// Toughness constructor with one parameter
	Toughness(Item* aItem);
	// Toughness destructor
	~Toughness();

	// Toughness description
	string Description();
};

