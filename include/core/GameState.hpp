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

#include "Map.hpp"

class GameState {
	public:
		GameState();
		~GameState();
		
		Map &currentMap() { return *m_currentMap; }
		void setCurrentMap(Map *map) { m_currentMap = map; }
		
		u16 playerRupees() const { return m_playerRupees; }
		
		static GameState &getInstance() {
			static GameState instance;
			return instance;
		}
		
	private:
		Map *m_currentMap;
		
		u16 m_playerRupees;
};

#endif // GAMESTATE_HPP_
