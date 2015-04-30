/*
 * =====================================================================================
 *
 *       Filename:  NPC.hpp
 *
 *    Description:  
 *
 *        Created:  22/01/2015 07:06:12
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
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
		
	private:
		u8 m_defaultDirection;
};

#endif // NPC_HPP_
