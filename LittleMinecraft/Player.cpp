#include "Player.h"

// Default Constructor
Player::Player() {
	fID = "0001";
	fName = "Steve";
	fCurrentHealth = 100;
	fMaxHealth = 100;
	fCurrentProtection = 0;
	fMaxProtection = 100;
	fCoordinate[0] = 0;
	fCoordinate[1] = 0;
}

// Constructor with two parameter
Player::Player(string aID, string aName, double aX, double aY) {
	fID = aID;
	fName = aName;
	fCurrentHealth = 100;
	fMaxHealth = 100;
	fCurrentProtection = 0;
	fMaxProtection = 100;
	fCoordinate[0] = aX;
	fCoordinate[1] = aY;
}

// Player Class Destructor
Player::~Player() {} 

// get player id
string Player::getID() { return fID; } 

// get player name
string Player::getName() { return fName; } 

// get player current health
int Player::getCurrentHealth() { return fCurrentHealth; } 

// get player maxhealth
int Player::getMaxHealth() { return fMaxHealth; } 

// get player current protection
int Player::getCurrentProtection() { return fCurrentProtection; } 

// get player max protection
int Player::getMaxProtection() { return fMaxProtection; } 

// get player coordinate
double Player::getCoordinate(int aIndex) { return fCoordinate[aIndex]; }

// get player slot detail
Item* Player::getSlot(int aIndex) { return fSlot[aIndex]; }

// set player id
void Player::setID(string aID) { fID = aID; } 

// set player name
void Player::setName(string aName) { fName = aName; } 

// set player current health
void Player::setCurrentHealth(int aCurrentHealth) { fCurrentHealth = aCurrentHealth; } 

// set player max health
void Player::setMaxHealth(int aMaxHealth) { fMaxHealth = aMaxHealth; } 

// set player current protection

void Player::setCurrentProtection(int aCurrentProtection) { fCurrentProtection = aCurrentProtection; } 

// set player maximum protection
void Player::setMaxProtection(int aMaxProtection) { fMaxProtection = aMaxProtection; } 

// set player coordinate
void Player::setCoordinate(double aX, double aY) { fCoordinate[0] = aX; fCoordinate[1] = aY; } 

// set player slot value
void Player::setSlot(int aIndex, Item* aItem) { fSlot[aIndex] = aItem; } 

void Player::Status() {
	cout << "Player Status:" << endl;
	cout << "(ID) Name: " << "(" << getID() << ") " << getName() << endl;
	cout << "Health: " << getCurrentHealth() << "/" << getMaxHealth() << endl;
	cout << "Protection: " << getCurrentProtection() << "/" << getMaxProtection() << endl;
	cout << "Coordinate: " << getCoordinate(0) << "," << getCoordinate(1) << endl;
	cout << "" << endl;
}

// check plaer inventory is full
bool Player::isEmpty() {
	bool empty = true;
	for (int i = 0; i < 10; i++) {
		if (getSlot(i)->getName() != "empty slot") {
			empty = false;
			i = 10;
		}
	}
	return empty;
}

// check plaer inventory is full
bool Player::isFull() {
	bool full = true;
	for (int i = 0; i < 10; i++) {
		if (getSlot(i)->getName() == "empty slot") {
			full = false;
			i = 10;
		}
	}
	return full;
}

// check item availability
bool Player::CheckItem(string aItemName, int aQuantity) {
	bool found = false;
	for (int i = 0; i < 10; i++) {
		if (getSlot(i)->getName() == aItemName && getSlot(i)->getQuantity() >= aQuantity) {
			found = true;
			i = 10;
		}
		else {
			found = false;
		}
	}
	return found;
}

// player get inventory slot index
int Player::getSlotIndex(string aItemName) {
	int index = 0;
	for (int i = 0; i < 10; i++) {
		if (getSlot(i)->getName() == aItemName) {
			index = i;
			i = 10;
		}
	}
	return index;
}

// add item into player inventory
void Player::AddItem(string aID, string aItemName, int aQuantity) {
	if (!isFull()) {
		if (CheckItem(aItemName, 1)) {
			for (int i = 0; i < 10; i++) {
				if (getSlot(i)->getID() == aID && getSlot(i)->getName() == aItemName) {
					getSlot(i)->setQuantity(getSlot(i)->getQuantity() + aQuantity);
					i = 10;
				}
			}
		}
		else {
			for (int i = 0; i < 10; i++) {
				if (getSlot(i)->getName() == "empty slot") {
					getSlot(i)->setID(aID);
					getSlot(i)->setName(aItemName);
					getSlot(i)->setQuantity(aQuantity);
					i = 10;
				}
			}
		}
	}
	else {
		cout << "Your Inventory is full!" << endl;
	}
}

// remove item into player inventory
void Player::RemoveItem(string aID, string aItemName, int aQuantity) {
	if (!isEmpty()) {
		for (int i = 0; i < 10; i++) {
			if (getSlot(i)->getID() == aID && getSlot(i)->getName() == aItemName) {
				getSlot(i)->setQuantity(getSlot(i)->getQuantity() - aQuantity);
				if (getSlot(i)->getQuantity() == 0) {
					getSlot(i)->setID("empty_slot");
					getSlot(i)->setName("empty slot");
					getSlot(i)->setQuantity(1);
				}
				i = 10;
			}
		}
	}
	else {
		cout << "Your Inventory is empty!" << endl;
	}
	
}

// player craft item
bool Player::CraftItem(string aItemName) {
	bool crafted = false;
	if (aItemName == "Pickaxe" || aItemName == "Axe") {
		if (CheckItem("Wood", 3) && CheckItem("Stick", 2)) {
			RemoveItem("wood", "Wood", 3);
			RemoveItem("stick", "Stick", 2);
			if (aItemName == "Pickaxe") {
				AddItem("pickaxe", "Pickaxe", 1);
				cout << "You crafted a Pickaxe!" << endl;
			}
			else if (aItemName == "Axe") {
				AddItem("axe", "Axe", 1);
				cout << "You crafted an Axe!" << endl;
			}
			crafted = true;
		}
		else {
			cout << "Sorry you do not have enough wood and stick" << endl;
			crafted = false;
		}
	}
	else if (aItemName == "Sword") {
		if (CheckItem("Wood", 2) && CheckItem("Stick", 1)) {
			RemoveItem("wood", "Wood", 2);
			RemoveItem("stick", "Stick", 1);
			AddItem("sword", "Sword", 1);
			cout << "You crafted a Sword!" << endl;
			crafted = true;
		}
		else {
			cout << "Sorry you do not have enough wood and stick!" << endl;
			crafted = false;
		}
	}
	else {
		cout << "Sorry you do not know how to craft " << aItemName << "!" << endl;
		crafted = false;
	}
	return crafted;
}

// player feed creature
bool Player::FeedCreature(string aCreatureName, string aItemName) {
	bool feed = false;
	if (aCreatureName == "Sheep") {
		Sheep s;
		s.Eat(aItemName);
		feed = true;
	}
	else if (aCreatureName == "Cow") {
		Cow c;
		c.Eat(aItemName);
		feed = true;
	}
	else if (aCreatureName == "Pig") {
		Pig p;
		p.Eat(aItemName);
		feed = true;
	}
	else {
		cout << "There are no " << aCreatureName << " around!" << endl;
		feed = false;
	}
	return feed;
}

