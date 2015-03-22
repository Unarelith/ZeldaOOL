/*
 * =====================================================================================
 *
 *       Filename:  Debug.hpp
 *
 *    Description:  
 *
 *        Created:  08/02/2015 22:03:38
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
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

#define _FILE_ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)

#ifdef DEBUG_ENABLED
#	define DEBUG(args...) { std::cout << _FILE_ << ":" << __LINE__ << ": "; Debug::print(args); }
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
	
	template<typename... Args>
	void print(Args &&...args) {
		std::cout << makeString(std::forward<Args>(args)...) << std::endl;
	}
}

#endif // DEBUG_HPP_
