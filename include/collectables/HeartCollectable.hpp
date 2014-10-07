/*
 * =====================================================================================
 *
 *       Filename:  HeartCollectable.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/10/2014 17:19:24
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef HEARTCOLLECTABLE_HPP_
#define HEARTCOLLECTABLE_HPP_

#include "Collectable.hpp"

class HeartCollectable : public Collectable {
	public:
		HeartCollectable(float x, float y);
		~HeartCollectable();
		
		void action();
};

#endif // HEARTCOLLECTABLE_HPP_
