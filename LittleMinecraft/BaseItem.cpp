#include "BaseItem.h"

// BaseItem default constructor
BaseItem::BaseItem() {
	fID = "empty_slot";
	fName = "empty slot";
	fQuantity = 1;
	fDamage = 3;
	fDurability = 10;
}

BaseItem::BaseItem(string aID, string aName) {
	fID = aID;
	fName = aName;
	fQuantity = 1;
	fDamage = 3;
	fDurability = 10;
}

// BaseItem constructor with five parameters
BaseItem::BaseItem(string aID, string aName, int aQuantity, int aDamage, int aDurability) : Item(aID, aName, aQuantity, aDamage, aDurability) {
	fID = aID;
	fName = aName;
	fQuantity = aQuantity;
	fDamage = aDamage;
	fDurability = aDurability;
}

// BaseItem destructor
BaseItem::~BaseItem() {}

// Show baseitem description
string BaseItem::Description() {
	string description = "Item ID: " + getID() + "\nItem Name: " + getName() + "\nDamage: " + to_string(getDamage()) 
		+ "\nDurability: " + to_string(getDurability()) + "\nEnhancements:";
	return description;
}

