/*
 * =====================================================================================
 *
 *       Filename:  Movement.hpp
 *
 *    Description:  
 *
 *        Created:  14/02/2015 19:51:57
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef MOVEMENT_HPP_
#define MOVEMENT_HPP_

#include "SceneObject.hpp"

class Movement {
	public:
		virtual ~Movement() = default;
		
		bool isFinished() const { return m_isFinished; }
		
		virtual void process(SceneObject &object) = 0;
		
	protected:
		bool m_isFinished = false;
};

#endif // MOVEMENT_HPP_
