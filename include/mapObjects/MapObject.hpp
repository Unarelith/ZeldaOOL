/*
 * =====================================================================================
 *
 *       Filename:  MapObject.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/12/2014 19:46:13
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

#include "Movable.hpp"

class MapObject : public Movable {
	public:
		MapObject();
		MapObject(std::string filename, u8 type, u16 frameWidth = 16, u16 frameHeight = 16);
		virtual ~MapObject();
		
		void load(std::string filename, u8 type, u16 frameWidth = 16, u16 frameHeight = 16);
		
		bool inCollisionWith(MapObject &mapObject);
		
		void mapObjectsCollisions();
		
		virtual void reset() {}
		virtual void update() {}
		virtual void draw() { Movable::draw(); }
		
		virtual void collisionAction(MapObject &mapObject) = 0;
		
		enum Type {
			Enemy,
			Interactive,
			NPC,
			Player
		};
		
	private:
		u8 m_type;
};

#endif // MAPOBJECT_HPP_
