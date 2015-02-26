/*
 * =====================================================================================
 *
 *       Filename:  CollectableMovement.hpp
 *
 *    Description:  
 *
 *        Created:  26/02/2015 19:11:36
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
			OutOfChest
		};
		
		CollectableMovement(Type type) : m_type(type) {}
		
		void process(SceneObject &object) override;
		
	private:
		Type m_type;
		
		float m_movementCounter = 0;
};

#endif // COLLECTABLEMOVEMENT_HPP_
