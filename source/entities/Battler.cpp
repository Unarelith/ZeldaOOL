/*
 * =====================================================================================
 *
 *       Filename:  Battler.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/10/2014 01:11:07
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "Battler.hpp"

Battler::Battler() {
}

Battler::Battler(std::string filename, u16 x, u16 y, u16 width, u16 height, u8 direction) {
	load(filename, x, y, width, height, direction);
}

Battler::~Battler() {
}

void Battler::load(std::string filename, u16 x, u16 y, u16 width, u16 height, u8 direction) {
	Character::load(filename, x, y, width, height, direction);
	
	m_hurt = false;
}

void Battler::update() {
	if(m_hurtTimer.time() > 1500) {
		m_hurt = false;
	}
}

void Battler::drawFrame(float x, float y, u16 frame) {
	if(m_hurt && m_hurtTimer.time() % 200 < 100) setPaletteID(1);
	
	Sprite::drawFrame(x, y, frame);
	
	if(m_hurt) setPaletteID(0);
}

void Battler::hurt() {
	m_hurt = true;
	
	m_hurtTimer.reset();
	m_hurtTimer.start();
}

