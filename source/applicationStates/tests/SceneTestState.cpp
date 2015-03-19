/*
 * =====================================================================================
 *
 *       Filename:  SceneTestState.cpp
 *
 *    Description:  
 *
 *        Created:  15/02/2015 12:43:41
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "ApplicationStateStack.hpp"
#include "GamePad.hpp"
#include "Map.hpp"
#include "SceneTestState.hpp"

#include "CollectableFactory.hpp"
#include "OctorokFactory.hpp"
#include "PlayerFactory.hpp"

SceneTestState::SceneTestState() {
	Map::currentMap = &Map::getMap(0, 0, 0);
	
	m_player = PlayerFactory::create(80, 48);
	Scene::player = &m_player;
	
	Map::currentMap->scene().addObject(CollectableFactory::createRupees(6 * 16 + 6, 4 * 16 + 1, RupeesAmount::Thirty, CollectableMovement::Type::Dropped));
}

void SceneTestState::update() {
	Map::currentMap->update();
	
	if(GamePad::isKeyPressedOnce(GameKey::A)) {
		Map::currentMap->scene().addObject(OctorokFactory::create(100, 80));
	}
	else if(GamePad::isKeyPressedOnce(GameKey::B)) {
		Map::currentMap->scene().addObject(CollectableFactory::createRupees(6 * 16 + 6, 4 * 16 + 1, RupeesAmount::Thirty, CollectableMovement::Type::Dropped));
	}
	
	if(GamePad::isKeyPressedOnce(GameKey::Select)) {
		ApplicationStateStack::getInstance().pop();
	}
}

void SceneTestState::draw() {
	m_font.drawString(4, -2, "Press A or B");
	
	Map::currentMap->draw();
}

