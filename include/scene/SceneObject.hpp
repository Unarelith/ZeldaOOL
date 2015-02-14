/*
 * =====================================================================================
 *
 *       Filename:  SceneObject.hpp
 *
 *    Description:  
 *
 *        Created:  14/02/2015 14:57:00
 *       Compiler:  gcc
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef SCENEOBJECT_HPP_
#define SCENEOBJECT_HPP_

#include <map>
#include <memory>
#include <typeindex>

class SceneObject {
	public:
		template<typename T, typename... Args>
		T *setComponent(Args &&...args) {
			m_components[typeid(T)] = std::make_shared<T>(std::forward<Args>(args)...);
			return getComponent<T>();
		}
		
		template<typename T>
		T *getComponent() {
			if(m_components.find(typeid(T)) != m_components.end()) {
				return std::static_pointer_cast<T>(m_components[typeid(T)]).get();
			} else {
				return nullptr;
			}
		}
		
	private:
		std::map<std::type_index, std::shared_ptr<void>> m_components;
};

#endif // SCENEOBJECT_HPP_
