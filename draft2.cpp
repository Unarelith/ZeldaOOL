/*
 * =====================================================================================
 *
 *       Filename:  draft2.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  28/08/2014 01:25:00
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
class Action {
	public:
		Action() {
		}
		
		virtual ~Action() {
		}
		
		virtual void update() = 0;
		
		virtual void draw() = 0;
};

class StandingAction : public Action {
	/* ... */
}

class MovingAction : public Action {
	public:
		MovingAction() {
		}
		
		~MovingAction() {
		}
		
		void update() {
			// Player is a global object in
			// CharacterManager namespace
			using namespace CharacterManager;
			
			// Keys...
			
			player.setX(player.x() + player.vx());
			player.setY(player.y() + player.vy());
			
			player.setVX(0);
			player.setVY(0);
			
			// That's ugly code, right?
		}
		
		void draw() {
		}
};

class SwordSwingingAction : public Action {
	public:
		SwordSwingingAction() {
		}
		
		~SwordSwingingAction() {
		}
		
		void update() {
			using namespace CharacterManager;
			
			m_sword.update(Sword::State::Swinging);
			
			// /!\ DANGER ZONE /!\ \\
			//		Here find a way to move link
			//		forward, then back to his
			//		previous position
			// /!\ END OF DANGER ZONE /!\ \\
		}
		
		void draw() {
			// I don't really like these "using
			// namespace" everywhere
			using namespace CharacterManager;
			
			player.playAnimation(player.x(), player.y(), player.direction() + 8);
			
			// Useful to draw 'weed' effect ;)
			EffectManager::drawEffects(&player);
			
			m_sword.draw();
		}
		
	private:
		Sword m_sword;
};

namespace ActionManager {
	Action *changeAction(Action **currentAction, Action *nextAction) {
		if(*currentAction) delete *currentAction;
		*currentAction = nextAction;
	}
	
}

class Player : public Character {
	public:
		Player() : Character(/*...*/) {
			// ...
			
			m_currentAction = nullptr;
			
			ActionManager::changeAction(m_currentAction, new StandingAction());
		}
		
		~Player() {
		}
		
		void update() {
			m_currentAction->update();
		}
		
		void draw() {
			m_currentAction->draw();
		}
		
		// ...
		
	private:
		// ...
		
		Action *m_currentAction;
}

