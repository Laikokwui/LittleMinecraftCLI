#include "Sheep.h"

// Sheep default constructor
Sheep::Sheep() {
	fName = "Sheep";
	fSize = SizeType::ADULT;
	fWoolColour = ColourType::WHITE;
	fCurrentHealth = 50;
	fMaxHealth = 50;
	fCoordinate[0] = 0;
	fCoordinate[1] = 0;
}

// Sheep constructor with two parameter
Sheep::Sheep(string aName, int aCurrentHealth, SizeType aSize, ColourType aWoolColour, double aX, double aY) : Creature(aName, aCurrentHealth, aSize, aX, aY) {
	fName = aName;
	fSize = aSize;
	fWoolColour = aWoolColour;
	fCurrentHealth = aCurrentHealth;
	fMaxHealth = 50;
	fCoordinate[0] = aX;
	fCoordinate[1] = aY;
}

// Sheep destructor
Sheep::~Sheep() {}

// get Sheep wool colour
ColourType Sheep::getColour() { return fWoolColour; }

// set Sheep wool colour
void Sheep::setColour(ColourType aWoolColour) { fWoolColour = aWoolColour; }

// Sheep eat function
void Sheep::Eat(string aItemName) {
	if (aItemName == "Wheat") {
		cout << "Sheep eaten your " << aItemName << "!" << endl;
	}
	else {
		cout << "Sheep don't eat " << aItemName << "!" << endl;
	}
}

