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
#include "Scene.hpp"
#include "Tileset.hpp"
#include "Transformable.hpp"
#include "View.hpp"

class Map : public IDrawable, public Transformable {
	public:
		Map(u16 area, u16 x, u16 y, u16 width, u16 height, Tileset &tileset, const std::vector<u16> &data);

		void reset();

		void update();

		void updateTiles();

		u16 getTile(u16 tileX, u16 tileY);
		void setTile(u16 tileX, u16 tileY, u16 id, bool persistent = false);

		bool passable(float x, float y);
		bool onDoor(float x, float y);
		bool isTile(float x, float y, u16 tile);

		u16 area() const { return m_area; }
		u16 x() const { return m_x; }
		u16 y() const { return m_y; }

		u16 width() const { return m_width; }
		u16 height() const { return m_height; }

		Scene &scene() { return m_scene; }

		Tileset &tileset() { return m_tileset; }

		View &view() { return m_view; }

		static Map &getMap(u16 area, u16 mapX, u16 mapY);
		static bool mapExists(u16 area, u16 mapX, u16 mapY);

		Map &getSideMap(s8 dx, s8 dy) { return getMap(m_area, m_x + dx, m_y + dy); }
		bool hasSideMap(s8 dx, s8 dy) { return mapExists(m_area, m_x + dx, m_y + dy); }

		static Map *currentMap;

		enum EventType {
			ButtonPressed,
			ChangeMap,
			ChestOpened,
			GrassCutted
		};

	private:
		void draw(RenderTarget &target, RenderStates states) const override;

		u16 m_area = 0;
		u16 m_x = 0;
		u16 m_y = 0;

		u16 m_zoneID = 0;

		u16 m_width = 0;
		u16 m_height = 0;

		MapAnimator m_animator;
		MapRenderer m_renderer;

		Scene m_scene;

		Tileset &m_tileset;

		std::vector<u16> m_baseData;
		std::vector<u16> m_data;

		View m_view;
};

#endif // TILEMAP_HPP_
