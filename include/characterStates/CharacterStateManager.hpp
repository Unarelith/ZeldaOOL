/*
 * =====================================================================================
 *
 *       Filename:  CharacterStateManager.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  13/10/2014 16:45:25
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef CHARACTERSTATEMANAGER_HPP_
#define CHARACTERSTATEMANAGER_HPP_

#include <functional>
#include <memory>

#include "AbstractCharacterState.hpp"

class Character;

class CharacterStateManager {
	public:
		void update();
		void updateStates();
		
		void render();
		
		template<typename StateType, typename... Args>
		void setNextState(Args &&...args) {
			if(!m_currentState || typeid(*m_currentState) != typeid(StateType)) {
				m_stateTransition = [=]{ return new StateType(args...); };
			}
		}
		
		const AbstractCharacterState &currentState() const { return *m_currentState; }
		
	private:
		std::unique_ptr<AbstractCharacterState> m_currentState{nullptr};
		
		std::function<AbstractCharacterState*(void)> m_stateTransition;
};

#endif // CHARACTERSTATEMANAGER_HPP_
