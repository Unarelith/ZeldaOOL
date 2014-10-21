/*
 * =====================================================================================
 *
 *       Filename:  CharacterState.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  13/10/2014 16:54:33
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef CHARACTERSTATE_HPP_
#define CHARACTERSTATE_HPP_

#include "ICharacterState.hpp"

template<typename T>
class CharacterState : public ICharacterState {
	public:
		CharacterState(T &character);
		virtual ~CharacterState();
		
		virtual void update() = 0;
		
		virtual void render() = 0;
		
		virtual bool canStartMapTransition() { return false; }
		
		void setNextState(StateTransition stateTransition);
		
	protected:
		T &m_character;
};

#include "CharacterState.inl"

#endif // CHARACTERSTATE_HPP_
