/*
 * =====================================================================================
 *
 *       Filename:  SceneObjectList.hpp
 *
 *    Description:
 *
 *        Created:  17/01/2018 19:36:14
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef SCENEOBJECTLIST_HPP_
#define SCENEOBJECTLIST_HPP_

#include <algorithm>
#include <deque>

#include "SceneObject.hpp"

class SceneObjectList {
	using iterator = std::deque<SceneObject>::iterator;
	using const_iterator = std::deque<SceneObject>::const_iterator;

	public:
		SceneObject &addObject(SceneObject &&object) {
			m_objects.emplace_back(std::move(object));
			return m_objects.back();
		}

		SceneObject *findByName(const std::string &name) {
			auto it = std::find_if(m_objects.begin(), m_objects.end(), [name] (SceneObject &object) { return object.name() == name; });
			if (it == m_objects.end())
				return nullptr;
			else
				return &*it;
		}

		void removeByName(const std::string &name) {
			auto it = std::find_if(m_objects.begin(), m_objects.end(), [name] (SceneObject &object) { return object.name() == name; });
			if (it != m_objects.end())
				m_objects.erase(it);
		}

		void pop() { m_objects.pop_back(); }

		SceneObject &operator[](size_t n) { return m_objects[n]; }

		void remove(size_t n) { m_objects.erase(m_objects.begin() + n); }

		iterator begin() noexcept { return m_objects.begin(); }
		iterator end() noexcept { return m_objects.end(); }

		const_iterator begin() const noexcept { return m_objects.begin(); }
		const_iterator end() const noexcept { return m_objects.end(); }

		size_t size() const { return m_objects.size(); }

	private:
		std::deque<SceneObject> m_objects;
};

#endif // SCENEOBJECTLIST_HPP_
