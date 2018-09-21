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
#include "MapState.hpp"
#include "MenuState.hpp"
#include "MessageBoxState.hpp"
#include "PlayerFactory.hpp"
#include "ResourceHandler.hpp"
#include "Scene.hpp"
#include "TileMapFactory.hpp"

#include "BattleController.hpp"
#include "BehaviourController.hpp"
#include "LifetimeController.hpp"
#include "MovementController.hpp"

#include "EffectView.hpp"
#include "HitboxView.hpp"
#include "SpriteView.hpp"
#include "TileMapView.hpp"

MapState::MapState() {
	m_scene.setPosition(0, 16);

	m_scene.addController<MovementController>();
	m_scene.addController<BattleController>();
	m_scene.addController<BehaviourController>();
	m_scene.addController<LifetimeController>();

	m_scene.addView<TileMapView>();
	m_scene.addView<SpriteView>();
	m_scene.addView<EffectView>();
	// m_scene.addView<HitboxView>();

	m_scene.addObject(TileMapFactory::create("tilemap-a1"));
	m_player = &m_scene.addObject(PlayerFactory::create(64, 48));

	AudioPlayer::playMusic("plain");
}

void MapState::update() {
	m_scene.update();

	m_statsBar.update(*m_player);

	if(GamePad::isKeyPressedOnce(GameKey::Select)) {
		m_stateStack->push<MessageBoxState>(*m_player, "L'[1]Arbre Bojo[0] est tout à l'est de cette grotte.", this);
	}

	if(GamePad::isKeyPressedOnce(GameKey::Start)) {
		AudioPlayer::playEffect("menuOpen");

		m_stateStack->push<MenuState>(*m_player);
	}
}

void MapState::draw(RenderTarget &target, RenderStates states) const {
	target.draw(m_scene, states);

	target.draw(m_statsBar, states);
}

