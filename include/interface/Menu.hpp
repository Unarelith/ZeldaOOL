/*
 * =====================================================================================
 *
 *       Filename:  Menu.hpp
 *
 *    Description:  
 *
 *        Created:  02/10/2014 14:33:21
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef MENU_HPP_
#define MENU_HPP_

#include "Image.hpp"
#include "Vector2.hpp"

class Menu {
	public:
		void update();
		
		void draw();
		
	private:
		Image m_background{"interface-menuBackground"};
		Image m_cursor{"interface-menuCursor"};
		
		Vector2s8 m_cursorPosition = {0, 0};
};

#endif // MENU_HPP_
