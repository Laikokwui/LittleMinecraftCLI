#include "InventoryIterator.h"

// initialize all fInventory from player class getSlot() and ItemMap
InventoryIterator::InventoryIterator(Player& aPlayer) {
	fIndex = 0;
	Item* aItem;
	for (int i = fIndex; i < 10; i++) {
		aItem = aPlayer.getSlot(i); // using player class getSlot to get the item object
		fInventory[i] = ItemMap(aItem->getName(), aItem->getQuantity()); // create ItemMap and store the item value in!
	}
}

// Used by auxiliary, create a copy but at a specific position
InventoryIterator::InventoryIterator(const InventoryIterator& aIter, int aIndex) {
	fIndex = aIndex;
	for (int i = 0; i < 10; i++) {
		fInventory[i] = aIter.fInventory[i];
	}
}

InventoryIterator::~InventoryIterator() {} // Destructor

// Dereference operator, returns current value/fMap at the current position
const ItemMap& InventoryIterator::operator*() const{
	return fInventory[fIndex]; // return the item
}

// prefix ++i, increment and return the iterator
InventoryIterator& InventoryIterator::operator++() {
	fIndex++;
	return *this;
}

// postfix i++, return the iterator (old position) then increment
InventoryIterator InventoryIterator::operator++(int) {
	InventoryIterator temp = *this;
	++(*this);
	return temp;
}

// Equivalence methods to compare two iterators, used together with begin/end e.g iter != iter.end()
bool InventoryIterator::operator==(const InventoryIterator& aOther) const {
	return (fIndex == aOther.fIndex);
}

bool InventoryIterator::operator!=(const InventoryIterator& aOther) const {
	return !(*this == aOther);
}

// Auxiliary methods, to return a copy of the iterator but now at the beginning and end positions
InventoryIterator InventoryIterator::begin() {
	return *this; 
}

InventoryIterator InventoryIterator::end() {
	return InventoryIterator(*this, 10); // last element from fInventory
}
