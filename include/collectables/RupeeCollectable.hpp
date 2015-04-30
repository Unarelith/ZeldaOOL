/*
 * =====================================================================================
 *
 *       Filename:  RupeeCollectable.hpp
 *
 *    Description:  
 *
 *        Created:  07/10/2014 18:21:46
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef RUPEECOLLECTABLE_HPP_
#define RUPEECOLLECTABLE_HPP_

#include "Collectable.hpp"

class RupeeCollectable : public Collectable {
	public:
		RupeeCollectable(float x, float y, u16 rupees);
		
		void action() override;
		
	private:
		u16 m_rupees;
};

#endif // RUPEECOLLECTABLE_HPP_
