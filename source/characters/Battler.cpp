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
#include "HurtState.hpp"

Battler::Battler(const std::string &filename, u16 x, u16 y, u16 width, u16 height, u8 direction) {
	load(filename, x, y, width, height, direction);
}

void Battler::load(const std::string &filename, u16 x, u16 y, u16 width, u16 height, u8 direction) {
	Character::load(filename, x, y, width, height, direction);
}

void Battler::reset(Map &) {
	m_life = m_maxLife;
	
	m_hurt = false;
}

void Battler::update() {
	if(m_hurtTimer.time() > 500) {
		m_hurt = false;
	}
}

void Battler::drawFrame(float x, float y, u16 frame) {
	if(m_hurt && m_hurtTimer.time() % 100 < 50) setPaletteID(1);
	
	Sprite::drawFrame(x, y, frame);
	
	if(m_hurt) setPaletteID(0);
}

void Battler::addHearts(float hearts) {
	m_life += hearts * 4;
	
	if(m_life > m_maxLife) {
		m_life = m_maxLife;
	}
}

void Battler::removeLife(u16 life) {
	m_life -= life;
	
	if(m_life < 0) {
		m_life = 0;
	}
}

void Battler::hurt(u8 strength, s16 vx, s16 vy) {
	if(!m_hurt) {
		removeLife(strength);
		
		m_hurt = true;
		
		m_hurtTimer.reset();
		m_hurtTimer.start();
		
		hurtAction(vx, vy);
	}
}

void Battler::hurtAction(s16 vx, s16 vy) {
	setNextState<HurtState>(vx, vy, m_speed);
}

