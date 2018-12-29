/*
 * =====================================================================================
 *
 *       Filename:  SwordBehaviour.cpp
 *
 *    Description:
 *
 *        Created:  02/05/2015 17:44:54
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <gk/core/input/GamePad.hpp>

#include "AudioPlayer.hpp"
#include "GameKey.hpp"
#include "SwordBehaviour.hpp"

#include "HitboxComponent.hpp"
#include "PositionComponent.hpp"
#include "SpriteComponent.hpp"
#include "WeaponComponent.hpp"

SwordBehaviour::SwordBehaviour() : Behaviour("Swinging") {
	AudioPlayer::playEffect("swordSlash1");
}

void SwordBehaviour::action(SceneObject &sword) {
	auto &swordPosition = sword.get<PositionComponent>();
	auto &weaponComponent = sword.get<WeaponComponent>();
	auto &spriteComponent = sword.get<SpriteComponent>();
	Sprite &sprite = spriteComponent.sprite();

	SceneObject &owner = weaponComponent.owner;
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

			AudioPlayer::playEffect("swordSlash1");

			ownerSprite.getAnimation((s8)ownerPosition.direction + 8).reset();
			sprite.getAnimation((s8)ownerPosition.direction).reset();
		}
	}
	else if(m_state == "Loading") {
		if(m_loadingTimer.time() > 650) {
			m_state = "Loaded";

			AudioPlayer::playEffect("swordCharge");
		}

		if(!gk::GamePad::isKeyPressed(weaponComponent.key)) {
			m_state = "Finished";
		}
	}
	else if(m_state == "Loaded") {
		if(!gk::GamePad::isKeyPressed(weaponComponent.key)) {
			AudioPlayer::playEffect("swordSpin");

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

void SwordBehaviour::updateHitboxes(SceneObject &sword) {
	auto &spriteComponent = sword.get<SpriteComponent>();
	auto &hitboxComponent = sword.get<HitboxComponent>();

	u16 frame = spriteComponent.sprite().currentAnimation().currentFrame();
	if(frame < 12) {
		hitboxComponent.setCurrentHitbox(frame);
	}
	else if(frame < 16) {
		hitboxComponent.setCurrentHitbox(frame - 4);
	}
}

void SwordBehaviour::updateSprite(SceneObject &sword) {
	auto &sprite = sword.get<SpriteComponent>();

	if (m_state == "Finished") {
		sprite.setEnabled(false);
	}
	else {
		sprite.setState(m_state, sword);
	}
}

