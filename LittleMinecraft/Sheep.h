#pragma once

#include "Creature.h"
#include <iostream>

using namespace std;

// Wool colour type enum
enum class ColourType { RED, YELLOW, ORANGE, LIGHTBLUE, BLUE, LIME, GREEN, PURPLE, BROWN, LIGHTGREY, WHITE, BLACK, PINK };

// Sheep (derived class to Creature)
class Sheep : public Creature {
private:
	// Sheep's wool colour type enum
	ColourType fWoolColour;
public:
	// Sheep default constructor
	Sheep(); 

	// Sheep constructor with six parameters
	Sheep(string aName, int aCurrentHealth, SizeType aSize, ColourType aWoolColour, double aX, double aY);

	// Sheep destructor
	~Sheep(); 

	// get Sheep wool colour
	ColourType getColour();

	// set Sheep wool colour
	void setColour(ColourType aWoolColour);

	// Sheep eat function
	void Eat(string aItemName);

	// Sheep accept function
	void accept(Visitor& aVisitor);
};

