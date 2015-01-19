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
		Map(const std::string &filename, Tileset &tileset, u16 area, u16 x, u16 y);
		
		void load(const std::string &filename, Tileset &tileset, u16 area, u16 x, u16 y);
		
		void resetTiles();
		
		void updateTile(u16 tileX, u16 tileY, u16 id) override; 
		
		void update(bool onlyTiles = false);
		
		void draw();
		
		template<typename T, typename... Args>
		T &addObject(Args &&...args) {
			m_objects.emplace_back(new T(std::forward<Args>(args)...));
			m_objects.back()->addCollisionHandler(std::bind(&Map::checkCollisionsFor, this, m_objects.back().get()));
			return static_cast<T&>(*m_objects.back());
		}
		
		void removeObject(MapObject &object);
		
		bool objectAtPosition(const MapObject &obj, float x, float y) const;
		
		void checkCollisionsFor(MapObject *object);
		
		enum EventType {
			ButtonPressed,
			ChangeMap,
			ChestOpened,
			GrassCutted
		};
		
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
		
		std::vector<std::unique_ptr<MapObject>> m_objects;
};

#endif // MAP_HPP_
