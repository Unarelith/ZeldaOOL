/*
 * =====================================================================================
 *
 *       Filename:  HeartCollectable.hpp
 *
 *    Description:  
 *
 *        Created:  07/10/2014 17:19:24
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef HEARTCOLLECTABLE_HPP_
#define HEARTCOLLECTABLE_HPP_

#include "Collectable.hpp"

class HeartCollectable : public Collectable {
	public:
		HeartCollectable(float x, float y);
		
		void action();
};

#endif // HEARTCOLLECTABLE_HPP_
