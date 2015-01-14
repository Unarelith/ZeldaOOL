/*
 * =====================================================================================
 *
 *       Filename:  Menu.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/10/2014 14:33:21
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef MENU_HPP_
#define MENU_HPP_

#include "Image.hpp"

class Menu {
	public:
		Menu();
		~Menu();
		
		void update();
		
		void draw();
		
	private:
		Image m_background;
		Image m_cursor;
		
		s8 m_cursorX;
		s8 m_cursorY;
};

#endif // MENU_HPP_
