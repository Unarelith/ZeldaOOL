/*
 * =====================================================================================
 *
 *       Filename:  TestState.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/12/2014 21:36:48
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef TESTSTATE_HPP_
#define TESTSTATE_HPP_

#include "ApplicationState.hpp"
#include "Camera.hpp"
#include "Chunk.hpp"

class TestState : public ApplicationState {
	public:
		TestState();
		~TestState();
		
		void update();
		
		void draw();
		
	private:
		Camera m_camera;
		Chunk m_chunk;
};

#endif // TESTSTATE_HPP_
