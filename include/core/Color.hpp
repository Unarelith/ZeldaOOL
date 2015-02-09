/*
 * =====================================================================================
 *
 *       Filename:  Color.hpp
 *
 *    Description:  
 *
 *        Created:  09/02/2015 02:53:04
 *       Compiler:  gcc
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef COLOR_HPP_
#define COLOR_HPP_

#include "Types.hpp"

class Color {
	public:
		Color() = default;
		Color(u8 _r, u8 _g, u8 _b, u8 _a = 255);
		
		Color operator-(const Color &color);
		
		u8 r = 255;
		u8 g = 255;
		u8 b = 255;
		u8 a = 255;
		
		static const Color black;
		static const Color white;
		static const Color text;
		static const Color blue;
		static const Color red;
};

#endif // COLOR_HPP_
