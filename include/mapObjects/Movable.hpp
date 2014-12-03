/*
 * =====================================================================================
 *
 *       Filename:  Movable.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/12/2014 17:28:35
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef MOVABLE_HPP_
#define MOVABLE_HPP_

#include <functional>
#include <memory>

#include "Movement.hpp"
#include "Sprite.hpp"

class Movable : public Sprite {
	public:
		Movable();
		Movable(std::string filename, u16 frameWidth, u16 frameHeight, Movement *movement);
		~Movable();
		
		void load(std::string filename, u16 frameWidth, u16 frameHeight, Movement *movement);
		
		void move();
		
		void draw();
		
		enum Direction {
			Down,
			Right,
			Left,
			Up
		};
		
		void setVelocity(float vx, float vy) { m_vx = vx; m_vy = vy; }
		
		void setDirection(u8 direction) { m_direction = direction; }
		
	protected:
		float m_vx;
		float m_vy;
		
		u8 m_direction;
		
		std::vector<std::function<void(void)>> m_collisionHandlers;
		
	private:
		float m_speed;
		bool m_moving;
		
		bool m_blocked;
		
		std::unique_ptr<Movement> m_movement;
};

#endif // MOVABLE_HPP_
