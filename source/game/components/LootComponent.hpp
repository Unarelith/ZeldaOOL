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
