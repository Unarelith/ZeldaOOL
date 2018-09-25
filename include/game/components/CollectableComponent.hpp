/*
 * =====================================================================================
 *
 *       Filename:  CollectableComponent.hpp
 *
 *    Description:
 *
 *        Created:  01/05/2015 23:47:25
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef COLLECTABLECOMPONENT_HPP_
#define COLLECTABLECOMPONENT_HPP_

#include <functional>
#include <string>

#include "SceneObject.hpp"

class CollectableComponent {
		using CollectableAction = std::function<void(SceneObject&)>;

	public:
		CollectableComponent(const std::string &soundEffectName)
			: m_soundEffectName(soundEffectName) {}

		void action(SceneObject &player) { if(m_action) m_action(player); }

		void setAction(CollectableAction action) { m_action = action; }

		const std::string &soundEffectName() const { return m_soundEffectName; }

	private:
		CollectableAction m_action;

		std::string m_soundEffectName;
};

#endif // COLLECTABLECOMPONENT_HPP_
