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

#include "InventoryComponent.hpp"
#include "Scene.hpp"
#include "StatsBar.hpp"

void StatsBar::draw() {
	m_background.draw(0, 0);
	
	// u8 maxLife = Player::player.maxLife();
	u8 maxLife = 13 * 4;
	for(u8 j = 0 ; j <= maxLife / 28 ; j++) {
		for(u8 i = 0 ; i < maxLife / 4 - j * 7 && i < 7 ; i++) {
			// s16 life = Player::player.life() - j * 28;
			s16 life = 11 * 4 - j * 28;
			
			if(life > (i + 1) * 4) {
				m_hearts.drawFrame(104 + i * 8, j * 8, 4);
			}
			else if(i * 4 <= life) {
				m_hearts.drawFrame(104 + i * 8, j * 8, life - (i * 4));
			} else {
				m_hearts.drawFrame(104 + i * 8, j * 8, 0);
			}
		}
	}
	
	// u16 rupees = Player::player.inventory().rupees();
	u16 rupees = 197;
	for(u8 i = 0 ; i <= log10(rupees) ; i++) {
		m_numbers.drawFrame(81 + 8 * i, 9, (rupees % (u16)pow(10, floor(log10(rupees) - i + 1))) / pow(10, floor(log10(rupees) - i)));
	}
	
	auto &inventory = Scene::player->get<InventoryComponent>();
	
	Weapon *weaponA = inventory.getWeaponA();
	Weapon *weaponB = inventory.getWeaponB();
	
	if(weaponA) weaponA->icon().draw(46, -1);
	if(weaponB) weaponB->icon().draw(6, -1);
}

