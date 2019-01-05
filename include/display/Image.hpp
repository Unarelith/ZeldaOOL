/*
 * =====================================================================================
 *
 *       Filename:  Image.hpp
 *
 *    Description:
 *
 *        Created:  20/09/2014 16:21:56
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef IMAGE_HPP_
#define IMAGE_HPP_

#include <gk/graphics/Image.hpp>

class Image : public gk::Image {
	public:
		Image() = default;
		Image(const std::string &textureName) : gk::Image(textureName) {}
		Image(const gk::Texture &texture) : gk::Image(texture) {}

		void setPaletteID(u8 paletteID) { m_paletteID = paletteID; }

	private:
		void draw(gk::RenderTarget &target, gk::RenderStates states) const override;

		u8 m_paletteID = 0;
};

#endif // IMAGE_HPP_
