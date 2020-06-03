/*
 * =====================================================================================
 *
 *  ZeldaOOL
 *
 *  Copyright (C) 2014-2020 Unarelith, Quentin Bazin <zelda.ool@unarelith.net>
 *
 *  This file is part of ZeldaOOL.
 *
 *  ZeldaOOL is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  ZeldaOOL is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with ZeldaOOL; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA  02110-1301 USA
 *
 * =====================================================================================
 */
#ifndef MAP_HPP_
#define MAP_HPP_

#include <gk/gl/Transformable.hpp>
#include <gk/scene/Scene.hpp>

#include "MapAnimator.hpp"
#include "MapRenderer.hpp"
#include "Tileset.hpp"

class Map : public gk::Drawable, public gk::Transformable {
	public:
		Map(u16 area, u16 x, u16 y, u16 width, u16 height, Tileset &tileset, const std::vector<u16> &data);

		void reset();

		void update();

		void updateTiles();

		u16 getTile(u16 tileX, u16 tileY);
		void setTile(u16 tileX, u16 tileY, u16 id, bool write = true, bool persistent = false);

		bool passable(float x, float y);
		bool onDoor(float x, float y);
		bool isTile(float x, float y, u16 tile);

		u16 area() const { return m_area; }
		u16 x() const { return m_x; }
		u16 y() const { return m_y; }

		u16 width() const { return m_width; }
		u16 height() const { return m_height; }

		gk::Scene &scene() { return m_scene; }

		Tileset &tileset() { return m_tileset; }

		enum EventType {
			ButtonPressed,
			ChangeMap,
			ChestOpened,
			GrassCutted
		};

	private:
		void draw(gk::RenderTarget &target, gk::RenderStates states) const override;

		u16 m_area = 0;
		u16 m_x = 0;
		u16 m_y = 0;

		u16 m_zoneID = 0;

		Tileset &m_tileset;

		u16 m_width = 0;
		u16 m_height = 0;

		std::vector<u16> m_baseData;
		std::vector<u16> m_data;

		MapAnimator m_animator;
		MapRenderer m_renderer;

		gk::Scene m_scene;
};

#endif // TILEMAP_HPP_
