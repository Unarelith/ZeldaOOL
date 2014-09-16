/*
 * =====================================================================================
 *
 *       Filename:  Map.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  15/09/2014 20:53:36
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef MAP_HPP_
#define MAP_HPP_

#include "AnimatedTile.hpp"
#include "Object.hpp"
#include "Tileset.hpp"

class Map {
	public:
		Map();
		Map(const Map &map);
		Map(std::string filename, Tileset *tileset, u16 area, u16 x, u16 y);
		~Map();
		
		bool load(std::string filename, Tileset *tileset, u16 area, u16 x, u16 y);
		
		void resetTiles();
		
		void updateTexture(s16 offsetX = 0, s16 offsetY = 0);
		
		void update();
		
		void draw();
		void drawTile(u16 tileX, u16 tileY);
		
		u16 getTile(u16 tileX, u16 tileY);
		void setTile(u16 tileX, u16 tileY, u16 tile);
		
		void addObject(Object &obj) { m_objects.push_back(Object(obj)); }
		
		enum EventType {
			ButtonPressed
		};
		
		void sendEvent(EventType event, Entity *e = nullptr);
		
		Tileset &tileset() const { return *m_tileset; }
		
		u16 area() const { return m_area; }
		
		u16 x() const { return m_x; }
		u16 y() const { return m_y; }
		
		u16 width() const { return m_width; }
		u16 height() const { return m_height; }
		
		void setPosition(float x, float y) { m_posX = x; m_posY = y; }
		
	private:
		std::string m_filename;
		
		Tileset *m_tileset;
		
		u16 m_area;
		
		u16 m_x;
		u16 m_y;
		
		u16 m_width;
		u16 m_height;
		
		u16 m_tileWidth;
		u16 m_tileHeight;
		
		std::vector<s16> m_baseData;
		std::vector<s16> m_data;
		
		SDL_Texture *m_texture;
		Uint32 m_pixelFormat;
		
		std::vector<AnimatedTile> m_animatedTiles;
		
		std::vector<Object> m_objects;
		
		u16 m_posX;
		u16 m_posY;
};

#endif // MAP_HPP_

