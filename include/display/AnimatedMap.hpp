/*
 * =====================================================================================
 *
 *       Filename:  AnimatedMap.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/12/2014 14:24:38
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef ANIMATEDMAP_HPP_
#define ANIMATEDMAP_HPP_

#include "AnimatedTile.hpp"
#include "TileMap.hpp"

class AnimatedMap : public TileMap {
	public:
		AnimatedMap();
		AnimatedMap(std::string filename, std::string tilesetName);
		~AnimatedMap();
		
		virtual void updateTile(u16 tileX, u16 tileY);
		
		void update();
		
	private:
		std::vector<AnimatedTile> m_animatedTiles;
};

#endif // ANIMATEDMAP_HPP_
