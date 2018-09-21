/*
 * =====================================================================================
 *
 *       Filename:  Scene.hpp
 *
 *    Description:
 *
 *        Created:  17/01/2018 19:34:20
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef SCENE_HPP_
#define SCENE_HPP_

#include <functional>
#include <list>

#include "AbstractController.hpp"
#include "AbstractView.hpp"
#include "IDrawable.hpp"
#include "SceneObject.hpp"
#include "SceneObjectList.hpp"
#include "Transformable.hpp"

class Scene : public IDrawable, public Transformable {
	public:
		void reset();
		void update();

		SceneObject &addObject(SceneObject &&object);

		void addCollisionChecker(std::function<void(SceneObject &)> checker);
		void checkCollisionsFor(SceneObject &object);

		SceneObjectList &objects() { return m_objects; }
		const SceneObjectList &objects() const { return m_objects; }

		template<typename T, typename... Args>
		auto addController(Args &&...args) -> typename std::enable_if<std::is_base_of<AbstractController, T>::value, T&>::type {
			m_controllerList.emplace_back(new T(std::forward<Args>(args)...));
			return *dynamic_cast<T*>(m_controllerList.back().get());
		}

		template<typename T, typename... Args>
		auto addView(Args &&...args) -> typename std::enable_if<std::is_base_of<AbstractView, T>::value, T&>::type {
			m_viewList.emplace_back(new T(std::forward<Args>(args)...));
			return *dynamic_cast<T*>(m_viewList.back().get());
		}

		bool isInactive() { return m_controllerList.empty() && m_viewList.empty(); }

	private:
		void draw(RenderTarget &target, RenderStates states) const override;

		SceneObjectList m_objects;

		std::list<std::unique_ptr<AbstractController>> m_controllerList;
		std::list<std::unique_ptr<AbstractView>> m_viewList;
};

#endif // SCENE_HPP_
