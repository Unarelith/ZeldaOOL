/*
 * =====================================================================================
 *
 *       Filename:  RectangleShape.hpp
 *
 *    Description:  
 *
 *        Created:  27/09/2014 17:06:48
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef RECTANGLESHAPE_HPP_
#define RECTANGLESHAPE_HPP_

#include "Color.hpp"
#include "Rect.hpp"
#include "Vector2.hpp"

class RectangleShape {
	public:
		RectangleShape() = default;
		RectangleShape(Vector2f position, u16 width, u16 height);
		
		void draw(Color color = Color::black, bool wireframe = false);
		
		void setPosition(Vector2f position) { m_position = position; }
		void move(Vector2f d) { m_position += d; }
		
		void resize(u16 width, u16 height) { m_width = width; m_height = height; }
		
		Vector2f position() const { return m_position; }
		
		u16 width() const { return m_width; }
		u16 height() const { return m_height; }
		
	private:
		Vector2f m_position;
		
		u16 m_width;
		u16 m_height;
};

#endif // RECTANGLESHAPE_HPP_
