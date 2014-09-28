/*
 * =====================================================================================
 *
 *       Filename:  Color.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  27/09/2014 22:35:45
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "Color.hpp"

Color Color::black(0, 0, 0);
Color Color::white(255, 255, 255);
Color Color::text(248, 208, 136);
Color Color::blue(32, 168, 248);

Color::Color(u8 _r, u8 _g, u8 _b) {
	r = 255.0f / _r;
	g = 255.0f / _g;
	b = 255.0f / _b;
	a = 1.0f;
}

Color::~Color() {
}

