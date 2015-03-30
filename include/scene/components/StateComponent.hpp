/*
 * =====================================================================================
 *
 *       Filename:  StateComponent.hpp
 *
 *    Description:  
 *
 *        Created:  30/03/2015 16:16:05
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef STATECOMPONENT_HPP_
#define STATECOMPONENT_HPP_

#include <map>
#include <string>

#include "Types.hpp"

class StateComponent {
	public:
		void addState(std::string name, s16 anim, bool animated = true)  {
			m_animations.emplace(name, std::make_pair(anim, animated));
		}
		
		std::string currentState() const { return m_currentState; }
		
		s16 currentAnimation() const {
			if(m_animations.find(m_currentState) != m_animations.end()) {
				return m_animations.at(m_currentState).first;
			} else {
				return -1;
			}
		}
		
		bool isAnimated() const {
			if(m_animations.find(m_currentState) != m_animations.end()) {
				return m_animations.at(m_currentState).second;
			} else {
				return false;
			}
		}
		
		void setCurrentState(std::string state) { m_currentState = state; }
		
	private:
		std::string m_currentState;
		
		std::map<std::string, std::pair<s16, bool>> m_animations;
};

#endif // STATECOMPONENT_HPP_
