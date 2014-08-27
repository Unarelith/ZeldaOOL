/*
 * =====================================================================================
 *
 *       Filename:  Sword.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  24/08/2014 21:13:17
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "CharacterManager.hpp"
#include "EffectManager.hpp"
#include "Sword.hpp"

using namespace CharacterManager;

s16 swordPosition[4][4][2] = {
	{{-12,   0}, {-12,  12}, { -1,  16}, { -1,  16}},
	{{  0, -12}, { 12, -12}, { 15,   1}, { 15,   1}},
	{{  0, -12}, {-12, -12}, {-15,   1}, {-15,   1}},
	{{ 12,   0}, { 12, -12}, {  0, -15}, {  0, -15}}
};

Sword::Sword() : Weapon("graphics/animations/sword.png", 16, 16) {
	addAnimation({0, 4, 8, 8}, 90);
	addAnimation({1, 5, 9, 9}, 90);
	addAnimation({2, 6, 10, 10}, 90);
	addAnimation({3, 7, 11, 11}, 90);
	
	m_tmpPlayerX = 0;
	m_tmpPlayerY = 0;
}

Sword::~Sword() {
}

bool Sword::reset() {
	if(animationCurrentFrame(player.direction()) > 2 || !m_animations[player.direction()].isPlaying) {
		resetAnimation(player.direction());
		player.resetAnimation(player.direction() + 8);
		
		if(m_tmpPlayerX != 0 || m_tmpPlayerY != 0) {
			player.setPosition(m_tmpPlayerX, m_tmpPlayerY);
			
			m_tmpPlayerX = 0;
			m_tmpPlayerY = 0;
		}
		
		return true;
	} else {
		return false;
	}
}

bool Sword::update() {
	if(animationCurrentFrame(player.direction()) == 2) {
		if(m_tmpPlayerX == 0 && m_tmpPlayerY == 0) {
			m_tmpPlayerX = player.x();
			m_tmpPlayerY = player.y();
			
			if(player.direction() == Character::Direction::Left) {
				player.move(-3, 0);
			}
			else if(player.direction() == Character::Direction::Right) {
				player.move(3, 0);
			}
			else if(player.direction() == Character::Direction::Up) {
				player.move(0, -3);
			}
			else if(player.direction() == Character::Direction::Down) {
				player.move(0, 3);
			}
		}
	}
	
	if(!animationAtEnd(player.direction())) {
		m_x = player.x() + swordPosition[player.direction()][animationCurrentFrame(player.direction())][0];
		m_y = player.y() + swordPosition[player.direction()][animationCurrentFrame(player.direction())][1];
		
		return false;
	} else {
		player.setPosition(m_tmpPlayerX, m_tmpPlayerY);
		
		m_tmpPlayerX = 0;
		m_tmpPlayerY = 0;
		
		return true;
	}
}

void Sword::draw() {
 	using namespace CharacterManager;
	
	player.playAnimation(player.x(), player.y(), player.direction() + 8);
	
	EffectManager::drawEffects(&player);
	
	playAnimation(m_x, m_y, player.direction());
}

