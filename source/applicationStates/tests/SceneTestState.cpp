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
#include "GamePad.hpp"
#include "OctorokFactory.hpp"
#include "PlayerFactory.hpp"
#include "SceneTestState.hpp"

SceneTestState::SceneTestState() : m_map(&Map::getMap(0, 0, 0)) {
	m_scene.addObject(PlayerFactory::create(75, 50));
}

void SceneTestState::update() {
	m_map->update();
	
	m_scene.update();
	
	if(GamePad::isKeyPressedOnce(GameKey::A)) {
		m_scene.addObject(OctorokFactory::create(100, 80));
	}
	
	if(GamePad::isKeyPressedOnce(GameKey::Select)) {
		ApplicationStateStack::getInstance().pop();
	}
}

void SceneTestState::draw() {
	m_font.drawString(4, -2, "A: Spawn an Octorok");
	
	m_map->draw();
	
	m_scene.draw();
}

