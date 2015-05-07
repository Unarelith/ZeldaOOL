/*
 * =====================================================================================
 *
 *       Filename:  SceneSystem.hpp
 *
 *    Description:  
 *
 *        Created:  07/05/2015 17:05:23
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef SCENESYSTEM_HPP_
#define SCENESYSTEM_HPP_

#include "SceneObject.hpp"
#include "SceneObjectList.hpp"

class SceneSystem {
	public:
		static void reset(SceneObjectList &objectList);
		static void update(SceneObjectList &objectList);
		static void draw(SceneObjectList &objectList);
		
		static void resetObject(SceneObject &object);
		static void updateObject(SceneObject &object);
		static void drawObject(SceneObject &object);
};

#endif // SCENESYSTEM_HPP_
