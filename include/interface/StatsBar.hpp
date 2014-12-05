/*
 * =====================================================================================
 *
 *       Filename:  StatsBar.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/12/2014 00:50:01
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef STATSBAR_HPP_
#define STATSBAR_HPP_

#include "Sprite.hpp"

class StatsBar {
	public:
		StatsBar();
		~StatsBar();
		
		void draw();
		
		static StatsBar &getInstance() {
			static StatsBar instance;
			return instance;
		}
		
	private:
		Image m_background;
		
		Sprite m_hearts;
		Sprite m_numbers;
};

#endif // STATSBAR_HPP_
