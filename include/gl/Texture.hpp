/*
 * =====================================================================================
 *
 *       Filename:  Texture.hpp
 *
 *    Description:  
 *
 *        Created:  08/02/2015 22:57:51
 *       Compiler:  gcc
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
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
		Texture(const std::string &filename);
		Texture(const Texture &texture) = delete;
		Texture(Texture &&texture);
		~Texture();
		
		Texture &operator=(const Texture &) = delete;
		Texture &operator=(Texture &&) = default;
		
		static void bind(const Texture *texture);
		
		u16 width() const { return m_width; }
		u16 height() const { return m_height; }
		
	protected:
		GLuint m_texture = 0;
		
		u16 m_width = 0;
		u16 m_height = 0;
};

#endif // TEXTURE_HPP_
