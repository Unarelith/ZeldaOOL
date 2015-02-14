/*
 * =====================================================================================
 *
 *       Filename:  SceneObjectTestState.hpp
 *
 *    Description:  
 *
 *        Created:  14/02/2015 17:37:32
 *       Compiler:  gcc
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef SCENEOBJECTTESTSTATE_HPP_
#define SCENEOBJECTTESTSTATE_HPP_

#include "ApplicationState.hpp"
#include "DrawingSystem.hpp"
#include "Font.hpp"
#include "MovementSystem.hpp"
#include "SceneObject.hpp"

class SceneObjectTestState : public ApplicationState {
	public:
		SceneObjectTestState();
		
		void update() override;
		
		void draw() override;
		
	private:
		DrawingSystem m_drawingSystem;
		
		MovementSystem m_movementSystem;
		
		Font m_font{"interface-font", 8, 16};
		
		SceneObject m_object;
};

#endif // SCENEOBJECTTESTSTATE_HPP_
