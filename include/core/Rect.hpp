/*
 * =====================================================================================
 *
 *       Filename:  Rect.hpp
 *
 *    Description:  
 *
 *        Created:  15/09/2014 22:13:37
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef RECT_HPP_
#define RECT_HPP_

#include <algorithm>

#include "Vector2.hpp"

template<typename T>
class Rect {
	public:
		Rect() = default;
		
		Rect(T _x, T _y, T _width, T _height) {
			reset(_x, _y, _width, _height);
		}
		Rect(Vector2<T> _position, T _width, T _height) {
			reset(_position.x, _position.y, _width, _height);
		}
		
		void reset(T _x, T _y, T _width, T _height) {
			x = _x;
			y = _y;
			width = _width;
			height = _height;
		}
		
		void reset(Rect<T> rect) {
			x = rect.x;
			y = rect.y;
			width = rect.width;
			height = rect.height;
		}
		
		void move(Vector2<T> d) { x += d.x; y += d.y; }
		
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
		
		Vector2<T> position() { return {x, y}; }
		
		void setPosition(Vector2<T> vector2) { x = vector2.x; y = vector2.y; }
		
		Rect operator+(const Vector2<T> &vector2) const { return Rect{x + vector2.x, y + vector2.y, width, height}; }
		Rect operator-(const Vector2<T> &vector2) const { return Rect{x - vector2.x, y - vector2.y, width, height}; }
		
		Rect &operator+=(const Vector2<T> &vector2) { *this = operator+(vector2); return *this; }
		Rect &operator-=(const Vector2<T> &vector2) { *this = operator-(vector2); return *this; }
		
		T x = 0;
		T y = 0;
		T width = 0;
		T height = 0;
};

using IntRect = Rect<int>;
//using Rects8 = Rect<s8>;
//using Rects16 = Rect<s16>;
//using Rects32 = Rect<s32>;
//using Rects64 = Rect<s64>;
//
//using Rectu = Rect<unsigned int>;
//using Rectu8 = Rect<u8>;
//using Rectu16 = Rect<u16>;
//using Rectu32 = Rect<u32>;
//using Rectu64 = Rect<u64>;

using FloatRect = Rect<float>;
using DoubleRect = Rect<double>;

#endif // RECT_HPP_
