/*
 * =====================================================================================
 *
 *       Filename:  Tileset.hpp
 *
 *    Description:  
 *
 *        Created:  12/02/2015 22:01:24
 *       Compiler:  gcc
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef TILESET_HPP_
#define TILESET_HPP_

#include "Texture.hpp"
#include "TileAnimation.hpp"

class Tileset : public Texture {
	public:
		Tileset() = default;
		Tileset(const std::string &filename, const std::string &configFile, u16 tileWidth = 16, u16 tileHeight = 16);
		
		void load(const std::string &filename, const std::string &configFile, u16 tileWidth = 16, u16 tileHeight = 16);
		
		const std::vector<u16> &info() const { return m_info; }
		
		u16 tileWidth() const { return m_tileWidth; }
		u16 tileHeight() const { return m_tileHeight; }
		
		const std::vector<TileAnimation> &anims() const { return m_anims; }
		
	private:
		std::vector<u16> m_info;
		
		u16 m_tileWidth;
		u16 m_tileHeight;
		
		std::vector<TileAnimation> m_anims;
};

#endif // TILESET_HPP_
