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
	if(GamePad::isKeyPressedOnce(GameKey::Select)) {
		ApplicationStateStack::getInstance().pop();
	}
}

void MapTestState::draw() {
	m_tilemap.draw();
}

