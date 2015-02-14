/*
 * =====================================================================================
 *
 *       Filename:  TransitionTestState.cpp
 *
 *    Description:  
 *
 *        Created:  14/02/2015 10:37:25
 *       Compiler:  gcc
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "ApplicationStateStack.hpp"
#include "DoorTransition.hpp"
#include "GamePad.hpp"
#include "Map.hpp"
#include "ScrollingTransition.hpp"
#include "TransitionState.hpp"
#include "TransitionTestState.hpp"

TransitionTestState::TransitionTestState() {
	Map::currentMap = &Map::getMap(0, 0, 0);
}

void TransitionTestState::update() {
	if(m_mode == Mode::Menu) {
		if(GamePad::isKeyPressedOnce(GameKey::A)) {
			m_mode = Mode::Scrolling;
		}
		else if(GamePad::isKeyPressedOnce(GameKey::B)) {
			m_mode = Mode::Door;
		}
		
		if(GamePad::isKeyPressedOnce(GameKey::Select)) {
			ApplicationStateStack::getInstance().pop();
		}
	}
	else if(m_mode == Mode::Scrolling) {
		if(GamePad::isKeyPressedOnce(GameKey::Left) && Map::currentMap->hasSideMap(-1, 0)) {
			ApplicationStateStack::getInstance().push<TransitionState>(new ScrollingTransition(ScrollingTransition::Mode::ScrollingLeft), this);
		}
		else if(GamePad::isKeyPressedOnce(GameKey::Right) && Map::currentMap->hasSideMap(1, 0)) {
			ApplicationStateStack::getInstance().push<TransitionState>(new ScrollingTransition(ScrollingTransition::Mode::ScrollingRight), this);
		}
		else if(GamePad::isKeyPressedOnce(GameKey::Up) && Map::currentMap->hasSideMap(0, -1)) {
			ApplicationStateStack::getInstance().push<TransitionState>(new ScrollingTransition(ScrollingTransition::Mode::ScrollingUp), this);
		}
		else if(GamePad::isKeyPressedOnce(GameKey::Down) && Map::currentMap->hasSideMap(0, 1)) {
			ApplicationStateStack::getInstance().push<TransitionState>(new ScrollingTransition(ScrollingTransition::Mode::ScrollingDown), this);
		}
		
		if(GamePad::isKeyPressedOnce(GameKey::Select)) {
			m_mode = Mode::Menu;
		}
	}
	else if(m_mode == Mode::Door) {
		if(GamePad::isKeyPressedOnce(GameKey::Start)) {
			ApplicationStateStack::getInstance().push<TransitionState>(new DoorTransition((Map::currentMap->area() + 1) % 4, 0, 0, 0, 0, 0), this);
		}
		
		if(GamePad::isKeyPressedOnce(GameKey::Select)) {
			m_mode = Mode::Menu;
		}
	}
}

void TransitionTestState::draw() {
	if(m_mode == Mode::Menu) {
		m_font.drawString(8, 8,  "A: Scrolling");
		m_font.drawString(8, 24, "B: Door");
	} else {
		Map::currentMap->draw();
	}
}

