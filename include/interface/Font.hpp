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

#include "Sprite.hpp"

class Font : public Sprite {
	public:
		Font() = default;
		Font(const std::string &filename, u16 charWidth, u16 charHeight);
		
		void load(const std::string &filename, u16 charWidth, u16 charHeight);
		
		void drawChar(float x, float y, u8 c);
		void drawString(float x, float y, const std::string &str, s16 charsToDraw);
		
		u16 charWidth() const { return m_frameWidth; }
		u16 charHeight() const { return m_frameHeight; }
};

#endif // FONT_HPP_
