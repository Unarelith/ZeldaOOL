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
#include <memory>

#include "MapObject.hpp"
#include "Player.hpp"

#include "SceneObject.hpp"

class Scene {
	public:
		void update();
		
		void draw();
		
		SceneObject &addObject(SceneObject &&object);
		
		void checkCollisionsFor(SceneObject &object);
		
		template<typename T, typename... Args>
		T &addObject(Args &&...args) {
			m_oldObjects.emplace_back(new T(std::forward<Args>(args)...));
			m_oldObjects.back()->addCollisionHandler(std::bind(static_cast<void(Scene::*)(MapObject*)>(&Scene::checkCollisionsFor), this, m_oldObjects.back().get()));
			return static_cast<T&>(*m_oldObjects.back());
		}
		
		void removeObject(MapObject &object);
		
		bool objectAtPosition(MapObject &obj, float x, float y);
		
		MapObject *getObject(float x, float y);
		
		void checkCollisionsFor(MapObject *object);
		
		static bool isPlayer(const SceneObject &) { return false; }
		
	private:
		std::vector<std::unique_ptr<MapObject>> m_oldObjects;
		
		std::deque<SceneObject> m_objects;
};

#endif // SCENE_HPP_
