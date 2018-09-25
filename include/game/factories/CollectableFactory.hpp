/*
 * =====================================================================================
 *
 *       Filename:  CollectableFactory.hpp
 *
 *    Description:
 *
 *        Created:  01/05/2015 23:43:01
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef COLLECTABLEFACTORY_HPP_
#define COLLECTABLEFACTORY_HPP_

#include "CollectableMovement.hpp"
#include "SceneObject.hpp"

enum RupeesAmount : u8 {
	One     = 1,
	Five    = 5,
	Thirty  = 30,
	Hundred = 100
};

enum CollectableType {
	Heart,
	Rupees
};

class CollectableFactory {
	public:
		static SceneObject create(u16 x, u16 y, const std::string &name, const std::string &soundEffectName, CollectableMovement::Type movementType);

		static SceneObject createHeart(u16 x, u16 y, CollectableMovement::Type movementType);
		static SceneObject createRupees(u16 x, u16 y, RupeesAmount amount, CollectableMovement::Type movementType);
};

#endif // COLLECTABLEFACTORY_HPP_
