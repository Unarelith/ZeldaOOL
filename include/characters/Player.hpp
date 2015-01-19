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
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "Battler.hpp"
#include "Inventory.hpp"

class Player : public Battler {
	public:
		void load();
		
		void update(bool states = true);
		
		void draw();
		
		void collisionAction(MapObject &object) override;
		
		void mapCollisions();
		
		Inventory &inventory() { return m_inventory; }
		
	private:
		Inventory m_inventory;
		
		bool m_inDoor;
};

#endif // PLAYER_HPP_
