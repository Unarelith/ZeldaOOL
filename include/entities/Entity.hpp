/*
 * =====================================================================================
 *
 *       Filename:  Entity.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  13/08/2014 22:53:24
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

#include <SFML/Graphics.hpp>

#include "Types.hpp"

class Entity {
	public:
		Entity(s16 x, s16 y, u16 width, u16 height);
		~Entity();
		
		bool inCollisionWith(Entity *e);
		
		bool onTile(u16 tile);
		
		void setHitbox(sf::IntRect hitbox) { m_hitbox = hitbox; }
		
		void setPosition(double x, double y) { m_x = x; m_y = y; }
		
		void setVelocity(double vx, double vy) { m_vx = vx; m_vy = vy; }
		
		double x() const { return m_x; }
		double y() const { return m_y; }
		
		double vx() const { return m_vx; }
		double vy() const { return m_vy; }
		
	protected:
		double m_x;
		double m_y;
		
		u16 m_width;
		u16 m_height;
		
		double m_vx;
		double m_vy;
		
		sf::IntRect m_hitbox;
};

#endif // ENTITY_HPP_
