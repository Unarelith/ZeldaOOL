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
#include "Vector2.hpp"

class HurtMovement : public Movement {
	public:
		HurtMovement(Vector2f v, float speed)
			: m_v(v), m_speed(speed) {}
		
		void process(SceneObject &object) override;
		
	private:
		Vector2f m_v;
		
		float m_speed;
		float m_oldSpeed;
		
		float m_movementCounter = 0;
};

#endif // HURTMOVEMENT_HPP_
