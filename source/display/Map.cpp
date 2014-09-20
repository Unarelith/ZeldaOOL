/*
 * =====================================================================================
 *
 *       Filename:  Map.cpp
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

#include "Application.hpp"
#include "Debug.hpp"
#include "Map.hpp"
#include "VertexAttribute.hpp"

Map::Map() {
}

Map::Map(std::string filename, Texture &texture, u16 width, u16 height) {
	load(filename, texture, width, height);
}

Map::~Map() {
	free(m_data);
	
	glDeleteBuffers(1, &m_vbo);
}

void Map::load(std::string filename, Texture &texture, u16 width, u16 height) {
	m_texture = &texture;
	
	m_width = width;
	m_height = height;
	
	glGenBuffers(1, &m_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	
	u16* table = (u16*)malloc(m_width * m_height * sizeof(u16));
	
	int filesize;
	struct stat file_status;
	if(stat(filename.c_str(), &file_status) != 0) {
		filesize = sizeof(table) * m_width * m_height;
	} else {
		filesize = file_status.st_size;
	}
	
	SDL_RWops *f = SDL_RWFromFile(filename.c_str(), "r");
	if(!f) {
		error("Unable to open file %s: %s", filename.c_str(), SDL_GetError());
		exit(EXIT_FAILURE);
	}
	SDL_RWread(f, table, 2, filesize);
	SDL_RWclose(f);
	
	m_data = table;
	
	glBufferData(GL_ARRAY_BUFFER, sizeof(VertexAttribute) * m_width * m_height * 6, NULL, GL_DYNAMIC_DRAW);
	
	for(u16 y = 0 ; y < m_height ; y++) {
		for(u16 x = 0 ; x < m_width ; x++) {
			updateTile(m_data[x + y * m_width], x * 16, y * 16);
		}
	}
	
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Map::updateTile(u16 id, float x, float y) {
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

void Map::render() {
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	
	m_texture->bind();
	
	glVertexAttribPointer(Application::window.defaultShader().attrib("coord2d"), 2, GL_FLOAT, GL_FALSE, sizeof(VertexAttribute), 0);
	glVertexAttribPointer(Application::window.defaultShader().attrib("texcoord"), 2, GL_FLOAT, GL_FALSE, sizeof(VertexAttribute), (GLvoid*) offsetof(VertexAttribute, texcoord));
	
	glDrawArrays(GL_TRIANGLES, 0, 6 * m_width * m_height);
	
	m_texture->unbind();
	
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

