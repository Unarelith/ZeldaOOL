/*
 * =====================================================================================
 *
 *       Filename:  MapState.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  15/09/2014 00:22:30
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include <cmath>

#include "AnimationManager.hpp"
#include "AudioPlayer.hpp"
#include "CharacterManager.hpp"
#include "ChestObject.hpp"
#include "DialogState.hpp"
#include "DoorManager.hpp"
#include "DoorTransition.hpp"
#include "EffectManager.hpp"
#include "GameStateManager.hpp"
#include "Keyboard.hpp"
#include "MapLoader.hpp"
#include "MapState.hpp"
#include "MenuState.hpp"
#include "Octorok.hpp"
#include "ResourceHandler.hpp"
#include "ScrollingTransition.hpp"
#include "TilesetLoader.hpp"
#include "TimeManager.hpp"
#include "TransitionState.hpp"
#include "WeaponManager.hpp"

MapState::MapState() {
	WeaponManager::init();
	
	CharacterManager::player.load();
	
	ResourceHandler::getInstance().addType("data/config/tilesets.xml", TilesetLoader());
	ResourceHandler::getInstance().addType("data/config/maps.xml", MapLoader());
	
	Map::currentMap = &Map::getMap(0, 0, 0);
	
	DoorManager::init();
	
	EffectManager::init();
	
	AnimationManager::init();
	
	Object *button = new Object(7 * 16, 2 * 16);
	
	button->setEventAction(Map::EventType::ButtonPressed, [&](Object *obj) {
		AudioPlayer::playEffect("chest");
		
		Map::currentMap->setTile(obj->x() / 16, obj->y() / 16, 8);
		
		Map::currentMap->setTile(7, 6, 36);
		Map::currentMap->setTile(8, 6, 36);
	});
	
	Map::currentMap->addObject(button);
	
	ChestObject *testChest = new ChestObject(1 * 16, 5 * 16);
	ChestObject *testChest2 = new ChestObject(5 * 16, 2 * 16);
	
	Map::getMap(0, 0, 1).addObject(testChest);
	Map::getMap(2, 0, 0).addObject(testChest2);
	
	Map::getMap(0, 1, 0).addEnemy(new Octorok(5 * 16, 4 * 16, Character::Direction::Right));
	Map::getMap(2, 0, 0).addEnemy(new Octorok(5 * 16, 3 * 16, Character::Direction::Right));
	
	AudioPlayer::playMusic("plain");
}

MapState::~MapState() {
	WeaponManager::free();
}

void MapState::update() {
	Map::currentMap->update();
	
	CharacterManager::player.update();
	
	if(CharacterManager::player.stateManager().currentState()->canStartMapTransition()) {
		if(CharacterManager::player.x() < -3) {
			GameStateManager::push(new TransitionState(new ScrollingTransition(ScrollingTransition::Mode::ScrollingLeft)));
		}
		else if(CharacterManager::player.x() + 13 > Map::currentMap->width() * 16) {
			GameStateManager::push(new TransitionState(new ScrollingTransition(ScrollingTransition::Mode::ScrollingRight)));
		}
		else if(CharacterManager::player.y() < -1) {
			GameStateManager::push(new TransitionState(new ScrollingTransition(ScrollingTransition::Mode::ScrollingUp)));
		}
		else if(CharacterManager::player.y() + 15 > Map::currentMap->height() * 16) {
			GameStateManager::push(new TransitionState(new ScrollingTransition(ScrollingTransition::Mode::ScrollingDown)));
		}
	}
	
	if(Keyboard::isKeyPressedOnce(Keyboard::Select)) {
		GameStateManager::push(new DialogState(this, "L'[1]Arbre Bojo[0] est tout à l'est de cette grotte."));
	}
	
	if(Keyboard::isKeyPressedOnce(Keyboard::Start)) {
		AudioPlayer::playEffect("menuOpen");
		
		GameStateManager::push(new MenuState());
	}
}

void MapState::render() {
	View::bind(&Map::currentMap->view());
	
	Map::currentMap->draw();
	
	AnimationManager::playAnimations();
	
	CharacterManager::player.draw();
	
	EffectManager::drawEffects(&CharacterManager::player);
	
	View::bind(nullptr);
	
	m_statsBar.draw();
}

