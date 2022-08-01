#pragma once

#include "Creature.h"
#include <iostream>

using namespace std;

// Cow (derived class to Creature)
class Cow : public Creature {
public:
	// Cow default contructor
	Cow(); 

	// Cow constructor with two parameters
	Cow(string aName, int aCurrentHealth, SizeType aSize, double aX, double aY);

	// Cow destructor
	~Cow(); 

	// Cow eat function
	void Eat(string aItemName);

	// Cow milk function
	void Milk(string aItemName);

	// Cow accept function
	void accept(Visitor& aVisitor);
};

