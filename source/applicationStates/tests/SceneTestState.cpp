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
#include "ButtonFactory.hpp"
#include "GamePad.hpp"
#include "Map.hpp"
#include "OctorokFactory.hpp"
#include "PlayerFactory.hpp"
#include "SceneTestState.hpp"
#include "TeleporterFactory.hpp"

SceneTestState::SceneTestState() {
	Map::currentMap = &Map::getMap(0, 0, 0);
	
	m_player = PlayerFactory::create(75, 50);
	Scene::player = &m_player;
}

void SceneTestState::update() {
	Map::currentMap->update();
	
	if(GamePad::isKeyPressedOnce(GameKey::A)) {
		Map::currentMap->scene().addObject(OctorokFactory::create(100, 80));
	}
	
	if(GamePad::isKeyPressedOnce(GameKey::Select)) {
		ApplicationStateStack::getInstance().pop();
	}
}

void SceneTestState::draw() {
	m_font.drawString(4, -2, "A: Spawn an Octorok");
	
	Map::currentMap->draw();
}

