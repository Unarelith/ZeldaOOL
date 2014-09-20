/*
 * =====================================================================================
 *
 *       Filename:  TileMap.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  20/09/2014 15:28:35
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include <sys/stat.h>

#define GLM_FORCE_RADIANS
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Application.hpp"
#include "Debug.hpp"
#include "TileMap.hpp"
#include "VertexAttribute.hpp"

TileMap::TileMap() {
}

TileMap::TileMap(Texture &texture, u16 width, u16 height, s16 *data) {
	load(texture, width, height, data);
}

TileMap::~TileMap() {
	glDeleteBuffers(1, &m_vbo);
}

void TileMap::load(Texture &texture, u16 width, u16 height, s16 *data) {
	m_texture = &texture;
	
	m_width = width;
	m_height = height;
	
	glGenBuffers(1, &m_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	
	m_data = data;
	
	glBufferData(GL_ARRAY_BUFFER, sizeof(VertexAttribute) * m_width * m_height * 6, NULL, GL_DYNAMIC_DRAW);
	
	for(u16 y = 0 ; y < m_height ; y++) {
		for(u16 x = 0 ; x < m_width ; x++) {
			updateTile(m_data[x + y * m_width], x * 16, y * 16);
		}
	}
	
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	
	m_shader.load("shaders/map.v.glsl", "shaders/map.f.glsl");
	
	m_shader.useProgram();
	
	glm::mat4 projectionMatrix = glm::ortho(0.0f, WINDOW_WIDTH * 1.0f, WINDOW_HEIGHT * 1.0f, 0.0f);
	
	glUniformMatrix4fv(m_shader.uniform("uProjectionMatrix"), 1, GL_FALSE, glm::value_ptr(projectionMatrix));
	
	Application::window.useDefaultShader();
}

void TileMap::updateTile(u16 id, float x, float y) {
	float texTileX = id % (m_texture->width() / 16) * 16.0f / m_texture->width();
	float texTileY = id / (m_texture->width() / 16) * 16.0f / m_texture->height();
	
	float tileWidth = 16.0f / m_texture->width();
	float tileHeight = 16.0f / m_texture->height();
	
	VertexAttribute attributes[] = {	
		{{x		   , y		  },	{texTileX			 , texTileY}},
		{{x + 16.0f, y		  },	{texTileX + tileWidth, texTileY}},
		{{x + 16.0f, y + 16.0f},	{texTileX + tileWidth, texTileY + tileHeight}},
		{{x		   , y		  },	{texTileX			 , texTileY}},
		{{x + 16.0f, y + 16.0f},	{texTileX + tileWidth, texTileY + tileHeight}},
		{{x		   , y + 16.0f},	{texTileX			 , texTileY + tileHeight}}
	};
	
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(attributes) * (x / 16 + (y / 16) * m_width), sizeof(attributes), attributes);
}

void TileMap::draw() {
	m_shader.useProgram();
	
	glEnableVertexAttribArray(4);
	glEnableVertexAttribArray(5);
	
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	
	glVertexAttribPointer(m_shader.attrib("coord2d"), 2, GL_FLOAT, GL_FALSE, sizeof(VertexAttribute), 0);
	glVertexAttribPointer(m_shader.attrib("texcoord"), 2, GL_FLOAT, GL_FALSE, sizeof(VertexAttribute), (GLvoid*) offsetof(VertexAttribute, texcoord));
	
	m_texture->bind();
	
	glDrawArrays(GL_TRIANGLES, 0, 6 * m_width * m_height);
	
	m_texture->unbind();
	
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	
	Application::window.useDefaultShader();
}

