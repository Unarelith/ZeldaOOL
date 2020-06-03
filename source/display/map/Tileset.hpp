/*
 * =====================================================================================
 *
 *  ZeldaOOL
 *
 *  Copyright (C) 2014-2020 Unarelith, Quentin Bazin <zelda.ool@unarelith.net>
 *
 *  This file is part of ZeldaOOL.
 *
 *  ZeldaOOL is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  ZeldaOOL is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with ZeldaOOL; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA  02110-1301 USA
 *
 * =====================================================================================
 */
#ifndef TILESET_HPP_
#define TILESET_HPP_

#include <vector>

#include <SFML/Graphics/Texture.hpp>

#include <gk/core/IntTypes.hpp>

class Tile {
	public:
		Tile(u16 type = 0) : m_type(type) {}

		struct AnimationFrame {
			u16 tileID;
			u16 duration;
		};

		u16 getFrameCount() const { return m_animation.size(); }
		const AnimationFrame &getFrame(u16 id) const { return m_animation.at(id); }
		void addAnimationFrame(u16 tileID, u16 duration) { m_animation.emplace_back(AnimationFrame{tileID, duration}); }

		u16 type() const { return m_type; }

	private:
		std::vector<AnimationFrame> m_animation;

		u16 m_type = 0;
};

class Tileset : public sf::Texture {
	public:
		Tileset() = default;
		Tileset(const Tileset &) = delete;
		Tileset(Tileset &&tileset) = default;
		Tileset(const std::string &filename, const std::string &configFile);

		void load(const std::string &filename, const std::string &configFile);

		const std::vector<u16> &info() const { return m_info; }

		const Tile &getTile(u16 id) const { return m_tiles.at(id); }
		void setTile(u16 id, Tile &tile) { m_tiles.at(id) = tile; }

		u16 tileWidth() const { return m_tileWidth; }
		u16 tileHeight() const { return m_tileHeight; }
		u16 tileCount() const { return m_tiles.size(); }

	private:
		std::vector<u16> m_info;

		u16 m_tileWidth;
		u16 m_tileHeight;

		std::vector<Tile> m_tiles;
};

#endif // TILESET_HPP_
