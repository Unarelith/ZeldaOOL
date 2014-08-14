/*
 * =====================================================================================
 *
 *       Filename:  Character.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  14/08/2014 19:06:45
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
		
		enum State {
			Standing,
			Moving
		};
		
		enum Direction {
			Down,
			Right,
			Left,
			Up
		};
		
	protected:
		State m_state;
		
		u8 m_direction;
};

#endif // CHARACTER_HPP_
