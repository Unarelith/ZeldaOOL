/*
 * =====================================================================================
 *
 *       Filename:  Tileset.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  15/09/2014 20:59:15
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
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
		Tileset(const Tileset &) = delete;
		Tileset(Tileset &&tileset) = default;
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
