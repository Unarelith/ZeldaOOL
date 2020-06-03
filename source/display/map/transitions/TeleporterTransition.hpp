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
#ifndef TELEPORTERTRANSITION_HPP_
#define TELEPORTERTRANSITION_HPP_

#include <gk/graphics/RectangleShape.hpp>

#include "Direction.hpp"
#include "Map.hpp"
#include "Transition.hpp"

class TeleporterTransition : public Transition {
	public:
		TeleporterTransition(u16 area, u16 mapX, u16 mapY, u16 playerX, u16 playerY, Direction playerDirection);

		void update() override;

	private:
		void draw(gk::RenderTarget &target, gk::RenderStates states) const override;

		Map *m_nextMap;

		gk::Timer m_timer;

		gk::RectangleShape m_rect1;
		gk::RectangleShape m_rect2;

		gk::Color m_color;
};

#endif // TELEPORTERTRANSITION_HPP_
