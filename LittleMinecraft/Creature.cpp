#include "Creature.h"

// Creature default constructor
Creature::Creature() {
	fName = "UnknownCreature";
	fSize = SizeType::BABY;
	fCurrentHealth = 40;
	fMaxHealth = 40;
	fCoordinate[0] = 0;
	fCoordinate[1] = 0;
}

// Creature constructor with five parameters
Creature::Creature(string aName, int aCurrentHealth, SizeType aSize, double aX, double aY) {
	fName = aName;
	fSize = aSize;
	fCurrentHealth = aCurrentHealth;
	fMaxHealth = 40;
	fCoordinate[0] = aX;
	fCoordinate[1] = aY;
}

// Creature destructor
Creature::~Creature() {} 

// get Creature name
string Creature::getName() { return fName; } 

// get Creature size type
SizeType Creature::getSize() { return fSize; } 

// get Creature current health
int Creature::getCurrentHealth() { return fCurrentHealth; } 

// get Creature max health
int Creature::getMaxHealth() { return fMaxHealth; } 

// get Creature coordinate
double Creature::getCoordinate(int aIndex) { return fCoordinate[aIndex]; }

// set Creature name
void Creature::setName(string aName) { fName = aName; } 

// set Creature size type
void Creature::setSize(SizeType aSize) { fSize = aSize; } 

// set Creature current health
void Creature::setCurrentHealth(int aCurrentHealth) { fCurrentHealth = aCurrentHealth; } 

// set Creature max health
void Creature::setMaxHealth(int aMaxHealth) { fMaxHealth = aMaxHealth; } 

// set Creature coordinate
void Creature::setCoordinate(double aX, double aY) { fCoordinate[0] = aX; fCoordinate[1] = aY; }

void Creature::accept(class Visitor& aVisitor){}

