/*
 * =====================================================================================
 *
 *       Filename:  StatsBar.cpp
 *
 *    Description:
 *
 *        Created:  15/09/2014 23:34:53
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include <cmath>

#include "HealthComponent.hpp"
#include "InventoryComponent.hpp"
#include "Scene.hpp"
#include "StatsBar.hpp"

void StatsBar::update() {
	auto &playerInventory = Scene::player->get<InventoryComponent>();

	Weapon *weaponA = playerInventory.getWeaponA();
	Weapon *weaponB = playerInventory.getWeaponB();

	if(weaponA) weaponA->icon().setPosition(46, -1);
	if(weaponB) weaponB->icon().setPosition(6, -1);
}

void StatsBar::draw(RenderTarget &target, RenderStates states) const {
	target.draw(m_background, states);

	// FIXME: Do not create temporary objects each frame (obviously)
	drawHearts(target, states);
	drawRupees(target, states);

	auto &playerInventory = Scene::player->get<InventoryComponent>();

	Weapon *weaponA = playerInventory.getWeaponA();
	Weapon *weaponB = playerInventory.getWeaponB();

	if(weaponA) target.draw(weaponA->icon(), states);
	if(weaponB) target.draw(weaponB->icon(), states);
}

void StatsBar::drawHearts(RenderTarget &target, RenderStates states) const {
	auto &playerHealth = Scene::player->get<HealthComponent>();

	u8 maxLife = playerHealth.maxLife();
	for(u8 j = 0 ; j <= maxLife / 28 ; j++) {
		for(u8 i = 0 ; i < maxLife / 4 - j * 7 && i < 7 ; i++) {
			s16 life = playerHealth.life() - j * 28;

			Sprite hearts{"interface-hearts", 7, 7};

			hearts.setPosition(104 + i * 8, j * 8);
			if(life > (i + 1) * 4) {
				hearts.setCurrentFrame(4);
			}
			else if(i * 4 <= life) {
				hearts.setCurrentFrame(life - (i * 4));
			} else {
				hearts.setCurrentFrame(0);
			}

			target.draw(hearts, states);
		}
	}
}

void StatsBar::drawRupees(RenderTarget &target, RenderStates states) const {
	auto &playerInventory = Scene::player->get<InventoryComponent>();
	u16 rupees = playerInventory.rupees();
	for(u8 i = 0 ; i <= log10(rupees) ; i++) {
		Sprite numbers{"interface-numbers", 7, 6};
		numbers.setPosition(81 + 8 * i, 9);
		numbers.setCurrentFrame((rupees % (u16)pow(10, floor(log10(rupees) - i + 1))) / pow(10, floor(log10(rupees) - i)));
		target.draw(numbers, states);
	}
}

