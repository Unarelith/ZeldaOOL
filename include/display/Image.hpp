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

#include <gk/core/Color.hpp>
#include <gk/core/Rect.hpp>
#include <gk/gl/IDrawable.hpp>
#include <gk/gl/Texture.hpp>
#include <gk/gl/Transformable.hpp>
#include <gk/gl/VertexBuffer.hpp>

class Image : public gk::IDrawable, public gk::Transformable {
	public:
		Image() = default;
		Image(const std::string &textureName);
		Image(const gk::Texture &texture);

		void load(const std::string &textureName);
		void load(const gk::Texture &texture);

		const gk::FloatRect &clipRect() const { return m_clipRect; }
		void setClipRect(float x, float y, u16 width, u16 height);

		u16 width() const { return m_width; }
		u16 height() const { return m_height; }

		void setColor(const gk::Color &color) { m_color = color; updateVertexBuffer(); }
		void setPaletteID(u8 paletteID) { m_paletteID = paletteID; }

	private:
		void updateVertexBuffer() const;

		void draw(gk::RenderTarget &target, gk::RenderStates states) const override;

		const gk::Texture *m_texture = nullptr;

		u16 m_width = 0;
		u16 m_height = 0;

		gk::FloatRect m_clipRect;

		gk::VertexBuffer m_vbo;

		gk::Color m_color = gk::Color::white;
		u8 m_paletteID = 0;
};

#endif // IMAGE_HPP_
