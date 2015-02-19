/*
 * =====================================================================================
 *
 *       Filename:  Scene.hpp
 *
 *    Description:  
 *
 *        Created:  15/02/2015 12:45:05
 *       Compiler:  gcc
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef SCENE_HPP_
#define SCENE_HPP_

#include <deque>

#include "SceneObject.hpp"

class Scene {
	public:
		void update(SceneObject &player);
		
		void draw(SceneObject &player);
		
		SceneObject &addObject(SceneObject &&object);
		
		void checkCollisionsFor(SceneObject &object);
		
	private:
		std::deque<SceneObject> m_objects;
};

#endif // SCENE_HPP_
