/*
 * =====================================================================================
 *
 *       Filename:  Text.hpp
 *
 *    Description:
 *
 *        Created:  24/06/2018 01:48:24
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef TEXT_HPP_
#define TEXT_HPP_

#include <string>

#include "Sprite.hpp"

class Text : public gk::Drawable, public gk::Transformable {
	public:
		Text(const std::string &textureName, u8 charWidth, u8 charHeight);

		const std::string &text() const { return m_text; }
		void setText(const std::string &text) { m_text = text; updateTextSprites(); }

		void setColor(const gk::Color &color) { m_color = color; }

		void setCharSpacing(s8 charSpacingX, s8 charSpacingY) { m_charSpacingX = charSpacingX; m_charSpacingY = charSpacingY; }

		const gk::Vector2i &getSize() const { return m_size; }

	private:
		void draw(gk::RenderTarget &target, gk::RenderStates states) const override;

		void updateTextSprites();

		std::string m_text;
		std::vector<Sprite> m_textSprites;

		std::string m_textureName;
		u8 m_charWidth;
		u8 m_charHeight;
		s8 m_charSpacingX = 1;
		s8 m_charSpacingY = 1;

		gk::Vector2i m_size;

		gk::Color m_color = gk::Color::White;
};

#endif // TEXT_HPP_
