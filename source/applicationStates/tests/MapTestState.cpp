/*
 * =====================================================================================
 *
 *       Filename:  MapTestState.cpp
 *
 *    Description:  
 *
 *        Created:  12/02/2015 23:12:10
 *       Compiler:  gcc
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "ApplicationStateStack.hpp"
#include "GamePad.hpp"
#include "MapTestState.hpp"

void MapTestState::update() {
	if(GamePad::isKeyPressed(GameKey::Left))  m_map->view().move( 1,  0);
	if(GamePad::isKeyPressed(GameKey::Right)) m_map->view().move(-1,  0);
	if(GamePad::isKeyPressed(GameKey::Up))    m_map->view().move( 0,  1);
	if(GamePad::isKeyPressed(GameKey::Down))  m_map->view().move( 0, -1);
	
	if(GamePad::isKeyPressedOnce(GameKey::A)) {
		static u16 area = 1;
		m_map = &Map::getMap(area++ % 4, 0, 0);
	}
	
	if(GamePad::isKeyPressedOnce(GameKey::B)) {
		if(m_map->hasSideMap(0, 1)) {
			m_map = &m_map->getSideMap(0, 1);
		}
		else if(m_map->hasSideMap(1, 0)) {
			m_map = &m_map->getSideMap(1, 0);
		}
		else if(m_map->hasSideMap(0, -1)) {
			m_map = &m_map->getSideMap(0, -1);
		}
		else if(m_map->hasSideMap(-1, 0)) {
			m_map = &m_map->getSideMap(-1, 0);
		}
	}
	
	m_map->update();
	
	if(GamePad::isKeyPressedOnce(GameKey::Select)) {
		ApplicationStateStack::getInstance().pop();
	}
}

void MapTestState::draw() {
	m_map->draw();
	
	View::bind(&m_map->view());
	
	m_font.drawString(0, -40, "A: change area");
	m_font.drawString(0, -24, "B: change map");
	
	View::bind(nullptr);
}

