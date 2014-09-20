/*
 * =====================================================================================
 *
 *       Filename:  Map.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  20/09/2014 19:04:19
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef MAP_HPP_
#define MAP_HPP_

#include <vector>

#include "TileMap.hpp"

class Map : public TileMap {
	public:
		Map();
		Map(std::string filename, Texture &texture);
		~Map();
		
		bool load(std::string filename, Texture &texture);
		
		void resetTiles();
		
		void draw();
		
		u16 getTile(u16 tileX, u16 tileY);
		void setTile(u16 tileX, u16 tileY, u16 tile);
		
	private:
		std::string m_filename;
		
		u16 m_tileWidth;
		u16 m_tileHeight;
		
		std::vector<s16> m_baseData;
		std::vector<s16> m_data;
};

#endif // MAP_HPP_
