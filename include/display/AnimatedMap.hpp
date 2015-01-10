/*
 * =====================================================================================
 *
 *       Filename:  AnimatedMap.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  26/12/2014 13:48:42
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
		AnimatedMap(Tileset &tileset, u16 width, u16 height, s16 *data);
		virtual ~AnimatedMap();
		
		void load(Tileset &tileset, u16 width, u16 height, s16 *data);
		
		virtual void updateTile(u16 tileX, u16 tileY, u16 id);
		
		void animateTiles();
		
	private:
		std::vector<AnimatedTile> m_animatedTiles;
};

#endif // ANIMATEDMAP_HPP_
