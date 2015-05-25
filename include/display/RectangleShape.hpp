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

class RectangleShape {
	public:
		RectangleShape() = default;
		RectangleShape(float x, float y, u16 width, u16 height);
		
		void draw(Color color = Color::black, bool wireframe = false);
		
		void setPosition(float x, float y) { m_x = x; m_y = y; }
		void move(float dx, float dy) { m_x += dx; m_y += dy; }
		
		void resize(u16 width, u16 height) { m_width = width; m_height = height; }
		
		float x() const { return m_x; }
		float y() const { return m_y; }
		
		u16 width() const { return m_width; }
		u16 height() const { return m_height; }
		
	private:
		float m_x;
		float m_y;
		
		u16 m_width;
		u16 m_height;
};

#endif // RECTANGLESHAPE_HPP_
