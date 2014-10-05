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
		
		Map *m_nextMap;
		
		float m_scrolled;
		
		StatsBar m_statsBar;
};

#endif // SCROLLINGTRANSITION_HPP_
