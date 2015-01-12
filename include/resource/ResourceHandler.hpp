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

#include <vector>

#include "XMLFile.hpp"

class ResourceInfo;

class ResourceLoader {
	public:
		ResourceLoader() {}
		virtual ~ResourceLoader() {}
		
		virtual ResourceInfo &load(XMLElement *element);
		
	private:
		std::vector<ResourceInfo*> m_infos;
};

class ResourceHandler {
	public:
		ResourceHandler();
		~ResourceHandler();
		
		void add(ResourceLoader &loader) { m_loaders.push_back(loader); }
		
	private:
		std::vector<ResourceLoader> m_loaders;
};

#endif // RESOURCEHANDLER_HPP_
