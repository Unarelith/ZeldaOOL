/*
 * =====================================================================================
 *
 *       Filename:  LootComponent.cpp
 *
 *    Description:
 *
 *        Created:  05/08/2015 22:53:00
 *
 *         Author:  Akromha, <maxinus.nr@gmail.com>
 *
 * =====================================================================================
 */
#include "LootComponent.hpp"

void LootComponent::addItem(float dropChances, CollectableType item, RupeesAmount amount) {
	m_totalLootChances += dropChances;

	m_lootList.emplace_back(LootChance{m_totalLootChances, item, amount});
}

void LootComponent::dropItem(float x, float y) {
	if(m_itemDropped) return;

	float random = (float)(rand() % 10000) / 10000;

	u8 i = 0;
	bool lootFound = false;
	while(i < m_lootList.size() && !lootFound) {
		if(m_lootList[i].dropRange >= random) {
			lootFound = true;
		} else {
			i++;
		}
	}

	if(lootFound) {
		if(m_lootList[i].itemType == Rupees) {
			Map::currentMap->scene().addObject(CollectableFactory::createRupees(x, y, m_lootList[i].amount, CollectableMovement::Type::Dropped));
		}
		else if(m_lootList[i].itemType == Heart) {
			Map::currentMap->scene().addObject(CollectableFactory::createHeart(x, y, CollectableMovement::Type::Dropped));
		}
	}

	m_itemDropped = true;
}
