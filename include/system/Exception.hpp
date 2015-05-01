/*
 * =====================================================================================
 *
 *       Filename:  Exception.hpp
 *
 *    Description:  
 *
 *        Created:  26/12/2014 01:26:16
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef EXCEPTION_HPP_
#define EXCEPTION_HPP_

#include <exception>
#include <string>

#include "Debug.hpp"

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
			return ("at " + m_filename + ":" + std::to_string(m_line) + ": " + m_errorMsg.c_str()).c_str();
		}
		
	private:
		u16 m_line;
		std::string m_filename;
		
		std::string m_errorMsg;
};

#endif // EXCEPTION_HPP_
