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
#include <map>

#include "Font.hpp"
#include "Image.hpp"
#include "RectangleShape.hpp"

class MessageBox {
	public:
		enum Position : u8 {
			Top    = 24,
			Bottom = 96
		};
		
		MessageBox(const std::string &text = "", Position position = Position::Top);
		
		void update();
		
		void draw();
		void drawText();
		
		void setText(const std::string &text);
		
		void setPosition(Position position) { m_rectangle.setPosition(8, position); }
		
	private:
		bool isTimeToDisplayLetter(u16 letterIndex);
		bool textDisplayFinished();
		
		const u8 m_charPerLine = 16;
		const u8 m_delay = 50;
		
		std::string m_text;
		
		Font m_font{"interface-font", 8, 16};
		
		Image m_dialogArrow{"interface-dialogArrow"};
		
		RectangleShape m_rectangle{8, Position::Top, 144, 40};
		
		Timer m_charTimer;
		
		bool m_displayArrow = true;
		
		u8 m_page = 0;
		
		u16 m_charsToDisplay = m_charPerLine * 2;
		
		Color m_currentColor = Color::text;
		std::map<u16, Color> m_colorChanges;
};

#endif // MESSAGEBOX_HPP_
