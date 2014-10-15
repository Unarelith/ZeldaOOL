/*
 * =====================================================================================
 *
 *       Filename:  Weapon.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  15/09/2014 22:25:55
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef WEAPON_HPP_
#define WEAPON_HPP_

#include "CharacterManager.hpp"
#include "PlayerState.hpp"

class Weapon : public Sprite, public Entity {
	public:
		Weapon(std::string filename, u16 width, u16 height);
		virtual ~Weapon();
		
		virtual void loadState() = 0;
		
		virtual void update() = 0;
		
		virtual void draw() = 0;
		
		bool keyPressed();
		bool keyPressedOnce();
		
		u8 id() const { return m_id; }
		
		PlayerState *playerState() const { return m_playerState; }
		
	protected:
		u8 m_id;
		
		Player &m_player;
		
		PlayerState *m_playerState;
};

#endif // WEAPON_HPP_
