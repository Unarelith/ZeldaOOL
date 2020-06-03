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
#ifndef INVENTORYCOMPONENT_HPP_
#define INVENTORYCOMPONENT_HPP_

#include <array>
#include <string>

#include <gk/core/input/InputHandler.hpp>

#include "Image.hpp"

class Item {
	public:
		Item(const std::string &name)
			: m_icon("icons-" + name), m_name(name) {}

		Image &icon() { return m_icon; }

		std::string name() const { return m_name; }

	private:
		Image m_icon;

		std::string m_name;
};

class Weapon : public Item {
	public:
		Weapon(const std::string &name, u8 strength = 0)
			: Item(name), m_strength(strength) {}

		u8 strength() const { return m_strength; }

	private:
		u8 m_strength = 0;
};

class InventoryComponent {
	public:
		Weapon *addWeapon(const std::string &name);
		Weapon *getWeapon(u8 x, u8 y) { return m_weapons[x][y]; }
		void removeWeapon(u8 x, u8 y) { m_weapons[x][y] = nullptr; }

		void equipWeapon(u8 x, u8 y, gk::GameKey key);

		Weapon *getWeaponA() { return m_weaponA; }
		Weapon *getWeaponB() { return m_weaponB; }

		void addRupees(u16 rupees) { m_rupees = (m_rupees + rupees > 999) ? 999 : m_rupees + rupees; }
		void removeRupees(u16 rupees) { m_rupees = (m_rupees - rupees < 0) ? 0 : m_rupees - rupees; }

		u16 rupees() const { return m_rupees; }

	private:
		// NOTE: The '{}' are here to value-initialize the pointers (extra braces are needed until C++14)
		std::array<std::array<Weapon*, 4>, 4> m_weapons{{{{}}, {{}}, {{}}, {{}}}};

		Weapon *m_weaponA = nullptr;
		Weapon *m_weaponB = nullptr;

		u16 m_rupees = 197;
};

#endif // INVENTORYCOMPONENT_HPP_
