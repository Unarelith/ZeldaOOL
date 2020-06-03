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
// #include <gk/audio/AudioPlayer.hpp> // FIXME: GAMEKIT
#include <gk/core/ApplicationStateStack.hpp>
#include <gk/scene/component/MovementComponent.hpp>

#include "CollectableFactory.hpp"
#include "ChestOpeningState.hpp"
#include "LifetimeComponent.hpp"
#include "MessageBoxState.hpp"
#include "MovementController.hpp"
#include "PositionComponent.hpp"
#include "Sprite.hpp"
#include "World.hpp"

ChestOpeningState::ChestOpeningState(gk::SceneObject &chest, gk::ApplicationState *parent) : gk::ApplicationState(parent) {
	m_item = &World::getInstance().currentMap()->scene().addObject(CollectableFactory::createRupees(0, 0, RupeesAmount::Thirty, CollectableMovement::Type::Chest));
	m_item->set<LifetimeComponent>();

	auto &chestPosition = chest.get<PositionComponent>();
	auto &itemPosition = m_item->get<PositionComponent>();

	itemPosition.x = chestPosition.x + 8 - itemPosition.sizeX / 2;
	itemPosition.y = chestPosition.y - 8;

	Sprite::pause = true;
}

void ChestOpeningState::update() {
	if(m_state == State::Opening) {
		MovementController movementController;
		movementController.update(*m_item);

		auto &movementComponent = m_item->get<gk::MovementComponent>();
		if(movementComponent.movements.top()->isFinished()) {
			m_state = State::Opened;
		}
	}
	else if(m_state == State::Opened) {
		// gk::AudioPlayer::playSound("sfx-itemNew"); // FIXME: GAMEKIT

		gk::ApplicationStateStack::getInstance().push<MessageBoxState>("Vous obtenez [2]30 Rubis[0]!\nC'est bien.", this);

		m_state = State::Finished;
	}
	else if(m_state == State::Finished) {
		Sprite::pause = false;

		m_item->get<LifetimeComponent>().kill();

		gk::ApplicationStateStack::getInstance().pop();
	}
}

void ChestOpeningState::draw(gk::RenderTarget &target, gk::RenderStates states) const {
	target.draw(*m_parent, states);
}

