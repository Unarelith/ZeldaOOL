/*
 * =====================================================================================
 *
 *       Filename:  Character.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  15/09/2014 22:17:21
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

#include "CharacterStateManager.hpp"
#include "Movable.hpp"

class Character : public Movable {
	public:
		Character() = default;
		Character(const std::string &filename, u16 x, u16 y, u16 width, u16 height, u8 direction);
		
		void load(const std::string &filename, u16 x, u16 y, u16 width, u16 height, u8 direction);
		
		void turn(bool clockwise = true);
		
		virtual void mapCollisions();
		
		virtual void mapCollisionAction(float vx, float vy);
		
		ICharacterState::StateTransition defaultState() const { return m_defaultState; }
		CharacterStateManager &stateManager() { return m_stateManager; }
		
		void updateDirection();
		
	protected:
		ICharacterState::StateTransition m_defaultState{[]{return nullptr;}};
		CharacterStateManager m_stateManager;
};

#endif // CHARACTER_HPP_
