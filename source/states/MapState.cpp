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
#include "ChestObject.hpp"
#include "DialogState.hpp"
#include "DoorManager.hpp"
#include "DoorTransition.hpp"
#include "EffectManager.hpp"
#include "GameStateManager.hpp"
#include "IconManager.hpp"
#include "Keyboard.hpp"
#include "MapState.hpp"
#include "MenuState.hpp"
#include "Octorok.hpp"
#include "ScrollingTransition.hpp"
#include "Sound.hpp"
#include "TimeManager.hpp"
#include "TransitionState.hpp"
#include "WeaponManager.hpp"

MapState::MapState() {
	WeaponManager::init();
	
	CharacterManager::player.load();
	
	MapManager::init();
	DoorManager::init();
	
	EffectManager::init();
	
	AnimationManager::init();
	
	IconManager::init();
	
	Object *button = new Object(7 * 16, 2 * 16);
	
	button->setEventAction(Map::EventType::ButtonPressed, [&](Object *obj) {
		Sound::Effect::chest.play();
		
		MapManager::currentMap->setTile(obj->x() / 16, obj->y() / 16, 8);
		
		MapManager::currentMap->setTile(7, 6, 36);
		MapManager::currentMap->setTile(8, 6, 36);
	});
	
	MapManager::currentMap->addObject(button);
	
	ChestObject *testChest = new ChestObject(1 * 16, 5 * 16);
	ChestObject *testChest2 = new ChestObject(5 * 16, 2 * 16);
	
	MapManager::getMap(0, 0, 1)->addObject(testChest);
	MapManager::getMap(2, 0, 0)->addObject(testChest2);
	
	MapManager::getMap(0, 1, 0)->addEnemy(new Octorok(5 * 16, 4 * 16, Character::Direction::Right));
	MapManager::getMap(2, 0, 0)->addEnemy(new Octorok(5 * 16, 3 * 16, Character::Direction::Right));
	
	Sound::Music::plain.play();
}

MapState::~MapState() {
	WeaponManager::free();
}

void MapState::update() {
	MapManager::currentMap->update();
	
	CharacterManager::player.update();
	
	if(CharacterManager::player.currentState()->canStartMapTransition()) {
		if(CharacterManager::player.x() < -3) {
			GameStateManager::push(new TransitionState(new ScrollingTransition(ScrollingTransition::Mode::ScrollingLeft)));
		}
		else if(CharacterManager::player.x() + 13 > MapManager::currentMap->width() * 16) {
			GameStateManager::push(new TransitionState(new ScrollingTransition(ScrollingTransition::Mode::ScrollingRight)));
		}
		else if(CharacterManager::player.y() < -1) {
			GameStateManager::push(new TransitionState(new ScrollingTransition(ScrollingTransition::Mode::ScrollingUp)));
		}
		else if(CharacterManager::player.y() + 15 > MapManager::currentMap->height() * 16) {
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
	
	MapManager::currentMap->enableView();
	
	AnimationManager::playAnimations();
	
	CharacterManager::player.draw();
	
	EffectManager::drawEffects(&CharacterManager::player);
	
	MapManager::currentMap->disableView();
	
	m_statsBar.draw();
}

