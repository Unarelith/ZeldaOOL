/*
 * =====================================================================================
 *
 *       Filename:  FactoriesTestState.hpp
 *
 *    Description:  
 *
 *        Created:  14/02/2015 21:56:06
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef FACTORIESTESTSTATE_HPP_
#define FACTORIESTESTSTATE_HPP_

#include "ApplicationState.hpp"
#include "DrawingSystem.hpp"
#include "Font.hpp"
#include "MovementSystem.hpp"
#include "SceneObject.hpp"

class FactoriesTestState : public ApplicationState {
	public:
		FactoriesTestState();
		
		void update() override;
		
		void draw() override;
		
	private:
		DrawingSystem m_drawingSystem;
		
		MovementSystem m_movementSystem;
		
		Font m_font{"interface-font", 8, 16};
		
		SceneObject m_player;
		std::vector<SceneObject> m_octoroks;
};

#endif // FACTORIESTESTSTATE_HPP_
