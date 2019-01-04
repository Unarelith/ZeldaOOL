/*
 * =====================================================================================
 *
 *       Filename:  HurtMovement.hpp
 *
 *    Description:
 *
 *        Created:  18/01/2015 18:55:11
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef HURTMOVEMENT_HPP_
#define HURTMOVEMENT_HPP_

#include <gk/core/IntTypes.hpp>

#include <gk/scene/movement/Movement.hpp>

class HurtMovement : public gk::Movement {
	public:
		HurtMovement(float vx, float vy)
			: m_vx(vx), m_vy(vy) {}

		void process(gk::SceneObject &object) override;

	private:
		float m_vx;
		float m_vy;

		float m_movementCounter = 0;
};

#endif // HURTMOVEMENT_HPP_
