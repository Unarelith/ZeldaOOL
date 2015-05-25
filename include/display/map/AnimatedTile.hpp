/*
 * =====================================================================================
 *
 *       Filename:  AnimatedTile.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  15/09/2014 22:36:50
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
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
