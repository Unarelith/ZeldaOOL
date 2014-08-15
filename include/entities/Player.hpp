/*
 * =====================================================================================
 *
 *       Filename:  Player.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  14/08/2014 19:11:30
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
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
		
		void move();
		
		void draw();
		
		enum State {
			Standing,
			Moving,
			Colliding,
			Attacking
		};
		
	private:
		State m_state;
};

#endif // PLAYER_HPP_
