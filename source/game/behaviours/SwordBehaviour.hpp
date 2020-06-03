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
#ifndef SWORDBEHAVIOUR_HPP_
#define SWORDBEHAVIOUR_HPP_

#include <gk/core/Timer.hpp>

#include "Behaviour.hpp"

class SwordBehaviour : public Behaviour {
	public:
		SwordBehaviour();

		void update(gk::SceneObject &sword) override;

		void updateHitboxes(gk::SceneObject &sword);
		void updateSprite(gk::SceneObject &sword);

	private:
		bool m_keyReleased = false;

		gk::Timer m_loadingTimer;

		gk::Timer m_spinTimer;
		u16 m_spinCurrentFrame = 0;
		u16 m_spinFrameCounter = 0;
};

#endif // SWORDBEHAVIOUR_HPP_
