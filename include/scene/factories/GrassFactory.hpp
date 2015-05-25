/*
 * =====================================================================================
 *
 *       Filename:  GrassFactory.hpp
 *
 *    Description:  
 *
 *        Created:  02/05/2015 20:32:26
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef GRASSFACTORY_HPP_
#define GRASSFACTORY_HPP_

#include "SceneObject.hpp"
#include "Vector2.hpp"

class GrassFactory {
	public:
		static SceneObject create(Vector2u16 tile, bool lowGrass = false);
};

#endif // GRASSFACTORY_HPP_
