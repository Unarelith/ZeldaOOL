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
#ifndef HEALTHCOMPONENT_HPP_
#define HEALTHCOMPONENT_HPP_

#include <gk/core/IntTypes.hpp>

class HealthComponent {
	public:
		HealthComponent(u8 maxLife, u8 life = 0)
			: m_maxLife(maxLife), m_life(life ? life : maxLife) {}

		void setLife(u8 newLife) { m_life = (newLife > m_maxLife) ? m_maxLife : newLife; }
		void addLife(u8 lifeAdded) { setLife(m_life + lifeAdded); }
		void removeLife(u8 lifeRemoved) { (lifeRemoved > m_life) ? setLife(0) : setLife(m_life - lifeRemoved); }

		u8 life() const { return m_life; }
		u8 maxLife() const { return m_maxLife; }

		bool isHurt = false;
		bool isDead = false;

	private:
		u8 m_maxLife = 0;
		u8 m_life = 0;

};

#endif // HEALTHCOMPONENT_HPP_
