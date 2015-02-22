/*
 * =====================================================================================
 *
 *       Filename:  Scene.hpp
 *
 *    Description:  
 *
 *        Created:  15/02/2015 12:45:05
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef SCENE_HPP_
#define SCENE_HPP_

#include <deque>

#include "SceneObject.hpp"

class Scene {
	public:
		void update();
		
		void draw();
		
		SceneObject &addObject(SceneObject &&object);
		
		void checkCollisionsFor(SceneObject &object);
		
		static bool isPlayer(SceneObject &object) { return &object == player; }
		static SceneObject *player;
		
	private:
		std::deque<SceneObject> m_objects;
};

#endif // SCENE_HPP_
