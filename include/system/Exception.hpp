/*
 * =====================================================================================
 *
 *       Filename:  Exception.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  26/12/2014 01:26:16
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef EXCEPTION_HPP_
#define EXCEPTION_HPP_

#include <exception>
#include <string>

#include "Debug.hpp"
#include "Types.hpp"

#define EXCEPTION(args...) (Exception(__LINE__, _FILE_, args))

class Exception : public std::exception {
	public:
		template<typename... Args>
		Exception(u16 line, std::string filename, Args &&...args) noexcept {
			m_line = line;
			m_filename = filename;
			
			m_errorMsg = Debug::makeString(std::forward<Args>(args)...);
		}
		
		virtual const char *what() const noexcept {
			return (Debug::textColor(Debug::TextColor::Red, true) + "at " + m_filename + ":" + std::to_string(m_line) + ": " + Debug::textColor(0, true) + m_errorMsg.c_str() + Debug::textColor()).c_str();
		}
		
	private:
		u16 m_line;
		std::string m_filename;
		
		std::string m_errorMsg;
};

#endif // EXCEPTION_HPP_
