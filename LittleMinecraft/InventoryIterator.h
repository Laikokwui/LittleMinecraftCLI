#pragma once
#include "Player.h"
#include "ItemMap.h"
#include <iostream>

using namespace std;

class InventoryIterator {
private:
	ItemMap fInventory[10]; // all the item to iterate
	int fIndex; // index of the inventory 
public:
	InventoryIterator(Player& aPlayer); // initialize all fInventory from player class getSlot() and ItemMap
	InventoryIterator(const InventoryIterator& aIter, int aIndex); // Used by auxiliary, create a copy but at a specific position
	~InventoryIterator(); // Destructor

	const ItemMap& operator*() const; // Dereference operator, returns current value/fMap at the current position
	InventoryIterator& operator++(); // prefix ++i, increment and return the iterator
	InventoryIterator operator++(int); // postfix i++, return the iterator (old position) then increment

	// Equivalence methods to compare two iterators
	bool operator==(const InventoryIterator& aOther) const; 
	bool operator!=(const InventoryIterator& aOther) const;

	// Auxiliary methods, to return begin and end positions
	InventoryIterator begin();
	InventoryIterator end();
};

