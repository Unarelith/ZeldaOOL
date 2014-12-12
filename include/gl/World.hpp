/*
 * =====================================================================================
 *
 *       Filename:  World.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/12/2014 22:37:36
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef WORLD_HPP_
#define WORLD_HPP_

#include <memory>

#include "Chunk.hpp"

class World {
	public:
		World();
		~World();
		
		void draw();
		
	private:
		std::vector<std::unique_ptr<Chunk>> m_chunks;
};

#endif // WORLD_HPP_
