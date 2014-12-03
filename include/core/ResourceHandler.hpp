/*
 * =====================================================================================
 *
 *       Filename:  ResourceHandler.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/12/2014 17:30:09
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
#include <string>

#include "Exception.hpp"

class ResourceHandler {
	public:
		ResourceHandler();
		~ResourceHandler();
		
		void loadResources();
		
		template<typename T, typename... Args>
		void add(std::string name, Args... args) {
			m_resources[name] = std::shared_ptr<void>(new T(args...));
		}
		
		template<typename T>
		T &get(std::string name) {
			if(m_resources.find(name) == m_resources.end()) {
				throw EXCEPTION("Unable to find resource with name:", name);
			}
			
			return *static_cast<T*>(m_resources[name].get());
		}
		
		static ResourceHandler &getInstance() {
			static ResourceHandler instance;
			return instance;
		}
		
	private:
		std::map<std::string, std::shared_ptr<void>> m_resources;
};

#endif // RESOURCEHANDLER_HPP_
