/*
 * =====================================================================================
 *
 *       Filename:  PlayerState.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  15/09/2014 22:24:24
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef PLAYERSTATE_HPP_
#define PLAYERSTATE_HPP_

#include "CharacterState.hpp"
#include "Player.hpp"

class PlayerState : public CharacterState {
	public:
		PlayerState();
		virtual ~PlayerState();
		
		virtual void update() = 0;
		
		virtual void draw() = 0;
		
	protected:
		Player &m_player;
};

#endif // PLAYERSTATE_HPP_
