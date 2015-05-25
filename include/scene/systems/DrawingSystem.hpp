/*
 * =====================================================================================
 *
 *       Filename:  DrawingSystem.hpp
 *
 *    Description:  
 *
 *        Created:  01/05/2015 23:57:52
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef DRAWINGSYSTEM_HPP_
#define DRAWINGSYSTEM_HPP_

#include "SceneObject.hpp"
#include "Vector2.hpp"

class DrawingSystem {
	public:
		static void draw(SceneObject &object);
		
		static void drawSprite(SceneObject &object, Vector2f position);
		static void drawSpriteComponent(SceneObject &object, Vector2f position);
};

#endif // DRAWINGSYSTEM_HPP_
