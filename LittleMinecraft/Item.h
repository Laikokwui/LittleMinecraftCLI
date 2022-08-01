#pragma once
#include <iostream>

using namespace std;

// Item (Base class)
class Item {
protected:
	// Item Id
	string fID; 
	// Item Name
	string fName; 
	// Item quantity
	int fQuantity; 
	// item damage point
	int fDamage; 
	// item durability
	int fDurability; 

public:
	// Item default constructor
	Item(); 
	Item(string aID, string aName);
	// Item constructor with five parameters
	Item(string aID, string aName, int aQuantity, int aDamage, int aDurability);
	// Item destructor
	~Item(); 

	// get item id
	string getID(); 
	// get item name
	string getName();  
	// get item quantity
	int getQuantity();
	// get item damage
	int getDamage();
	// get item durability
	int getDurability();

	// set item id
	void setID(string aID); 
	// set item name
	void setName(string aName); 
	// set item quantity
	void setQuantity(int aQuantity); 
	// set Item damage
	void setDamage(int aDamage);
	// set item durabiliy
	void setDurability(int aDurability);
	
	// virtual item description
	virtual string Description() = 0;
};

