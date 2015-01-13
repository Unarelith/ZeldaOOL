/*
 * =====================================================================================
 *
 *       Filename:  ResourceHandler.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/01/2015 23:07:01
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef RESOURCEHANDLER_HPP_
#define RESOURCEHANDLER_HPP_

#include <map>
#include <memory>

#include "Exception.hpp"
#include "XMLFile.hpp"

class ResourceLoader;

class ResourceHandler {
	public:
		void addType(const std::string &xmlFilename, ResourceLoader &&loader);
		
		template<typename T, typename... Args>
		void add(std::string name, Args &...args) {
			if(m_resources.find(name) != m_resources.end()) {
				throw EXCEPTION("A resource already exists with name:", name);
			}
			
			m_resources.emplace(name, std::make_shared<T>(args...));
		}
		
		template<typename ResourceType>
		ResourceType &get(const std::string &name) {
			if(m_resources.find(name) == m_resources.end()) {
				throw EXCEPTION("Unable to find resource with name:", name);
			}
			
			return *static_cast<ResourceType*>(m_resources[name].get());
		}
		
		static ResourceHandler &getInstance() {
			static ResourceHandler instance;
			return instance;
		}
		
	private:
		ResourceHandler() = default;
		
		std::map<std::string, std::shared_ptr<void>> m_resources;
};

#endif // RESOURCEHANDLER_HPP_
