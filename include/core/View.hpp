/*
 * =====================================================================================
 *
 *       Filename:  View.hpp
 *
 *    Description:  
 *
 *        Created:  12/02/2015 23:34:41
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef VIEW_HPP_
#define VIEW_HPP_

#include "Types.hpp"

class View {
	public:
		View() = default;
		View(float x, float y, u16 width, u16 height);
		
		void load(float x, float y, u16 width, u16 height);
		
		void reset(float x, float y, u16 width, u16 height);
		
		void move(float offsetX, float offsetY);
		void setPosition(float x, float y);
		
		static void bind(const View *view);
		
	private:
		float m_x = 0;
		float m_y = 0;
		
		u16 m_width = 0;
		u16 m_height = 0;
};

#endif // VIEW_HPP_
