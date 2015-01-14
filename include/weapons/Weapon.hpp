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

#include "Enemy.hpp"
#include "ICharacterState.hpp"
#include "PlayerState.hpp"

class Weapon : public Sprite, public Entity {
	public:
		Weapon(const std::string &name, u8 level, u16 width, u16 height);
		Weapon(const Weapon &) = delete;
		Weapon(Weapon &&) = default;
		virtual ~Weapon() = default;
		
		virtual void update() = 0;
		
		virtual void draw() = 0;
		
		virtual void testCollisionWith(Enemy *enemy) = 0;
		
		bool keyPressed();
		bool keyPressedOnce();
		
		Image &icon() { return m_icon; }
		
		u8 id() const { return m_id; }
		
		ICharacterState::StateTransition playerStateTransition() const { return m_playerStateTransition; }
		
	protected:
		u8 m_id;
		
		u8 m_level = 0;
		u8 m_strength = 0;
		
		Image m_icon;
		
		Player &m_player;
		
		ICharacterState::StateTransition m_playerStateTransition;
};

#endif // WEAPON_HPP_
