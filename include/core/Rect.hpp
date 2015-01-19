/*
 * =====================================================================================
 *
 *       Filename:  Rect.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  15/09/2014 22:13:37
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef RECT_HPP_
#define RECT_HPP_

template<typename T>
class Rect {
	public:
		Rect() = default;
		Rect(T _x, T _y, T _width, T _height);
		
		void reset(T _x, T _y, T _width, T _height);
		
		bool intersects(const Rect<T> &rect) const;
		
		T x = 0;
		T y = 0;
		T width = 0;
		T height = 0;
};

#include "Rect.inl"

typedef Rect<int> IntRect;
typedef Rect<float> FloatRect;

#endif // RECT_HPP_
