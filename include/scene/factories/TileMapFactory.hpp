/*
 * =====================================================================================
 *
 *       Filename:  TileMapFactory.hpp
 *
 *    Description:
 *
 *        Created:  10/04/2018 17:03:59
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef TILEMAPFACTORY_HPP_
#define TILEMAPFACTORY_HPP_

#include "SceneObjectList.hpp"

class TileMapFactory {
	public:
		static SceneObject create(const std::string &mapName);

	private:
		static void load(const std::string &mapName, SceneObjectList &objectList);
};

#endif // TILEMAPFACTORY_HPP_
