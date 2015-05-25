/*
 * =====================================================================================
 *
 *       Filename:  MessageBox.hpp
 *
 *    Description:  
 *
 *        Created:  22/02/2015 17:49:25
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef MESSAGEBOX_HPP_
#define MESSAGEBOX_HPP_

#include <algorithm>
#include <functional>
#include <string>

#include "Image.hpp"
#include "RectangleShape.hpp"
#include "TextBox.hpp"

class MessageBox {
	public:
		enum Position : u8 {
			Top    = 24,
			Bottom = 96
		};
		
		MessageBox(const std::string &text = "", Position position = Position::Top);
		
		void update();
		
		void draw();
		
		void setPosition(Position position) { m_rectangle.setPosition({(float)8, (float)position}); }
		
		bool finished() const { return m_finished; }
		
	private:
		Image m_dialogArrow{"interface-dialogArrow"};
		
		RectangleShape m_rectangle{{8.0f, Position::Top}, 144, 40};
		
		TextBox m_textBox;
		
		bool m_finished = false;
};

#endif // MESSAGEBOX_HPP_
