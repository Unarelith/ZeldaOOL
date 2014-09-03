/*
 * =====================================================================================
 *
 *       Filename:  Weapon.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/09/2014 19:46:41
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

class Weapon : public Sprite, public Entity {
	public:
		Weapon(std::string filename, u16 width, u16 height);
		~Weapon();
		
	protected:
		Player &m_player;
};

#endif // WEAPON_HPP_
