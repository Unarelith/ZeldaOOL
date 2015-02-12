/*
 * =====================================================================================
 *
 *       Filename:  AudioTestState.hpp
 *
 *    Description:  
 *
 *        Created:  12/02/2015 19:28:59
 *       Compiler:  gcc
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef AUDIOTESTSTATE_HPP_
#define AUDIOTESTSTATE_HPP_

#include "ApplicationState.hpp"
#include "Font.hpp"

class AudioTestState : public ApplicationState {
	public:
		void update() override;
		
		void draw() override;
		
	private:
		Font m_font{"interface-font", 8, 16};
		
		std::vector<std::string> m_musics{
			"indoor",
			"plain",
			"underground"
		};
		
		s8 m_musicID = 0;
};

#endif // AUDIOTESTSTATE_HPP_
