/*
 * =====================================================================================
 *
 *       Filename:  ResourceHandler.hpp
 *
 *    Description:  
 *
 *        Created:  10/01/2015 23:07:01
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef RESOURCEHANDLER_HPP_
#define RESOURCEHANDLER_HPP_

#include <map>
#include <memory>

#include "Exception.hpp"
#include "XMLFile.hpp"

class ResourceHandler {
	public:
		template<typename T, typename... Args>
		T &add(const std::string &name, Args &&...args) {
			if(has(name)) {
				throw EXCEPTION("A resource already exists with name:", name);
			}
			
			m_resources[name] = std::make_shared<T>(std::forward<Args>(args)...);
			
			return get<T>(name);
		}
		
		bool has(const std::string &name) {
			return m_resources.find(name) != m_resources.end();
		}
		
		template<typename T>
		T &get(const std::string &name) {
			if(!has(name)) {
				throw EXCEPTION("Unable to find resource with name:", name);
			}
			
			return *std::static_pointer_cast<T>(m_resources[name]);
		}
		
		template<typename ResourceLoader>
		static void loadConfigFile(const std::string &xmlFilename) {
			ResourceLoader loader;
			loader.load(xmlFilename, getInstance());
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
