/*
 * =====================================================================================
 *
 *       Filename:  Debug.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  14/09/2014 23:50:22
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef DEBUG_HPP_
#define DEBUG_HPP_

#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "Types.hpp"

#define DEBUG_ENABLED

#ifndef __ANDROID__
#	define DEBUG_COLOR
#endif

#define _FILE_ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)

#ifdef DEBUG_ENABLED
#	define DEBUG(args...) { std::cout << Debug::textColor(Debug::TextColor::Red, true) << _FILE_ << ":" << __LINE__ << ":" << Debug::textColor(); Debug::print(args); }
#else
#	define DEBUG(args...) {}
#endif

namespace Debug {
	enum TextColor {
		White = 0,
		Red = 31,
		Blue = 36
	};
	
	template<typename... Args>
	std::string makeString(Args &&...args) {
		std::ostringstream stream;
		std::vector<int> tmp{0, ((void)(stream << args << " "), 0)...};
		
		return stream.str();
	}
	
	inline std::string textColor(u8 color = TextColor::White, bool bold = false) {
#ifdef DEBUG_COLOR
		return std::string("\33[0;") + ((color < 10) ? "0" : "") + std::to_string(color) + ";0" + ((bold) ? "1" : "0") + "m";
#else
		return "";
#endif
	}
	
	template<typename... Args>
	void print(Args &&...args) {
		std::cout << textColor(0, true) << makeString(std::forward<Args>(args)...) << textColor() << std::endl;
	}
}

#endif // DEBUG_HPP_
