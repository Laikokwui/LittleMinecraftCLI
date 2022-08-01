#pragma once

#include "Item.h"
#include <iostream>
#include <string>

using namespace std;

// BaseItem (derived class to Item)
class BaseItem : public Item {
public:
	// BaseItem default constructor
	BaseItem();
	BaseItem(string aID, string aName);
	// BaseItem constructor with five parameters
	BaseItem(string aID, string aName, int aQuantity, int aDamage, int aDurability);
	// BaseItem destructor
	~BaseItem(); 

	// Show baseitem description
	string Description();
};

