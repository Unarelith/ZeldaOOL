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

#include "MapAnimator.hpp"
#include "MapRenderer.hpp"
#include "Rect.hpp"
#include "Scene.hpp"
#include "Tileset.hpp"
#include "Vector2.hpp"
#include "View.hpp"

class Map {
	public:
		Map(u16 area, IntRect rect, Tileset &tileset, const std::vector<u16> &data);
		
		void reset();
		
		void update();
		
		void draw();
		
		void updateTiles();
		
		u16 getTile(Vector2u16 tile);
		void setTile(Vector2u16 tile, u16 id, bool persistent = false);
		
		bool passable(Vector2u16 position);
		bool onDoor(Vector2u16 position);
		bool isTile(Vector2u16 position, u16 tile);
		
		u16 area() const { return m_area; }
		IntRect rect() const { return m_rect; }
		
		Scene &scene() { return m_scene; }
		
		Tileset &tileset() { return m_tileset; }
		
		View &view() { return m_view; }
		
		static Map &getMap(u16 area, Vector2u16 map);
		static bool mapExists(u16 area, Vector2u16 map);
		
		Map &getSideMap(Vector2s8 d) { return getMap(m_area, m_rect.position() + d); }
		bool hasSideMap(Vector2s8 d) { return mapExists(m_area, m_rect.position() + d); }
		
		static Map *currentMap;
		
		enum EventType {
			ButtonPressed,
			ChangeMap,
			ChestOpened,
			GrassCutted
		};
		
	private:
		u16 m_area = 0;
		IntRect m_rect = {0, 0, 0, 0};
		
		u16 m_zoneID = 0;
		
		MapAnimator m_animator;
		
		MapRenderer m_renderer;
		
		Scene m_scene;
		
		Tileset &m_tileset;
		
		std::vector<u16> m_baseData;
		std::vector<u16> m_data;
		
		View m_view;
};

#endif // TILEMAP_HPP_
