/*
 * =====================================================================================
 *
 *       Filename:  ChestOpeningState.cpp
 *
 *    Description:  
 *
 *        Created:  24/02/2015 15:44:29
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
#include "MovementSystem.hpp"
#include "MovementComponent.hpp"
#include "PositionComponent.hpp"
#include "Sprite.hpp"

ChestOpeningState::ChestOpeningState(SceneObject &chest, ApplicationState *parent) : ApplicationState(parent) {
	m_item = &Map::currentMap->scene().addObject(CollectableFactory::createRupees(0, 0, RupeesAmount::Thirty, CollectableMovement::Type::OutOfChest));
	m_item->setComponent<LifetimeComponent>();
	
	auto *chestPosition = chest.getComponent<PositionComponent>();
	auto *itemPosition = m_item->getComponent<PositionComponent>();
	
	itemPosition->x = chestPosition->x + 7 - itemPosition->width / 2;
	itemPosition->y = chestPosition->y - 8;
	
	Sprite::pause = true;
}

void ChestOpeningState::update() {
	if(m_state == State::Opening) {
		MovementSystem::process(*m_item);
		
		auto *movementComponent = m_item->getComponent<MovementComponent>();
		if(movementComponent->movement->isFinished()) {
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
		
		m_item->getComponent<LifetimeComponent>()->kill();
		
		ApplicationStateStack::getInstance().pop();
	}
}

void ChestOpeningState::draw() {
	m_parent->draw();
}

