/*
 * =====================================================================================
 *
 *       Filename:  Collectable.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/10/2014 17:19:02
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef COLLECTABLE_HPP_
#define COLLECTABLE_HPP_

#include "Entity.hpp"
#include "Image.hpp"

class Collectable : public Image, public Entity {
	public:
		Collectable();
		Collectable(float x, float y, std::string iconFilename);
		virtual ~Collectable();
		
		void load(float x, float y, std::string iconFilename);
		
		virtual void update();
		
		virtual void action() = 0;
		
		void draw();
		
	private:
		float m_movementCounter;
};

#endif // COLLECTABLE_HPP_
