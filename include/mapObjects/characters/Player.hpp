/*
 * =====================================================================================
 *
 *       Filename:  Player.hpp
 *
 *    Description:  
 *
 *        Created:  15/09/2014 22:17:43
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
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
		
		static Player player;
		
	private:
		Inventory m_inventory;
		
		// Flag used to know if the player is still on
		// a door after a DoorTransition
		bool m_inDoor = false;
};

#endif // PLAYER_HPP_
