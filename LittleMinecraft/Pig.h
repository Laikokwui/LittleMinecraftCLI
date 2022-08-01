#pragma once

#include "Creature.h"
#include <iostream>

using namespace std;

// Pig (derived class to Creature)
class Pig : public Creature {
public:
	// Pig default constructor
	Pig(); 

	// Pig constructor with five parameters
	Pig(string aName, int aCurrentHealth, SizeType aSize, double aX, double aY);

	// Pig destructor
	~Pig(); 

	// Pig eat function
	void Eat(string aItemName);

	// Pig accept function
	void accept(Visitor& aVisitor);
};

