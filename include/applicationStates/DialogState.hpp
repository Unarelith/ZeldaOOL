/*
 * =====================================================================================
 *
 *       Filename:  DialogState.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  29/09/2014 19:38:40
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef DIALOGSTATE_HPP_
#define DIALOGSTATE_HPP_

#include "Dialog.hpp"
#include "MapState.hpp"

class DialogState : public ApplicationState {
	public:
		DialogState(ApplicationState *parent, const std::string &text);
		
		void update();
		
		void render();
		
	private:
		Dialog m_dialog;
};

#endif // DIALOGSTATE_HPP_
