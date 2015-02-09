/*
 * =====================================================================================
 *
 *       Filename:  ResourceHandler.hpp
 *
 *    Description:  
 *
 *        Created:  09/02/2015 01:47:27
 *       Compiler:  gcc
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef RESOURCEHANDLER_HPP_
#define RESOURCEHANDLER_HPP_

#include <map>
#include <memory>

#include "Exception.hpp"

class ResourceHandler {
	public:
		template<typename ResourceLoader>
		void addType(const std::string &xmlFilename) {
			ResourceLoader loader;
			loader.load(xmlFilename, *this);
		}
		
		template<typename T, typename... Args>
		void add(std::string name, Args &&...args) {
			if(m_resources.find(name) != m_resources.end()) {
				throw EXCEPTION("A resource already exists with name:", name);
			}
			
			m_resources.emplace(name, std::make_shared<T>(std::forward<Args>(args)...));
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
