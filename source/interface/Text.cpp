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
#include "ResourceHandler.hpp"
#include "Text.hpp"
#include "Texture.hpp"

Text::Text() : m_texture(ResourceHandler::getInstance().get<Texture>("interface-font")) {
	m_charWidth = 8;
	m_charHeight = 16;
}

void Text::draw(RenderTarget &target, RenderStates states) const {
	applyTransform(states);

	for(const Sprite &sprite : m_textSprites) {
		target.draw(sprite, states);
	}
}

// FIXME: USE A VBO INSTEAD
void Text::updateTextSprites() {
	m_textSprites.clear();

	int x = 0;
	Color color = Color{70, 70, 70, 255};
	for(unsigned char c : m_text) {
		Sprite sprite{"interface-font", 8, 8};
		if(c > 128 && c < 195) sprite.setCurrentFrame(c + 35);
		else if(c >= 32)       sprite.setCurrentFrame(c - 29);
		sprite.setPosition(x + 1, 1, 0);
		sprite.setColor(color);
		m_textSprites.emplace_back(std::move(sprite));
		x += m_charWidth;
	}
	x = 0;
	color = m_color;
	for(unsigned char c : m_text) {
		Sprite sprite{"interface-font", 8, 8};
		if(c > 128 && c < 195) sprite.setCurrentFrame(c + 35);
		else if(c >= 32)       sprite.setCurrentFrame(c - 29);
		sprite.setPosition(x, 0, 0);
		if (c == '[')
			color = Color::blue;
		sprite.setColor(color);
		m_textSprites.emplace_back(std::move(sprite));
		x += m_charWidth;
	}

	m_size.x = x;
	m_size.y = 8;
}

