/*
 * =====================================================================================
 *
 *       Filename:  DialogState.hpp
 *
 *    Description:  
 *
 *        Created:  29/09/2014 19:38:40
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
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
		
		void draw();
		
	private:
		Dialog m_dialog;
};

#endif // DIALOGSTATE_HPP_
