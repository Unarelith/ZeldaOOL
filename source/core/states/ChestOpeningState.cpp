/*
 * =====================================================================================
 *
 *       Filename:  ChestOpeningState.cpp
 *
 *    Description:
 *
 *        Created:  07/10/2014 00:58:51
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "ApplicationStateStack.hpp"
#include "AudioPlayer.hpp"
#include "CollectableFactory.hpp"
#include "ChestOpeningState.hpp"
#include "LifetimeComponent.hpp"
#include "Map.hpp"
#include "MessageBoxState.hpp"
#include "MovementComponent.hpp"
#include "MovementController.hpp"
#include "PositionComponent.hpp"
#include "Sprite.hpp"

ChestOpeningState::ChestOpeningState(SceneObject &chest, ApplicationState *parent) : ApplicationState(parent) {
	m_item = &Map::currentMap->scene().addObject(CollectableFactory::createRupees(0, 0, RupeesAmount::Thirty, CollectableMovement::Type::Chest));
	m_item->set<LifetimeComponent>();

	auto &chestPosition = chest.get<PositionComponent>();
	auto &itemPosition = m_item->get<PositionComponent>();

	itemPosition.x = chestPosition.x + 8 - itemPosition.width / 2;
	itemPosition.y = chestPosition.y - 8;

	Sprite::pause = true;
}

void ChestOpeningState::update() {
	if(m_state == State::Opening) {
		MovementController movementController;
		movementController.update(*m_item);

		auto &movementComponent = m_item->get<MovementComponent>();
		if(movementComponent.movements.top()->isFinished()) {
			m_state = State::Opened;
		}
	}
	else if(m_state == State::Opened) {
		AudioPlayer::playEffect("itemNew");

		ApplicationStateStack::getInstance().push<MessageBoxState>("Vous obtenez [2]30 Rubis[0]!\nC'est bien.", this);

		m_state = State::Finished;
	}
	else if(m_state == State::Finished) {
		Sprite::pause = false;

		m_item->get<LifetimeComponent>().kill();

		ApplicationStateStack::getInstance().pop();
	}
}

void ChestOpeningState::draw(RenderTarget &target, RenderStates states) const {
	target.draw(*m_parent, states);
}

