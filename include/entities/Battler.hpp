/*
 * =====================================================================================
 *
 *       Filename:  Battler.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/10/2014 01:10:56
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef BATTLER_HPP_
#define BATTLER_HPP_

#include "Character.hpp"

class Battler : public Character {
	public:
		Battler();
		Battler(std::string filename, u16 x, u16 y, u16 width, u16 height, u8 direction);
		~Battler();
		
		void load(std::string filename, u16 x, u16 y, u16 width, u16 height, u8 direction);
		
		void update();
		
		void drawFrame(float x, float y, u16 frame);
		
		void hurt() { m_hurt = true; m_hurtTimer.reset(); m_hurtTimer.start(); }
		
	private:
		bool m_hurt;
		Timer m_hurtTimer;
};

#endif // BATTLER_HPP_
