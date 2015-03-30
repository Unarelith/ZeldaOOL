/*
 * =====================================================================================
 *
 *       Filename:  DrawingSystem.hpp
 *
 *    Description:  
 *
 *        Created:  14/02/2015 19:35:32
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef DRAWINGSYSTEM_HPP_
#define DRAWINGSYSTEM_HPP_

#include "SceneObject.hpp"

class DrawingSystem {
	public:
		static void draw(SceneObject &object);
		
		static void drawImage(SceneObject &object, float x, float y);
		static void drawSprite(SceneObject &object, float x, float y);
};

#endif // DRAWINGSYSTEM_HPP_
