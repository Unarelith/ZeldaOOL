/*
 * =====================================================================================
 *
 *       Filename:  Color.cpp
 *
 *    Description:  
 *
 *        Created:  09/02/2015 03:02:13
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "Color.hpp"

Color Color::black(0, 0, 0);
Color Color::white(255, 255, 255);
Color Color::text(248, 208, 136);
Color Color::blue(32, 168, 248);
Color Color::red(232, 8, 24);

Color::Color(u8 _r, u8 _g, u8 _b, u8 _a) {
	r = _r;
	g = _g;
	b = _b;
	a = _a;
}

std::vector<float> Color::makeArray(u8 vertices) {
	std::vector<float> colors = {r / 255.0f, g / 255.0f, b / 255.0f, a / 255.0f};
	std::vector<float> array(4 * vertices);
	
	for(u8 i = 0 ; i < vertices ; i++) {
		std::copy(colors.begin(), colors.end(), array.begin() + i * 4); 
	}
	
	return array;
}

Color Color::operator-(const Color &color) {
	return Color(r - color.r, g - color.g, b - color.b, a - color.a);
}

