/*
 * =====================================================================================
 *
 *       Filename:  InventoryComponentTests.hpp
 *
 *    Description:  
 *
 *        Created:  21/05/2015 01:24:48
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef INVENTORYCOMPONENTTESTS_HPP_
#define INVENTORYCOMPONENTTESTS_HPP_

#include <cxxtest/TestSuite.h>

#include "InventoryComponent.hpp"
#include "ItemLoader.hpp"
#include "ResourceHandler.hpp"
#include "TextureLoader.hpp"

class InventoryComponentTests : public CxxTest::TestSuite  {
	public:
		InventoryComponentTests() {
			ResourceHandler::getInstance().loadConfigFile<TextureLoader>("data/config/textures.xml");
			ResourceHandler::getInstance().loadConfigFile<ItemLoader>("data/config/items.xml");
		}
		
		void testAdd() {
			InventoryComponent inventory;
			
			inventory.addWeapon("swordL1");
			
			TS_ASSERT_EQUALS(inventory.getWeapon(0, 0)->name(), "swordL1");
		}
		
		void testEquip() {
			InventoryComponent inventory;
			
			Weapon *sword = inventory.addWeapon("swordL1");
			inventory.equipWeapon(0, 0, GameKey::A);
			
			TS_ASSERT_EQUALS(inventory.getWeaponA(), sword);
		}
		
		void testRupees() {
			InventoryComponent inventory;
			
			inventory.addRupees(2130);
			
			TS_ASSERT_EQUALS(inventory.rupees(), 999);
			
			inventory.removeRupees(1351);
			
			TS_ASSERT_EQUALS(inventory.rupees(), 0);
		}
};

#endif // INVENTORYCOMPONENTTESTS_HPP_
