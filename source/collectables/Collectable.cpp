/*
 * =====================================================================================
 *
 *       Filename:  Collectable.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/10/2014 17:19:12
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "CharacterManager.hpp"
#include "Collectable.hpp"
#include "MapManager.hpp"

Collectable::Collectable(float x, float y, std::string iconFilename) : Image(iconFilename), Entity(x + 8 - width() / 2, y, width(), height()) {
}

Collectable::~Collectable() {
}

void Collectable::update() {
	if(m_movementCounter < 5) {
		m_movementCounter += 0.25f;
		
		m_y += 0.25f;
	}
	else if(CharacterManager::player.inCollisionWith(this)) {
		action();
		
		MapManager::currentMap->removeCollectable(this);
	}
}

void Collectable::draw() {
	Image::draw(m_x, m_y);
}

