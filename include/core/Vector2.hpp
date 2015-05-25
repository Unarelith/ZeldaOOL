/*
 * =====================================================================================
 *
 *       Filename:  Vector2.hpp
 *
 *    Description:  
 *
 *        Created:  12/05/2015 18:45:17
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef VECTOR2_HPP_
#define VECTOR2_HPP_

#include <utility>

#include "IntTypes.hpp"

template<typename T>
class Vector2 {
	public:
		Vector2() = default;
		
		Vector2(T _x, T _y) : x(_x), y(_y) {}
		
		template<typename U>
		Vector2(const Vector2<U> &vector2) : x(vector2.x), y(vector2.y) {}
		
		Vector2 operator+(const Vector2<T> &vector2) const { return Vector2{x + vector2.x, y + vector2.y}; }
		Vector2 operator-(const Vector2<T> &vector2) const { return Vector2{x - vector2.x, y - vector2.y}; }
		Vector2 operator*(T n)                       const { return Vector2{x * n, y * n}; }
		Vector2 operator/(T n)                       const { return Vector2{x / n, y / n}; }
		
		Vector2& operator=(T n)                     { x = n; y = n; return *this; }
		Vector2 &operator+=(const Vector2 &vector2) { *this = operator+(vector2); return *this; }
		Vector2 &operator-=(const Vector2 &vector2) { *this = operator-(vector2); return *this; }
		Vector2 &operator*=(T n)                    { *this = operator*(n); return *this; }
		Vector2 &operator/=(T n)                    { *this = operator/(n); return *this; }
		
		bool operator==(const Vector2<T> &vector2) const { return x == vector2.x && y == vector2.y; }
		bool operator!=(const Vector2<T> &vector2) const { return !operator==(vector2); }
		
		// Needed if Vector2 is used as a key in a std::map
		bool operator<(const Vector2<T> &vector2) const { return x < vector2.x && y <= vector2.y; }
		bool operator>(const Vector2<T> &vector2) const { return x > vector2.x && y >= vector2.y; }
		
		T x;
		T y;
};

template<typename T>
Vector2<T> operator*(T n, Vector2<T> &vector2) { return vector2.operator*(n); }

using Vector2i = Vector2<int>;
using Vector2s8 = Vector2<s8>;
using Vector2s16 = Vector2<s16>;
using Vector2s32 = Vector2<s32>;
using Vector2s64 = Vector2<s64>;

using Vector2u = Vector2<unsigned int>;
using Vector2u8 = Vector2<u8>;
using Vector2u16 = Vector2<u16>;
using Vector2u32 = Vector2<u32>;
using Vector2u64 = Vector2<u64>;

using Vector2f = Vector2<float>;
using Vector2d = Vector2<double>;

#endif // VECTOR2_HPP_

