/*
 * =====================================================================================
 *
 *       Filename:  NPC.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  22/01/2015 07:06:12
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef NPC_HPP_
#define NPC_HPP_

#include "Character.hpp"

class NPC : public Character {
	public:
		NPC() = default;
		NPC(const std::string &textureName, u16 x, u16 y, u16 width, u16 height, u8 direction);
		
		void load(const std::string &textureName, u16 x, u16 y, u16 width, u16 height, u8 direction);
		
		bool playerInFrontOfThis();
		
		void update();
		
		void draw();
};

#endif // NPC_HPP_
