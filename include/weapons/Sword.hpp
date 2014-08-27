/*
 * =====================================================================================
 *
 *       Filename:  Sword.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  24/08/2014 21:12:57
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef SWORD_HPP_
#define SWORD_HPP_

#include "Weapon.hpp"

class Sword : public Weapon {
	public:
		Sword();
		~Sword();
		
		bool reset();
		
		bool update();
		
		void draw();
		
	private:
		double m_tmpPlayerX;
		double m_tmpPlayerY;
};

#endif // SWORD_HPP_
