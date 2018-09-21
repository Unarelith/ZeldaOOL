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
#include "SceneObject.hpp"

class Menu : public IDrawable {
	public:
		Menu();

		void update(SceneObject &player);

	private:
		void draw(RenderTarget &target, RenderStates states) const override;

		Image m_background{"interface-menuBackground"};
		Image m_cursor{"interface-menuCursor"};

		s8 m_cursorX = 0;
		s8 m_cursorY = 0;

		const SceneObject *m_player = nullptr;
};

#endif // MENU_HPP_
