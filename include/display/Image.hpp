/*
 * =====================================================================================
 *
 *       Filename:  Image.hpp
 *
 *    Description:  
 *
 *        Created:  09/02/2015 02:24:34
 *       Compiler:  gcc
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef IMAGE_HPP_
#define IMAGE_HPP_

#include "Color.hpp"
#include "Rect.hpp"
#include "Texture.hpp"
#include "Types.hpp"

class Image {
	public:
		Image() = default;
		Image(const std::string &resourceName);
		
		void load(const std::string &resourceName);
		
		void setTexture(const std::string &resourceName);
		
		void setClipRect(float x, float y, u16 width, u16 height);
		void setPosRect(float x, float y, u16 width, u16 height);
		
		void draw(float x, float y, s16 width = -1, s16 height = -1);
		void draw();
		
		u16 width() const { return m_width; }
		u16 height() const { return m_height; }
		
		void setColor(Color color) { m_color = color; }
		
	private:
		Texture *m_texture = nullptr;
		
		u16 m_width = 0;
		u16 m_height = 0;
		
		FloatRect m_clipRect;
		FloatRect m_posRect;
		
		Color m_color = Color::white;
};

#endif // IMAGE_HPP_
