/*
 * =====================================================================================
 *
 *       Filename:  MessageBox.hpp
 *
 *    Description:
 *
 *        Created:  22/02/2015 17:49:25
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef MESSAGEBOX_HPP_
#define MESSAGEBOX_HPP_

#include <algorithm>
#include <functional>
#include <string>

#include <SFML/Graphics/RectangleShape.hpp>

#include "Image.hpp"
#include "TextBox.hpp"

class MessageBox : public sf::Drawable, public sf::Transformable {
	public:
		enum Position : u8 {
			Top    = 24,
			Bottom = 96
		};

		MessageBox(const std::string &text = "", Position position = Position::Top);

		void update();

		bool finished() const { return m_finished; }

	private:
		void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

		Image m_dialogArrow{"interface-dialogArrow"};

		sf::RectangleShape m_rectangle;

		TextBox m_textBox;

		bool m_finished = false;
};

#endif // MESSAGEBOX_HPP_
