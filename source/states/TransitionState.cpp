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
#include <gk/core/ApplicationStateStack.hpp>
#include <gk/core/Debug.hpp>

#include "TransitionState.hpp"

TransitionState::TransitionState(gk::ApplicationState *parent) : gk::ApplicationState(parent) {
	m_statsBar.update();
}

void TransitionState::update() {
	m_statsBar.update();

	if(!m_transition || m_transition->atEnd()) {
		if(!m_transition) gkDebug() << "Empty TransitionState created, I'll pop it";

		m_stateStack->pop();
	} else {
		m_transition->update();
	}
}

void TransitionState::draw(gk::RenderTarget &target, gk::RenderStates states) const {
	if (m_transition)
		target.draw(*m_transition, states);

	if(m_transition->drawStatsBar()) {
		target.draw(m_statsBar, states);
	}
}

