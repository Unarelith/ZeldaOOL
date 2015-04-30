/*
 * =====================================================================================
 *
 *       Filename:  StatsBar.hpp
 *
 *    Description:  
 *
 *        Created:  15/09/2014 23:34:47
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef STATSBAR_HPP_
#define STATSBAR_HPP_

#include "Sprite.hpp"

class StatsBar {
	public:
		void draw();
		
	private:
		Image m_background{"interface-stats"};
		
		Sprite m_hearts{"interface-hearts", 7, 7};
		Sprite m_numbers{"interface-numbers", 7, 6};
};

#endif // STATSBAR_HPP_
