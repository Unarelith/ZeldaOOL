/*
 * =====================================================================================
 *
 *       Filename:  Image.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/12/2014 20:52:37
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

#include <string>

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "Types.hpp"

class Image : public sf::Sprite {
	public:
		Image();
		Image(std::string filename);
		~Image();
		
		void load(std::string filename);
		
		void setClipRect(s16 x, s16 y, u16 width, u16 height);
		
		void draw();
		void draw(float x, float y, s16 width = -1, s16 height = -1);
		
		u16 width() const { return m_texture.getSize().x; }
		u16 height() const { return m_texture.getSize().y; }
		
	private:
		sf::Texture m_texture;
};

#endif // IMAGE_HPP_
