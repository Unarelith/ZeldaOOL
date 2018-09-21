/*
 * =====================================================================================
 *
 *       Filename:  MapAnimator.hpp
 *
 *    Description:
 *
 *        Created:  30/04/2015 19:45:10
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
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
