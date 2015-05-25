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
#include "Vector2.hpp"

struct AnimatedTile {
	AnimatedTile(Vector2u16 _tile, u16 _nextFrame, const TileAnimation &_anim) :
		tile(_tile), nextFrame(_nextFrame), anim(_anim) {}
	
	Vector2u16 tile;
	
	u16 nextFrame;
	
	const TileAnimation &anim;
	
	Timer timer;
};

#endif // ANIMATEDTILE_HPP_
