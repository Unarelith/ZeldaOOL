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
	if(GamePad::isKeyPressed(GameKey::Left))  m_tilemap.view().move( 1,  0);
	if(GamePad::isKeyPressed(GameKey::Right)) m_tilemap.view().move(-1,  0);
	if(GamePad::isKeyPressed(GameKey::Up))    m_tilemap.view().move( 0,  1);
	if(GamePad::isKeyPressed(GameKey::Down))  m_tilemap.view().move( 0, -1);
	
	if(GamePad::isKeyPressedOnce(GameKey::Select)) {
		ApplicationStateStack::getInstance().pop();
	}
}

void MapTestState::draw() {
	m_tilemap.draw();
}

