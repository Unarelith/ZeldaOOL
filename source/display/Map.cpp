/*
 * =====================================================================================
 *
 *       Filename:  Map.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  15/09/2014 20:53:45
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include <cmath>

#include "Application.hpp"
#include "Config.hpp"
#include "CharacterManager.hpp"
#include "MapManager.hpp"
#include "XMLFile.hpp"

Map::Map() {
}

Map::Map(std::string filename, Tileset *tileset, u16 area, u16 x, u16 y) {
	load(filename, tileset, area, x, y);
}

Map::~Map() {
	SDL_DestroyTexture(m_texture);
}

bool Map::load(std::string filename, Tileset *tileset, u16 area, u16 x, u16 y) {
	m_tileset = tileset;
	
	m_area = area;
	
	m_x = x;
	m_y = y;
	
	XMLFile doc(filename);
	
	XMLElement *mapElement = doc.FirstChildElement("map").ToElement();
	
	m_width = mapElement->IntAttribute("width");
	m_height = mapElement->IntAttribute("height");
	
	m_tileWidth = mapElement->IntAttribute("tilewidth");
	m_tileHeight = mapElement->IntAttribute("tileheight");
	
	XMLElement *tileElement = mapElement->FirstChildElement("layer")->FirstChildElement("data")->FirstChildElement("tile");
	while(tileElement) {
		m_baseData.push_back(tileElement->IntAttribute("gid") - 1);
		
		tileElement = tileElement->NextSiblingElement("tile");
	}
	
	m_data = m_baseData;
	
	SDL_QueryTexture(m_tileset->texture.texture(), &m_pixelFormat, nullptr, nullptr, nullptr);
	
	m_texture = SDL_CreateTexture(Application::window.renderer(), m_pixelFormat, SDL_TEXTUREACCESS_TARGET, m_width * m_tileWidth, m_height * m_tileHeight);
	
	updateTexture();
	
	return true;
}

void Map::resetTiles() {
	m_data = m_baseData;
}

void Map::updateTexture(s16 offsetX, s16 offsetY) {
	SDL_SetRenderTarget(Application::window.renderer(), m_texture);
	
	for(s16 y = 1 ; y < m_height + 1 ; y++) {
		for(s16 x = 0 ; x < m_width ; x++) {
			drawTile(x + offsetX, y + offsetY);
			
			for(auto &it : m_tileset->anims) {
				for(auto &n : it.frames) {
					if(getTile(x, y - 1) == n) {
						m_animatedTiles.push_back(AnimatedTile(x, y - 1, n + 1 % it.frames.size(), it));
					}
				}
			}
		}
	}
	
	SDL_SetRenderTarget(Application::window.renderer(), nullptr);
}

void Map::update() {
	for(auto &it : m_animatedTiles) {
		if(!it.timer.isStarted()) {
			it.timer.start();
		}
		
		if(it.timer.time() >= it.anim.delay) {
			setTile(it.tileX, it.tileY, it.anim.frames[it.nextFrame % it.anim.frames.size()]);
			it.nextFrame++;
			it.timer.reset();
			it.timer.start();
		}
	}
}

void Map::draw() {
	SDL_Rect clip, pos;
	
	clip.x = 0;
	clip.y = 0;
	clip.w = Application::window.width();
	clip.h = Application::window.height();
	
	pos.x = 0;
	pos.y = 16;
	pos.w = Application::window.width();
	pos.h = Application::window.height() - 16;
	
	SDL_RenderCopy(Application::window.renderer(), m_texture, &clip, &pos);
	
	MapManager::tilesets[0]->texture.draw(16, 16);
}

void Map::drawTile(u16 tileX, u16 tileY) {
	s16 tileNb = m_data[tileX + (tileY - 1) * m_width];
	
	if(tileNb == -1) return;
	
	u16 tilesetX = tileNb % (m_tileset->texture.width() / m_tileWidth);
	u16 tilesetY = tileNb / (m_tileset->texture.height() / m_tileWidth);
	
	m_tileset->texture.setClipRect(tilesetX, tilesetY, m_tileWidth, m_tileHeight);
	m_tileset->texture.draw(tileX * m_tileWidth, tileY * m_tileHeight, m_tileWidth, m_tileHeight);
}

u16 Map::getTile(u16 tileX, u16 tileY) {
	if(tileX + tileY * m_width < (u16)m_data.size()) {
		return m_data[tileX + tileY * m_width];
	} else {
		return 0;
	}
}

void Map::setTile(u16 tileX, u16 tileY, u16 tile) {
	if(tileX + tileY * m_width < (u16)m_data.size()) {
		m_data[tileX + tileY * m_width] = tile;
		
		SDL_SetRenderTarget(Application::window.renderer(), m_texture);
		
		drawTile(tileX, tileY + 1);
		
		SDL_SetRenderTarget(Application::window.renderer(), nullptr);
	}
}

void Map::sendEvent(EventType event, Entity *e) {
	if(!e) e = &CharacterManager::player;
	
	for(auto &it : m_objects) {
		if((floor(it.x() / 16) == floor((e->x() + 6) / 16))
		&& (floor(it.y() / 16) == floor((e->y() + 11) / 16))) {
			it.onEvent(event);
			
			break;
		}
	}
}

