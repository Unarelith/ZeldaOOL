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
#include "CollectableFactory.hpp"
#include "GrassObject.hpp"
#include "HeartCollectable.hpp"
#include "Map.hpp"

GrassObject::GrassObject(float x, float y, bool lowGrass) : MapObject(x, y, 16, 16) {
	m_grassDestroy.addAnimation({0, 1, 2, 3, 4, 5}, 50);
	
	m_lowGrass = lowGrass;
}

void GrassObject::reset(Map &) {
	m_grassDestroy.currentAnimation().reset();
	
	m_cutted = false;
}

void GrassObject::draw() {
	if(m_cutted && !m_grassDestroy.currentAnimation().isFinished()) {
		m_grassDestroy.playAnimation(m_x - 8, m_y - 8, 0);
	}
}

void GrassObject::onEvent(u8 event) {
	if(event == Map::EventType::GrassCutted) {
		AudioPlayer::playEffect("grassDestroy");
		
		m_grassDestroy.setColorMod(Color(255, 255, 255, (m_lowGrass) ? 125 : 255));
		
		m_cutted = true;
		
		if(rand() % 5 == 0) {
			Map::currentMap->scene().addObject(CollectableFactory::createRupees(m_x, m_y, RupeesAmount::One, CollectableMovement::Type::Dropped));
		}
		else if(rand() % 15 == 7) {
			Map::currentMap->scene().addObject<HeartCollectable>(m_x, m_y);
		}
		else if(rand() % 25 == 11) {
			Map::currentMap->scene().addObject(CollectableFactory::createRupees(m_x, m_y, RupeesAmount::Five, CollectableMovement::Type::Dropped));
		}
		else if(rand() % 250 == 176) {
			Map::currentMap->scene().addObject(CollectableFactory::createRupees(m_x, m_y, RupeesAmount::Thirty, CollectableMovement::Type::Dropped));
		}
		
		Map::currentMap->setTile((m_x + 8) / 16, (m_y + 8) / 16, 36);
	}
}

