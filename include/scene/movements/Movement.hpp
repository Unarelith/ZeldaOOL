/*
 * =====================================================================================
 *
 *       Filename:  Movement.hpp
 *
 *    Description:  
 *
 *        Created:  13/10/2014 00:48:24
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
