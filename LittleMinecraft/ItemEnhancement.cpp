#include "ItemEnhancement.h"

ItemEnhancement::ItemEnhancement() {}

ItemEnhancement::ItemEnhancement(Item* baseItem) : m_Enhancement(baseItem) {}

ItemEnhancement::~ItemEnhancement() {}

string ItemEnhancement::Description() {
	return m_Enhancement->Description();
}
