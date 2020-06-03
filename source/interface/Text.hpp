/*
 * =====================================================================================
 *
 *  ZeldaOOL
 *
 *  Copyright (C) 2014-2020 Unarelith, Quentin Bazin <zelda.ool@unarelith.net>
 *
 *  This file is part of ZeldaOOL.
 *
 *  ZeldaOOL is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  ZeldaOOL is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with ZeldaOOL; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA  02110-1301 USA
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
