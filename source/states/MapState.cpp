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
#include "ApplicationStateStack.hpp"
#include "GameState.hpp"
#include "MapState.hpp"
#include "ScrollingTransition.hpp"
#include "TransitionState.hpp"

#include "GamePad.hpp"
#include "TestState.hpp"

MapState::MapState() : m_statsBar(StatsBar::getInstance()) {
	m_link = &Player::getInstance();
}

MapState::~MapState() {
}

void MapState::update() {
	GameState::getInstance().currentMap().update();
	
	m_link->move();
	
	if(m_link->x() < -3) {
		ApplicationStateStack::getInstance().push(new TransitionState(new ScrollingTransition(ScrollingTransition::Mode::ScrollingLeft)));
	}
	else if(m_link->x() + 13 > GameState::getInstance().currentMap().width() * 16) {
		ApplicationStateStack::getInstance().push(new TransitionState(new ScrollingTransition(ScrollingTransition::Mode::ScrollingRight)));
	}
	else if(m_link->y() < -1) {
		ApplicationStateStack::getInstance().push(new TransitionState(new ScrollingTransition(ScrollingTransition::Mode::ScrollingUp)));
	}
	else if(m_link->y() + 15 > GameState::getInstance().currentMap().height() * 16) {
		ApplicationStateStack::getInstance().push(new TransitionState(new ScrollingTransition(ScrollingTransition::Mode::ScrollingDown)));
	}
	
	if(GamePad::getInstance().isKeyPressedOnce(GamePad::Select)) {
		Application::getInstance().window().pushGLStates();
		ApplicationStateStack::getInstance().push(new TestState());
	}
}

void MapState::draw() {
	GameState::getInstance().currentMap().draw();
	
	m_statsBar.draw();
	
	Application::getInstance().window().setView(TileMap::view);
	
	m_link->draw();
	
	Application::getInstance().resetView();
}

