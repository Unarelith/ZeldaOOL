/*
 * =====================================================================================
 *
 *       Filename:  Map.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/12/2014 03:46:04
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

#include "AnimatedMap.hpp"

class Map : public AnimatedMap {
	public:
		Map();
		Map(std::string filename, std::string tilesetName, u16 area, u16 x, u16 y, u16 zoneID);
		~Map();
		
		void load(std::string filename, std::string tilesetName, u16 area, u16 x, u16 y, u16 zoneID);
		
		u16 area() const { return m_area; }
		
		u16 x() const { return m_x; }
		u16 y() const { return m_y; }
		
		static Map &getMap(u16 area, u16 x, u16 y);
		Map &getSideMap(s8 dx, s8 dy) { return getMap(m_area, m_x + dx, m_y + dy); }
		
	private:
		u16 m_area;
		
		u16 m_x;
		u16 m_y;
		
		u16 m_zoneID;
};

#endif // MAP_HPP_
