/*
 * =====================================================================================
 *
 *       Filename:  Player.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/12/2014 21:53:01
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "Character.hpp"

class Player : public Character {
	public:
		Player();
		~Player();
		
		void collisionAction(Character &character);
		
		void mapCollisions();
		
		u16 maxLife() const { return m_maxLife; }
		s16 life() const { return m_life; }
		
		static Player &getInstance() {
			static Player instance;
			return instance;
		}
		
	private:
		u16 m_maxLife;
		s16 m_life;
};

#endif // PLAYER_HPP_
