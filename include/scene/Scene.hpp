/*
 * =====================================================================================
 *
 *       Filename:  Scene.hpp
 *
 *    Description:  
 *
 *        Created:  01/05/2015 22:49:45
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
		void reset();
		
		void update();
		void updateObject(SceneObject &object);
		
		void draw();
		
		SceneObject &addObject(SceneObject &&object);
		
		void checkCollisionsFor(SceneObject &object);
		
		static bool isPlayer(const SceneObject &object) { return player == &object; }
		
		static SceneObject *player;
		
	private:
		std::deque<SceneObject> m_objects;
};

#endif // SCENE_HPP_
