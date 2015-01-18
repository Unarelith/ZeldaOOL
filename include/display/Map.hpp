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

#include "AnimatedMap.hpp"
#include "Collectable.hpp"
#include "Enemy.hpp"
#include "Object.hpp"
#include "Tileset.hpp"
#include "Vector2.hpp"

class Map : public AnimatedMap {
	public:
		Map() = default;
		Map(std::string filename, Tileset &tileset, u16 area, u16 x, u16 y);
		
		void load(std::string filename, Tileset &tileset, u16 area, u16 x, u16 y);
		
		void resetTiles();
		
		void updateTile(u16 tileX, u16 tileY, u16 id) override; 
		
		void update(bool onlyTiles = false);
		
		void draw();
		
		void addObject(Object *obj);
		void addEnemy(Enemy *enemy);
		
		template<typename T, typename... Args>
		void addCollectable(Args &&...args) {
			m_collectables.emplace_back(new T(std::forward<Args>(args)...));
		}
		
		void removeCollectable(Collectable *collectable);
		
		enum EventType {
			ButtonPressed,
			ChangeMap,
			ChestOpened,
			GrassCutted
		};
		
		bool objectAtPosition(Object *obj, float x, float y);
		void sendEvent(EventType event, MapObject *object = nullptr, Vector2i offsets = Vector2i(6, 11));
		
		u16 area() const { return m_area; }
		
		u16 x() const { return m_x; }
		u16 y() const { return m_y; }
		
		u16 width() const { return m_width; }
		u16 height() const { return m_height; }
		
		static Map &getMap(u16 area, u16 mapX, u16 mapY);
		
		static Map *currentMap;
		
	private:
		u16 m_area;
		
		u16 m_x;
		u16 m_y;
		
		std::vector<std::unique_ptr<Object>> m_objects;
		std::vector<std::unique_ptr<Collectable>> m_collectables;
		std::vector<std::unique_ptr<Enemy>> m_enemies;
};

#endif // MAP_HPP_
