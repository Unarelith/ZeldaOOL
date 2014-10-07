/*
 * =====================================================================================
 *
 *       Filename:  Image.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  20/09/2014 16:21:56
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
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

class Image : public Texture {
	public:
		Image();
		Image(std::string filename);
		~Image();
		
		void load(std::string filename);
		
		void setClipRect(float x, float y, u16 width, u16 height);
		void setPosRect(float x, float y, u16 width, u16 height);
		
		void draw(float x, float y, s16 width = -1, s16 height = -1);
		void draw();
		
		void setColorMod(Color colorMod) { m_colorMod = colorMod; }
		
	private:
		FloatRect m_clipRect;
		FloatRect m_posRect;
		
		Color m_colorMod;
};

#endif // IMAGE_HPP_
