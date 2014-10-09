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

Collectable::Collectable() {
}

Collectable::Collectable(float x, float y, std::string iconFilename) {
	load(x, y, iconFilename);
}

Collectable::~Collectable() {
}

void Collectable::load(float x, float y, std::string iconFilename) {
	Image::load(iconFilename);
	
	Entity::load(x + 7 - width() / 2, y + 8 - height(), width(), height());
	
	m_movementCounter = 0;
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

