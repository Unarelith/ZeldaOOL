/*
 * =====================================================================================
 *
 *       Filename:  XMLTileMap.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  13/01/2015 22:33:50
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef XMLTILEMAP_HPP_
#define XMLTILEMAP_HPP_

#include <string>
#include <vector>

#include "Types.hpp"

class XMLTileMap {
	public:
		XMLTileMap() = default;
		XMLTileMap(const XMLTileMap &) = delete;
		XMLTileMap(XMLTileMap &&) = default;
		XMLTileMap(const std::string &filename);
		
		void load(const std::string &filename);
		
		void resetTiles();
		
		u16 getTile(u16 tileX, u16 tileY);
		
	protected:
		u16 m_width = 0;
		u16 m_height = 0;
		
		std::vector<u16> m_baseData;
		std::vector<u16> m_data;
};

#endif // XMLTILEMAP_HPP_
