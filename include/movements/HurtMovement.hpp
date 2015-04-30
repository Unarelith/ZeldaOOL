/*
 * =====================================================================================
 *
 *       Filename:  HurtMovement.hpp
 *
 *    Description:  
 *
 *        Created:  18/01/2015 18:55:11
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef HURTMOVEMENT_HPP_
#define HURTMOVEMENT_HPP_

#include "Movement.hpp"
#include "Types.hpp"

class HurtMovement : public Movement {
	public:
		HurtMovement(s16 vx, s16 vy, float speed);
		
		void doMovement(Movable &movable) override;
		
	private:
		s16 m_vx = 0;
		s16 m_vy = 0;
		
		float m_speed;
		
		float m_movementCounter = 0;
};

#endif // HURTMOVEMENT_HPP_
