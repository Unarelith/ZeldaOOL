/*
 * =====================================================================================
 *
 *       Filename:  Vector2.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  15/09/2014 21:09:01
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef VECTOR_HPP_
#define VECTOR_HPP_

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

#endif // VECTOR_HPP_
