/*
 * =====================================================================================
 *
 *       Filename:  CollectableFactory.hpp
 *
 *    Description:  
 *
 *        Created:  01/05/2015 23:43:01
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef COLLECTABLEFACTORY_HPP_
#define COLLECTABLEFACTORY_HPP_

#include "CollectableMovement.hpp"
#include "IntTypes.hpp"
#include "SceneObject.hpp"
#include "Vector2.hpp"

enum RupeesAmount : u8 {
	One    = 1,
	Five   = 5,
	Thirty = 30,
};

class CollectableFactory {
	public:
		static SceneObject create(Vector2f position, const std::string &name, const std::string &soundEffectName, CollectableMovement::Type movementType);
		
		static SceneObject createHeart(Vector2f position, CollectableMovement::Type movementType);
		static SceneObject createRupees(Vector2f position, RupeesAmount amount, CollectableMovement::Type movementType);
};

#endif // COLLECTABLEFACTORY_HPP_
