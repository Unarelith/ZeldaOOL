/*
 * =====================================================================================
 *
 *       Filename:  Movable.hpp
 *
 *    Description:  
 *
 *        Created:  18/01/2015 01:47:56
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef MOVABLE_HPP_
#define MOVABLE_HPP_

#include <memory>

#include "MapObject.hpp"
#include "Movement.hpp"
#include "SceneObject.hpp"

class Movable : public MapObject {
	public:
		Movable() = default;
		Movable(const std::string &textureName, float x, float y, u16 frameWidth, u16 frameHeight);
		
		void load(const std::string &textureName, float x, float y, u16 frameWidth, u16 frameHeight);
		
		void updateMovement();
		virtual void update() { updateMovement(); }
		virtual void draw();
		
		enum Direction {
			Down,
			Right,
			Left,
			Up
		};
		
		float vx() const { return m_vx; }
		float vy() const { return m_vy; }
		
		void setVX(float vx) { m_vx = vx; }
		void setVY(float vy) { m_vy = vy; }
		void setVelocity(float vx, float vy) { m_vx = vx; m_vy = vy; }
		
		u8 direction() const { return m_direction; }
		void setDirection(u8 direction) { if(!m_directionLocked) m_direction = direction; }
		
		bool directionLocked() const { return m_directionLocked; }
		void lockDirection() { m_directionLocked = true; }
		void unlockDirection() { m_directionLocked = false; }
		
		bool isMoving() const { return m_moving; }
		bool blocked() const { return m_blocked; }
		
		float speed() const { return m_speed; }
		void setSpeed(float speed) { m_speed = speed; }
		
		OldMovement &getMovement() { return *m_movement; }
		
		template<typename T, typename... Args>
		void setMovement(Args &&...args) {
			m_movement = std::make_shared<T>(std::forward<Args>(args)...);
			if(!m_defaultMovement) m_defaultMovement = m_movement;
		}
		
		void resetMovement() { m_movement = m_defaultMovement; }
		
	protected:
		u8 m_direction = Direction::Down;
		bool m_directionLocked = false;
		
		bool m_blocked = false;
		
		bool m_moving = false;
		
		float m_speed = 0.4f;
		
	private:
		std::shared_ptr<OldMovement> m_defaultMovement{nullptr};
		std::shared_ptr<OldMovement> m_movement{nullptr};
};

#endif // MOVABLE_HPP_
