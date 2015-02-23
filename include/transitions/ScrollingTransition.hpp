/*
 * =====================================================================================
 *
 *       Filename:  ScrollingTransition.hpp
 *
 *    Description:  
 *
 *        Created:  14/02/2015 10:27:41
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef SCROLLINGTRANSITION_HPP_
#define SCROLLINGTRANSITION_HPP_

#include "Map.hpp"
#include "Transition.hpp"

class ScrollingTransition : public Transition {
	public:
		enum class Mode {
			ScrollingLeft,
			ScrollingRight,
			ScrollingUp,
			ScrollingDown
		};
		
		ScrollingTransition(Mode mode);
		
		void update();
		
		void draw();
		
	private:
		Mode m_mode;
		
		float m_vx = 0;
		float m_vy = 0;
		
		Map *m_nextMap = nullptr;
		
		float m_scrolled = 0;
};

#endif // SCROLLINGTRANSITION_HPP_
