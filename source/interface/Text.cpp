/*
 * =====================================================================================
 *
 *       Filename:  Text.cpp
 *
 *    Description:
 *
 *        Created:  24/06/2018 01:50:39
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <SFML/Graphics/RenderTarget.hpp>

#include <gk/resource/ResourceHandler.hpp>

#include "Text.hpp"

Text::Text(const std::string &textureName, u8 charWidth, u8 charHeight) {
	m_textureName = textureName;
	m_charWidth = charWidth;
	m_charHeight = charHeight;
}

void Text::draw(sf::RenderTarget &target, sf::RenderStates states) const {
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
		sprite.setPosition(x, y);
		sprite.setColor(m_color);
		m_textSprites.emplace_back(std::move(sprite));
		x += m_charWidth + m_charSpacingX;
	}

	m_size.x = std::max(x, maxX);
	m_size.y = y + m_charHeight;
}

