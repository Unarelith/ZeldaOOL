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
		HurtMovement(float vx, float vy)
			: m_vx(vx), m_vy(vy) {}
		
		void process(SceneObject &object) override;
		
	private:
		float m_vx;
		float m_vy;
		
		float m_movementCounter = 0;
};

#endif // HURTMOVEMENT_HPP_
