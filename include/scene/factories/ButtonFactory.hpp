/*
 * =====================================================================================
 *
 *       Filename:  ButtonFactory.hpp
 *
 *    Description:  
 *
 *        Created:  19/02/2015 01:49:19
 *       Compiler:  gcc
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef BUTTONFACTORY_HPP_
#define BUTTONFACTORY_HPP_

#include "SceneObject.hpp"
#include "Types.hpp"

class ButtonFactory {
	public:
		static SceneObject create(u16 tileX, u16 tileY);
};

#endif // BUTTONFACTORY_HPP_
