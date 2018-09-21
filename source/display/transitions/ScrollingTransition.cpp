/*
 * =====================================================================================
 *
 *       Filename:  ScrollingTransition.cpp
 *
 *    Description:
 *
 *        Created:  05/10/2014 17:45:59
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "Application.hpp"
#include "Config.hpp"
#include "PositionComponent.hpp"
#include "Scene.hpp"
#include "ScrollingTransition.hpp"
#include "Sprite.hpp"
#include "TileMapFactory.hpp"

ScrollingTransition::ScrollingTransition(SceneObject &player, SceneObject &tilemap, Mode mode) : m_player(player), m_tilemap(tilemap) {
	setPosition(0, 16);

	m_mode = mode;

	if(m_mode == Mode::ScrollingLeft) {
		m_vx = -1;
	}
	else if(m_mode == Mode::ScrollingRight) {
		m_vx = 1;
	}
	else if(m_mode == Mode::ScrollingUp) {
		m_vy = -1;
	}
	else if(m_mode == Mode::ScrollingDown) {
		m_vy = 1;
	}

	std::string mapName = tilemap.name();
	mapName[9] += m_vx;
	mapName[8] += m_vy;

	m_nextMap = TileMapFactory::create(mapName.substr(8, 2));
	m_nextMap.get<TileMap>().setPosition(tilemap.get<TileMap>().width() * 16 * m_vx,
	                                     tilemap.get<TileMap>().height() * 16 * m_vy);

	Sprite::pause = true;
}

void ScrollingTransition::update() {
	PositionComponent &positionComponent = m_player.get<PositionComponent>();
	// positionComponent.move(m_vx * 0.15f, m_vy * 0.21f);
	positionComponent.move(-m_vx * 1.45f, -m_vy * 1.27f);

	auto &tilemap = m_tilemap.get<TileMap>();
	auto &next = m_nextMap.get<TileMap>();
	tilemap.move(-m_vx * 1.6f, -m_vy * 1.5f);
	next.move(-m_vx * 1.6f, -m_vy * 1.5f);
	// move(-m_vx * 1.6f, -m_vy * 1.5f);

	if(m_vx != 0) m_scrolled += 1.6f;
	if(m_vy != 0) m_scrolled += 1.5f;

	if((m_scrolled >= SCREEN_WIDTH       && m_vx != 0)
	|| (m_scrolled >= SCREEN_HEIGHT - 16 && m_vy != 0)) {
		// if(m_vx < 0)      positionComponent.move(next.width() * 16, 0);
		// else if(m_vx > 0) positionComponent.move(-tilemap.width() * 16, 0);
		// else if(m_vy < 0) positionComponent.move(0, next.height() * 16);
		// else if(m_vy > 0) positionComponent.move(0, -tilemap.height() * 16);

		next.setPosition(0, 0);
		m_tilemap = m_nextMap;
		TileMap::currentMap = &m_tilemap.get<TileMap>();

		m_scrolled = 0;

		Sprite::pause = false;

		m_atEnd = true;
	}

	// auto &objectList = m_player.get<SceneObjectList>();
	// for(auto &object : objectList) {
	// 	if (object.has<PositionComponent>()) {
	// 		auto &position = object.get<PositionComponent>();
	// 		position.x = positionComponent.x;
	// 		position.y = positionComponent.y;
	// 	}
	// }
    //
	// auto &mapObjectList = m_tilemap.get<SceneObjectList>();
	// for(auto &object : mapObjectList) {
	// 	if (object.has<PositionComponent>()) {
	// 		auto &position = object.get<PositionComponent>();
	// 		position.move(-m_vx * 1.6, -m_vy * 1.5f);
	// 	}
	// }
    //
	// auto &nextmapObjectList = m_nextMap.get<SceneObjectList>();
	// for(auto &object : nextmapObjectList) {
	// 	if (object.has<PositionComponent>()) {
	// 		auto &position = object.get<PositionComponent>();
	// 		position.move(-m_vx * 1.6, -m_vy * 1.5f);
	// 	}
	// }
}

#include "SpriteView.hpp"
#include "TileMapView.hpp"

void ScrollingTransition::draw(RenderTarget &target, RenderStates states) const {
	applyTransform(states);

	TileMapView mapView;
	mapView.draw(m_nextMap, target, states);
	mapView.draw(m_tilemap, target, states);

	SpriteView view;
	view.draw(m_player, target, states);
}

