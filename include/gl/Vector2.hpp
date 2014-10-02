/*
 * =====================================================================================
 *
 *       Filename:  Vector2.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/10/2014 18:38:52
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef VECTOR2_HPP_
#define VECTOR2_HPP_

template<typename T>
class Vector2 {
	public:
		Vector2() {}
		Vector2(T _x, T _y) { x = _x; y = _y; }
		~Vector2() {}
		
		T x;
		T y;
};

typedef Vector2<int> Vector2i;
typedef Vector2<unsigned int> Vector2u;
typedef Vector2<float> Vector2f;

#endif // VECTOR2_HPP_
