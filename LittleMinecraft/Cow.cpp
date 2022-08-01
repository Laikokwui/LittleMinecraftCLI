#include "Cow.h"

// Cow default constructor
Cow::Cow() {
	fName = "Cow";
	fSize = SizeType::ADULT;
	fCurrentHealth = 50;
	fMaxHealth = 50;
	fCoordinate[0] = 0;
	fCoordinate[1] = 0;
}

// Cow constructor with five parameters
Cow::Cow(string aName, int aCurrentHealth, SizeType aSize, double aX, double aY) : Creature(aName, aCurrentHealth, aSize, aX, aY) {
	fName = aName;
	fSize = aSize;
	fCurrentHealth = aCurrentHealth;
	fMaxHealth = 50;
	fCoordinate[0] = aX;
	fCoordinate[1] = aY;
}

// Cow destructor
Cow::~Cow() {} 

// Cow eat function
void Cow::Eat(string aItemName) {
	if (aItemName == "Wheat") {
		cout << "Cow eaten your " << aItemName << "!" << endl;
	}
	else {
		cout << "Cow don't eat " << aItemName << "!" << endl;
	}
}

// Cow milk function
void Cow::Milk(string aItemName) {
	if (aItemName == "Bucket") {
		cout << "You fill the " << aItemName << " with Milk!" << endl;
	}
	else {
		cout << "You cannot collect milk with " << aItemName << "!" << endl;
	}
}

