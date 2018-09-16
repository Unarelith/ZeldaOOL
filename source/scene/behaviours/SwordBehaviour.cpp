/*
 * =====================================================================================
 *
 *       Filename:  SwordBehaviour.cpp
 *
 *    Description:
 *
 *        Created:  02/05/2015 17:44:54
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "AudioPlayer.hpp"
#include "GamePad.hpp"
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
	Sprite &sprite = spriteComponent.sprite;

	SceneObject &owner = weaponComponent.owner;
	auto &ownerPosition = owner.get<PositionComponent>();

	auto &ownerSpriteComponent = owner.get<SpriteComponent>();
	auto &ownerSprite = ownerSpriteComponent.sprite;

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

		if(!GamePad::isKeyPressed(weaponComponent.key)) {
			m_keyReleased = true;
		}
		else if(m_keyReleased && sprite.getAnimation((s8)ownerPosition.direction).displayedFramesAmount() >= 4) {
			if(GamePad::isKeyPressed(GameKey::Left)) {
				ownerPosition.direction = Direction::Left;
			}

			if(GamePad::isKeyPressed(GameKey::Right)) {
				ownerPosition.direction = Direction::Right;
			}

			if(GamePad::isKeyPressed(GameKey::Up)) {
				ownerPosition.direction = Direction::Up;
			}

			if(GamePad::isKeyPressed(GameKey::Down)) {
				ownerPosition.direction = Direction::Down;
			}

			m_keyReleased = false;

			AudioPlayer::playEffect("swordSlash1");

			ownerSprite.getAnimation((s8)ownerPosition.direction + 8).reset();
			sprite.getAnimation((s8)ownerPosition.direction).reset();
		}
	}
	else if(m_state == "Loading") {
		if(m_loadingTimer.time() > 650 && !m_isLoaded) {
			m_isLoaded = true;

			AudioPlayer::playEffect("swordCharge");
		}

		//if(!keyPressed()) {
		if(!GamePad::isKeyPressed(weaponComponent.key)) {
			if(m_loadingTimer.time() > 650) {
				AudioPlayer::playEffect("swordSpin");

				m_isLoaded = false;

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
			} else {
				m_state = "Finished";
			}
		}
	}
	else if(m_state == "SpinAttack") {
		if(m_spinFrameCounter < 9) {
			if(m_spinCurrentFrame != sprite.getAnimation(8).displayedFramesAmount()) {
				m_spinCurrentFrame = sprite.getAnimation(8).displayedFramesAmount();

				m_spinFrameCounter++;
			}
		} else {
			ownerSpriteComponent.animID = (s8)ownerPosition.direction;
			m_spinTimer.start();

			spriteComponent.isAnimated = false;
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

	u16 frame = spriteComponent.sprite.getAnimation(spriteComponent.animID).currentFrame();
	if(frame < 12) {
		hitboxComponent.setCurrentHitbox(frame);
	}
	else if(frame < 16) {
		hitboxComponent.setCurrentHitbox(frame - 4);
	}
}

void SwordBehaviour::updateSprite(SceneObject &sword) {
	auto &spriteComponent = sword.get<SpriteComponent>();
	auto &ownerPosition = sword.get<WeaponComponent>().owner.get<PositionComponent>();

	if(m_state == "Swinging") {
		spriteComponent.isAnimated = true;
		spriteComponent.animID = static_cast<s8>(ownerPosition.direction);
	}
	else if(m_state == "Loading") {
		spriteComponent.isAnimated = m_isLoaded;
		spriteComponent.animID = static_cast<s8>(ownerPosition.direction) + 4;
		spriteComponent.frameID = 1;
	}
	else if(m_state == "SpinAttack") {
		spriteComponent.isAnimated = m_spinFrameCounter < 9;
		spriteComponent.animID = 8;
		spriteComponent.frameID = m_spinCurrentFrame;
	} else {
		spriteComponent.isEnabled = false;
	}
}

