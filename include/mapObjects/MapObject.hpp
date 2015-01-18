/*
 * =====================================================================================
 *
 *       Filename:  MapObject.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  17/01/2015 22:54:52
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef MAPOBJECT_HPP_
#define MAPOBJECT_HPP_

#include <functional>

#include "Sprite.hpp"

class MapObject : public Sprite {
	public:
		MapObject() = default;
		MapObject(const std::string &textureName, float x, float y, u16 width, u16 height);
		
		void load(const std::string &textureName, float x, float y, u16 width, u16 height);
		
		bool inCollisionWith(const MapObject &object) const;
		
		void addCollisionHandler(const std::function<void(void)> &collisionHandler);
		
		void testCollisions();
		
		bool onTile(u16 tile) const;
		
		virtual void update() = 0;
		
		virtual void draw() = 0;
		
		float x() const { return m_x; }
		float y() const { return m_y; }
		
		void setPosition(float x, float y) { m_x = x; m_y = y; }
		void move(float dx, float dy) { m_x += dx; m_y += dy; }
		
	protected:
		float m_x = 0;
		float m_y = 0;
		
		u16 m_width = 0;
		u16 m_height = 0;
		
		IntRect m_hitbox{0, 0, 0, 0};
		
	private:
		std::vector<std::function<void(void)>> m_collisionHandlers;
};

#endif // MAPOBJECT_HPP_
