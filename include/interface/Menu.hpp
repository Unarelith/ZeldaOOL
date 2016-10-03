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

class Menu {
	public:
		void update();

		void draw();

	private:
		Image m_background{"interface-menuBackground"};
		Image m_cursor{"interface-menuCursor"};

		s8 m_cursorX = 0;
		s8 m_cursorY = 0;
};

#endif // MENU_HPP_
