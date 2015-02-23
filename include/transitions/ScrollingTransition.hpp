/*
 * =====================================================================================
 *
 *       Filename:  ScrollingTransition.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/10/2014 17:45:49
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef SCROLLINGTRANSITION_HPP_
#define SCROLLINGTRANSITION_HPP_

#include "Map.hpp"
#include "StatsBar.hpp"
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
		
		StatsBar m_statsBar;
};

#endif // SCROLLINGTRANSITION_HPP_
