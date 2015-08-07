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
	
	totalLootChances += dropChances;
	
	LootChance newLootChance = {totalLootChances, item, amount};
	
	lootList.push_back(newLootChance);
}

void LootComponent::dropItem(float x, float y) {
	
	if(itemDropped)
		return;
	
	float random = (float)(rand() % 10000) / 10000;
	
	u8 itr = 0;
	bool lootFound = false;
	
	while(itr < lootList.size() and not lootFound) {
		
		if(lootList[itr].dropRange >= random)
			lootFound = true;
		else
			itr++;
	}
	
	if(lootFound) {
		if(lootList[itr].itemType == Rupees)
			Map::currentMap->scene().addObject(CollectableFactory::createRupees(x, y, lootList[itr].amount, CollectableMovement::Type::Dropped));
		else if(lootList[itr].itemType == Heart)
			Map::currentMap->scene().addObject(CollectableFactory::createHeart(x, y, CollectableMovement::Type::Dropped));
	}
	
	itemDropped = true;
}
