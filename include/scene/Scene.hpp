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

#include <memory>

#include "MapObject.hpp"
#include "Player.hpp"

class Scene {
	public:
		void update();
		
		void draw();
		
		template<typename T, typename... Args>
		T &addObject(Args &&...args) {
			m_objects.emplace_back(new T(std::forward<Args>(args)...));
			m_objects.back()->addCollisionHandler(std::bind(&Scene::checkCollisionsFor, this, m_objects.back().get()));
			return static_cast<T&>(*m_objects.back());
		}
		
		void removeObject(MapObject &object);
		
		bool objectAtPosition(MapObject &obj, float x, float y);
		
		MapObject *getObject(float x, float y);
		
		void checkCollisionsFor(MapObject *object);
		
	private:
		std::vector<std::unique_ptr<MapObject>> m_objects;
};

#endif // SCENE_HPP_
