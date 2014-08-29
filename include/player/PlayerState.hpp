/*
 * =====================================================================================
 *
 *       Filename:  PlayerState.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  29/08/2014 04:46:51
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

class Player;

class PlayerState {
	public:
		PlayerState();
		virtual ~PlayerState();
		
		virtual void update() = 0;
		
		virtual void draw() = 0;
		
	protected:
		Player &m_player;
};

#include "CharacterManager.hpp"

#endif // PLAYERSTATE_HPP_
