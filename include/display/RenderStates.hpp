/*
 * =====================================================================================
 *
 *       Filename:  RenderStates.hpp
 *
 *    Description:
 *
 *        Created:  14/06/2018 19:52:27
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef RENDERSTATES_HPP_
#define RENDERSTATES_HPP_

#include <glm/matrix.hpp>

#include "IntTypes.hpp"

class Texture;
class Shader;

namespace VertexAttribute {
	enum {
		Coord2d     = 1,
		TexCoord    = 2,
		Color       = 4,

		All         = 0xff,
	};
}

struct RenderStates {
	const glm::mat4 *projectionMatrix = nullptr;
	const glm::mat4 *viewMatrix = nullptr;
	const glm::mat4 *modelMatrix = nullptr;

	const Texture *texture = nullptr;
	const Shader *shader = nullptr;

	u8 vertexAttributes = VertexAttribute::All;

	static const RenderStates Default; // Defined in RenderTarget.cpp
};

#endif // RENDERSTATES_HPP_
