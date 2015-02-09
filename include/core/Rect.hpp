/*
 * =====================================================================================
 *
 *       Filename:  Rect.hpp
 *
 *    Description:  
 *
 *        Created:  09/02/2015 02:25:53
 *       Compiler:  gcc
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef RECT_HPP_
#define RECT_HPP_

#include <algorithm>

template<typename T>
class Rect {
	public:
		Rect() = default;
		Rect(T _x, T _y, T _width, T _height) {
			reset(_x, _y, _width, _height);
		}
		
		void reset(T _x, T _y, T _width, T _height) {
			x = _x;
			y = _y;
			width = _width;
			height = _height;
		}
		
		bool intersects(const Rect<T> &rect) const {
			T r1MinX = std::min(x, static_cast<T>(x + width));
			T r1MaxX = std::max(x, static_cast<T>(x + width));
			T r1MinY = std::min(y, static_cast<T>(y + height));
			T r1MaxY = std::max(y, static_cast<T>(y + height));
			
			T r2MinX = std::min(rect.x, static_cast<T>(rect.x + rect.width));
			T r2MaxX = std::max(rect.x, static_cast<T>(rect.x + rect.width));
			T r2MinY = std::min(rect.y, static_cast<T>(rect.y + rect.height));
			T r2MaxY = std::max(rect.y, static_cast<T>(rect.y + rect.height));
			
			T interLeft   = std::max(r1MinX, r2MinX);
			T interTop    = std::max(r1MinY, r2MinY);
			T interRight  = std::min(r1MaxX, r2MaxX);
			T interBottom = std::min(r1MaxY, r2MaxY);
			
			return interLeft < interRight && interTop < interBottom;
		}
		
		T x = 0;
		T y = 0;
		T width = 0;
		T height = 0;
};

typedef Rect<int> IntRect;
typedef Rect<float> FloatRect;

#endif // RECT_HPP_
