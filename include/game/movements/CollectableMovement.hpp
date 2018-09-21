/*
 * =====================================================================================
 *
 *       Filename:  CollectableMovement.hpp
 *
 *    Description:
 *
 *        Created:  01/05/2015 23:41:31
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef COLLECTABLEMOVEMENT_HPP_
#define COLLECTABLEMOVEMENT_HPP_

#include "Movement.hpp"
#include "Timer.hpp"

class CollectableMovement : public Movement {
	public:
		enum class Type {
			Dropped,
			Chest
		};

		CollectableMovement(Type type) : m_type(type) {}

		void process(SceneObject &object) override;

	private:
		Type m_type;

		const float m_baseSpeed = 0.5f;

		float m_speed = -m_baseSpeed;
		float m_movementCounter = 0;
};

#endif // COLLECTABLEMOVEMENT_HPP_
