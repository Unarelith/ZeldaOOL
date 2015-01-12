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
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef DEBUG_HPP_
#define DEBUG_HPP_

#include <cstring>
#include <iostream>
#include <sstream>
#include <string>

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
	
	inline std::string textColor(u8 color = TextColor::White, bool bold = false) {
#ifdef DEBUG_COLOR
		return std::string("\33[0;") + ((color < 10) ? "0" : "") + std::to_string(color) + ";0" + ((bold) ? "1" : "0") + "m";
#else
		return std::string("");
#endif
	}
	
	template<typename T>
	std::string makeString(std::stringstream &sstream, T value) {
		sstream << value;
		return sstream.str();
	}
	
	template<typename T, typename... Args>
	std::string makeString(std::stringstream &sstream, T value, Args &...args) {
		sstream << value << " ";
		return makeString(sstream, args...);
	}
	
	template<typename... Args>
	void print(Args &...args) {
		std::stringstream sstream;
		
		std::cout << textColor(0, true) << makeString(sstream, args...) << textColor() << std::endl;
	}
}

#endif // DEBUG_HPP_
