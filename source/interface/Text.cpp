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
#include <gk/resource/ResourceHandler.hpp>

#include "Text.hpp"

Text::Text(const std::string &textureName, u8 charWidth, u8 charHeight) {
	m_textureName = textureName;
	m_charWidth = charWidth;
	m_charHeight = charHeight;
}

void Text::draw(gk::RenderTarget &target, gk::RenderStates states) const {
	states.transform *= getTransform();

	for(const Sprite &sprite : m_textSprites) {
		target.draw(sprite, states);
	}
}

// FIXME: USE A VBO INSTEAD
void Text::updateTextSprites() {
	m_textSprites.clear();

	int x = 0;
	int maxX = 0;
	int y = 0;
	for(char c : m_text) {
		if (c == '\n') {
			y += m_charHeight + m_charSpacingY;
			maxX = std::max(x, maxX);
			x = 0;
			continue;
		}

		Sprite sprite{m_textureName, m_charWidth, m_charHeight};
		sprite.setCurrentFrame(c);
		sprite.setPosition(x, y, 0);
		sprite.setColor(m_color);
		m_textSprites.emplace_back(std::move(sprite));
		x += m_charWidth + m_charSpacingX;
	}

	m_size.x = std::max(x, maxX);
	m_size.y = y + m_charHeight;
}

