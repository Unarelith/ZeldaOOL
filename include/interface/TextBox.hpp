/*
 * =====================================================================================
 *
 *       Filename:  TextBox.hpp
 *
 *    Description:
 *
 *        Created:  23/02/2015 17:14:50
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef TEXTBOX_HPP_
#define TEXTBOX_HPP_

#include <map>
#include <vector>

#include "Sprite.hpp"

class TextBox : public IDrawable, public Transformable {
	public:
		TextBox(const std::string &text);

		void setText(const std::string &text);
		void setSize(u16 width, u16 height);

		void updateTextSprites();

		bool scrollDown();
		void stopTextAnimation();

		bool isAtLastPage() const;
		bool textDisplayFinished() const;

		size_t textLength() const { return m_string.length(); }

		u32 charTimerTime() const { return m_charTimer.time(); }

		u8 charPerLine() const { return m_charPerLine; }

		u8 page() const { return m_page; }

	private:
		void draw(RenderTarget &target, RenderStates states) const override;

		bool isTimeToDisplayLetter(u16 letterIndex) const;

		const u8 m_delay = 50;

		std::string m_string;

		std::vector<Sprite> m_textSprites;

		Timer m_charTimer;

		u8 m_charPerLine = 16;

		u16 m_charsToDisplay = m_charPerLine * 2;

		u8 m_page = 0;

		Color m_currentColor = Color::text;
		std::map<u16, Color> m_colorChanges;

		u16 m_width;
		u16 m_height;
};

#endif // TEXTBOX_HPP_
