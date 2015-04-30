/*
 * =====================================================================================
 *
 *       Filename:  Collectable.hpp
 *
 *    Description:  
 *
 *        Created:  07/10/2014 17:19:02
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef COLLECTABLE_HPP_
#define COLLECTABLE_HPP_

#include "MapObject.hpp"

class Collectable : public MapObject {
	public:
		Collectable() = default;
		Collectable(const std::string &textureName, float x, float y);
		virtual ~Collectable() = default;
		
		void load(const std::string &textureName, float x, float y);
		
		virtual void update();
		
		virtual void action() = 0;
		
		void draw();
		
	private:
		float m_movementCounter = 0;
};

#endif // COLLECTABLE_HPP_
