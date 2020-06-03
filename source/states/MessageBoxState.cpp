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

#include "MessageBoxState.hpp"
#include "PositionComponent.hpp"
#include "World.hpp"

MessageBoxState::MessageBoxState(const std::string &text, gk::ApplicationState *parent) : gk::ApplicationState(parent), m_messageBox(text) {
	if(World::getInstance().player().get<PositionComponent>().y + 32 < MessageBox::Position::Bottom) {
		m_messageBox.setPosition(8, MessageBox::Position::Bottom);
	}
}

void MessageBoxState::update() {
	m_messageBox.update();

	if(m_messageBox.finished()) {
		m_stateStack->pop();
	}
}

void MessageBoxState::draw(gk::RenderTarget &target, gk::RenderStates states) const {
	target.draw(*m_parent, states);

	target.draw(m_messageBox, states);
}

