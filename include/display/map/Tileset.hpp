/*
 * =====================================================================================
 *
 *       Filename:  Tileset.hpp
 *
 *    Description:
 *
 *        Created:  15/09/2014 20:59:15
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef TILESET_HPP_
#define TILESET_HPP_

#include <vector>

#include <gk/gl/Texture.hpp>

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

class Tileset : public gk::Texture {
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
