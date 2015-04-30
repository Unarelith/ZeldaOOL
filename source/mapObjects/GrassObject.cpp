/*
 * =====================================================================================
 *
 *       Filename:  GrassObject.cpp
 *
 *    Description:  
 *
 *        Created:  07/10/2014 15:34:00
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "AudioPlayer.hpp"
#include "GrassObject.hpp"
#include "HeartCollectable.hpp"
#include "Map.hpp"
#include "RupeeCollectable.hpp"

GrassObject::GrassObject(float x, float y, bool lowGrass) : MapObject(x, y, 16, 16) {
	m_grassDestroy.addAnimation({0, 1, 2, 3, 4, 5}, 50);
	
	m_lowGrass = lowGrass;
}

void GrassObject::reset(Map &) {
	m_grassDestroy.resetAnimation(0);
	
	m_cutted = false;
}

void GrassObject::draw() {
	if(m_cutted && !m_grassDestroy.animationAtEnd(0)) {
		m_grassDestroy.playAnimation(m_x - 8, m_y - 8, 0);
	}
}

void GrassObject::onEvent(u8 event) {
	if(event == Map::EventType::GrassCutted) {
		AudioPlayer::playEffect("grassDestroy");
		
		m_grassDestroy.setColorMod(Color(255, 255, 255, (m_lowGrass) ? 125 : 255));
		
		m_cutted = true;
		
		if(rand() % 10 == 0) {
			Map::currentMap->addObject<RupeeCollectable>(m_x, m_y, 1);
		}
		else if(rand() % 30 == 14) {
			Map::currentMap->addObject<HeartCollectable>(m_x, m_y);
		}
		else if(rand() % 50 == 22) {
			Map::currentMap->addObject<RupeeCollectable>(m_x, m_y, 5);
		}
		else if(rand() % 500 == 333) {
			Map::currentMap->addObject<RupeeCollectable>(m_x, m_y, 30);
		}
		
		Map::currentMap->setTile((m_x + 8) / 16, (m_y + 8) / 16, 36);
	}
}

