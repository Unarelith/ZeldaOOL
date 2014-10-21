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

#include "ICharacterState.hpp"

class Character;

class CharacterStateManager {
	public:
		CharacterStateManager();
		CharacterStateManager(Character *character);
		~CharacterStateManager();
		
		void load(Character *character);
		
		void update();
		void updateStates();
		
		void render();
		
		void setNextState(ICharacterState::StateTransition stateTransition);
		
		void resetNextState();
		
		ICharacterState *currentState() const { return m_currentState; }
		
	private:
	 	ICharacterState *m_currentState;
	 	ICharacterState *m_nextState;
		
		ICharacterState::StateTransition m_stateTransition;
		
		static const ICharacterState::StateTransition nullFunction() {
			return [](){ return nullptr; };
		}
};

#endif // CHARACTERSTATEMANAGER_HPP_
