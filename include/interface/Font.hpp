/*
 * =====================================================================================
 *
 *       Filename:  Font.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  26/09/2014 20:41:39
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef FONT_HPP_
#define FONT_HPP_

#include "Color.hpp"
#include "Shader.hpp"
#include "Sprite.hpp"

class Font : public Sprite {
	public:
		Font();
		~Font();
		
		void drawChar(float x, float y, char32_t c);
		void drawString(float x, float y, std::u32string str, Color color = Color::text);
		u8 drawTextBox(float x, float y, u16 width, u16 height, std::u32string str, u16 lineOffset, Color color = Color::text);
		
		u16 charWidth() const { return m_frameWidth; }
		u16 charHeight() const { return m_frameHeight; }
		
	private:
		Shader m_shader;
};

#endif // FONT_HPP_
