/*
 * =====================================================================================
 *
 *       Filename:  SceneObject.hpp
 *
 *    Description:  
 *
 *        Created:  01/05/2015 23:09:38
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

#include "Debug.hpp"

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
		void remove() {
			m_components.erase(typeid(T));
		}
		
		void debug() {
			DEBUG("=== Component list of object:", (void*)this, " ===");
			DEBUG("=== List address:", (void*)&m_components);
			for(auto &it : m_components) {
				DEBUG(it.first.name(), ":", (void*)it.second.get());
			}
			DEBUG("=== End of list. ===");
		}
		
	private:
		std::map<std::type_index, std::shared_ptr<void>> m_components;
};

#endif // SCENEOBJECT_HPP_
