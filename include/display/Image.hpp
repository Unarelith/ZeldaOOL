/*
 * =====================================================================================
 *
 *       Filename:  Image.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  22/07/2014 14:42:03
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

#include <SFML/Graphics.hpp>

#include "Types.hpp"

class Image {
	public:
		Image();
		Image(const Image &image);
		Image(std::string filename);
		~Image();
		
		void load(std::string filename);
		
		void setClipRect(u16 clipX, u16 clipY, u16 width, u16 height);
		void draw(s16 x, s16 y, s16 width = -1, s16 height = -1);
		
		u16 width() { return m_texture.getSize().x; }
		u16 height() { return m_texture.getSize().y; }
		
		sf::Texture getTexture() const { return m_texture; }
		
	protected:
		std::string m_filename;
		
		sf::Sprite m_image;
		
	private:
		sf::Texture m_texture;
};

#endif // IMAGE_HPP_
