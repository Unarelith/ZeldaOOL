/*
 * =====================================================================================
 *
 *       Filename:  TextBox.hpp
 *
 *    Description:
 *
 *        Created:  23/02/2015 17:14:50
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef TEXTBOX_HPP_
#define TEXTBOX_HPP_

#include <map>
#include <vector>

#include "Color.hpp"
#include "Sprite.hpp"

class TextBox : public sf::Drawable, public sf::Transformable {
	public:
		TextBox(const std::string &text, u16 width, u16 height);

		void updateTextSprites();
		void setText(const std::string &text);

		bool scrollDown();
		void stopTextAnimation();

		bool isAtLastPage() const;
		bool textDisplayFinished() const;

		size_t textLength() const { return m_string.length(); }

		u32 charTimerTime() const { return m_charTimer.time(); }

		u8 charPerLine() const { return m_charPerLine; }

		u8 page() const { return m_page; }

	private:
		void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

		bool isTimeToDisplayLetter(u16 letterIndex) const;

		const u8 m_delay = 50;

		std::string m_string;

		std::vector<Sprite> m_textSprites;

		gk::Timer m_charTimer;

		u8 m_charPerLine = 16;

		u16 m_charsToDisplay = m_charPerLine * 2;

		u8 m_page = 0;

		sf::Color m_currentColor = Color::Text;
		std::map<u16, sf::Color> m_colorChanges;

		u16 m_width = 0;
		u16 m_height = 0;
};

#endif // TEXTBOX_HPP_
