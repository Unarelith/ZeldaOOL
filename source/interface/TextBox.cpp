/*
 * =====================================================================================
 *
 *       Filename:  TextBox.cpp
 *
 *    Description:
 *
 *        Created:  23/02/2015 17:15:03
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <functional>

#include <gk/audio/AudioPlayer.hpp>
#include <gk/system/Exception.hpp>

#include "TextBox.hpp"

TextBox::TextBox(const std::string &text, u16 width, u16 height) {
	m_charTimer.start();

	m_width = width;
	m_height = height;

	setText(text);
}

void TextBox::updateTextSprites() {
	u16 charX = 8;
	u16 charY = 0;

	const u16 charWidth = 8;
	const u16 charHeight = 16;

	m_charPerLine = (m_width - 16) / charWidth;

	m_charsToDisplay = m_charPerLine * 2;

	m_currentColor = getTextColor();

	m_textSprites.clear();

	for(u16 i = 0 ; i < m_string.length() ; i++) {
		// Change color if a color tag is found
		if(m_colorChanges.find(i) != m_colorChanges.end()) {
			m_currentColor = m_colorChanges[i];
		}

		// If the text is out of the box, don't display it
		if(i < m_page * m_charPerLine) continue;

		// If the text is out of the box, don't display it
		if(charY + charHeight > m_height) {
			break;
		}

		// Letter by letter text display
		if(isTimeToDisplayLetter(i)) {
			gk::AudioPlayer::repeatEffect("textLetter", m_delay);
			break;
		}

		// Jump to next line if a newline character is encountered
		if(m_string[i] == '\n') {
			m_charsToDisplay -= m_charPerLine - (charX - 8) / charWidth;

			charX = 8;
			charY += charHeight;

			continue;
		}

		if(m_string[i] == ' ') {
			// If a space is the first character of a line, don't display it
			if(charX == 8) continue;

			size_t nextSpace = m_string.find_first_of(' ', i + 1);

			u8 wordLength = ((nextSpace != std::string::npos) ? nextSpace : m_string.length()) - i - 1;

			// Check if the word is out of the box, if it is, jump to next line
			if(charX + wordLength * charWidth > m_width - 16) {
				m_charsToDisplay -= m_charPerLine - (charX - 8) / charWidth;

				charX = 8;
				charY += charHeight;

				continue;
			}
		}

		Sprite sprite{"interface-font", 8, 16};
		if((u8)m_string[i] > 128 && (u8)m_string[i] < 195)
			sprite.setCurrentFrame((u8)m_string[i] + 35);
		else if((u8)m_string[i] >= 32)
			sprite.setCurrentFrame((u8)m_string[i] - 29);
		sprite.setPosition(charX, charY);
		sprite.setColor(m_currentColor);
		m_textSprites.emplace_back(std::move(sprite));

		charX += charWidth;
	}
}

void TextBox::setText(const std::string &text) {
	m_string = text;

	// Fix problems with accents
	m_string.erase(std::remove_if(m_string.begin(), m_string.end(), std::bind(std::equal_to<u8>(), 195, std::placeholders::_1)), m_string.end());

	// Search for color tags in the form '[0..9]', for example: '[2]'
	// and add their informations to m_colorChanges
	size_t nextColorTag = m_string.find_first_of('[');
	while(nextColorTag != std::string::npos) {
		gk::Color color;

		// Find the color
		switch(m_string[nextColorTag + 1]) {
			case '0': color = getTextColor(); break;
			case '1': color = gk::Color::blue; break;
			case '2': color = gk::Color::red;  break;
			default: throw EXCEPTION("MessageBox parsing error at string index", std::to_string(nextColorTag + 1) + ":", "Unrecognized color tag");
		}

		// Make sure that the tag is complete
		if(m_string[nextColorTag + 2] != ']') {
			throw EXCEPTION("MessageBox parsing error at string index", std::to_string(nextColorTag + 2) + ":", "Missing ']'");
		}

		m_colorChanges[nextColorTag] = color;

		// Delete the tag from the string
		m_string.erase(nextColorTag, 3);

		nextColorTag = m_string.find_first_of('[', nextColorTag);
	}

	updateTextSprites();
}

void TextBox::draw(gk::RenderTarget &target, gk::RenderStates states) const {
	states.transform *= getTransform();

	for(const Sprite &sprite : m_textSprites) {
		target.draw(sprite, states);
	}
}

bool TextBox::scrollDown() {
	// Don't animate again the first line's drawing
	m_charTimer.setTime(m_charsToDisplay * m_delay);

	if(!isAtLastPage()) {
		m_page++;
		return false;
	} else {
		return true;
	}
}

void TextBox::stopTextAnimation() {
	m_charTimer.setTime((m_charsToDisplay + m_page * m_charPerLine) * m_delay);
}

bool TextBox::isAtLastPage() const {
	return m_string.length() / m_charPerLine <= m_page + 1u;
}

bool TextBox::textDisplayFinished() const {
	return m_charTimer.time() / m_delay > u16(m_charsToDisplay + m_page * m_charPerLine);
}

bool TextBox::isTimeToDisplayLetter(u16 letterIndex) const {
	return m_charTimer.time() / m_delay < letterIndex;
}

