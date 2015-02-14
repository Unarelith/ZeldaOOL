/*
 * =====================================================================================
 *
 *       Filename:  Transition.hpp
 *
 *    Description:  
 *
 *        Created:  14/02/2015 10:26:16
 *       Compiler:  gcc
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *        Company:  
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
