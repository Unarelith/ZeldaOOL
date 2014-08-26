/*
 * =====================================================================================
 *
 *       Filename:  Weapon.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  24/08/2014 21:08:15
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

#include "Sprite.hpp"
#include "Entity.hpp"

class Weapon : public Sprite, public Entity {
	public:
		Weapon(std::string filename, u16 frameWidth, u16 frameHeight);
		virtual ~Weapon();
		
		virtual void reset() = 0;
		
		virtual bool update() = 0;
		
		virtual void draw() = 0;
};

#endif // WEAPON_HPP_
