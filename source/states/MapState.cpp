/*
 * =====================================================================================
 *
 *       Filename:  MapState.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/12/2014 21:23:07
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "Application.hpp"
#include "KeyboardMovement.hpp"
#include "MapState.hpp"
#include "ResourceHandler.hpp"

MapState::MapState() {
	m_link.load("link", 16, 16, new KeyboardMovement);
	m_link.addAnimation({4, 0}, 110);
	m_link.addAnimation({5, 1}, 110);
	m_link.addAnimation({6, 2}, 110);
	m_link.addAnimation({7, 3}, 110);
	m_link.setPosition(96, 64);
	
	m_map = &ResourceHandler::getInstance().get<AnimatedMap>("a1");
	m_map->setPosition(0, 16);
}

MapState::~MapState() {
}

void MapState::update() {
	m_map->update();
	
	m_link.move();
}

void MapState::draw() {
	m_map->draw();
	
	m_link.draw();
}

