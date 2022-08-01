#pragma once

#include <iostream>

using namespace std;

enum class SizeType { BABY, ADULT };

// Creature (Base Class)
class Creature {
protected:
	// Creature name
	string fName; 

	// Creature size type
	SizeType fSize;

	// Creature current health
	int fCurrentHealth; 

	// Creature max health
	int fMaxHealth; 

	// Creature coordinate
	double fCoordinate[2]; 
public:
	// Creature default constructor
	Creature(); 

	// Creature constructor with five parameters
	Creature(string aName, int aCurrentHealth, SizeType aSize, double aX, double aY); 

	// Creature destructor
	~Creature();

	// get Creature name
	string getName();

	// get Creature size type
	SizeType getSize();

	// get Creature current health
	int getCurrentHealth();

	// get Creature maximum health
	int getMaxHealth();

	// get Creature coordinate
	double getCoordinate(int aIndex);

	// set Creature name
	void setName(string aName);

	// set Creature size type
	void setSize(SizeType aSize);

	// set Creature current health
	void setCurrentHealth(int aCurrentHealth);

	// set Creature max health
	void setMaxHealth(int aMaxHealth); 

	// set Creature's coordinate
	void setCoordinate(double aX, double aY);

	// Creature eat function
	virtual void Eat(string aItemName) = 0;

	// Creature accept funtion
	void accept(class Visitor& aVisitor); 
};

