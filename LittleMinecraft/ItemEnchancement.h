#pragma once
#include "Item.h"

class ItemEnchancement : public Item {
protected:
    Item* fItem;
public:
    ItemEnchancement();
    ItemEnchancement(Item* aItem);
    ~ItemEnchancement();

    virtual string Description() = 0;
};

