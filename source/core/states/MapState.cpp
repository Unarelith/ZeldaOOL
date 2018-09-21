/*
 * =====================================================================================
 *
 *       Filename:  MapState.cpp
 *
 *    Description:
 *
 *        Created:  15/09/2014 00:22:30
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "ApplicationStateStack.hpp"
#include "AudioPlayer.hpp"
#include "Config.hpp"
#include "GamePad.hpp"
#include "Map.hpp"
#include "MapState.hpp"
#include "MenuState.hpp"
#include "MessageBoxState.hpp"
#include "PlayerFactory.hpp"
#include "ResourceHandler.hpp"
#include "Scene.hpp"

MapState::MapState() {
	Map::currentMap = &Map::getMap(0, 0, 0);

	m_player = PlayerFactory::create(64, 48);
	Scene::player = &m_player;

	AudioPlayer::playMusic("plain");
}

void MapState::update() {
	Map::currentMap->update();

	m_statsBar.update();

	if(GamePad::isKeyPressedOnce(GameKey::Select)) {
		m_stateStack->push<MessageBoxState>("L'[1]Arbre Bojo[0] est tout à l'est de cette grotte.", this);
	}

	if(GamePad::isKeyPressedOnce(GameKey::Start)) {
		AudioPlayer::playEffect("menuOpen");

		m_stateStack->push<MenuState>();
	}
}

void MapState::draw(RenderTarget &target, RenderStates states) const {
	if (Map::currentMap)
		target.draw(*Map::currentMap, states);

	target.draw(m_statsBar, states);
}

