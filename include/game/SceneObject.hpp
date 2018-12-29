/*
 * =====================================================================================
 *
 *       Filename:  SceneObject.hpp
 *
 *    Description:
 *
 *        Created:  17/01/2018 19:34:42
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef SCENEOBJECT_HPP_
#define SCENEOBJECT_HPP_

#include <memory>
#include <typeindex>
#include <unordered_map>

#include <gk/system/Exception.hpp>

class SceneObject {
	public:
		SceneObject(const std::string &name = "null", const std::string &type = "null")
			: m_name(name), m_type(type) {}

		template<typename T, typename... Args>
		T &set(Args &&...args) {
			m_components[typeid(T).hash_code()] = std::make_shared<T>(std::forward<Args>(args)...);
			return get<T>();
		}

		template<typename T>
		bool has() const {
			return m_components.count(typeid(T).hash_code()) == 1;
		}

		template<typename T>
		T &get() const {
			auto it = m_components.find(typeid(T).hash_code());
			if(it == m_components.end()) {
				throw EXCEPTION("SceneObject", (void*)this, "(\"" + m_name + "\", \"" + m_type + "\") doesn't have a component of type:", typeid(T).name());
			}

			return *std::static_pointer_cast<T>(it->second);
		}

		template<typename T>
		void remove() {
			m_components.erase(typeid(T).hash_code());
		}

		void debug() const {
#ifdef DEBUG_ENABLED
			DEBUG("=== Component list of object:", (void*)this, "===");
			DEBUG("=== List address:", (void*)&m_components);

			for(auto &it : m_components) {
				DEBUG(it.first, ":", (void*)it.second.get());
			}

			DEBUG("=== End of list. ===");
#endif
		}

		const std::string &name() const { return m_name; }
		const std::string &type() const { return m_type; }

	private:
		std::string m_name;
		std::string m_type;

		std::unordered_map<size_t, std::shared_ptr<void>> m_components;
};

#endif // SCENEOBJECT_HPP_
