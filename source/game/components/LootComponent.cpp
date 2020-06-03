/*
 * =====================================================================================
 *
 *  ZeldaOOL
 *
 *  Copyright (C) 2014-2020 Unarelith, Quentin Bazin <zelda.ool@unarelith.net>
 *
 *  This file is part of ZeldaOOL.
 *
 *  ZeldaOOL is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  ZeldaOOL is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with ZeldaOOL; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA  02110-1301 USA
 *
 * =====================================================================================
 */
#include "LootComponent.hpp"
#include "World.hpp"

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
			World::getInstance().currentMap()->scene().addObject(CollectableFactory::createRupees(x, y, m_lootList[i].amount, CollectableMovement::Type::Dropped));
		}
		else if(m_lootList[i].itemType == Heart) {
			World::getInstance().currentMap()->scene().addObject(CollectableFactory::createHeart(x, y, CollectableMovement::Type::Dropped));
		}
	}

	m_itemDropped = true;
}
