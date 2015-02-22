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

#include "Font.hpp"
#include "Image.hpp"
#include "RectangleShape.hpp"

class MessageBox {
	public:
		MessageBox();
		
		void update();
		
		void draw();
		void drawText();
		
		enum Position : u8 {
			Top    = 24,
			Bottom = 96
		};
		
		void setText(const std::string &text) {
			m_text = text;
			
			// Fix problems with accents
			m_text.erase(std::remove_if(m_text.begin(), m_text.end(), std::bind(std::equal_to<u8>(), 195, std::placeholders::_1)), m_text.end());
		}
		
		void setPosition(Position position) { m_rectangle.setPosition(8, position); }
		
	private:
		std::string m_text;
		
		Font m_font{"interface-font", 8, 16};
		
		Image m_dialogArrow{"interface-dialogArrow"};
		
		RectangleShape m_rectangle{8, Position::Top, 144, 40};
		
		Timer m_charTimer;
		
		u8 m_page = 0;
};

#endif // MESSAGEBOX_HPP_
