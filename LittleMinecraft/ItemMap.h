#pragma once
#include <iostream>

using namespace std;

// Item map is use to map out all the items from player inventory
// This help because the iterator need const value
class ItemMap {
private:
	string fName; // Item Name
	int fQuantity; // Item Quantity
public:
	ItemMap(); // default contructor
	ItemMap(string aName, int aQuantity); // contructor with two parameter
	~ItemMap(); // destructor

	//read-only getter 
	string getName() const;
	int getQuantity() const;
};

