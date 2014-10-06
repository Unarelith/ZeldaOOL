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
#include "Application.hpp"
#include "Config.hpp"
#include "CharacterManager.hpp"
#include "Chest.hpp"
#include "DialogState.hpp"
#include "Door.hpp"
#include "DoorTransition.hpp"
#include "EffectManager.hpp"
#include "GameStateManager.hpp"
#include "IconManager.hpp"
#include "Keyboard.hpp"
#include "MapEventManager.hpp"
#include "MapState.hpp"
#include "MenuState.hpp"
#include "ScrollingTransition.hpp"
#include "Sound.hpp"
#include "TimeManager.hpp"
#include "TransitionState.hpp"
#include "WeaponManager.hpp"

MapState::MapState() {
	WeaponManager::init();
	
	CharacterManager::player.load();
	
	MapManager::init();
	
	EffectManager::init();
	
	AnimationManager::init();
	
	IconManager::init();
	
	Object *button = new Object(7 * 16, 2 * 16);
	
	button->setEventAction(Map::EventType::ButtonPressed, [&](Object *obj) {
		Sound::Effect::chest.play();
		
		MapManager::currentMap->setTile(obj->x() / 16, obj->y() / 16 - 1, 8);
		
		MapManager::currentMap->setTile(7, 6, 36);
		MapManager::currentMap->setTile(8, 6, 36);
	});
	
	MapManager::currentMap->addObject(button);
	
	Door *testDoor = new Door(3 * 16, 2 * 16);
	testDoor->setDestination(1, 0, 0, 4 * 16 + 8, 7 * 16, Character::Direction::Up);
	
	Door *testDoor2 = new Door(4 * 16 + 8, 7 * 16);
	testDoor2->setDestination(0, 1, 0, 3 * 16, 3 * 16, Character::Direction::Down);
	
	Door *testDoor3 = new Door(2 * 16, 5 * 16);
	testDoor3->setDestination(2, 0, 0, 4 * 16 + 8, 7 * 16, Character::Direction::Up);
	
	Door *testDoor4 = new Door(4 * 16 + 8, 7 * 16);
	testDoor4->setDestination(0, 0, 0, 2 * 16, 6 * 16, Character::Direction::Down);
	
	MapManager::getMap(0, 1, 0)->addObject(testDoor);
	MapManager::getMap(1, 0, 0)->addObject(testDoor2);
	MapManager::getMap(0, 0, 0)->addObject(testDoor3);
	MapManager::getMap(2, 0, 0)->addObject(testDoor4);
	
	Chest *testChest = new Chest(1 * 16, 5 * 16);
	Chest *testChest2 = new Chest(5 * 16, 2 * 16);
	
	MapManager::getMap(0, 0, 1)->addObject(testChest);
	MapManager::getMap(2, 0, 0)->addObject(testChest2);
	
	Sound::Music::plain.play();
}

MapState::~MapState() {
	WeaponManager::free();
}

void MapState::update() {
	MapManager::currentMap->update();
	
	CharacterManager::player.update();
	
	MapEventManager::update();
	
	if(CharacterManager::player.currentState()->canStartMapTransition()) {
		if(CharacterManager::player.x() < -3) {
			GameStateManager::push(new TransitionState(new ScrollingTransition(ScrollingTransition::Mode::ScrollingLeft)));
		}
		else if(CharacterManager::player.x() + 13 > MapManager::currentMap->width() * 16) {
			GameStateManager::push(new TransitionState(new ScrollingTransition(ScrollingTransition::Mode::ScrollingRight)));
		}
		else if(CharacterManager::player.y() < 15) {
			GameStateManager::push(new TransitionState(new ScrollingTransition(ScrollingTransition::Mode::ScrollingUp)));
		}
		else if(CharacterManager::player.y() + 15 > MapManager::currentMap->height() * 16 + 16) {
			GameStateManager::push(new TransitionState(new ScrollingTransition(ScrollingTransition::Mode::ScrollingDown)));
		}
	}
	
	if(Keyboard::isKeyPressedOnce(Keyboard::Select)) {
		GameStateManager::push(new DialogState(this, "L'[1]Arbre Bojo[0] est tout à l'est de cette grotte."));
	}
	
	if(Keyboard::isKeyPressedOnce(Keyboard::Start)) {
		Sound::Effect::menuOpen.play();
		
		GameStateManager::push(new MenuState());
	}
}

void MapState::render() {
	MapManager::currentMap->draw();
	
	AnimationManager::playAnimations();
	
	CharacterManager::player.draw();
	
	EffectManager::drawEffects(&CharacterManager::player);
	
	m_statsBar.draw();
}

