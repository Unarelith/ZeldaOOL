/*
 * =====================================================================================
 *
 *       Filename:  TileMap.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  20/09/2014 15:28:20
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef TILEMAP_HPP_
#define TILEMAP_HPP_

#include "OpenGL.hpp"
#include "Tileset.hpp"
#include "VertexBuffer.hpp"
#include "View.hpp"
#include "XMLTileMap.hpp"

class TileMap : public XMLTileMap {
	public:
		TileMap() = default;
		TileMap(const TileMap &) = delete;
		TileMap(TileMap &&tilemap) = default;
		TileMap(const std::string &filename, Tileset &tileset);
		
		void load(const std::string &filename, Tileset &tileset);
		
		virtual void updateTile(u16 tileX, u16 tileY, u16 id) override;
		
		void draw();
		
		void setTile(u16 tileX, u16 tileY, u16 id);
		
		Tileset &tileset() { return *m_tileset; }
		
		View &view() { return m_view; }
		
	protected:
		Tileset *m_tileset;
		
		View m_view;
		
	private:
		VertexBuffer m_vbo;
};

#endif // TILEMAP_HPP_
