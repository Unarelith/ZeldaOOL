/*
 * =====================================================================================
 *
 *       Filename:  GameState.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/12/2014 22:32:21
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef GAMESTATE_HPP_
#define GAMESTATE_HPP_

#include "AnimatedMap.hpp"

class GameState {
	public:
		GameState();
		~GameState();
		
		AnimatedMap &currentMap() { return *m_currentMap; }
		void setCurrentMap(u8 mapX, u8 mapY);
		
		static GameState &getInstance() {
			static GameState instance;
			return instance;
		}
		
	private:
		AnimatedMap *m_currentMap;
};

#endif // GAMESTATE_HPP_
