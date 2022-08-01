#pragma once

#include "Item.h"
#include "BaseItem.h"
#include <iostream>

using namespace std;

class ItemEnhancement : public Item {
protected:
	Item* m_Enhancement;
public:
	ItemEnhancement();
	ItemEnhancement(Item* baseItem);
	~ItemEnhancement();

	string Description();
};

