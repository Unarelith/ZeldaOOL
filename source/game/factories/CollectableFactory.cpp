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
// #include <gk/audio/AudioPlayer.hpp> // FIXME: GAMEKIT
#include <gk/resource/ResourceHandler.hpp>
#include <gk/scene/component/CollisionComponent.hpp>
#include <gk/scene/component/HitboxComponent.hpp>
#include <gk/scene/component/MovementComponent.hpp>
#include <gk/scene/Scene.hpp>

#include "CollectableFactory.hpp"

#include "Image.hpp"
#include "CollectableComponent.hpp"
#include "HealthComponent.hpp"
#include "InventoryComponent.hpp"
#include "LifetimeComponent.hpp"
#include "PositionComponent.hpp"

gk::SceneObject CollectableFactory::create(u16 x, u16 y, const std::string &name, const std::string &soundEffectName, CollectableMovement::Type movementType) {
	gk::SceneObject object(name, "Collectable");
	object.set<gk::MovementComponent>(new CollectableMovement(movementType)).speed = 0.4f;
	object.set<CollectableComponent>("sfx-" + soundEffectName);
	object.set<LifetimeComponent>(6000);

	auto &image = object.set<Image>("collectables-" + name);

	object.set<PositionComponent>(x + 7 - image.width() / 2, y + 8 - image.height() / 2, image.width(), image.height());

	auto &collisionComponent = object.set<gk::CollisionComponent>();
	collisionComponent.addAction(&CollectableFactory::collectableAction);

	auto &hitboxComponent = object.set<gk::HitboxComponent>();
	hitboxComponent.addHitbox(0, 0, image.width(), image.height());

	return object;
}

gk::SceneObject CollectableFactory::createHeart(u16 x, u16 y, CollectableMovement::Type movementType) {
	gk::SceneObject object = create(x, y, "heart", "getHeart", movementType);
	object.get<CollectableComponent>().setAction([](gk::SceneObject &player) {
		player.get<HealthComponent>().addLife(4);
	});

	return object;
}

gk::SceneObject CollectableFactory::createRupees(u16 x, u16 y, RupeesAmount amount, CollectableMovement::Type movementType) {
	std::string name = "rupees" + std::to_string(amount);

	gk::SceneObject object = create(x, y, name, (amount == RupeesAmount::One) ? "getRupee" : "getRupees5", movementType);
	object.get<CollectableComponent>().setAction([amount](gk::SceneObject &player) {
		player.get<InventoryComponent>().addRupees(amount);
	});

	return object;
}

void CollectableFactory::collectableAction(gk::SceneObject &collectable, gk::SceneObject &object, bool inCollision) {
	auto &collectableComponent = collectable.get<CollectableComponent>();
	auto &lifetimeComponent = collectable.get<LifetimeComponent>();

	if(object.type() == "Player" && inCollision) {
		// gk::AudioPlayer::playSound(collectableComponent.soundEffectName()); // FIXME: GAMEKIT

		collectableComponent.action(object);

		lifetimeComponent.kill();
	}
}

