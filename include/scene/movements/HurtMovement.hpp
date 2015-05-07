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

#include "IntTypes.hpp"
#include "Movement.hpp"

class HurtMovement : public Movement {
	public:
		HurtMovement(s16 vx, s16 vy, float speed)
			: m_vx(vx), m_vy(vy), m_speed(speed) {}
		
		void process(SceneObject &object) override;
		
	private:
		s16 m_vx;
		s16 m_vy;
		
		float m_speed;
		float m_oldSpeed;
		
		float m_movementCounter = 0;
};

#endif // HURTMOVEMENT_HPP_
