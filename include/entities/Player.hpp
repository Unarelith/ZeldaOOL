/*
 * =====================================================================================
 *
 *       Filename:  Player.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  15/09/2014 22:17:43
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

#include "Battler.hpp"
#include "Inventory.hpp"
#include "PlayerState.hpp"

class Player : public Battler {
	public:
		Player();
		~Player();
		
		void load();
		
		void update();
		void updateStates();
		
		void draw();
		
		void mapCollisions();
		
		void setNextStateType(PlayerState::StateType nextType);
		
		PlayerState *currentState() const { return m_state; }
		
		Inventory &inventory() { return m_inventory; }
		
	private:
		PlayerState *m_state;
		
		Inventory m_inventory;
		
		bool m_inDoor;
};

#endif // PLAYER_HPP_
