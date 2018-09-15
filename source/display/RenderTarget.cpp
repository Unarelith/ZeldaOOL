/*
 * =====================================================================================
 *
 *       Filename:  RenderTarget.cpp
 *
 *    Description:
 *
 *        Created:  14/06/2018 19:55:28
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "IDrawable.hpp"
#include "RenderTarget.hpp"
#include "Shader.hpp"
#include "Texture.hpp"
#include "Vertex.hpp"
#include "VertexBuffer.hpp"

const RenderStates RenderStates::Default{};

void RenderTarget::draw(const IDrawable &drawable, const RenderStates &states) {
	drawable.draw(*this, states);
}

void RenderTarget::draw(const VertexBuffer &vertexBuffer, GLenum mode, std::size_t firstVertex, std::size_t vertexCount, const RenderStates &states) {
	if (!states.shader) return;

	Shader::bind(states.shader);

	VertexBuffer::bind(&vertexBuffer);

	states.shader->setUniform("u_projectionMatrix", (states.projectionMatrix) ? *states.projectionMatrix : glm::mat4{1});
	states.shader->setUniform("u_modelMatrix", (states.modelMatrix) ? *states.modelMatrix : glm::mat4{1});
	states.shader->setUniform("u_viewMatrix", (states.viewMatrix) ? *states.viewMatrix : glm::mat4{1});

	if (states.vertexAttributes & VertexAttribute::Coord2d) {
		states.shader->enableVertexAttribArray("coord2d");
		glVertexAttribPointer(states.shader->attrib("coord2d"), 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), reinterpret_cast<GLvoid *>(offsetof(Vertex, coord2d)));
	}

	if (states.vertexAttributes & VertexAttribute::TexCoord) {
		states.shader->enableVertexAttribArray("texCoord");
		glVertexAttribPointer(states.shader->attrib("texCoord"), 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), reinterpret_cast<GLvoid *>(offsetof(Vertex, texCoord)));
	}

	if (states.vertexAttributes & VertexAttribute::Color) {
		states.shader->enableVertexAttribArray("color");
		glVertexAttribPointer(states.shader->attrib("color"), 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), reinterpret_cast<GLvoid *>(offsetof(Vertex, color)));
	}

	if (states.texture)
		Texture::bind(states.texture);

	glDrawArrays(mode, firstVertex, vertexCount);

	Texture::bind(nullptr);

	if (states.vertexAttributes & VertexAttribute::Color)
		states.shader->disableVertexAttribArray("color");
	if (states.vertexAttributes & VertexAttribute::TexCoord)
		states.shader->disableVertexAttribArray("texCoord");
	if (states.vertexAttributes & VertexAttribute::Coord2d)
		states.shader->disableVertexAttribArray("coord2d");

	VertexBuffer::bind(nullptr);

	Shader::bind(nullptr);
}

