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

#include <gk/gl/Drawable.hpp>
#include <gk/gl/VertexBuffer.hpp>

#include "Tileset.hpp"

class Map;

class MapRenderer : public gk::Drawable {
	public:
		void init(Map *map, u16 mapWidth, u16 mapHeight);

		void updateTile(u16 tileX, u16 tileY, u16 id, Map &map);

	private:
		void draw(gk::RenderTarget &target, gk::RenderStates states) const override;

		gk::VertexBuffer m_vbo;

		Map *m_map = nullptr;
};

#endif // MAPRENDERER_HPP_
