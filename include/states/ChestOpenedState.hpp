/*
 * =====================================================================================
 *
 *       Filename:  ChestOpenedState.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/10/2014 00:58:17
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef CHESTOPENEDSTATE_HPP_
#define CHESTOPENEDSTATE_HPP_

#include "GameState.hpp"
#include "Image.hpp"

class ChestOpenedState : public GameState {
	public:
		ChestOpenedState(GameState *parent, float x, float y);
		~ChestOpenedState();
		
		void update();
		
		void render();
	
		enum State {
			Opening,
			Opened,
			Finished
		};
		
	private:
		State m_state;
		
		Image m_item;
		
		float m_itemX;
		float m_itemY;
		
		float m_movementCounter;
		
		float m_speed;
};

#endif // CHESTOPENEDSTATE_HPP_
