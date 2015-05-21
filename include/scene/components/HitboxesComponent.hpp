/*
 * =====================================================================================
 *
 *       Filename:  HitboxesComponent.hpp
 *
 *    Description:
 *
 *        Created:  09/05/2015 01:54:00
 *
 *         Author:  Jonathan Péclat, <peclatj@bluewin.ch>
 *
 * =====================================================================================
 */
#ifndef HITBOXESCOMPONENT_HPP_
#define HITBOXESCOMPONENT_HPP_

#include "Rect.hpp"

class Hitbox {
	public:
		Hitbox(IntRect _rect, std::string _name = "default", bool _isEnabled = true, float _sensitivity = 1.0f)
			: rect(_rect), name(_name), isEnabled(_isEnabled), sensitivity(_sensitivity) {}
		
		IntRect rect;
		std::string name;
		bool isEnabled;
		float sensitivity;
};

class HitboxesComponent {
	using iterator = std::vector<Hitbox>::iterator;
	
	public:
		template<typename... Args>
		void addHitbox(Args &&...args) {
			m_hitboxes.emplace_back(std::forward<Args>(args)...);
		}
		
		Hitbox &operator[](size_t i) {
			return m_hitboxes[i];
		}
		
		void remove(size_t i) {
			m_hitboxes.erase(m_hitboxes.begin() + i);
		}
		
		void disableHitboxes() {
			for(auto& hitbox : m_hitboxes) {
				hitbox.isEnabled = false;
			}
		}
		
		void enableHitboxes() {
			for(auto& hitbox : m_hitboxes) {
				hitbox.isEnabled = true;
			}
		}
		
		bool isHitboxesEnabled() {
			for(auto& hitbox : m_hitboxes) {
				if(hitbox.isEnabled) return true;
			}
			return false;
		}
		
		iterator begin() noexcept { return m_hitboxes.begin(); }
		iterator end() noexcept { return m_hitboxes.end(); }
		
		size_t size() const { return m_hitboxes.size(); }
		
	private:
		std::vector<Hitbox> m_hitboxes;
};


#endif // HITBOXESCOMPONENT_HPP_
