/*
 * =====================================================================================
 *
 *       Filename:  Image.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  15/09/2014 19:47:53
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef IMAGE_HPP_
#define IMAGE_HPP_

#include <string>

#include "SDLHeaders.hpp"
#include "Types.hpp"

class Image {
	public:
		Image();
		Image(const Image &image);
		Image(std::string filename);
		~Image();
		
		void load(std::string filename);
		
		void setClipRect(s16 x, s16 y, u16 width, u16 height);
		void setPosRect(s16 x, s16 y, u16 width, u16 height);
		
		void draw(s16 x, s16 y, s16 width = -1, s16 height = -1);
		
		u16 width() const { return m_width; }
		u16 height() const { return m_height; }
		
		SDL_Texture *texture() const { return m_texture; }
		
	protected:
		std::string m_filename;
		
	private:
		u16 m_width;
		u16 m_height;
		
		SDL_Texture *m_texture;
		
		SDL_Rect m_clipRect;
		SDL_Rect m_posRect;
};

#endif // IMAGE_HPP_
