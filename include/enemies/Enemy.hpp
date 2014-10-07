/*
 * =====================================================================================
 *
 *       Filename:  Enemy.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/10/2014 21:38:31
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef ENEMY_HPP_
#define ENEMY_HPP_

#include "Character.hpp"

class Enemy : public Character {
	public:
		Enemy();
		Enemy(std::string filename, u16 x, u16 y, u16 width, u16 height, u8 direction);
		virtual ~Enemy();
		
		void load(std::string filename, u16 x, u16 y, u16 width, u16 height, u8 direction);
		
		virtual void update() = 0;
		
		virtual void draw() = 0;
};

#endif // ENEMY_HPP_
