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
		AnimatedMap() = default;
		AnimatedMap(const AnimatedMap &) = delete;
		AnimatedMap(AnimatedMap &&animatedMap) = default;
		AnimatedMap(const std::string &filename, Tileset &tileset);
		
		void load(const std::string &filename, Tileset &tileset);
		
		virtual void updateTile(u16 tileX, u16 tileY, u16 id) override;
		
		void animateTiles();
		
	private:
		std::vector<AnimatedTile> m_animatedTiles;
};

#endif // ANIMATEDMAP_HPP_
