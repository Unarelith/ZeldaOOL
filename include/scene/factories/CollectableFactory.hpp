/*
 * =====================================================================================
 *
 *       Filename:  CollectableFactory.hpp
 *
 *    Description:  
 *
 *        Created:  24/02/2015 23:21:14
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef COLLECTABLEFACTORY_HPP_
#define COLLECTABLEFACTORY_HPP_

#include "SceneObject.hpp"
#include "Types.hpp"

enum class RupeesAmount : u8 {
	One    = 1,
	Five   = 5,
	Thirty = 30,
};

class CollectableFactory {
	public:
		static SceneObject create(u16 x, u16 y, const std::string &name);
		
		static SceneObject createRupees(u16 x, u16 y, RupeesAmount amount);
};

#endif // COLLECTABLEFACTORY_HPP_
