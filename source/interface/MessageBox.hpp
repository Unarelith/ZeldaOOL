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
#ifndef MESSAGEBOX_HPP_
#define MESSAGEBOX_HPP_

#include <algorithm>
#include <functional>
#include <string>

#include <gk/graphics/RectangleShape.hpp>

#include "Image.hpp"
#include "TextBox.hpp"

class MessageBox : public gk::Drawable, public gk::Transformable {
	public:
		enum Position : u8 {
			Top    = 24,
			Bottom = 96
		};

		MessageBox(const std::string &text = "", Position position = Position::Top);

		void update();

		bool finished() const { return m_finished; }

	private:
		void draw(gk::RenderTarget &target, gk::RenderStates states) const override;

		Image m_dialogArrow{"interface-dialogArrow"};

		gk::RectangleShape m_rectangle{144, 40, gk::Color::Black};

		TextBox m_textBox;

		bool m_finished = false;
};

#endif // MESSAGEBOX_HPP_
