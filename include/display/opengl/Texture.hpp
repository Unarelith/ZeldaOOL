/*
 * =====================================================================================
 *
 *       Filename:  Texture.hpp
 *
 *    Description:
 *
 *        Created:  19/09/2014 21:16:31
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef TEXTURE_HPP_
#define TEXTURE_HPP_

#include <string>

#include "IntTypes.hpp"
#include "OpenGL.hpp"
#include "SDLHeaders.hpp"

class Texture {
	public:
		Texture() = default;
		Texture(const Texture &texture) = default;
		Texture(Texture &&texture);
		Texture(const std::string &filename);
		~Texture();

		Texture &operator=(const Texture &) = default;
		Texture &operator=(Texture &&) = default;

		void load(const std::string &filename);

		static void bind(const Texture *texture);

		u16 width() const { return m_width; }
		u16 height() const { return m_height; }

	protected:
		GLuint m_texture = 0;

		u16 m_width = 0;
		u16 m_height = 0;
};

#endif // TEXTURE_HPP_
