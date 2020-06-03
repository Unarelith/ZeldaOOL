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
#ifndef TEXTBOX_HPP_
#define TEXTBOX_HPP_

#include <map>
#include <vector>

#include "Color.hpp"
#include "Sprite.hpp"

class TextBox : public gk::Drawable, public gk::Transformable {
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
		void draw(gk::RenderTarget &target, gk::RenderStates states) const override;

		bool isTimeToDisplayLetter(u16 letterIndex) const;

		const u8 m_delay = 50;

		std::string m_string;

		std::vector<Sprite> m_textSprites;

		gk::Timer m_charTimer;

		u8 m_charPerLine = 16;

		u16 m_charsToDisplay = m_charPerLine * 2;

		u8 m_page = 0;

		gk::Color m_currentColor = Color::Text;
		std::map<u16, gk::Color> m_colorChanges;

		u16 m_width = 0;
		u16 m_height = 0;
};

#endif // TEXTBOX_HPP_
