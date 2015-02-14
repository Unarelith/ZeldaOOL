/*
 * =====================================================================================
 *
 *       Filename:  MapAnimator.hpp
 *
 *    Description:  
 *
 *        Created:  13/02/2015 01:44:35
 *       Compiler:  gcc
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef MAPANIMATOR_HPP_
#define MAPANIMATOR_HPP_

#include "AnimatedTile.hpp"
#include "Tileset.hpp"

class Map;

class MapAnimator {
	public:
		void updateTile(u16 tileX, u16 tileY, u16 tileID, const Tileset &tileset);
		
		void animateTiles(Map &map);
		
	private:
		std::vector<AnimatedTile> m_animatedTiles;
};

#endif // MAPANIMATOR_HPP_
