/*
 * =====================================================================================
 *
 *       Filename:  TileMap.hpp
 *
 *    Description:
 *
 *        Created:  08/04/2018 19:29:29
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef TILEMAP_HPP_
#define TILEMAP_HPP_

#include "IDrawable.hpp"
#include "Tileset.hpp"
#include "Transformable.hpp"
#include "VertexBuffer.hpp"
#include "PropertyHolder.hpp"

class TileMap : public PropertyHolder, public IDrawable, public Transformable {
	public:
		TileMap(u16 width, u16 height, Tileset &tileset, const std::vector<u16> &data);

		void updateAnimations();

		u16 getTile(u16 tileX, u16 tileY) const;
		void setTile(u16 tileX, u16 tileY, u16 id);

		const Tile &getTileInfo(float x, float y) const;

		const Tileset &tileset() const { return m_tileset; }

		u16 width() const { return m_width; }
		u16 height() const { return m_height; }

		// FIXME: TO REMOVE
		static TileMap *currentMap;

	private:
		struct TileAnimation {
			Timer timer;
			u16 currentFrame = 0;
		};

		void draw(RenderTarget &target, RenderStates states) const override;

		u16 m_width;
		u16 m_height;

		Tileset &m_tileset;

		std::vector<u16> m_data;
		std::vector<TileAnimation> m_tileAnimations;

		VertexBuffer m_vbo;
};

#endif // TILEMAP_HPP_

