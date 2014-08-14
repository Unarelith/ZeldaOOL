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
		
		void setHitbox(sf::IntRect hitbox) { m_hitbox = hitbox; }
		
	protected:
		double m_x;
		double m_y;
		
		u16 m_width;
		u16 m_height;
		
		float m_vx;
		float m_vy;
		
		sf::IntRect m_hitbox;
};

#endif // ENTITY_HPP_
