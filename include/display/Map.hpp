/*
 * =====================================================================================
 *
 *       Filename:  Map.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  20/09/2014 19:04:19
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef MAP_HPP_
#define MAP_HPP_

#include "AnimatedTile.hpp"
#include "Collectable.hpp"
#include "Enemy.hpp"
#include "Object.hpp"
#include "TileMap.hpp"
#include "Tileset.hpp"
#include "Vector2.hpp"

class Map : public TileMap {
	public:
		Map();
		Map(const Map &map);
		Map(std::string filename, Tileset *tileset, u16 area, u16 x, u16 y);
		~Map();
		
		bool load(std::string filename, Tileset *tileset, u16 area, u16 x, u16 y);
		
		void resetTiles();
		
		void updateTiles();
		
		void update();
		
		void draw();
		
		u16 getTile(u16 tileX, u16 tileY);
		void setTile(u16 tileX, u16 tileY, u16 tile);
		
		void addObject(Object *obj);
		void addCollectable(Collectable *collectable);
		void addEnemy(Enemy *enemy);
		
		void removeCollectable(Collectable *collectable);
		
		enum EventType {
			ButtonPressed,
			ChangeMap,
			ChestOpened,
			GrassCutted
		};
		
		bool objectAtPosition(Object *obj, float x, float y);
		void sendEvent(EventType event, Entity *e = nullptr, Vector2i offsets = Vector2i(6, 11));
		
		Tileset &tileset() const { return *m_tileset; }
		
		u16 area() const { return m_area; }
		
		u16 x() const { return m_x; }
		u16 y() const { return m_y; }
		
		u16 width() const { return m_width; }
		u16 height() const { return m_height; }
		
		void enableView() { m_view.enable(); }
		void disableView() { m_view.disable(); }
		
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
		
		std::vector<AnimatedTile> m_animatedTiles;
		
		std::vector<Object*> m_objects;
		std::vector<Collectable*> m_collectables;
		std::vector<Enemy*> m_enemies;
};

#endif // MAP_HPP_
