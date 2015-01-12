/*
 * =====================================================================================
 *
 *       Filename:  Texture.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  19/09/2014 21:16:31
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef TEXTURE_HPP_
#define TEXTURE_HPP_

#include <string>

#include "OpenGL.hpp"
#include "SDLHeaders.hpp"
#include "Types.hpp"

class Texture {
	public:
		Texture();
		Texture(const std::string &filename);
		
		void load(const std::string &filename);
		
		static void bind(const Texture *texture);
		
		void setPaletteID(u8 id) { m_paletteID = id; }
		
		u16 width() const { return m_width; }
		u16 height() const { return m_height; }
		
	protected:
		std::string m_filename;
		
		u16 m_width;
		u16 m_height;
		
		GLuint m_texture;
		
		u8 m_paletteID;
};

#endif // TEXTURE_HPP_
