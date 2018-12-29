/*
 * =====================================================================================
 *
 *       Filename:  MapAnimator.hpp
 *
 *    Description:
 *
 *        Created:  30/04/2015 19:45:10
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef MAPANIMATOR_HPP_
#define MAPANIMATOR_HPP_

#include <gk/core/Timer.hpp>

#include "Tileset.hpp"

class Map;

class MapAnimator {
	public:
		void init(Map &map);

		void animateTiles(Map &map);

	private:
		struct TileAnimation {
			gk::Timer timer;
			u16 currentFrame = 0;
		};

		std::vector<TileAnimation> m_tileAnimations;
};

#endif // MAPANIMATOR_HPP_
