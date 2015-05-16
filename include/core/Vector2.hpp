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

template<typename T>
class Vector2 {
	public:
		Vector2 operator+(const Vector2 &vector2) const { return Vector2{x + vector2.x, y + vector2.y}; }
		Vector2 operator-(const Vector2 &vector2) const { return Vector2{x - vector2.x, y - vector2.y}; }
		Vector2 operator*(T n)                    const { return Vector2{x * n, y * n}; }
		
		Vector2 operator+=(const Vector2 &vector2) { return operator+(*this, vector2); }
		Vector2 operator-=(const Vector2 &vector2) { return operator-(*this, vector2); }
		Vector2 operator*=(T n)                    { return operator*(n); }
		
		bool operator==(const Vector2 &vector2) const { return x == vector2.x && y == vector2.y; }
		bool operator!=(const Vector2 &vector2) const { return !operator==(vector2); }
		
		// Needed if Vector2 is used as a key in a std::map
		bool operator<(const Vector2 &vector2) const { return x < vector2.x && y <= vector2.y; }
		bool operator>(const Vector2 &vector2) const { return x > vector2.x && y >= vector2.y; }
		
		T x;
		T y;
};

template<typename T>
Vector2<T> operator*(T n, Vector2<T> &vector2) { return vector2.operator*(n); }

using Vector2i = Vector2<int>;
using Vector2u = Vector2<unsigned int>;
using Vector2f = Vector2<float>;
using Vector2d = Vector2<double>;

#endif // VECTOR2_HPP_

