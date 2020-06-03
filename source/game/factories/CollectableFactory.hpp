/*
 * =====================================================================================
 *
 *  ZeldaOOL
 *
 *  Copyright (C) 2014-2020 Unarelith, Quentin Bazin <zelda.ool@unarelith.net>
 *
 *  This file is part of ZeldaOOL.
 *
 *  ZeldaOOL is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  ZeldaOOL is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with ZeldaOOL; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA  02110-1301 USA
 *
 * =====================================================================================
 */
#ifndef COLLECTABLEFACTORY_HPP_
#define COLLECTABLEFACTORY_HPP_

#include <gk/scene/SceneObject.hpp>

#include "CollectableMovement.hpp"

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
		static gk::SceneObject create(u16 x, u16 y, const std::string &name, const std::string &soundEffectName, CollectableMovement::Type movementType);

		static gk::SceneObject createHeart(u16 x, u16 y, CollectableMovement::Type movementType);
		static gk::SceneObject createRupees(u16 x, u16 y, RupeesAmount amount, CollectableMovement::Type movementType);

	private:
		static void collectableAction(gk::SceneObject &collectable, gk::SceneObject &object, bool inCollision);
};

#endif // COLLECTABLEFACTORY_HPP_
