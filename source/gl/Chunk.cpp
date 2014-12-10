/*
 * =====================================================================================
 *
 *       Filename:  Chunk.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/12/2014 02:00:35
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include <SFML/OpenGL.hpp>

#include "Chunk.hpp"
#include "GameState.hpp"
#include "ResourceHandler.hpp"

Chunk::Chunk() : m_texture(ResourceHandler::getInstance().get<Tileset>("plain").texture()), m_map(GameState::getInstance().currentMap()) {
}

Chunk::~Chunk() {
}

void Chunk::update() {
}

void Chunk::draw() {
	for(u16 z = 0 ; z < m_map.height() ; z++) {
		for(u16 x = 0 ; x < m_map.width() ; x++) {
			s16 tile = m_map.getTile(x, z);
			
			switch(tile) {
				case 3:
					drawCube(x, 1, z, tile);
					break;
				// Top tree
				case 30:
				case 31:
					drawCube(x, 2, z, tile);
					drawCube(x, 1, z, tile + 16);
					drawCube(x, 2, z + 1, tile + 1);
					drawCube(x, 1, z + 1, tile + 16 + 1);
					break;
				case 62:
				case 63:
					drawCube(x, 2, z, tile);
					drawCube(x, 1, z, tile - 16);
					break;
				// Bottom tree
				case 46:
				case 47:
					break;
				// Walls
				case 120:
				case 127:
				case 138:
				case 147:
				case 148:
				case 158:
					drawCube(x, 2, z, 148);
				case 145:
					drawCube(x, 2, z, 134);
				case 168:
					drawCube(x, 2, z, 133);
				case 247:
					drawCube(x, 1, z, tile);
					break;
				default:
					drawCube(x, 0, z, tile);
					break;
			}
		}
	}
}

short Chunk::getTileFace(int i, short tile) {
	switch(tile) {
		// Tree top
		case 30:
		case 31:
			// Front and back
			if(i == 0 || i == 2) {
				return tile - (tile % 30) * 2 + 1;
			}
			break;
		// Tree bottom
		case 46:
		case 47:
			// Front and back
			if(i == 0 || i == 2) {
				return tile - (tile % 46) * 2 + 1;
			}
			break;
		// Mountains
		case 127:
		case 120:
		case 138:
		case 147:
			if(i != 1 && i != 3) {
				return 148;
			}
			break;
		case 133:
			if(i == 5) {
				return 134;
			}
			break;
		case 134:
			if(i == 5) {
				return 133;
			}
			break;
		case 145:
			if(i == 5) {
				return 144;
			}
			break;
		case 168:
			if(i == 2) {
				return 144;
			}
			else if(i == 5) {
				return 145;
			}
			break;
	}
	
	return tile;
}

void Chunk::drawCube(float x, float y, float z, short tile) {
	GLfloat coords[] = {
		// Front
		x, y, z + 1,
		x + 1, y, z + 1,
		x + 1, y + 1, z + 1,
		x, y + 1, z + 1,
		// Top
		x, y + 1, z + 1,
		x + 1, y + 1, z + 1,
		x + 1, y + 1, z,
		x, y + 1, z,
		// Back
		x + 1, y, z,
		x, y, z,
		x, y + 1, z,
		x + 1, y + 1, z,
		// Bottom
		x, y, z,
		x + 1, y, z,
		x + 1, y, z + 1,
		x, y, z + 1,
		// Left
		x, y, z,
		x, y, z + 1,
		x, y + 1, z + 1,
		x, y + 1, z,
		// Right
		x + 1, y, z + 1,
		x + 1, y, z,
		x + 1, y + 1, z,
		x + 1, y + 1, z + 1 
	};
	
	GLfloat colors[3 * 4 * 6] = {
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f
	};
	
	GLfloat texCoords[2 * 4 * 6];
	for(int i = 0 ; i < 6 ; i++) {
		float textureX1 = (getTileFace(i, tile) % (m_texture.getSize().x / 16)) * 16 / (float)m_texture.getSize().x;
		float textureY1 = (getTileFace(i, tile) / (m_texture.getSize().x / 16)) * 16 / (float)m_texture.getSize().y;
		
		float textureX2 = textureX1 + 16 / (float)m_texture.getSize().x;
		float textureY2 = textureY1 + 16 / (float)m_texture.getSize().y;
		
		texCoords[i * 8]	 = textureX1;
		texCoords[i * 8 + 1] = textureY2;
		
		texCoords[i * 8 + 2] = textureX2;
		texCoords[i * 8 + 3] = textureY2;
		
		texCoords[i * 8 + 4] = textureX2;
		texCoords[i * 8 + 5] = textureY1;
		
		texCoords[i * 8 + 6] = textureX1;
		texCoords[i * 8 + 7] = textureY1;
	}
	
	for(int i = 1 ; i < 6 ; i++) {
		memcpy(&colors[i * 4 * 3], &colors[0], 3 * 4 * sizeof(GLfloat));	
	}
	
	GLubyte indices[] = {
		// Front
		0, 1, 2,
		2, 3, 0,
		// Top
		4, 5, 6,
		6, 7, 4,
		// Back
		8, 9, 10,
		10, 11, 8,
		// Bottom
		12, 13, 14,
		14, 15, 12,
		// Left
		16, 17, 18,
		18, 19, 16,
		// Right
		20, 21, 22,
		22, 23, 20
	};
	
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	
	glVertexPointer(3, GL_FLOAT, 0, coords);
	glColorPointer(3, GL_FLOAT, 0, colors);
	glTexCoordPointer(2, GL_FLOAT, 0, texCoords);
	
	sf::Texture::bind(&m_texture);
	
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_BYTE, indices);
	
	sf::Texture::bind(nullptr);
	
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
}
