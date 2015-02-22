/*
 * =====================================================================================
 *
 *       Filename:  AnimatedTile.hpp
 *
 *    Description:  
 *
 *        Created:  13/02/2015 00:30:47
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef ANIMATEDTILE_HPP_
#define ANIMATEDTILE_HPP_

#include "Timer.hpp"
#include "TileAnimation.hpp"

struct AnimatedTile {
	AnimatedTile(u16 _tileX, u16 _tileY, u16 _nextFrame, const TileAnimation &_anim) :
		tileX(_tileX), tileY(_tileY), nextFrame(_nextFrame), anim(_anim) {}
	
	u16 tileX;
	u16 tileY;
	
	u16 nextFrame;
	
	const TileAnimation &anim;
	
	Timer timer;
};

#endif // ANIMATEDTILE_HPP_
