/*
 * =====================================================================================
 *
 *       Filename:  Transition.hpp
 *
 *    Description:  
 *
 *        Created:  05/10/2014 17:42:25
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef TRANSITION_HPP_
#define TRANSITION_HPP_

class Transition {
	public:
		virtual ~Transition() = default;
		
		virtual void update() = 0;
		
		virtual void draw() = 0;
		
		bool atEnd() const { return m_atEnd; }
		
	protected:
		bool m_atEnd = false;
};

#endif // TRANSITION_HPP_
