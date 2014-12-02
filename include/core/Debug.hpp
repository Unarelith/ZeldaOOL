/*
 * =====================================================================================
 *
 *       Filename:  Debug.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/12/2014 23:47:59
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

#define _FILE (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)
#define DEBUG(args...) { std::cout << "\33[0;36;01m" << _FILE << ":" << __LINE__ << ": \33[0m"; Debug::print(args); }

namespace Debug {
	template<typename T>
	std::string makeString(std::stringstream &stream, T value) {
		stream << value;
		return stream.str();
	}
	
	template<typename T, typename... Args>
	std::string makeString(std::stringstream &stream, T value, Args... args) {
		stream << value << " ";
		return makeString(stream, args...);
	}
	
	template<typename... Args>
	void print(Args... args) {
		std::stringstream stream;
		
		std::cout << "\33[0;00;01m" << makeString(stream, args...) << "\33[0m" << std::endl;
	}
}

#endif // DEBUG_HPP_
