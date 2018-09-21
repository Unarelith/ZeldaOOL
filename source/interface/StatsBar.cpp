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

StatsBar::StatsBar() {
	m_rupees.setPosition(81, 9);
	m_hearts.setPosition(104, 0);
}

void StatsBar::update(const SceneObject &player) {
	auto &playerInventory = player.get<InventoryComponent>();

	Weapon *weaponA = playerInventory.getWeaponA();
	Weapon *weaponB = playerInventory.getWeaponB();

	// FIXME: Use a single Sprite for multiple icons, reuse it by changing its texture
	if(weaponA) weaponA->icon().setPosition(46, -1);
	if(weaponB) weaponB->icon().setPosition(6, -1);

	updateRupees(player);
	updateHearts(player);
}

void StatsBar::updateRupees(const SceneObject &player) {
	// FIXME: Map rework
	auto &playerInventory = player.get<InventoryComponent>();
	u16 rupees = playerInventory.rupees();

	std::string text;
	for(u8 i = 0 ; i <= log10(rupees) ; i++) {
		text.push_back((rupees % (u16)pow(10, floor(log10(rupees) - i + 1))) / pow(10, floor(log10(rupees) - i)));
	}

	m_rupees.setText(text);
}

void StatsBar::updateHearts(const SceneObject &player) {
	auto &playerHealth = player.get<HealthComponent>();
	u8 maxLife = playerHealth.maxLife();

	std::string text;
	for(u8 j = 0 ; j <= maxLife / 28 ; j++) {
		for(u8 i = 0 ; i < maxLife / 4 - j * 7 && i < 7 ; i++) {
			s16 life = playerHealth.life() - j * 28;

			if(life > (i + 1) * 4) {
				text.push_back(4);
			}
			else if(i * 4 <= life) {
				text.push_back(life - (i * 4));
			} else {
				text.push_back(0);
			}
		}

		text.push_back('\n');
	}

	m_hearts.setText(text);
}

void StatsBar::draw(RenderTarget &target, RenderStates states) const {
	target.draw(m_background, states);

	target.draw(m_hearts, states);
	target.draw(m_rupees, states);

	// FIXME: Map rework
	// auto &playerInventory = Scene::player->get<InventoryComponent>();
    //
	// Weapon *weaponA = playerInventory.getWeaponA();
	// Weapon *weaponB = playerInventory.getWeaponB();
    //
	// if(weaponA) target.draw(weaponA->icon(), states);
	// if(weaponB) target.draw(weaponB->icon(), states);
}

