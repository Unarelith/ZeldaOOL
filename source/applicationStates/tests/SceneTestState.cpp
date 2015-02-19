/*
 * =====================================================================================
 *
 *       Filename:  SceneTestState.cpp
 *
 *    Description:  
 *
 *        Created:  15/02/2015 12:43:41
 *       Compiler:  gcc
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "ApplicationStateStack.hpp"
#include "ButtonFactory.hpp"
#include "GamePad.hpp"
#include "Map.hpp"
#include "OctorokFactory.hpp"
#include "PlayerFactory.hpp"
#include "SceneTestState.hpp"

SceneTestState::SceneTestState() {
	Map::currentMap = &Map::getMap(0, 0, 0);
	
	m_player = PlayerFactory::create(75, 50);
	
	Map::currentMap->scene().addObject(ButtonFactory::create(7, 2));
}

void SceneTestState::update() {
	Map::currentMap->update(m_player);
	
	if(GamePad::isKeyPressedOnce(GameKey::A)) {
		Map::currentMap->scene().addObject(OctorokFactory::create(100, 80));
	}
	
	if(GamePad::isKeyPressedOnce(GameKey::Select)) {
		ApplicationStateStack::getInstance().pop();
	}
}

void SceneTestState::draw() {
	m_font.drawString(4, -2, "A: Spawn an Octorok");
	
	Map::currentMap->draw(m_player);
}

