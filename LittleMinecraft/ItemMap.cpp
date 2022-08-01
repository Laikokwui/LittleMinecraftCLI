#include "ItemMap.h"

// default constructor
ItemMap::ItemMap() {}

// constructor with two parameter
ItemMap::ItemMap(string aName, int aQuantity) {
	fName = aName;
	fQuantity = aQuantity;
}

ItemMap::~ItemMap() {} // destructor

// getter for item name and item quantity
string ItemMap::getName() const { return fName; }
int ItemMap::getQuantity() const { return fQuantity; }

