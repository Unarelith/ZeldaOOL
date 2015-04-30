/*
 * =====================================================================================
 *
 *       Filename:  CharacterState.hpp
 *
 *    Description:  
 *
 *        Created:  13/10/2014 16:54:33
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef CHARACTERSTATE_HPP_
#define CHARACTERSTATE_HPP_

#include "Character.hpp"

template<typename T = Character>
class CharacterState : public AbstractCharacterState {
	public:
		CharacterState(T &character) : m_character(character) {}
		
		template<typename StateType, typename... Args>
		void setNextState(Args &&...args) {
			m_character.stateManager().setNextState<StateType>(std::forward<Args>(args)...);
		}
		
	protected:
		T &m_character;
};

#endif // CHARACTERSTATE_HPP_
