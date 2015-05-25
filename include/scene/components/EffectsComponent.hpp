/*
 * =====================================================================================
 *
 *       Filename:  EffectsComponent.hpp
 *
 *    Description:  
 *
 *        Created:  24/05/2015 20:50:01
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef EFFECTSCOMPONENT_HPP_
#define EFFECTSCOMPONENT_HPP_

#include <map>
#include <string>

#include "Sprite.hpp"

class EffectsComponent {
	using EffectList = std::map<std::string, std::pair<Sprite, bool>>;
	
	public:
		void addEffect(const std::string &name, const std::string &textureName) {
			m_effects.emplace(name, std::make_pair<Sprite, bool>(textureName, false));
		}
		
		void enableIf(const std::string &name, bool condition) {
			m_effects.at(name).second = condition;
		}
		
		EffectList &effects() { return m_effects; }
		
	private:
		EffectList m_effects;
};

#endif // EFFECTSCOMPONENT_HPP_
