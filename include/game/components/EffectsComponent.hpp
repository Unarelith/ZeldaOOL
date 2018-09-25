/*
 * =====================================================================================
 *
 *       Filename:  EffectsComponent.hpp
 *
 *    Description:
 *
 *        Created:  24/05/2015 20:50:01
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef EFFECTSCOMPONENT_HPP_
#define EFFECTSCOMPONENT_HPP_

#include <map>
#include <string>

#include "Sprite.hpp"

class Effect : public Sprite {
	public:
		Effect(const std::string &textureName, u16 frameWidth, u16 frameHeight, Vector2f _offset = {0, 0})
			: Sprite(textureName, frameWidth, frameHeight), offset(_offset) {}

		Vector2i offset;
		bool isEnabled = false;
};

class EffectsComponent {
	public:
		Effect &addEffect(const std::string &name, const std::string &textureName, u16 frameWidth, u16 frameHeight, Vector2f offset = {0, 0}) {
			m_effects.emplace(name, Effect{textureName, frameWidth, frameHeight, offset});
			return m_effects.at(name);
		}

		void enableIf(const std::string &name, bool condition) {
			m_effects.at(name).isEnabled = condition;
		}

		void enable(const std::string &name) {
			m_effects.at(name).isEnabled = true;
		}

		std::map<std::string, Effect> &effects() { return m_effects; }

	private:
		std::map<std::string, Effect> m_effects;
};

#endif // EFFECTSCOMPONENT_HPP_
