/*
 * =====================================================================================
 *
 *       Filename:  Rect.inl
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  15/09/2014 22:13:42
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include <algorithm>

template<typename T>
Rect<T>::Rect() {
}

template<typename T>
Rect<T>::Rect(T _x, T _y, T _width, T _height) {
	reset(_x, _y, _width, _height);
}

template<typename T>
void Rect<T>::reset(T _x, T _y, T _width, T _height) {
	x = _x;
	y = _y;
	width = _width;
	height = _height;
}

template<typename T>
Rect<T>::~Rect() {
}

template<typename T>
bool Rect<T>::intersects(const Rect<T> &rectangle) const {
	T r1MinX = std::min(x, static_cast<T>(x + width));
	T r1MaxX = std::max(x, static_cast<T>(x + width));
	T r1MinY = std::min(y, static_cast<T>(y + height));
	T r1MaxY = std::max(y, static_cast<T>(y + height));
	
	T r2MinX = std::min(rectangle.x, static_cast<T>(rectangle.x + rectangle.width));
	T r2MaxX = std::max(rectangle.x, static_cast<T>(rectangle.x + rectangle.width));
	T r2MinY = std::min(rectangle.y, static_cast<T>(rectangle.y + rectangle.height));
	T r2MaxY = std::max(rectangle.y, static_cast<T>(rectangle.y + rectangle.height));
	
	T interLeft   = std::max(r1MinX, r2MinX);
	T interTop    = std::max(r1MinY, r2MinY);
	T interRight  = std::min(r1MaxX, r2MaxX);
	T interBottom = std::min(r1MaxY, r2MaxY);
	
	if((interLeft < interRight) && (interTop < interBottom)) {
		return true;
	} else {
		return false;
	}
}

