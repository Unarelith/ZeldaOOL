/*
 * =====================================================================================
 *
 *       Filename:  PropertyHolder.hpp
 *
 *    Description:
 *
 *        Created:  08/04/2018 19:33:25
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef PROPERTYHOLDER_HPP_
#define PROPERTYHOLDER_HPP_

#include <map>
#include <variant>

#include "XMLFile.hpp"

class PropertyHolder {
	public:
		using Property = std::variant<std::string, int, bool, float>;

		template<typename T>
		const T &getProperty(const std::string &name) const { return std::get<T>(m_properties.at(name)); }
		void addProperty(const std::string &name, const Property &property) { m_properties.emplace(name, property); }

		void loadProperties(tinyxml2::XMLElement *propertyElement);

	private:
		std::map<std::string, Property> m_properties;
};

#endif // PROPERTYHOLDER_HPP_
