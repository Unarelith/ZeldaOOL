/*
 * =====================================================================================
 *
 *       Filename:  World.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/12/2014 22:37:51
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "World.hpp"

World::World() {
	for(u8 y = 0 ; y < 2 ; y++) {
		for(u8 x = 0 ; x < 2 ; x++) {
			m_chunks.push_back(std::unique_ptr<Chunk>(new Chunk(0, x, y)));
			m_chunks.back()->update();
		}
	}
}

World::~World() {
}

void World::draw() {
	for(auto &it : m_chunks) {
		it->draw();
	}
}

