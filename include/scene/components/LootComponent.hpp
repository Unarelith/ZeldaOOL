/*
 * =====================================================================================
 *
 *       Filename:  LootComponent.hpp
 *
 *    Description:
 *
 *        Created:  02/08/2015 19:30:00
 *
 *         Author:  Akromha, <maxinus.nr@gmail.com>
 *
 * =====================================================================================
 */
#ifndef LOOTCOMPONENT_HPP_
#define LOOTCOMPONENT_HPP_

#include "Map.hpp"
#include "CollectableFactory.hpp"

#include <vector>

typedef struct {
	float dropRange;
	CollectableType itemType;
	RupeesAmount amount; //Used only for rupees
} LootChance;

class LootComponent {
	public:
		LootComponent() {}
		
		void addItem(float dropChances, CollectableType item, RupeesAmount amount = One);
		void dropItem(float x, float y);
		
	private:
		bool itemDropped = false;
		float totalLootChances = 0;
		
		std::vector<LootChance> lootList;
};

#endif // LOOTCOMPONENT_HPP_
