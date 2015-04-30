/*
 * =====================================================================================
 *
 *       Filename:  Map.hpp
 *
 *    Description:  
 *
 *        Created:  30/04/2015 19:43:10
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef MAP_HPP_
#define MAP_HPP_

#include <memory>

#include "MapAnimator.hpp"
#include "MapObject.hpp"
#include "MapRenderer.hpp"
#include "Player.hpp"
#include "Tileset.hpp"
#include "VertexBuffer.hpp"
#include "View.hpp"

class Map {
	public:
		Map(u16 area, u16 x, u16 y, u16 width, u16 height, Tileset &tileset, const std::vector<u16> &data);
		
		void update();
		
		void draw();
		
		void resetTiles();
		void updateTiles();
		
		u16 getTile(u16 tileX, u16 tileY);
		void setTile(u16 tileX, u16 tileY, u16 id);
		
		bool passable(float x, float y);
		bool onDoor(float x, float y);
		bool isTile(float x, float y, u16 tile);
		
		u16 area() const { return m_area; }
		u16 x() const { return m_x; }
		u16 y() const { return m_y; }
		
		u16 width() const { return m_width; }
		u16 height() const { return m_height; }
		
		Tileset &tileset() { return m_tileset; }
		
		View &view() { return m_view; }
		
		static Map &getMap(u16 area, u16 mapX, u16 mapY);
		static bool mapExists(u16 area, u16 mapX, u16 mapY);
		
		Map &getSideMap(s8 dx, s8 dy) { return getMap(m_area, m_x + dx, m_y + dy); }
		bool hasSideMap(s8 dx, s8 dy) { return mapExists(m_area, m_x + dx, m_y + dy); }
		
		static Map *currentMap;
		
		// OLD PART BEGINS HERE
		template<typename T, typename... Args>
		T &addObject(Args &&...args) {
			m_objects.emplace_back(new T(std::forward<Args>(args)...));
			m_objects.back()->addCollisionHandler(std::bind(&Map::checkCollisionsFor, this, m_objects.back().get()));
			return static_cast<T&>(*m_objects.back());
		}
		
		void removeObject(MapObject &object) {
			m_objects.erase(std::remove_if(m_objects.begin(), m_objects.end(),
							[&](std::unique_ptr<MapObject> &it) {
								return it.get() == &object;
							}), m_objects.end());
		}
		
		bool objectAtPosition(const MapObject &obj, float x, float y) const {
			return((floor(obj.x() / 8) == floor(x / 8)
				 || floor(obj.x() / 8) == floor(x / 8) - 1)
				&& (floor(obj.y() / 8) == floor(y / 8)
				 || floor(obj.y() / 8) == floor(y / 8) - 1));
		}
		
		MapObject *getObject(float x, float y) {
			for(auto &it : m_objects) {
				if(objectAtPosition(*it, x, y)) {
					return it.get();
				}
			}
			
			return nullptr;
		}

		void checkCollisionsFor(MapObject *object) {
			for(auto &it : m_objects) {
				MapObject *object2 = (it && it.get() != object) ? it.get() : &Player::player;
				
				if(object->inCollisionWith(*object2)) {
					object->collisionAction(*object2);
					object2->collisionAction(*object);
				}
			}
		}
		
		enum EventType {
			ButtonPressed,
			ChangeMap,
			ChestOpened,
			GrassCutted
		};
		
	private:
		u16 m_area = 0;
		u16 m_x = 0;
		u16 m_y = 0;
		
		u16 m_zoneID = 0;
		
		u16 m_width = 0;
		u16 m_height = 0;
		
		MapAnimator m_animator;
		
		MapRenderer m_renderer;
		
		Tileset &m_tileset;
		
		std::vector<u16> m_baseData;
		std::vector<u16> m_data;
		
		View m_view;
		
		std::vector<std::unique_ptr<MapObject>> m_objects;
};

#endif // TILEMAP_HPP_
