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

struct LootChance {
	float dropRange;
	CollectableType itemType;
	RupeesAmount amount; // Only used for rupees
};

class LootComponent {
	public:
		void addItem(float dropChances, CollectableType item, RupeesAmount amount = One);
		void dropItem(float x, float y);
		
	private:
		bool m_itemDropped = false;
		
		float m_totalLootChances = 0;
		
		std::vector<LootChance> m_lootList;
};

#endif // LOOTCOMPONENT_HPP_
