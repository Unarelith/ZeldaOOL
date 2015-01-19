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
 *        Company:  
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
		
		void updateDirection();
		
		template<typename StateType, typename... Args>
		void setNextState(Args &&...args) {
			m_stateManager.setNextState<StateType>(std::forward<Args>(args)...);
		}
		
		CharacterStateManager &stateManager() { return m_stateManager; }
		
	protected:
		CharacterStateManager m_stateManager;
};

#endif // CHARACTER_HPP_
