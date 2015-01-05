/*
 * =====================================================================================
 *
 *       Filename:  View.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/10/2014 14:17:17
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef VIEW_HPP_
#define VIEW_HPP_

#include "Types.hpp"

class View {
	public:
		View();
		View(float x, float y, u16 width, u16 height);
		~View();
		
		void load(float x, float y, u16 width, u16 height);
		
		void reset(float x, float y, u16 width, u16 height);
		
		void move(float offsetX, float offsetY);
		void setPosition(float x, float y);
		
		static void bind(const View *view);
		
	private:
		float m_x;
		float m_y;
		
		u16 m_width;
		u16 m_height;
};

#endif // VIEW_HPP_
