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

#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/VertexArray.hpp>

#include "Tileset.hpp"
#include "Types.hpp"

class TileMap : public sf::Drawable, public sf::Transformable {
	public:
		TileMap();
		TileMap(std::string textureName, u16 width, u16 height, s16 *data);
		~TileMap();
		
		void load(std::string textureName, u16 width, u16 height, s16 *data);
		
		u16 getTile(s16 tileX, s16 tileY);
		void setTile(u16 tileX, u16 tileY, u16 tile);
		
		void draw();
		
	protected:
		u16 m_width;
		u16 m_height;
		
	private:
		virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
		
		Tileset *m_tileset;
		
		s16 *m_data;
		
		sf::VertexArray m_vertices;
};

#endif // TILEMAP_HPP_
