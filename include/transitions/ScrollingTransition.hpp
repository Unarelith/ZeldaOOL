/*
 * =====================================================================================
 *
 *       Filename:  ScrollingTransition.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/12/2014 05:30:14
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

#include "AnimatedMap.hpp"
#include "StatsBar.hpp"
#include "Transition.hpp"

class ScrollingTransition : public Transition {
	public:
		ScrollingTransition(u8 mode);
		~ScrollingTransition();
		
		void update();
		
		void draw();
		
		enum Mode {
			ScrollingLeft,
			ScrollingRight,
			ScrollingUp,
			ScrollingDown
		};
		
	private:
		Mode m_mode;
		
		float m_vx;
		float m_vy;
		
		AnimatedMap *m_nextMap;
		
		float m_scrolled;
		
		StatsBar &m_statsBar;
};

#endif // SCROLLINGTRANSITION_HPP_
