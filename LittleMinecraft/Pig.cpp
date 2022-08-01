#include "Pig.h"

// Pig default constructor
Pig::Pig() {
	fName = "Pig";
	fSize = SizeType::ADULT;
	fCurrentHealth = 50;
	fMaxHealth = 50;
	fCoordinate[0] = 0;
	fCoordinate[1] = 0;
}

// Pig constructor with five parameters
Pig::Pig(string aName, int aCurrentHealth, SizeType aSize, double aX, double aY) : Creature(aName, aCurrentHealth, aSize, aX, aY) {
	fName = aName;
	fSize = aSize;
	fCurrentHealth = aCurrentHealth;
	fMaxHealth = 50;
	fCoordinate[0] = aX;
	fCoordinate[1] = aY;
}

// Pig destructor
Pig::~Pig() {} 

// Pig eat function
void Pig::Eat(string aItemName) {
	if (aItemName == "Carrot"||"Potato") {
		cout << "Pig eaten your " << aItemName << "!" << endl;
	}
	else {
		cout << "Pig don't eat " << aItemName << "!" << endl;
	}
}

