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
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef WEAPON_HPP_
#define WEAPON_HPP_

#include "Enemy.hpp"
#include "PlayerState.hpp"

class Weapon : public Movable {
	public:
		Weapon(const std::string &name, u8 level, u16 width, u16 height);
		
		bool keyPressed();
		bool keyPressedOnce();
		
		Image &icon() { return m_icon; }
		
		u8 id() const { return m_id; }
		
		virtual void updateOwnerNextState() = 0;
		
	protected:
		u8 m_id;
		
		u8 m_level = 0;
		u8 m_strength = 0;
		
		Image m_icon;
		
		Player &m_player;
};

#endif // WEAPON_HPP_
