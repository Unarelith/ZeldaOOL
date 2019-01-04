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

class World : public gk::IDrawable, public gk::Transformable {
	public:
		World();

		void update();

		gk::SceneObject &player() { return m_player; }

		Map *currentMap() const { return m_currentMap; }
		void setCurrentMap(Map *currentMap) { m_currentMap = currentMap; }

		Map &getSideMap(s8 dx, s8 dy);

		static Map &getMap(u16 area, u16 mapX, u16 mapY);
		static bool mapExists(u16 area, u16 mapX, u16 mapY);

		static void setInstance(World *instance) { s_instance = instance; }
		static World &getInstance() { return *s_instance; }

	private:
		void draw(gk::RenderTarget &target, gk::RenderStates states) const override;

		static World *s_instance;

		gk::SceneObject m_player;

		Map *m_currentMap = nullptr;
};

#endif // WORLD_HPP_
