/*
 * =====================================================================================
 *
 *       Filename:  Image.hpp
 *
 *    Description:  
 *
 *        Created:  20/09/2014 16:21:56
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef IMAGE_HPP_
#define IMAGE_HPP_

#include "Color.hpp"
#include "Rect.hpp"
#include "Texture.hpp"

class Image {
	public:
		Image() = default;
		Image(const std::string &textureName);
		
		void load(const std::string &textureName);
		
		void setClipRect(FloatRect rect);
		void setPosRect(FloatRect rect);
		
		void draw(Vector2f position, s16 width = -1, s16 height = -1);
		void draw(FloatRect rect);
		void draw();
		
		u16 width() const { return m_width; }
		u16 height() const { return m_height; }
		
		void setPaletteID(u8 id) { m_paletteID = id; }
		
		void setColorMod(Color colorMod) { m_colorMod = colorMod; }
		
	private:
		Texture *m_texture = nullptr;
		
		u16 m_width = 0;
		u16 m_height = 0;
		
		FloatRect m_clipRect;
		FloatRect m_posRect;
		
		Color m_colorMod;
		
		u8 m_paletteID = 0;
};

#endif // IMAGE_HPP_
