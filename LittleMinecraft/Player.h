#pragma once

#include "Item.h"
#include "BaseItem.h"
#include "Sheep.h"
#include "Cow.h"
#include "Pig.h"
#include <iostream>
#include <string>

using namespace std;

class Player {
private:
	// Player id
	string fID; 
	// Player Name
	string fName; 
	// Player current health
	int fCurrentHealth;
	// Player Max health
	int fMaxHealth; 
	// Player Current protection
	int fCurrentProtection; 
	// Player Max Protection
	int fMaxProtection; 
	// coordinate for player
	double fCoordinate[2];
	// Player inventory slots
	Item* fSlot[10]; 

public:
	// player default constructor
	Player(); 
	// player constructor with four parameter
	Player(string aID, string aName, double aX, double aY); 
	// player destructor
	~Player(); 

	// get player id
	string getID(); 
	// get player name
	string getName(); 
	// get player current health
	int getCurrentHealth(); 
	// get player maximum health
	int getMaxHealth(); 
	// get player current protection
	int getCurrentProtection(); 
	// get player maximum protection
	int getMaxProtection(); 
	// get player coordinate
	double getCoordinate(int aIndex);
	// get player inventory's slot item object
	Item* getSlot(int aIndex); 

	// set player id
	void setID(string aID); 
	// set player name
	void setName(string aName); 
	// set player current health
	void setCurrentHealth(int aCurrentHealh); 
	// set player Maximum health
	void setMaxHealth(int aMaxHealth); 
	// set player current protection
	void setCurrentProtection(int aCurrentProtection); 
	// set player maximum protection
	void setMaxProtection(int aMaxProtection); 
	// set player coordinate
	void setCoordinate(double aX, double aY);
	// set player inventory's slot with item obj
	void setSlot(int aIndex, Item* aItem); 
	
	// Output player status
	void Status();
	// Player check inventory is empty
	bool isEmpty();
	// Player check inventory is full
	bool isFull();
	// player check item availability
	bool CheckItem(string aItemName, int aQuantity);
	// player get inventory slot index
	int getSlotIndex(string aItemName);
	// add item into player inventory
	void AddItem(string aID, string aItemName, int aQuantity);
	// remove item into player inventory
	void RemoveItem(string aID, string aItemName, int aQuantity);
	// player craft item
	bool CraftItem(string aItemName);
	// player feed creature
	bool FeedCreature(string aCreatureName, string aItemName);
};

