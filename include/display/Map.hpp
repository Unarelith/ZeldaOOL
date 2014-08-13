/*
 * =====================================================================================
 *
 *       Filename:  Map.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  15/07/2014 14:15:40
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef MAP_HPP_
#define MAP_HPP_

#include <SFML/Graphics.hpp>

#include "Image.hpp"

class Map : public sf::Drawable, public sf::Transformable {
	public:
		Map();
		Map(std::string filename, Image &tileset);
		~Map();
		
		bool load(std::string filename, Image &tileset);
		
		void update();
		
	private:
		virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
		
		sf::Texture m_tileset;
		
		sf::VertexArray m_vertices;
		
		s16* m_data;
		
		u16 m_width;
		u16 m_height;
		
		u16 m_tileWidth;
		u16 m_tileHeight;
};

#endif // MAP_HPP_
