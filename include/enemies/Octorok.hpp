/*
 * =====================================================================================
 *
 *       Filename:  Octorok.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/10/2014 21:39:07
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef OCTOROK_HPP_
#define OCTOROK_HPP_

#include "Enemy.hpp"

class Octorok : public Enemy {
	public:
		Octorok() = default;
		Octorok(u16 x, u16 y, u8 direction);
		
		void load(u16 x, u16 y, u8 direction);
		
		void reset();
		
		void update();
		
		void draw();
		
		void hurtAction(s16 vx, s16 vy) override;
};

#endif // OCTOROK_HPP_
