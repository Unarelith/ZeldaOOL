/*
 * =====================================================================================
 *
 *       Filename:  RupeeCollectable.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/10/2014 18:21:46
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef RUPEECOLLECTABLE_HPP_
#define RUPEECOLLECTABLE_HPP_

#include "Collectable.hpp"

class RupeeCollectable : public Collectable {
	public:
		RupeeCollectable(float x, float y, u16 rupees);
		~RupeeCollectable();
		
		void action();
		
	private:
		u16 m_rupees;
};

#endif // RUPEECOLLECTABLE_HPP_
