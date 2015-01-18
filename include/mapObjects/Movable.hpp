/*
 * =====================================================================================
 *
 *       Filename:  Movable.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  18/01/2015 01:47:56
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

#include <memory>

#include "MapObject.hpp"
#include "Movement.hpp"

class Movable : public MapObject {
	public:
		Movable(const std::string &filename, u16 frameWidth, u16 frameHeight);
		
		void move(float dx, float dy) { m_x += dx; m_y += dy; }
		
		virtual void update();
		virtual void draw();
		
		enum Direction {
			Down,
			Right,
			Left,
			Up
		};
		
		float x() const { return m_x; }
		float y() const { return m_y; }
		
		void setVelocity(float vx, float vy) { m_vx = vx; m_vy = vy; }
		
		u8 direction() const { return m_direction; }
		void setDirection(u8 direction) { m_direction = direction; }
		
		template<typename T, typename... Args>
		void setMovement(Args &&...args) {
			m_movement = std::unique_ptr<T>(new T(std::forward<Args>(args)...));
		}
		
	protected:
		float m_vx = 0;
		float m_vy = 0;
		
		u8 m_direction = Direction::Down;
		
		bool m_blocked = false;
		
	private:
		float m_speed = 0.4f;
		
		bool m_moving = false;
		
		std::unique_ptr<Movement> m_movement;
};

#endif // MOVABLE_HPP_
