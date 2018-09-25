/*
 * =====================================================================================
 *
 *       Filename:  MapRenderer.hpp
 *
 *    Description:
 *
 *        Created:  30/04/2015 19:47:12
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef MAPRENDERER_HPP_
#define MAPRENDERER_HPP_

#include "IDrawable.hpp"
#include "Tileset.hpp"
#include "VertexBuffer.hpp"

class Map;

class MapRenderer : public IDrawable {
	public:
		void init(Map *map, u16 mapWidth, u16 mapHeight);

		void updateTile(u16 tileX, u16 tileY, u16 id, Map &map);

	private:
		void draw(RenderTarget &target, RenderStates states) const override;

		VertexBuffer m_vbo;

		Map *m_map = nullptr;
};

#endif // MAPRENDERER_HPP_
