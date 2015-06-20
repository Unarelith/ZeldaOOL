/*
 * =====================================================================================
 *
 *       Filename:  Translator.hpp
 *
 *    Description:  
 *
 *        Created:  19/06/2015 00:33:21
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef TRANSLATOR_HPP_
#define TRANSLATOR_HPP_

#include <map>
#include <string>

class Translator {
	public:
		static void setLocale(const std::string &name);
		
		static std::string translate(const std::string &str);
		
	private:
		static std::map<std::string, std::string> &dictionary() {
			static std::map<std::string, std::string> dictionary;
			return dictionary;
		}
};

std::string _t(const std::string &str);

#endif // TRANSLATOR_HPP_
