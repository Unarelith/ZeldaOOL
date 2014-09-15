/*
 * =====================================================================================
 *
 *       Filename:  Character.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  15/09/2014 22:17:21
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

#include "Types.hpp"
#include "Sprite.hpp"
#include "Entity.hpp"

class Character : public Sprite, public Entity {
	public:
		Character(std::string filename, u16 x, u16 y, u16 width, u16 height, u8 direction);
		~Character();
		
		void draw();
		
		void turn(bool clockwise = true);
		
		enum Direction {
			Down,
			Right,
			Left,
			Up
		};
		
		u8 direction() const { return m_direction; }
		
		void setDirection(u8 direction) { m_direction = direction; }
		
	protected:
		u8 m_direction;
};

#endif // CHARACTER_HPP_
