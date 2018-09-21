/*
 * =====================================================================================
 *
 *       Filename:  Tileset.hpp
 *
 *    Description:
 *
 *        Created:  08/04/2018 19:33:25
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef TILESET_HPP_
#define TILESET_HPP_

#include <string>
#include <vector>

#include "PropertyHolder.hpp"
#include "Texture.hpp"
#include "Timer.hpp"

class Tile : public PropertyHolder {
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

class Tileset {
	public:
		Tileset(const std::string &name, u16 tileWidth, u16 tileHeight, u32 tileCount, Texture &texture);

		u16 tileWidth() const { return m_tileWidth; }
		u16 tileHeight() const { return m_tileHeight; }
		u16 tileCount() const { return m_tiles.size(); }

		const Tile &getTile(u16 id) const { return m_tiles.at(id); }
		void setTile(u16 id, Tile &tile) { m_tiles.at(id) = tile; }

		const Texture &texture() const { return m_texture; }

	private:
		std::string m_name;

		u16 m_tileWidth = 0;
		u16 m_tileHeight = 0;

		std::vector<Tile> m_tiles;

		Texture &m_texture;
};

#endif // TILESET_HPP_
