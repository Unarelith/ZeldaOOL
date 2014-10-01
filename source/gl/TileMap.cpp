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
	
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	
	m_shader.load("shaders/map.v.glsl", "shaders/map.f.glsl");
	ShaderManager::push(m_shader);
	
	m_x = 0;
	m_y = 0;
	
	glm::mat4 projectionMatrix = glm::ortho(m_x, m_x + WINDOW_WIDTH, m_y + WINDOW_HEIGHT - 16.0f, m_y - 16.0f);
	
	glUniformMatrix4fv(ShaderManager::currentShader().uniform("u_projectionMatrix"), 1, GL_FALSE, glm::value_ptr(projectionMatrix));
	
	glUniform2f(ShaderManager::currentShader().uniform("u_mapPosition"), m_x, m_y);
	
	ShaderManager::pop();
}

void TileMap::updateTile(float x, float y, u16 id) {
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	
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
	
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void TileMap::draw() {
	ShaderManager::push(m_shader);
	
	glUniform2f(ShaderManager::currentShader().uniform("u_mapPosition"), m_x, m_y);
	
	glEnableVertexAttribArray(ShaderManager::currentShader().attrib("coord2d"));
	glEnableVertexAttribArray(ShaderManager::currentShader().attrib("texCoord"));
	
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	
	glVertexAttribPointer(ShaderManager::currentShader().attrib("coord2d"), 2, GL_FLOAT, GL_FALSE, sizeof(VertexAttribute), 0);
	glVertexAttribPointer(ShaderManager::currentShader().attrib("texCoord"), 2, GL_FLOAT, GL_FALSE, sizeof(VertexAttribute), (GLvoid*) offsetof(VertexAttribute, texcoord));
	
	m_texture->bind();
	
	glDrawArrays(GL_TRIANGLES, 0, 6 * m_width * m_height);
	
	m_texture->unbind();
	
	glDisableVertexAttribArray(ShaderManager::currentShader().attrib("texCoord"));
	glDisableVertexAttribArray(ShaderManager::currentShader().attrib("coord2d"));
	
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	
	ShaderManager::pop();
}

