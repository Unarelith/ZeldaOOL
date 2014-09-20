/*
 * =====================================================================================
 *
 *       Filename:  StatsBar.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  15/09/2014 23:34:53
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include <cmath>

#include "CharacterManager.hpp"
#include "StatsBar.hpp"

StatsBar::StatsBar() {
	m_background.load("graphics/interface/stats.png");
	
	m_hearts.load("graphics/interface/hearts.png", 7, 7);
	m_numbers.load("graphics/interface/numbers.png", 7, 6);
}

StatsBar::~StatsBar() {
}

void StatsBar::draw() {
	m_background.draw(0, 0);
	
	u8 maxLife = CharacterManager::player.maxLife();
	for(u8 j = 0 ; j <= maxLife / 28 ; j++) {
		for(u8 i = 0 ; i < maxLife / 4 - j * 28 / 4 ; i++) {
			s16 life = CharacterManager::player.life() - j * 28;
			
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
	
	u16 rupees = CharacterManager::player.rupees();
	for(u8 i = 0 ; i <= log10(rupees) ; i++) {
		m_numbers.drawFrame(81 + 8 * i, 9, (rupees % (u16)pow(10, floor(log10(rupees) - i + 1))) / pow(10, floor(log10(rupees) - i)));
	}
}

