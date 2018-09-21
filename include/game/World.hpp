/*
 * =====================================================================================
 *
 *       Filename:  World.hpp
 *
 *    Description:
 *
 *        Created:  21/09/2018 22:21:27
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef WORLD_HPP_
#define WORLD_HPP_

#include "Map.hpp"

class World : public IDrawable, public Transformable {
	public:
		World();

		void update();

		Map *currentMap() const { return m_currentMap; }

		SceneObject &player() { return m_player; }

		static void setInstance(World *instance) { s_instance = instance; }
		static World &getInstance() { return *s_instance; }

	private:
		void draw(RenderTarget &target, RenderStates states) const override;

		static World *s_instance;

		Map *m_currentMap = nullptr;

		SceneObject m_player;
};

#endif // WORLD_HPP_
