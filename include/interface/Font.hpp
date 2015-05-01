/*
 * =====================================================================================
 *
 *       Filename:  Font.hpp
 *
 *    Description:  
 *
 *        Created:  26/09/2014 20:41:39
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef FONT_HPP_
#define FONT_HPP_

#include "Color.hpp"
#include "Sprite.hpp"

class Font {
	public:
		Font() = default;
		Font(const std::string &filename, u16 charWidth, u16 charHeight);
		
		void load(const std::string &filename, u16 charWidth, u16 charHeight);
		
		void drawChar(float x, float y, u8 c, Color color = Color::white);
		void drawString(float x, float y, const std::string &str, Color color = Color::white);
		
		u16 charWidth() const { return m_sprite.frameWidth(); }
		u16 charHeight() const { return m_sprite.frameHeight(); }
		
	private:
		Sprite m_sprite;
};

#endif // FONT_HPP_
