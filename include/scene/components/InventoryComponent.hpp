/*
 * =====================================================================================
 *
 *       Filename:  InventoryComponent.hpp
 *
 *    Description:  
 *
 *        Created:  15/05/2015 19:15:32
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef INVENTORYCOMPONENT_HPP_
#define INVENTORYCOMPONENT_HPP_

#include <map>
#include <string>

#include "Image.hpp"
#include "ResourceHandler.hpp"
#include "Vector2.hpp"

class Item {
	public:
		Item(const std::string &name)
			: m_icon("icons-" + name), m_name(name), m_description(name + "_description") {}
		
		Image &icon() { return m_icon; }
		
		std::string name() const { return m_name; }
		std::string description() const { return m_description; }
		
	protected:
		Image m_icon;
		
	private:
		std::string m_name;
		std::string m_description;
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
		void addWeapon(Vector2i position, const std::string &name) {
			weapons.emplace(position, ResourceHandler::getInstance().get<Weapon>("weapon-" + name));
		}
		
		std::map<Vector2i, Weapon&> weapons;
};

#endif // INVENTORYCOMPONENT_HPP_
