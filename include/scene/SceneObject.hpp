/*
 * =====================================================================================
 *
 *       Filename:  SceneObject.hpp
 *
 *    Description:  
 *
 *        Created:  14/02/2015 14:57:00
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef SCENEOBJECT_HPP_
#define SCENEOBJECT_HPP_

#include <map>
#include <memory>
#include <typeindex>

#include "Exception.hpp"

class SceneObject {
	public:
		SceneObject() = default;
		SceneObject(const SceneObject &) = delete;
		SceneObject(SceneObject &&) = default;
		
		SceneObject &operator=(const SceneObject &) = delete;
		SceneObject &operator=(SceneObject &&) = default;
		
		template<typename T, typename... Args>
		T &set(Args &&...args) {
			m_components[typeid(T)] = std::make_shared<T>(std::forward<Args>(args)...);
			return get<T>();
		}
		
		template<typename T>
		bool has() {
			return m_components.find(typeid(T)) != m_components.end();
		}
		
		template<typename T>
		T &get() {
			if(has<T>()) {
				return *std::static_pointer_cast<T>(m_components[typeid(T)]).get();
			} else {
				throw EXCEPTION("SceneObject", (void*)this, "doesn't have a component of type:", typeid(T).name());
			}
		}
		
		template<typename T>
		void removeComponent() {
			m_components.erase(typeid(T));
		}
		
	private:
		std::map<std::type_index, std::shared_ptr<void>> m_components;
};

#endif // SCENEOBJECT_HPP_
