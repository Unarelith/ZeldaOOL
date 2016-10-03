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

class DrawingSystem {
	public:
		static void draw(SceneObject &object);

		static void drawEffects(SceneObject &object, float x, float y);
		static void drawHitbox(SceneObject &object, float x, float y);
		static void drawSprite(SceneObject &object, float x, float y);
		static void drawSpriteComponent(SceneObject &object, float x, float y);
};

#endif // DRAWINGSYSTEM_HPP_
