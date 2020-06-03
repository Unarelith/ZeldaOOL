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
#ifndef WORLD_HPP_
#define WORLD_HPP_

#include "Map.hpp"

class World : public gk::Drawable, public gk::Transformable {
	public:
		World();

		void update();

		gk::SceneObject &player() { return m_player; }

		Map *currentMap() const { return m_currentMap; }
		void setCurrentMap(Map *currentMap) { m_currentMap = currentMap; }

		Map &getSideMap(s8 dx, s8 dy);

		static Map &getMap(u16 area, u16 mapX, u16 mapY);
		static bool mapExists(u16 area, u16 mapX, u16 mapY);

		static void setInstance(World *instance) { s_instance = instance; }
		static World &getInstance() { return *s_instance; }

	private:
		void draw(gk::RenderTarget &target, gk::RenderStates states) const override;

		static World *s_instance;

		gk::SceneObject m_player;

		Map *m_currentMap = nullptr;
};

#endif // WORLD_HPP_
