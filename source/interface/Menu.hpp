/*
 * =====================================================================================
 *
 *       Filename:  Menu.hpp
 *
 *    Description:
 *
 *        Created:  02/10/2014 14:33:21
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef MENU_HPP_
#define MENU_HPP_

#include "Image.hpp"

class Menu : public gk::Drawable {
	public:
		Menu();

		void update();

	private:
		void draw(gk::RenderTarget &target, gk::RenderStates states) const override;

		Image m_background{"interface-menuBackground"};
		Image m_cursor{"interface-menuCursor"};

		s8 m_cursorX = 0;
		s8 m_cursorY = 0;
};

#endif // MENU_HPP_
