/*
 * =====================================================================================
 *
 *       Filename:  Rectangle.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  27/09/2014 17:06:48
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef RECTANGLE_HPP_
#define RECTANGLE_HPP_

#include "Color.hpp"
#include "Types.hpp"

class Rectangle {
	public:
		Rectangle() = default;
		Rectangle(Rectangle &&) = default;
		Rectangle(const Rectangle &) = default;
		Rectangle(float x, float y, u16 width, u16 height);
		
		void draw(Color color = Color::black);
		
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

#endif // RECTANGLE_HPP_
