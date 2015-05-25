/*
 * =====================================================================================
 *
 *       Filename:  TextBox.hpp
 *
 *    Description:  
 *
 *        Created:  23/02/2015 17:14:50
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef TEXTBOX_HPP_
#define TEXTBOX_HPP_

#include "Font.hpp"

#include <map>

class TextBox {
	public:
		TextBox(const std::string &text);
		
		void draw(IntRect rect);
		
		void setText(const std::string &text);
		
		bool scrollDown();
		void stopTextAnimation();
		
		bool isAtLastPage();
		bool textDisplayFinished();
		
		size_t textLength() const { return m_text.length(); }
		
		u32 charTimerTime() const { return m_charTimer.time(); }
		
		u8 charPerLine() const { return m_charPerLine; }
		
		u8 page() const { return m_page; }
		
	private:
		bool isTimeToDisplayLetter(u16 letterIndex);
		
		const u8 m_delay = 50;
		
		std::string m_text;
		
		Font m_font{"interface-font", 8, 16};
		
		Timer m_charTimer;
		
		u8 m_charPerLine = 16;
		
		u16 m_charsToDisplay = m_charPerLine * 2;
		
		u8 m_page = 0;
		
		Color m_currentColor = Color::text;
		std::map<u16, Color> m_colorChanges;
};

#endif // TEXTBOX_HPP_
