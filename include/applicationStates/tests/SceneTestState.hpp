/*
 * =====================================================================================
 *
 *       Filename:  SceneTestState.hpp
 *
 *    Description:  
 *
 *        Created:  15/02/2015 12:42:07
 *       Compiler:  gcc
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef SCENETESTSTATE_HPP_
#define SCENETESTSTATE_HPP_

#include "ApplicationState.hpp"
#include "Font.hpp"
#include "Scene.hpp"

class SceneTestState : public ApplicationState {
	public:
		SceneTestState();
		
		void update() override;
		
		void draw() override;
		
	private:
		Font m_font{"interface-font", 8, 16};
		
		Scene m_scene;
};

#endif // SCENETESTSTATE_HPP_
