/*
 * =====================================================================================
 *
 *       Filename:  MapAnimator.cpp
 *
 *    Description:
 *
 *        Created:  30/04/2015 19:46:41
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "Map.hpp"
#include "MapAnimator.hpp"

void MapAnimator::init(Map &map) {
	m_tileAnimations.assign(map.width() * map.height(), {});
}

void MapAnimator::animateTiles(Map &map) {
	for (size_t x = 0 ; x < map.width() ; ++x) {
		for (size_t y = 0 ; y < map.height() ; ++y) {
			const Tile &tile = map.tileset().getTile(map.getTile(x, y));
			if (tile.getFrameCount()) {
				TileAnimation &tileAnimation = m_tileAnimations.at(x + y * map.width());
				if (!tileAnimation.timer.isStarted())
					tileAnimation.timer.start();

				if (tileAnimation.timer.time() > tile.getFrame(tileAnimation.currentFrame).duration) {
					tileAnimation.currentFrame++;
					tileAnimation.currentFrame %= tile.getFrameCount();

					map.setTile(x, y, tile.getFrame(tileAnimation.currentFrame).tileID, false);

					tileAnimation.timer.reset();
					tileAnimation.timer.start();
				}
			}
		}
	}
}

