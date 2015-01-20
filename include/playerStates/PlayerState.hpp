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
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef PLAYERSTATE_HPP_
#define PLAYERSTATE_HPP_

#include "CharacterState.hpp"
#include "Player.hpp"

class PlayerState : public CharacterState<Player> {
	public:
		PlayerState() : CharacterState(Player::player) {}
		
		virtual void update() = 0;
		
		virtual void render() = 0;
};

#endif // PLAYERSTATE_HPP_
