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
#include "ChestObject.hpp"
#include "DialogState.hpp"
#include "DoorLoader.hpp"
#include "DoorTransition.hpp"
#include "Keyboard.hpp"
#include "MapLoader.hpp"
#include "MapState.hpp"
#include "MenuState.hpp"
#include "NPC.hpp"
#include "Octorok.hpp"
#include "Player.hpp"
#include "ResourceHandler.hpp"
#include "ScrollingTransition.hpp"
#include "TilesetLoader.hpp"
#include "TransitionState.hpp"

MapState::MapState() {
	ResourceHandler::getInstance().loadConfigFile<TilesetLoader>("data/config/tilesets.xml");
	ResourceHandler::getInstance().loadConfigFile<MapLoader>("data/config/maps.xml");
	ResourceHandler::getInstance().loadConfigFile<DoorLoader>("data/config/doors.xml");
	
	Map::currentMap = &Map::getMap(0, 0, 0);
	
	Player::player.load();
	
	ButtonObject &button = Map::currentMap->addObject<ButtonObject>(7 * 16, 2 * 16);
	button.addTileChange(7, 6, 36);
	button.addTileChange(8, 6, 36);
	
	//Map::getMap(0, 0, 0).addObject<NPC>("characters-blueboy", 4 * 16, 1 * 16, 16, 16, Movable::Direction::Down);
	
	Map::getMap(0, 0, 1).addObject<ChestObject>(1 * 16, 5 * 16);
	Map::getMap(2, 0, 0).addObject<ChestObject>(5 * 16, 2 * 16);
	
	Map::getMap(0, 1, 0).addObject<Octorok>(5 * 16, 4 * 16, Movable::Direction::Right);
	Map::getMap(2, 0, 0).addObject<Octorok>(5 * 16, 3 * 16, Movable::Direction::Right);
	
	AudioPlayer::playMusic("plain");
}

void MapState::update() {
	Player::player.update();
	
	Map::currentMap->update();
	
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
	
	if(Keyboard::isKeyPressedOnce(Keyboard::Select)) {
		m_stateStack->push<DialogState>(this, "L'[1]Arbre Bojo[0] est tout à l'est de cette grotte.");
	}
	
	if(Keyboard::isKeyPressedOnce(Keyboard::Start)) {
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

