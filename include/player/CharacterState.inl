/*
 * =====================================================================================
 *
 *       Filename:  CharacterState.inl
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  13/10/2014 16:54:42
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "Character.hpp"

template<typename T>
CharacterState<T>::CharacterState(T &character) : m_character(character) {
}

template<typename T>
CharacterState<T>::~CharacterState() {
}

template<typename T>
void CharacterState<T>::setNextState(StateTransition stateTransition) {
	((Character*)(&m_character))->stateManager().setNextState(stateTransition);
}

