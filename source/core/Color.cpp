/*
 * =====================================================================================
 *
 *       Filename:  Color.cpp
 *
 *    Description:  
 *
 *        Created:  09/02/2015 03:02:13
 *       Compiler:  gcc
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "Color.hpp"

const Color Color::black(0, 0, 0);
const Color Color::white(255, 255, 255);
const Color Color::text(248, 208, 136);
const Color Color::blue(32, 168, 248);
const Color Color::red(232, 8, 24);

Color::Color(u8 _r, u8 _g, u8 _b, u8 _a) {
	r = _r;
	g = _g;
	b = _b;
	a = _a;
}

Color Color::operator-(const Color &color) {
	return Color(r - color.r, g - color.g, b - color.b, a - color.a);
}

