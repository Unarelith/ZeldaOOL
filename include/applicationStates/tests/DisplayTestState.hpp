/*
 * =====================================================================================
 *
 *       Filename:  DisplayTestState.hpp
 *
 *    Description:  
 *
 *        Created:  09/02/2015 02:15:29
 *       Compiler:  gcc
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef DISPLAYTESTSTATE_HPP_
#define DISPLAYTESTSTATE_HPP_

#include "ApplicationState.hpp"
#include "Font.hpp"
#include "Image.hpp"
#include "RectangleShape.hpp"
#include "Sprite.hpp"

class DisplayTestState : public ApplicationState {
	public:
		DisplayTestState();
		
		void update() override;
		
		void draw() override;
		
	private:
		Image m_image{"characters-link"};
		
		Sprite m_sprite{"characters-link", 16, 16};
		
		RectangleShape m_rect{64, 16, 32, 16};
		
		Font m_font{"interface-font", 8, 16};
};

#endif // DISPLAYTESTSTATE_HPP_
