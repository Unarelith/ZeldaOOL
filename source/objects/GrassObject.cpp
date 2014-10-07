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
#include "GrassObject.hpp"
#include "MapManager.hpp"
#include "Sound.hpp"

GrassObject::GrassObject(float x, float y, bool lowGrass) : Object(x, y) {
	m_lowGrass = lowGrass;
}

GrassObject::~GrassObject() {
}

void GrassObject::onEvent(u8 event) {
	if(event == Map::EventType::GrassCutted) {
		Sound::Effect::grassDestroy.play();
		
		if(m_lowGrass) {
			AnimationManager::grassDestroy.setColorMod(Color(255, 255, 255, 125));
		} else {
			AnimationManager::grassDestroy.setColorMod(Color(255, 255, 255));
		}
		
		AnimationManager::addGrassDestroyAnimation((m_x + 8) / 16, (m_y + 8) / 16);
		
		MapManager::currentMap->setTile((m_x + 8) / 16, (m_y + 8) / 16 - 1, 36);
	}
}

