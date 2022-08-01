#include "Item.h"

// Item default constructor
Item::Item() {
	fID = "empty_slot";
	fName = "empty slot";
	fQuantity = 1;
	fDamage = 3;
	fDurability = 10;
}

Item::Item(string aID, string aName) {
	fID = aID;
	fName = aName;
	fQuantity = 1;
	fDamage = 3;
	fDurability = 10;
}

// Item constructor with four parameters
Item::Item(string aID, string aName, int aQuantity, int aDamage, int aDurability) {
	fID = aID;
	fName = aName;
	fQuantity = aQuantity;
	fDamage = aDamage;
	fDurability = aDurability;
}

Item::~Item() {} // destructor

// get item id
string Item::getID() { return fID; } 
// get item name
string Item::getName() { return fName; } 
// get item quantity
int Item::getQuantity() { return fQuantity; } 
// get Item damage
int Item::getDamage() { return fDamage; }
// get item durabiliy
int Item::getDurability() { return fDurability; }

// set item id
void Item::setID(string aID) { fID = aID; } 
// set item name
void Item::setName(string aName) { fName = aName; } 
// set the item quantity
void Item::setQuantity(int aQuantity) { fQuantity = aQuantity; } 
// set Item damage
void Item::setDamage(int aDamage) { fDamage = aDamage; }
// set item durabiliy
void Item::setDurability(int aDurability) { fDurability = aDurability; }

