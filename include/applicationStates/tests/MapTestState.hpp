/*
 * =====================================================================================
 *
 *       Filename:  MapTestState.hpp
 *
 *    Description:  
 *
 *        Created:  12/02/2015 23:12:00
 *       Compiler:  gcc
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef MAPTESTSTATE_HPP_
#define MAPTESTSTATE_HPP_

#include "ApplicationState.hpp"
#include "Font.hpp"
#include "Map.hpp"

class MapTestState : public ApplicationState {
	public:
		MapTestState() : m_map(&Map::getMap(0, 0, 0)) {}
		
		void update() override;
		
		void draw() override;
		
	private:
		Font m_font{"interface-font", 8, 16};
		
		Map *m_map;
};

#endif // MAPTESTSTATE_HPP_
