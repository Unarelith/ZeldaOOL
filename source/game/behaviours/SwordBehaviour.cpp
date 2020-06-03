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
#include <gk/core/input/GamePad.hpp>
#include <gk/scene/component/HitboxComponent.hpp>

#include "GameKey.hpp"
#include "SwordBehaviour.hpp"

#include "PositionComponent.hpp"
#include "SpriteComponent.hpp"
#include "WeaponComponent.hpp"

SwordBehaviour::SwordBehaviour() : Behaviour("Swinging") {
	// gk::AudioPlayer::playSound("sfx-swordSlash1"); // FIXME: GAMEKIT
}

void SwordBehaviour::update(gk::SceneObject &sword) {
	auto &swordPosition = sword.get<PositionComponent>();
	auto &weaponComponent = sword.get<WeaponComponent>();
	auto &spriteComponent = sword.get<SpriteComponent>();
	Sprite &sprite = spriteComponent.sprite();

	gk::SceneObject &owner = weaponComponent.owner;
	auto &ownerPosition = owner.get<PositionComponent>();

	auto &ownerSpriteComponent = owner.get<SpriteComponent>();
	auto &ownerSprite = ownerSpriteComponent.sprite();

	swordPosition = ownerPosition;

	if(m_state == "Swinging") {
		if(sprite.currentAnimation().isFinished()) {
			if(!m_keyReleased) {
				m_state = "Loading";

				m_loadingTimer.reset();
				m_loadingTimer.start();
			} else {
				m_state = "Finished";
			}
		}

		if(!gk::GamePad::isKeyPressed(weaponComponent.key)) {
			m_keyReleased = true;
		}
		else if(m_keyReleased && sprite.getAnimation((s8)ownerPosition.direction).displayedFramesAmount() >= 4) {
			if(gk::GamePad::isKeyPressed(GameKey::Left)) {
				ownerPosition.direction = Direction::Left;
			}

			if(gk::GamePad::isKeyPressed(GameKey::Right)) {
				ownerPosition.direction = Direction::Right;
			}

			if(gk::GamePad::isKeyPressed(GameKey::Up)) {
				ownerPosition.direction = Direction::Up;
			}

			if(gk::GamePad::isKeyPressed(GameKey::Down)) {
				ownerPosition.direction = Direction::Down;
			}

			m_keyReleased = false;

			// gk::AudioPlayer::playSound("sfx-swordSlash1"); // FIXME: GameKit

			ownerSprite.getAnimation((s8)ownerPosition.direction + 8).reset();
			sprite.getAnimation((s8)ownerPosition.direction).reset();
		}
	}
	else if(m_state == "Loading") {
		if(m_loadingTimer.time() > 650) {
			m_state = "Loaded";

			// gk::AudioPlayer::playSound("sfx-swordCharge"); // FIXME: GameKit
		}

		if(!gk::GamePad::isKeyPressed(weaponComponent.key)) {
			m_state = "Finished";
		}
	}
	else if(m_state == "Loaded") {
		if(!gk::GamePad::isKeyPressed(weaponComponent.key)) {
			// gk::AudioPlayer::playSound("sfx-swordSpin"); // FIXME: GameKit

			m_state = "SpinAttack";

			if(ownerPosition.direction == Direction::Left) {
				m_spinCurrentFrame = 2;
			}
			else if(ownerPosition.direction == Direction::Right) {
				m_spinCurrentFrame = 6;
			}
			else if(ownerPosition.direction == Direction::Up) {
				m_spinCurrentFrame = 4;
			}
			else if(ownerPosition.direction == Direction::Down) {
				m_spinCurrentFrame = 0;
			}

			sprite.getAnimation(8).reset(m_spinCurrentFrame);
			sprite.getAnimation(8).start();

			ownerSprite.getAnimation(12).reset(m_spinCurrentFrame);
			ownerSprite.getAnimation(12).start();
		}
	}
	else if(m_state == "SpinAttack") {
		if(m_spinFrameCounter < 9) {
			if(m_spinCurrentFrame != sprite.getAnimation(8).displayedFramesAmount()) {
				m_spinCurrentFrame = sprite.getAnimation(8).displayedFramesAmount();

				m_spinFrameCounter++;
			}
		} else {
			m_spinTimer.start();

			sprite.getAnimation(8).stop();

			if(m_spinTimer.time() >= sprite.getAnimation(8).delay()) {
				m_state = "Finished";
			}
		}
	}

	updateSprite(sword);
	updateHitboxes(sword);
}

void SwordBehaviour::updateHitboxes(gk::SceneObject &sword) {
	auto &spriteComponent = sword.get<SpriteComponent>();
	auto &hitboxComponent = sword.get<gk::HitboxComponent>();

	u16 frame = spriteComponent.sprite().currentAnimation().currentFrame();
	if(frame < 12) {
		hitboxComponent.setCurrentHitbox(frame);
	}
	else if(frame < 16) {
		hitboxComponent.setCurrentHitbox(frame - 4);
	}
}

void SwordBehaviour::updateSprite(gk::SceneObject &sword) {
	auto &sprite = sword.get<SpriteComponent>();

	if (m_state == "Finished") {
		sprite.setEnabled(false);
	}
	else {
		sprite.setState(m_state, sword);
	}
}

