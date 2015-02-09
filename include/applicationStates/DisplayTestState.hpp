/*
 * =====================================================================================
 *
 *       Filename:  DisplayTestState.hpp
 *
 *    Description:  
 *
 *        Created:  09/02/2015 02:15:29
 *       Compiler:  gcc
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef DISPLAYTESTSTATE_HPP_
#define DISPLAYTESTSTATE_HPP_

#include "ApplicationState.hpp"
#include "Image.hpp"

class DisplayTestState : public ApplicationState {
	public:
		void update() override;
		
		void draw() override;
		
	private:
		Image m_image{"characters-link"};
};

#endif // DISPLAYTESTSTATE_HPP_
