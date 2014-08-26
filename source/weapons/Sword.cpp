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
#include "Sword.hpp"

s16 swordPosition[4][4][2] = {
	{{-12,   0}, {-12,  12}, {  0,  16}, {  0,  16}},
	{{  0, -12}, { 12, -12}, { 12,   0}, { 12,   0}},
	{{  0, -12}, {-12, -12}, {-12,   0}, {-12,   0}},
	{{ 12,   0}, { 12, -12}, {  0, -12}, {  0, -12}}
};

Sword::Sword() : Weapon("graphics/animations/sword.png", 16, 16) {
	addAnimation({0, 4, 8, 8}, 90);
	addAnimation({1, 5, 9, 9}, 90);
	addAnimation({2, 6, 10, 10}, 90);
	addAnimation({3, 7, 11, 11}, 90);
}

Sword::~Sword() {
}

void Sword::reset() {
	resetAnimation(CharacterManager::player.direction());
}

bool Sword::update() {
	using namespace CharacterManager;
	
	if(!animationAtEnd(player.direction())) {
		m_x = player.x() + swordPosition[player.direction()][animationCurrentFrame(player.direction())][0];
		m_y = player.y() + swordPosition[player.direction()][animationCurrentFrame(player.direction())][1];
		
		return false;
	} else {
		m_x = player.x();
		m_y = player.y();
		
		return true;
	}
}

void Sword::draw() {
	if(!animationAtEnd(CharacterManager::player.direction())) {
		playAnimation(m_x, m_y, CharacterManager::player.direction());
	} else {
		drawFrame(m_x, m_y, CharacterManager::player.direction() + 8);
	}
}

