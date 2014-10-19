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

#include "CharacterState.hpp"

class Character;

class CharacterStateManager {
	public:
		CharacterStateManager(Character *character);
		~CharacterStateManager();
		
		void update();
		void updateStates();
		
		void draw();
		
		void setNextState(std::string nextState) { m_nextState = nextState; }
		void resetNextState() { m_nextState = m_state->name(); }
		
		CharacterState *currentState() const { return m_state; }
		
	private:
		Character *m_character;
		
		CharacterState *m_state;
		
		std::string m_nextState;
};

#endif // CHARACTERSTATEMANAGER_HPP_
