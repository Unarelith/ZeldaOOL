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
#include "Types.hpp"

class Texture {
	public:
		Texture();
		Texture(std::string filename);
		~Texture();
		
		void load(std::string filename);
		
		void bind();
		void unbind() { glBindTexture(GL_TEXTURE_2D, 0); }
		
		int width() const { return m_width; }
		int height() const { return m_height; }
		
	protected:
		std::string m_filename;
		
		int m_width;
		int m_height;
		
		GLuint m_texture;
		
		GLint m_uniform;
		
	private:
		int m_comp;
		
		u8 *m_data;
};

#endif // TEXTURE_HPP_
