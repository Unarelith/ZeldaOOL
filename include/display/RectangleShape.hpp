/*
 * =====================================================================================
 *
 *       Filename:  RectangleShapeShape.hpp
 *
 *    Description:  
 *
 *        Created:  09/02/2015 02:52:12
 *       Compiler:  gcc
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef RECTANGLESHAPE_HPP_
#define RECTANGLESHAPE_HPP_

#include "Color.hpp"
#include "Types.hpp"

class RectangleShape {
	public:
		RectangleShape() = default;
		RectangleShape(float x, float y, u16 width, u16 height);
		
		void draw(Color color = Color::black);
		
		void setPosition(float x, float y) { m_x = x; m_y = y; }
		void move(float dx, float dy) { m_x += dx; m_y += dy; }
		
		void resize(u16 width, u16 height) { m_width = width; m_height = height; }
		
		float x() const { return m_x; }
		float y() const { return m_y; }
		
		u16 width() const { return m_width; }
		u16 height() const { return m_height; }
		
	private:
		float m_x = 0;
		float m_y = 0;
		
		u16 m_width = 0;
		u16 m_height = 0;
};

#endif // RECTANGLESHAPE_HPP_
