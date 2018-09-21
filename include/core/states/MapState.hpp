/*
 * =====================================================================================
 *
 *       Filename:  MapState.hpp
 *
 *    Description:
 *
 *        Created:  15/09/2014 00:21:30
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef MAPSTATE_HPP_
#define MAPSTATE_HPP_

#include "ApplicationState.hpp"
#include "Scene.hpp"
#include "Shader.hpp"
#include "StatsBar.hpp"

class MapState : public ApplicationState {
	public:
		MapState();

		void update() override;

	private:
		void draw(RenderTarget &target, RenderStates states) const override;

		StatsBar m_statsBar;

		Scene m_scene;

		SceneObject *m_player = nullptr;
};

#endif // MAPSTATE_HPP_
