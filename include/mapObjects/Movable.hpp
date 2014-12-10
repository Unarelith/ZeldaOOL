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
		Movable(std::string filename, u16 frameWidth, u16 frameHeight, Movement *movement = nullptr);
		~Movable();
		
		void load(std::string filename, u16 frameWidth, u16 frameHeight, Movement *movement = nullptr);
		
		void testCollisions();
		
		void move(float dx, float dy) { sf::Transformable::move(dx, dy); }
		void move();
		
		void draw();
		
		void addCollisionHandler(std::function<void(void)> collisionHandler);
		
		enum Direction {
			Down,
			Right,
			Left,
			Up
		};
		
		float x() const { return getPosition().x; }
		float y() const { return getPosition().y; }
		
		void setVelocity(float vx, float vy) { m_vx = vx; m_vy = vy; }
		
		u8 direction() const { return m_direction; }
		void setDirection(u8 direction) { m_direction = direction; }
		
		void setMovement(Movement *movement) { m_movement = std::unique_ptr<Movement>(movement); }
		
	protected:
		float m_vx;
		float m_vy;
		
		u8 m_direction;
		
		bool m_blocked;
		
		std::vector<std::function<void(void)>> m_collisionHandlers;
		
	private:
		float m_speed;
		bool m_moving;
		
		std::unique_ptr<Movement> m_movement;
};

#endif // MOVABLE_HPP_
