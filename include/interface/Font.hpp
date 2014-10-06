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
#include "ShaderManager.hpp"
#include "Sprite.hpp"

class Font : public Sprite {
	public:
		Font();
		Font(std::string filename, u16 charWidth, u16 charHeight);
		~Font();
		
		void load(std::string filename, u16 charWidth, u16 charHeight);
		
		void drawChar(float x, float y, u8 c);
		void drawString(float x, float y, std::string str, s16 charsToDraw);
		
		void setColor(Color color);
		
		u16 charWidth() const { return m_frameWidth; }
		u16 charHeight() const { return m_frameHeight; }
		
		Shader shader() const { return m_shader; }
		
	private:
		Shader m_shader;
		
		GLfloat m_colors[12];
};

#endif // FONT_HPP_
