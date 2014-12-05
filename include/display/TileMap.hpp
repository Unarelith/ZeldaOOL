/*
 * =====================================================================================
 *
 *       Filename:  TileMap.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/12/2014 19:52:56
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

#include <vector>

#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/View.hpp>

#include "Tileset.hpp"
#include "Types.hpp"

class TileMap : public sf::Drawable, public sf::Transformable {
	public:
		TileMap();
		TileMap(std::string filename, std::string textureName);
		~TileMap();
		
		void load(std::string filename, std::string textureName);
		
		virtual void updateTile(u16 tileX, u16 tileY);
		void updateTiles();
		
		s16 getTile(s16 tileX, s16 tileY);
		void setTile(u16 tileX, u16 tileY, u16 tile);
		
		bool passable(float x, float y);
		
		void draw();
		
		u16 width() const { return m_width; }
		u16 height() const { return m_height; }
		
		static sf::View view;
		
	protected:
		Tileset *m_tileset;
		
		u16 m_width;
		u16 m_height;
		
		u16 m_tileWidth;
		u16 m_tileHeight;
		
		std::vector<s16> m_data;
		
	private:
		virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
		
		sf::VertexArray m_vertices;
};

#endif // TILEMAP_HPP_
