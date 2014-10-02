/*
 * =====================================================================================
 *
 *       Filename:  Dialog.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  26/09/2014 20:34:27
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef DIALOG_HPP_
#define DIALOG_HPP_

#include <vector>

#include "Font.hpp"
#include "Rectangle.hpp"

class Dialog {
	public:
		Dialog();
		~Dialog();
		
		void update();
		
		void draw();
		void drawText();
		
		enum Position {
			Top		= 24,
			Bottom	= 96
		};
		
		void setText(std::string text);
		void setPosition(Position position) { m_rectangle.setPosition(8, position); }
		
		void scrollDown();
		
		bool waitForUser();
		
		bool lastPage() { return (m_currentLine + 2 >= (u8)m_lines.size()); }
		
	private:
		Rectangle m_rectangle;
		
		Font m_font;
		
		Sprite m_dialogArrow;
		
		u8 m_currentLine;
		
		std::vector<std::pair<u8, std::string>> m_lines;
		Timer m_charTimer;
		Timer m_soundTimer;
};

#endif // DIALOG_HPP_
