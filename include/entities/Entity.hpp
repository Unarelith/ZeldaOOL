/*
 * =====================================================================================
 *
 *       Filename:  Entity.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  15/09/2014 22:10:59
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef ENTITY_HPP_
#define ENTITY_HPP_

#include "Rect.hpp"
#include "Types.hpp"

class Entity {
	public:
		Entity();
		Entity(s16 x, s16 y, u16 width, u16 height);
		~Entity();
		
		void load(s16 x, s16 y, u16 width, u16 height);
		
		bool inCollisionWith(Entity *e);
		
		bool onTile(u16 tile);
		
		void move(float dx, float dy) { m_x += dx; m_y += dy; }
		
		void setHitbox(IntRect hitbox) { m_hitbox = hitbox; }
		
		void setPosition(float x, float y) { m_x = x; m_y = y; }
		
		void setVelocity(float vx, float vy) { m_vx = vx; m_vy = vy; }
		
		float x() const { return m_x; }
		float y() const { return m_y; }
		
		float vx() const { return m_vx; }
		float vy() const { return m_vy; }
		
		void setVX(float vx) { m_vx = vx; }
		void setVY(float vy) { m_vy = vy; }
		
	protected:
		float m_x;
		float m_y;
		
		u16 m_width;
		u16 m_height;
		
		float m_vx;
		float m_vy;
		
		IntRect m_hitbox;
};

#endif // ENTITY_HPP_
