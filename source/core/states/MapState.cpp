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
#include "AudioPlayer.hpp"
#include "ButtonObject.hpp"
#include "DoorLoader.hpp"
#include "DoorTransition.hpp"
#include "GamePad.hpp"
#include "MapLoader.hpp"
#include "MapState.hpp"
#include "MenuState.hpp"
#include "MessageBoxState.hpp"
#include "NPC.hpp"
#include "Player.hpp"
#include "PlayerFactory.hpp"
#include "ResourceHandler.hpp"
#include "Scene.hpp"
#include "ScrollingTransition.hpp"
#include "TilesetLoader.hpp"
#include "TransitionState.hpp"

MapState::MapState() {
	ResourceHandler::getInstance().loadConfigFile<TilesetLoader>("data/config/tilesets.xml");
	ResourceHandler::getInstance().loadConfigFile<MapLoader>("data/config/maps.xml");
	ResourceHandler::getInstance().loadConfigFile<DoorLoader>("data/config/doors.xml");
	
	Map::currentMap = &Map::getMap(0, 0, 0);
	
	Player::player.load();
	
	ButtonObject &button = Map::currentMap->scene().addObject<ButtonObject>(7 * 16, 2 * 16);
	button.addTileChange(7, 6, 36);
	button.addTileChange(8, 6, 36);
	
	//Map::getMap(0, 0, 0).scene().addObject<NPC>("characters-blueboy", 4 * 16, 1 * 16, 16, 16, Movable::Direction::Down);
	
	m_player = PlayerFactory::create(64, 48);
	
	Scene::player = &m_player;
	
	AudioPlayer::playMusic("plain");
}

void MapState::update() {
	Map::currentMap->update();
	
	Player::player.update();
	
	if(Player::player.stateManager().currentState().canStartMapTransition()) {
		if(Player::player.x() < -3) {
			m_stateStack->push<TransitionState>(new ScrollingTransition(ScrollingTransition::Mode::ScrollingLeft));
		}
		else if(Player::player.x() + 13 > Map::currentMap->width() * 16) {
			m_stateStack->push<TransitionState>(new ScrollingTransition(ScrollingTransition::Mode::ScrollingRight));
		}
		else if(Player::player.y() < -1) {
			m_stateStack->push<TransitionState>(new ScrollingTransition(ScrollingTransition::Mode::ScrollingUp));
		}
		else if(Player::player.y() + 15 > Map::currentMap->height() * 16) {
			m_stateStack->push<TransitionState>(new ScrollingTransition(ScrollingTransition::Mode::ScrollingDown));
		}
	}
	
	if(GamePad::isKeyPressedOnce(GameKey::Select)) {
		m_stateStack->push<MessageBoxState>("L'[1]Arbre Bojo[0] est tout à l'est de cette grotte.", this);
	}
	
	if(GamePad::isKeyPressedOnce(GameKey::Start)) {
		AudioPlayer::playEffect("menuOpen");
		
		m_stateStack->push<MenuState>();
	}
}

void MapState::draw() {
	Map::currentMap->draw();
	
	View::bind(&Map::currentMap->view());
	
	Player::player.draw();
	
	View::bind(nullptr);
	
	m_statsBar.draw();
}

