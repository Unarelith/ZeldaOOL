/*
 * =====================================================================================
 *
 *       Filename:  View.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  16/09/2014 21:44:28
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef VIEW_HPP_
#define VIEW_HPP_

#include "Rect.hpp"

class View {
	public:
		View();
		~View();
		
		void reset(const FloatRect &rect);
		
		void move(float offsetX, float offsetY);
		
		float x() const { return m_rect.x; }
		float y() const { return m_rect.y; }
		
		float width() const { return m_rect.width; }
		float height() const { return m_rect.height; }
		
	private:
		FloatRect m_rect;
};

#endif // VIEW_HPP_
