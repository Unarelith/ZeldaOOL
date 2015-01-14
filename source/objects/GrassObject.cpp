/*
 * =====================================================================================
 *
 *       Filename:  GrassObject.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/10/2014 15:34:00
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "AnimationManager.hpp"
#include "AudioPlayer.hpp"
#include "GrassObject.hpp"
#include "HeartCollectable.hpp"
#include "Map.hpp"
#include "RupeeCollectable.hpp"

GrassObject::GrassObject(float x, float y, bool lowGrass) : Object(x, y) {
	m_lowGrass = lowGrass;
}

GrassObject::~GrassObject() {
}

void GrassObject::onEvent(u8 event) {
	if(event == Map::EventType::GrassCutted) {
		AudioPlayer::playEffect("grassDestroy");
		
		if(m_lowGrass) {
			AnimationManager::getSprite("grassDestroy").setColorMod(Color(255, 255, 255, 125));
		} else {
			AnimationManager::getSprite("grassDestroy").setColorMod(Color(255, 255, 255));
		}
		
		AnimationManager::addGrassDestroyAnimation((m_x + 8) / 16, (m_y + 8) / 16);
		
		if(rand() % 10 == 0) {
			Map::currentMap->addCollectable(new RupeeCollectable(m_x, m_y, 1));
		}
		else if(rand() % 30 == 14) {
			Map::currentMap->addCollectable(new HeartCollectable(m_x, m_y));
		}
		else if(rand() % 50 == 22) {
			Map::currentMap->addCollectable(new RupeeCollectable(m_x, m_y, 5));
		}
		else if(rand() % 500 == 333) {
			Map::currentMap->addCollectable(new RupeeCollectable(m_x, m_y, 30));
		}
		
		Map::currentMap->setTile((m_x + 8) / 16, (m_y + 8) / 16, 36);
	}
}

